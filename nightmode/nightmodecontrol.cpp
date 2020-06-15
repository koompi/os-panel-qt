#include "nightmodecontrol.h"
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
nightmodecontrol::nightmodecontrol(QObject *parent) : QObject(parent)
{
    
}

bool nightmodecontrol::startNightmode()
{

    process.startDetached ("redshift-gtk");
    process.waitForStarted();
    process.waitForFinished(-1);
    process.close();
       qDebug()<< "red shift run";
       return true;

}

bool nightmodecontrol::stopNightmode()
{
    process.startDetached ("sudo", QStringList() << "killall" << "redshift");
    process.waitForStarted();
    process.waitForFinished(-1);
    process.close();
       qDebug()<< "red shift off";
       return true;
}









