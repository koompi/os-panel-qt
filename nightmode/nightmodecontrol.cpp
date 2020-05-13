#include "nightmodecontrol.h"
#include <QDebug>
nightmodecontrol::nightmodecontrol(QObject *parent) : QObject(parent)
{

}

QStringList nightmodecontrol::decorate_output(QString &output)
{
    qDebug() << output<<endl;
    QStringList displayList = output.split ('\n');
    displayList.pop_back ();
    displayList.removeAt (1);
    return displayList;
}

void nightmodecontrol::getdisplayName()
{
    QProcess *display2 = new QProcess(this);
    connect(display2, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray display_name =  display2->readAllStandardOutput ();
        QString output(display_name);
        emit onReadyGetDisplayName(decorate_output(output));
    });
    display2->start("bash",
                    QStringList()
                    << "-c"
                    << " xrandr |  grep \"connected\" | cut -f1 -d\" \"", QIODevice::ReadOnly
                    );
    display2->setReadChannel(QProcess::ProcessChannel::StandardOutput );
    display2->waitForReadyRead ();
    display2->waitForFinished();
    display2->close ();
}

bool nightmodecontrol::setmodeon(QStringList displayname)
{
    qDebug()<<"mode on";
//    qDebug() <<"first:"<< displayname.first () << endl;
//    qDebug() <<"last: "<< displayname.last ()<<endl;
    //    QProcess *process = new QProcess (this);
    //    process->start ("xrandr",QStringList() <<"--output"<<)

}

bool nightmodecontrol::setmodeoff(QStringList displayname)
{
    qDebug()<<"mode off";
}



