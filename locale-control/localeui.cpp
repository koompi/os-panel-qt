#include "localeui.h"
#include <QDebug>
#include <tuple>
#include <QSettings>
localeUi::localeUi(QWidget *parent) : QWidget(parent)
{
    setupUi (this);
    connect (backbtn, &QToolButton::clicked, [&](){
        localeStack->setCurrentIndex (0);
    });
    connect(advancedBtn, &QToolButton::clicked, []() {
        QProcess process;
        process.startDetached("systemsettings5");
        process.waitForStarted();
        process.waitForFinished(-1);
        process.close();
    });
    //to check when item combobox changed
    connect (regionBox, &QComboBox::textActivated, [&](QString text){
       emit onCurrentTextChanged (text);
    });
    connect (LanguageBox, &QComboBox::textActivated, [&](QString text){
       emit onCurrentTextChanged (text);
    });
    connect (timezoneBox, &QComboBox::textActivated, [&](QString text){
       emit onCurrentTextChanged (text);
    });
    connect (this, &localeUi::onCurrentTextChanged, [&](QString text){
       qInfo() << text<<endl;
       applyBtn->setEnabled (true);
    });
    localeCon = new localecontrol(this);
    connect (applyBtn, &QToolButton::clicked, [&](){
        if(localeSetting->isCreated ()){
            localeSetting->updateSettings (listcombos ());
            updateDescription ();
            applyBtn->setEnabled (false);
        }else{
            localeSetting->saveSettings ();
        }
    });
    connect (localeCon, &localecontrol::emitRegionLists, this, &localeUi::setRegionName);
    connect (localeCon, &localecontrol::emitLanguageLists,this,&localeUi::setLanguageName);
    connect(localeCon, &localecontrol::currentIndexChanged,this,&localeUi::setTimezone);
    connect(localeCon, &localecontrol::getTimeFormat,this,&localeUi::setTimeFormat);
    // get default value into each comboboxs
    setRegionName ();
    setLanguageName ();
    setTimeFormat ();
    setTimezone ();
    // set the right data into combox
    LanguageBox->setCurrentText (std::get<0>(currentLang ()));
    regionBox->setCurrentText (std::get<1>(currentLang ()));
    timezoneBox->setCurrentText (getTimezone_id ());
    // put combox data into description labels
    regionValue->setText (regionBox->currentText ());
    langValue->setText (LanguageBox->currentText ());
    timeformValue->setText (timeformatBox->currentText ());
    timezoneValue->setText (timezoneBox->currentText ());
    // create locale setting configuration file
    localeSetting = new localeconfig(listcombos (), this);
    localeSetting->loadSettings ();
    updateDescription ();

}

