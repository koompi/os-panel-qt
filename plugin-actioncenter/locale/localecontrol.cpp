#include "localecontrol.h"
#include <QApplication>
#include <QComboBox>
#include <QFile>
#include <QDebug>
#include <QLocale>
#include <QStandardPaths>
#include <QTextStream>
#include <QTextCodec>
#include <QDateTime>
#include <QMessageBox>

#include <algorithm>


const static QString lcLang = QStringLiteral("LANG");

const static QString lcNumeric = QStringLiteral("LC_NUMERIC");
const static QString lcTime = QStringLiteral("LC_TIME");
const static QString lcMonetary = QStringLiteral("LC_MONETARY");
const static QString lcMeasurement = QStringLiteral("LC_MEASUREMENT");
const static QString lcCollate = QStringLiteral("LC_COLLATE");
const static QString lcCtype = QStringLiteral("LC_CTYPE");

const static QString lcLanguage = QStringLiteral("LANGUAGE");
localecontrol::localecontrol(LXQt::Settings *settings,QWidget *parent) : QWidget (parent),ui (new Ui::LocaleUi()),
    hasChanged(new bool), mSettings(settings)
{
    ui->setupUi (this);
    connect (ui->backbtn, &QToolButton::clicked, [&](){
        getStack ()->setCurrentIndex (0);
    });
    connect (ui->ac_notification, &QToolButton::clicked, [](){
        QProcess process;
        process.startDetached (QStringLiteral("systemsettings5"));
        process.waitForStarted ();
        process.waitForFinished (-1);
        process.close ();
    });
    m_combos << ui->comRegion
             <<  ui->comNumbers
              <<  ui->comTime
               <<  ui->comCurrentcy
                <<  ui->comMeasurement;
    hasChanged = false;
    initControls ();
    connect (ui->applyBtn, &QPushButton::clicked, [this](){
        emit save ();
    });
    connect (ui->cacelBtn, &QPushButton::clicked, [this](){
        emit reset ();
    });
}

localecontrol::~localecontrol()
{
    delete ui;
}
bool countryLessThan(const QLocale & c1, const QLocale & c2)
{
    // get the strings as in addLocaleToCombo() -> clabel
    return QString::localeAwareCompare(!c1.nativeCountryName().isEmpty()
                                       ? c1.nativeCountryName()
                                       : c1.countryToString(c1.country()),
                                       !c2.nativeCountryName().isEmpty()
                                       ? c2.nativeCountryName()
                                       : c2.countryToString(c2.country())) < 0;
}

