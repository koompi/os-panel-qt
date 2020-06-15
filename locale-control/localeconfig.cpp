#include "localeconfig.h"

localeconfig::localeconfig(QList<QComboBox * > combox,QObject *parent) : QObject(parent),list_combos{combox}
{
    settings = new QSettings("KOOMPI", "action-locale");

}

void localeconfig::saveSettings()
{
    settings->beginGroup ("locale");
    settings->setValue ("format", list_combos.at (0)->currentText ());
    settings->setValue ("language", list_combos.at (1)->currentText ());
    settings->setValue ("timeformat", list_combos.at (2)->currentText ());
    settings->setValue ("timezone", list_combos.at(3)->currentText ());
    settings->endGroup ();
}

void localeconfig::loadSettings()
{
    QString format = settings->value ("locale/format").toString ();
    QString language = settings->value ("locale/language").toString ();
    QString timeformat = settings->value ("locale/timeformat").toString ();
    QString timezone = settings->value ("locale/timezone").toString ();
    list_combos.at (0)->setCurrentText (format);
    list_combos.at (1)->setCurrentText (language);
    list_combos.at (2)->setCurrentText (timeformat);
    list_combos.at (3)->setCurrentText (timezone);
    qInfo() <<"Format : " <<format<<Qt::endl;
    qInfo() << "Data loaded ..." <<Qt::endl;
}

void localeconfig::updateSettings (QList<QComboBox *> combox)
{
    Q_FOREACH (const QString &key,  settings->allKeys ()){
        settings->remove (key);
    }

    settings->beginGroup ("locale");
    settings->setValue ("format", combox.at (0)->currentText ());
    settings->setValue ("language", combox.at (1)->currentText ());
    settings->setValue ("timeformat", combox.at (2)->currentText ());
    settings->setValue ("timezone", combox.at(3)->currentText ());
    settings->endGroup ();

   qInfo() << "updated successfully......"<<Qt::endl;
}

void localeconfig::resetSettings()
{
    settings->clear ();
}

bool localeconfig::isCreated()
{
    if (QFile(settings->fileName ()).exists()){
        qDebug() << "File exists";
        return true;

    }else
    qDebug() << "File does not exist";
    return false;
}