void localeUi::setupUi(QWidget *Form)
{

    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(481, 1001);
    Form->setMinimumSize(QSize(100, 0));
    verticalLayout = new QVBoxLayout(Form);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    localehorizontalLayout = new QHBoxLayout();
    localehorizontalLayout->setObjectName(QString::fromUtf8("localehorizontalLayout"));
    backbtn = new QToolButton(Form);
    backbtn->setObjectName(QString::fromUtf8("backbtn"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
    backbtn->setSizePolicy(sizePolicy);
    backbtn->setMinimumSize(QSize(0, 0));
    QIcon icon;
    QString iconThemeName = QString::fromUtf8("draw-arrow-back");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    backbtn->setIcon(icon);
    backbtn->setPopupMode(QToolButton::DelayedPopup);
    backbtn->setAutoRaise(true);

    localehorizontalLayout->addWidget(backbtn);

    localeLabel = new QLabel(Form);
    localeLabel->setObjectName(QString::fromUtf8("localeLabel"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(localeLabel->sizePolicy().hasHeightForWidth());
    localeLabel->setSizePolicy(sizePolicy1);
    localeLabel->setMinimumSize(QSize(0, 0));
    localeLabel->setMaximumSize(QSize(16777215, 50));
    QFont font;
    font.setPointSize(15);
    localeLabel->setFont(font);
    localeLabel->setAlignment(Qt::AlignCenter);

    localehorizontalLayout->addWidget(localeLabel);

    horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    localehorizontalLayout->addItem(horizontalSpacer);


    verticalLayout->addLayout(localehorizontalLayout);

    verticalSpacer_2 = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_2);

    RegionLayout = new QHBoxLayout();
    RegionLayout->setObjectName(QString::fromUtf8("RegionLayout"));
    region = new QLabel(Form);
    region->setObjectName(QString::fromUtf8("region"));
    sizePolicy.setHeightForWidth(region->sizePolicy().hasHeightForWidth());
    region->setSizePolicy(sizePolicy);
    QFont font1;
    font1.setPointSize(11);
    region->setFont(font1);

    RegionLayout->addWidget(region);

    horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    RegionLayout->addItem(horizontalSpacer_2);

    regionBox = new QComboBox(Form);
    regionBox->setObjectName(QString::fromUtf8("regionBox"));
    sizePolicy1.setHeightForWidth(regionBox->sizePolicy().hasHeightForWidth());
    regionBox->setSizePolicy(sizePolicy1);

    RegionLayout->addWidget(regionBox);


    verticalLayout->addLayout(RegionLayout);

    LanguageLayout = new QHBoxLayout();
    LanguageLayout->setObjectName(QString::fromUtf8("LanguageLayout"));
    languages = new QLabel(Form);
    languages->setObjectName(QString::fromUtf8("languages"));
    sizePolicy.setHeightForWidth(languages->sizePolicy().hasHeightForWidth());
    languages->setSizePolicy(sizePolicy);
    languages->setFont(font1);
    languages->setFrameShape(QFrame::NoFrame);

    LanguageLayout->addWidget(languages);

    horizontalSpacer_3 = new QSpacerItem(61, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    LanguageLayout->addItem(horizontalSpacer_3);

    LanguageBox = new QComboBox(Form);
    LanguageBox->setObjectName(QString::fromUtf8("LanguageBox"));
    sizePolicy1.setHeightForWidth(LanguageBox->sizePolicy().hasHeightForWidth());
    LanguageBox->setSizePolicy(sizePolicy1);

    LanguageLayout->addWidget(LanguageBox);


    verticalLayout->addLayout(LanguageLayout);

    timeFormatLayout = new QHBoxLayout();
    timeFormatLayout->setObjectName(QString::fromUtf8("timeFormatLayout"));
    timeformat = new QLabel(Form);
    timeformat->setObjectName(QString::fromUtf8("timeformat"));
    sizePolicy.setHeightForWidth(timeformat->sizePolicy().hasHeightForWidth());
    timeformat->setSizePolicy(sizePolicy);
    timeformat->setFont(font1);

    timeFormatLayout->addWidget(timeformat);

    horizontalSpacer_4 = new QSpacerItem(42, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    timeFormatLayout->addItem(horizontalSpacer_4);

    timeformatBox = new QComboBox(Form);
    timeformatBox->setObjectName(QString::fromUtf8("timeformatBox"));
    sizePolicy1.setHeightForWidth(timeformatBox->sizePolicy().hasHeightForWidth());
    timeformatBox->setSizePolicy(sizePolicy1);

    timeFormatLayout->addWidget(timeformatBox);


    verticalLayout->addLayout(timeFormatLayout);

    timezoneLayout = new QHBoxLayout();
    timezoneLayout->setObjectName(QString::fromUtf8("timezoneLayout"));
    timezone = new QLabel(Form);
    timezone->setObjectName(QString::fromUtf8("timezone"));
    sizePolicy.setHeightForWidth(timezone->sizePolicy().hasHeightForWidth());
    timezone->setSizePolicy(sizePolicy);
    timezone->setFont(font1);

    timezoneLayout->addWidget(timezone);

    horizontalSpacer_6 = new QSpacerItem(60, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

    timezoneLayout->addItem(horizontalSpacer_6);

    timezoneBox = new QComboBox(Form);
    timezoneBox->setObjectName(QString::fromUtf8("timezoneBox"));
    sizePolicy1.setHeightForWidth(timezoneBox->sizePolicy().hasHeightForWidth());
    timezoneBox->setSizePolicy(sizePolicy1);

    timezoneLayout->addWidget(timezoneBox);


    verticalLayout->addLayout(timezoneLayout);

    verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_3);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
    horizontalSpacer_5 = new QSpacerItem(248, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_5);

    advancedBtn = new QPushButton(Form);
    advancedBtn->setObjectName(QString::fromUtf8("advancedBtn"));
    sizePolicy.setHeightForWidth(advancedBtn->sizePolicy().hasHeightForWidth());
    advancedBtn->setSizePolicy(sizePolicy);
    advancedBtn->setLayoutDirection(Qt::RightToLeft);

    horizontalLayout->addWidget(advancedBtn);

    applyBtn = new QPushButton(Form);
    applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
    applyBtn->setEnabled (false);
    sizePolicy.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
    applyBtn->setSizePolicy(sizePolicy);
    applyBtn->setLayoutDirection(Qt::RightToLeft);


    horizontalLayout->addWidget(applyBtn);


    verticalLayout->addLayout(horizontalLayout);

    verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_4);

    descframe = new QFrame(Form);
    descframe->setObjectName(QString::fromUtf8("descframe"));
    descframe->setMinimumSize(QSize(0, 250));
    descframe->setFrameShape(QFrame::NoFrame);
    descframe->setFrameShadow(QFrame::Raised);
    verticalLayout_3 = new QVBoxLayout(descframe);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    description = new QLabel(descframe);
    description->setObjectName(QString::fromUtf8("description"));
    sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
    description->setSizePolicy(sizePolicy);

    horizontalLayout_6->addWidget(description);

    horizontalSpacer_10 = new QSpacerItem(328, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_6->addItem(horizontalSpacer_10);


    verticalLayout_3->addLayout(horizontalLayout_6);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    horizontalSpacer_11 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_7->addItem(horizontalSpacer_11);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    regionlabel = new QLabel(descframe);
    regionlabel->setObjectName(QString::fromUtf8("regionlabel"));
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(regionlabel->sizePolicy().hasHeightForWidth());
    regionlabel->setSizePolicy(sizePolicy2);

    horizontalLayout_2->addWidget(regionlabel);

    horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_7);

    regionValue = new QLabel(descframe);
    regionValue->setObjectName(QString::fromUtf8("regionValue"));

    horizontalLayout_2->addWidget(regionValue);


    verticalLayout_2->addLayout(horizontalLayout_2);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    languagelabel = new QLabel(descframe);
    languagelabel->setObjectName(QString::fromUtf8("languagelabel"));
    sizePolicy2.setHeightForWidth(languagelabel->sizePolicy().hasHeightForWidth());
    languagelabel->setSizePolicy(sizePolicy2);

    horizontalLayout_3->addWidget(languagelabel);

    horizontalSpacer_8 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_8);

    langValue = new QLabel(descframe);
    langValue->setObjectName(QString::fromUtf8("langValue"));

    horizontalLayout_3->addWidget(langValue);


    verticalLayout_2->addLayout(horizontalLayout_3);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    timeformatlabel = new QLabel(descframe);
    timeformatlabel->setObjectName(QString::fromUtf8("timeformatlabel"));
    sizePolicy2.setHeightForWidth(timeformatlabel->sizePolicy().hasHeightForWidth());
    timeformatlabel->setSizePolicy(sizePolicy2);

    horizontalLayout_4->addWidget(timeformatlabel);

    timeformValue = new QLabel(descframe);
    timeformValue->setObjectName(QString::fromUtf8("timeformValue"));

    horizontalLayout_4->addWidget(timeformValue);


    verticalLayout_2->addLayout(horizontalLayout_4);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    timezonelabel = new QLabel(descframe);
    timezonelabel->setObjectName(QString::fromUtf8("timezonelabel"));
    sizePolicy2.setHeightForWidth(timezonelabel->sizePolicy().hasHeightForWidth());
    timezonelabel->setSizePolicy(sizePolicy2);

    horizontalLayout_5->addWidget(timezonelabel);

    horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_5->addItem(horizontalSpacer_9);

    timezoneValue = new QLabel(descframe);
    timezoneValue->setObjectName(QString::fromUtf8("timezoneValue"));

    horizontalLayout_5->addWidget(timezoneValue);


    verticalLayout_2->addLayout(horizontalLayout_5);


    horizontalLayout_7->addLayout(verticalLayout_2);


    verticalLayout_3->addLayout(horizontalLayout_7);

    verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout_3->addItem(verticalSpacer_5);


    verticalLayout->addWidget(descframe);

    verticalSpacer = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
}

void localeUi::retranslateUi(QWidget *Form)
{
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    backbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
    localeLabel->setText(QCoreApplication::translate("Form", "Locale", nullptr));
    region->setText(QCoreApplication::translate("Form", "Format: ", nullptr));
    languages->setText(QCoreApplication::translate("Form", "Language :", nullptr));
    timeformat->setText(QCoreApplication::translate("Form", "Time Format :", nullptr));
    timezone->setText(QCoreApplication::translate("Form", "Time zone :", nullptr));
    advancedBtn->setText(QCoreApplication::translate("Form", "Advanced Setting", nullptr));
    applyBtn->setText(QCoreApplication::translate("Form", "Apply", nullptr));
    description->setText(QCoreApplication::translate("Form", "Description :", nullptr));
    regionlabel->setText(QCoreApplication::translate("Form", "Format :", nullptr));
    regionValue->setText(QString());
    languagelabel->setText(QCoreApplication::translate("Form", "Language :", nullptr));
    langValue->setText(QString());
    timeformatlabel->setText(QCoreApplication::translate("Form", "Time Format :", nullptr));
    timeformValue->setText(QString());
    timezonelabel->setText(QCoreApplication::translate("Form", "Time Zone : ", nullptr));
    timezoneValue->setText(QString());

}

QStackedWidget *localeUi::getLocaleStacked() const
{
    return localeStack;
}

void localeUi::setLocaleStacked(QStackedWidget *value)
{
    localeStack=value;
}

QString localeUi::getTimezone_id() const
{
    return timezone_id;
}

void localeUi::setTimezone_id(const QString &value)
{
    timezone_id = value;
}

void localeUi::setRegionName()
{
    qDebug() << "setRegionName called"<<endl;
    for (int i = 1; i < QLocale::LastCountry-1; ++i)
    {
        //        qDebug()<<QLocale::countryToString((QLocale::Country)i);
        regionBox->addItem ((QLocale::countryToString((QLocale::Country)i)));
    }
}

void localeUi::setLanguageName()
{
    qDebug()<< "set language called" <<endl ;
    QList<QLocale> allLocales = QLocale::matchingLocales(
                QLocale::AnyLanguage,
                QLocale::AnyScript,
                QLocale::AnyCountry);
    QSet<QString> iso639Languages;

    for(const QLocale &locale : allLocales) {
        iso639Languages.insert(QLocale::languageToString(locale.language()));
        LanguageBox->addItem (QLocale::languageToString(locale.language()));
    }
    //    rqDebug() << iso639Languages;
}

void localeUi::setTimezone()
{
    QByteArray id =timezoneBox->currentText().toLatin1();
    QTimeZone zone = QTimeZone(id);
    QList<QByteArray> ids = QTimeZone::availableTimeZoneIds();
    foreach (QByteArray id, ids) {
        timezoneBox->addItem(id);
    }
}

void localeUi::setTimeFormat()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    timeformatBox->addItem (dateTimeString);
    setTimezone_id (QString(dateTime.timeZone ().id()));
}

QList<QComboBox *> localeUi::listcombos()
{
    return {regionBox,LanguageBox, timeformatBox, timezoneBox};
}

void localeUi::updateDescription()
{
    regionValue->setText (regionBox->currentText ());
    langValue->setText (LanguageBox->currentText ());
    timeformValue->setText (timeformatBox->currentText ());
    timezoneValue->setText (timezoneBox->currentText ());

}
//
const std::tuple<QString, QString>  localeUi::currentLang()
{
    QLocale locale;
    QString curlang = locale.languageToString (locale.language ());
    locale.countryToString (QLocale::Country::UnitedStates);
    qDebug() << curlang<<endl;
    return std::tuple(curlang, locale.countryToString (QLocale::Country::UnitedStates));
}



