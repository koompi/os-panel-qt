#ifndef LOCALECONTROL_H
#define LOCALECONTROL_H

#include <QObject>
#include <QLocale>
#include <QLocale>
#include <QDebug>

class localecontrol : public QObject
{
    Q_OBJECT
public:
    explicit localecontrol(QObject *parent = nullptr);
    void listLanguage();
    void listRegion();

signals:
    void emitRegionLists(QString regions);
    void emitLanguageLists(QString regions);
     void currentIndexChanged(int);
     void getTimeFormat();
public slots:

};

#endif // LOCALECONTROL_H
