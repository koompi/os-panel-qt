#include "airplanecontrol.h"

airplaneControl::airplaneControl(QObject *parent) : QObject(parent)
{

}

bool airplaneControl::airplaneModeOn()
{
    process.start("rfkill" , QStringList()<< "block"<< "all");
    while(!process.waitForFinished()){
        process.readAll();
    }
    qDebug()<< "airplanemode on";
    process.close();
    return true;
}

bool airplaneControl::airplaneModeOff()
{

   process.start ("rfkill", QStringList()<< "unblock" << "all");
   while(!process.waitForFinished()){
       process.readAll();
   }
   qDebug()<<"airplanemode off";
   process.close();
   return true;
}
