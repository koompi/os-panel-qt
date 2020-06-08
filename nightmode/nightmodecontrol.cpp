#include "nightmodecontrol.h"
#include <QDebug>
nightmodecontrol::nightmodecontrol(QObject *parent) : QObject(parent)
{
    
}

bool nightmodecontrol::startNightmode()
{
    process.start("nightmode" );
        while(!process.waitForFinished()){
            process.readAll();
        }
        qDebug()<< "nightmode on";
        process.close();
        return true;
}

bool nightmodecontrol::stopNightmode()
{
    process.start("nightmode" , QStringList()<< "off");
        while(!process.waitForFinished()){
            process.readAll();
        }
        qDebug()<< "nightmode off";
        process.close();
        return true;
}