void localecontrol::load()
{
    QList<QLocale> allLocales = QLocale::matchingLocales(QLocale::AnyLanguage, QLocale::AnyScript, QLocale::AnyCountry);
    std::sort(allLocales.begin(), allLocales.end(), countryLessThan);
    for(QComboBox * combo : qAsConst(m_combos))
    {
        initCombo(combo, allLocales);
    }

    readConfig();

    for(QComboBox * combo : qAsConst(m_combos))
    {
        connectCombo(combo);
    }

    connect(ui->checkBox, &QAbstractButton::toggled, [ = ]()
    {
        updateDescription ();
        updateEnabled();
        hasChanged = true;
    });

    updateEnabled();
    updateDescription();
    hasChanged = false;
}
void localecontrol::initCombo(QComboBox *combo, const QList<QLocale> &allLocales)
{
    combo->clear();
    const QString clabel = tr("No change");
    combo->setInsertPolicy(QComboBox::InsertAlphabetically);
    combo->addItem(clabel, QString());
    for(const QLocale & l : qAsConst(allLocales))
    {
        addLocaleToCombo(combo, l);
    }
}
void localecontrol::connectCombo(QComboBox *combo)
{
    connect(combo, &QComboBox::currentTextChanged, [ = ]()
    {
        hasChanged = true;
        updateDescription();
    });
}
void localecontrol::addLocaleToCombo(QComboBox *combo, const QLocale &locale)
{

    const QString clabel = !locale.nativeCountryName().isEmpty() ? locale.nativeCountryName() : locale.countryToString(locale.country());
    // This needs to use name() rather than bcp47name() or later on the export will generate a non-sense locale (e.g. "it" instead of
    // "it_IT")
    // TODO: Properly handle scripts (@foo)
    QString cvalue = locale.name();
    if (!cvalue.contains(QLatin1Char('.')))
    { // explicitely add the encoding, otherwise Qt doesn't accept dead keys and garbles the output as well
        cvalue.append(QLatin1Char('.') + QString::fromUtf8(QTextCodec::codecForLocale()->name()));
    }

    QString flagcode;
    const QStringList split = locale.name().split(QLatin1Char('_'));
    if (split.count() > 1)
    {
        flagcode = split[1].toLower();
    }
    /* TODO Find a better place for flags ... */
    QString flag(QStandardPaths::locate(QStandardPaths::GenericDataLocation, QStringLiteral("kf5/locale/countries/%1/flag.png").arg(flagcode)));
    QIcon flagIcon;
    if (!flag.isEmpty())
    {
        flagIcon = QIcon(flag);
    }

    QString itemResult;
    itemResult = QStringLiteral("%1 - %2 (%3)")
            .arg(clabel,
                 locale.nativeLanguageName(),
                 locale.name());

    combo->addItem(flagIcon, itemResult, cvalue);
}
void setCombo(QComboBox *combo, const QString &key)
{
    const int ix = combo->findData(key);
    if (ix > -1)
    {
        combo->setCurrentIndex(ix);
    }
}
void localecontrol::readConfig()
{
    mSettings->beginGroup(QStringLiteral("Formats"));

    bool useDetailed = mSettings->value(QStringLiteral("useDetailed"), false).toBool();
    ui->checkBox->setChecked(useDetailed);

    setCombo(ui->comRegion, mSettings->value(lcLang, QString::fromLocal8Bit(qgetenv(lcLang.toLatin1().constData()))).toString());

    setCombo(ui->comNumbers, mSettings->value(lcNumeric, QString::fromLocal8Bit(qgetenv(lcNumeric.toLatin1().constData()))).toString());
    setCombo(ui->comTime, mSettings->value(lcTime, QString::fromLocal8Bit(qgetenv(lcTime.toLatin1().constData()))).toString());
    setCombo(ui->comColSort, mSettings->value(lcCollate, QString::fromLocal8Bit(qgetenv(lcCollate.toLatin1().constData()))).toString());
    setCombo(ui->comCurrentcy, mSettings->value(lcMonetary, QString::fromLocal8Bit(qgetenv(lcMonetary.toLatin1().constData()))).toString());
    setCombo(ui->comMeasurement, mSettings->value(lcMeasurement, QString::fromLocal8Bit(qgetenv(lcMeasurement.toLatin1().constData()))).toString());

    updateEnabled();

    mSettings->endGroup();
}
void localecontrol::writeConfig()
{
    mSettings->beginGroup(QStringLiteral("Formats"));
    //    mSettings->beginGroup (QStringLiteral ("Language&Region"));

    // global ends up empty here when OK button is clicked from kcmshell5,
    // apparently the data in the combo is gone by the time save() is called.
    // This might be a problem in KCModule, but does not directly affect us
    // since within systemsettings, it works fine.
    // See https://bugs.kde.org/show_bug.cgi?id=334624
    if (ui->comRegion->count() == 0)
    {
        qWarning() << "Couldn't read data from UI, writing configuration failed.";
        return;
    }
    const QString global = ui->comRegion->currentData().toString();

    if (!ui->checkBox->isChecked())
    {
        // Global setting, clean up config
        mSettings->remove(QStringLiteral("useDetailed"));
        if (global.isEmpty())
        {
            mSettings->remove(lcLang);
        }
        else
        {
            mSettings->setValue(lcLang, global);
        }
        mSettings->remove(lcNumeric);
        mSettings->remove(lcTime);
        mSettings->remove(lcMonetary);
        mSettings->remove(lcMeasurement);
        mSettings->remove(lcCollate);
        mSettings->remove(lcCtype);
        qDebug() << "You checked the box"<<Qt::endl;
    }
    else
    {
        qDebug() << "You didn't check the box"<<Qt::endl;
        // Save detailed settings
        mSettings->setValue(QStringLiteral("useDetailed"), true);

        if (global.isEmpty())
        {
            mSettings->remove(lcLang);
        }
        else
        {
            mSettings->setValue(lcLang, global);
        }

        const QString numeric = ui->comNumbers->currentData().toString();
        if (numeric.isEmpty())
        {
            mSettings->remove(lcNumeric);
        }
        else
        {
            mSettings->setValue(lcNumeric, numeric);
        }

        const QString time = ui->comTime->currentData().toString();
        if (time.isEmpty())
        {
            mSettings->remove(lcTime);
        }
        else
        {
            mSettings->setValue(lcTime, time);
        }

        const QString monetary = ui->comCurrentcy->currentData().toString();
        if (monetary.isEmpty())
        {
            mSettings->remove(lcMonetary);
        }
        else
        {
            mSettings->setValue(lcMonetary, monetary);
        }

        const QString measurement = ui->comMeasurement->currentData().toString();
        if (measurement.isEmpty())
        {
            mSettings->remove(lcMeasurement);
        }
        else
        {
            mSettings->setValue(lcMeasurement, measurement);
        }

        const QString collate = ui->comColSort->currentData().toString();
        if (collate.isEmpty())
        {
            mSettings->remove(lcCollate);
        }
        else
        {
            mSettings->setValue(lcCollate, collate);
        }
    }
    mSettings->endGroup();
}
void localecontrol::updateDescription()
{
    const bool useDetailed = ui->checkBox->isChecked();

    QLocale nloc;
    QLocale tloc;
    QLocale cloc;
    QLocale mloc;

    if (useDetailed)
    {
        nloc = QLocale(ui->comNumbers->currentData().toString());
        tloc = QLocale(ui->comTime->currentData().toString());
        cloc = QLocale(ui->comColSort->currentData().toString());
        mloc = QLocale(ui->comMeasurement->currentData().toString());
    }
    else
    {
        nloc = QLocale(ui->comRegion->currentData().toString());
        tloc = QLocale(ui->comRegion->currentData().toString());
        cloc = QLocale(ui->comRegion->currentData().toString());
        mloc = QLocale(ui->comRegion->currentData().toString());
    }

    const QString numberExample = nloc.toString(1000.01);
    const QString timeExample = tloc.toString(QDateTime::currentDateTime());
    const QString currencyExample = cloc.toCurrencyString(24);

    QString measurementSetting;
    if (mloc.measurementSystem() == QLocale::ImperialUKSystem)
    {
        measurementSetting = tr("Imperial UK");
    }
    else if (mloc.measurementSystem() == QLocale::ImperialUSSystem)
    {
        measurementSetting = tr("Imperial US");
    }
    else
    {
        measurementSetting = tr("Metric");
    }

    ui->numberValue->setText(numberExample);
    ui->timeValue->setText(timeExample);
    ui->CurrentcyValue->setText(currencyExample);
    ui->measureValue->setText(measurementSetting);
}
void localecontrol::initControls()
{
    defaults();
    load();
    hasChanged = false;
}

