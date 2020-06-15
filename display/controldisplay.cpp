#include "controldisplay.h"

controldisplay::controldisplay(QObject *parent) : QObject(parent)
{

}
QStringList  controldisplay::decorate_output(QString &output)
{
    qDebug() << output<<Qt::endl;
    QStringList displayList = output.split ('\n');
    displayList.pop_back ();
    return displayList;

}

void controldisplay::getDisplayName()
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

