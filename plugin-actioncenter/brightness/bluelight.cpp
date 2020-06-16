#include "bluelight.h"
#include <QScreen>
#include <QDebug>
#include <QGuiApplication>

bluelight::bluelight(QWidget *parent) : QWidget(parent)
{

}
float bluelight::getCurrentValue(float value)
{
    QScreen * screen = QGuiApplication::primaryScreen ();
        qDebug() << screen->name ()<<Qt::endl;
        qRegisterMetaType<QProcess::ExitStatus>("QProcess::ExitStatus");
        process.start(QStringLiteral("xrandr"),QStringList() << QStringLiteral("--output")<< screen->name ()<<QStringLiteral("--gamma")<< QString::number(value/100));
        while(!process.waitForFinished()){
            process.readAll();
        }
        process.close();
//    qDebug() << QString::number (value/100);
}
