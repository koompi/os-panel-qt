#include "nightmodeconfig.h"

nightmodeconfig::nightmodeconfig(QObject *parent) : QObject(parent), ui(new Ui::Quick_Center)
{

}

bool nightmodeconfig::nightmodeon()
{
    process.startDetached (QStringLiteral("redshift-gtk"));
    process.waitForStarted();
    process.waitForFinished(-1);
    process.close();
    qDebug()<< "red shift run" <<Qt::endl;
    return true;
}

bool nightmodeconfig::nightmodeoff()
{
    process.startDetached (QStringLiteral("killall"), QStringList() <<QStringLiteral("redshift"));
    process.waitForStarted();
    process.waitForFinished(-1);
    process.close();
    qDebug()<< "red shift off" << Qt::endl;
    return true;
}

