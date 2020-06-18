#include "localeconfig.h"


localeConfig::localeConfig(QList<QComboBox * > combox,QObject *parent) : QObject(parent),list_combos{combox}
{
    settings = new QSettings(QStringLiteral("KOOMPI"), QStringLiteral("action-locale"));
}

void localeConfig::saveSettings()
{
    settings->beginGroup (QStringLiteral("locale"));
    settings->setValue (QStringLiteral("format"), list_combos.at (0)->currentText ());
    settings->setValue (QStringLiteral("language"), list_combos.at (1)->currentText ());
    settings->setValue (QStringLiteral("timeformat"), list_combos.at (2)->currentText ());
    settings->setValue (QStringLiteral("timezone"), list_combos.at(3)->currentText ());
    settings->endGroup ();
}

void localeConfig::loadSettings()
{
    QString format = settings->value (QStringLiteral("locale/format")).toString ();
    QString language = settings->value (QStringLiteral("locale/language")).toString ();
    QString timeformat = settings->value (QStringLiteral("locale/timeformat")).toString ();
    QString timezone = settings->value (QStringLiteral("locale/timezone")).toString ();
    list_combos.at (0)->setCurrentText (format);
    list_combos.at (1)->setCurrentText (language);
    list_combos.at (2)->setCurrentText (timeformat);
    list_combos.at (3)->setCurrentText (timezone);
    qInfo() <<"Format : " <<format<<Qt::endl;
    qInfo() << "Data loaded ..." <<Qt::endl;
}

void localeConfig::updateSettings(QList<QComboBox *> combox )
{
    for ( QString &key:  settings->allKeys()){
        settings->remove (key);
    }

    settings->beginGroup (QStringLiteral("locale"));
    settings->setValue (QStringLiteral("format"), combox.at (0)->currentText ());
    settings->setValue (QStringLiteral("language"), combox.at (1)->currentText ());
    settings->setValue (QStringLiteral("timeformat"), combox.at (2)->currentText ());
    settings->setValue (QStringLiteral("timezone"), combox.at(3)->currentText ());
    settings->endGroup ();

    qInfo() << "updated successfully......"<<Qt::endl;
}

void localeConfig::resetSettings()
{
    settings->clear ();
}

bool localeConfig::isCreated()
{
    if (QFile(settings->fileName ()).exists()){
        qDebug() << "File exists";
        return true;

    }else
        qDebug() << "File does not exist";
    return false;
}
