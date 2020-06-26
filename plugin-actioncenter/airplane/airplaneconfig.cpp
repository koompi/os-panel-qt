#include "airplaneconfig.h"

airplaneConfig::airplaneConfig(QObject *parent) : QObject(parent), ui(new Ui::Quick_Center)
{

}

bool airplaneConfig::airplaneModeon()
{
    process.start(QStringLiteral("rfkill") , QStringList()<<QStringLiteral("block")<< QStringLiteral("all"));
        while(!process.waitForFinished()){
            process.readAll();
        }
        qDebug()<< "airplanemode on" <<Qt::endl;
        process.close();
        return true;
}

bool airplaneConfig::airplaneModeoff()
{
    process.start(QStringLiteral("rfkill") , QStringList()<<QStringLiteral("unblock")<< QStringLiteral("all"));
        while(!process.waitForFinished()){
            process.readAll();
        }
        qDebug()<< "airplanemode off" <<Qt::endl;
        process.close();
        return true;
}