void localecontrol::saveSettings()
{
    if (hasChanged)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Format Settings Changed"));
        msgBox.setText(tr("Do you want to save your changes? They will take effect the next time you log in."));
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);

        int ret = msgBox.exec();
        if( ret == QMessageBox::Save )
        {
            writeConfig();
        }
    }
}
void localecontrol::defaults()
{
    ui->checkBox->setChecked(false);

    // restore user defaults from env vars
    setCombo(ui->comRegion, QString::fromLocal8Bit(qgetenv(lcLang.toLatin1().constData())));
    setCombo(ui->comNumbers, QString::fromLocal8Bit(qgetenv(lcNumeric.toLatin1().constData())));
    setCombo(ui->comTime, QString::fromLocal8Bit(qgetenv(lcTime.toLatin1().constData())));
    setCombo(ui->comColSort, QString::fromLocal8Bit(qgetenv(lcCollate.toLatin1().constData())));
    setCombo(ui->comCurrentcy, QString::fromLocal8Bit(qgetenv(lcMonetary.toLatin1().constData())));
    setCombo(ui->comMeasurement, QString::fromLocal8Bit(qgetenv(lcMeasurement.toLatin1().constData())));

    updateEnabled();
}
void localecontrol::updateEnabled()
{

}
QStackedWidget *localecontrol::getStack() const
{
    return stack;
}
void localecontrol::setStack(QStackedWidget *value)
{
    stack = value;
}
//QString localecontrol::getTimezone_id() const
//{
//    return timezone_id;
//}

//void localecontrol::setTimezone_id(const QString &value)
//{
//    timezone_id = value;
//}
