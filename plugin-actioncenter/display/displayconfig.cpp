#include "displayconfig.h"
#include <QString>



displayConfig::displayConfig(QObject *parent) : QObject (parent)
{

}

QStringList displayConfig::decorate_output(QString &output)
{
    qDebug() << output<<Qt::endl;
    QStringList displayList = output.split (QStringLiteral ("\n"));
    displayList.pop_back ();
    return displayList;

}

void displayConfig::getDisplayName()
{
    QProcess *display2 = new QProcess(this);
    connect(display2, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray display_name =  display2->readAllStandardOutput ();
        QString output(QString::fromLatin1 (display_name));
        emit onReadyGetDisplayName(decorate_output(output));
    });
    display2->start(QStringLiteral("bash"),
                    QStringList()
                    << QStringLiteral("-c")
                    << QStringLiteral(" xrandr |  grep \"connected\" | cut -f1 -d\" \""), QIODevice::ReadOnly
                    );
    display2->setReadChannel(QProcess::ProcessChannel::StandardOutput );
    display2->waitForReadyRead ();
    display2->waitForFinished();
    display2->close ();
}



