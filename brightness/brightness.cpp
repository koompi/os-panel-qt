#include "brightness.h"
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>

brightness::brightness(QObject *parent) : QObject(parent)
{

}
float brightness::getCurrentValue(float value)
{
    QScreen * screen = QGuiApplication::primaryScreen ();
        qDebug() << screen->name ()<<Qt::endl;
        qRegisterMetaType<QProcess::ExitStatus>("QProcess::ExitStatus");
        process.start("xrandr",QStringList() << "--output"<< screen->name ()<< "--brightness"<< QString::number(value/100));
        while(!process.waitForFinished()){
            process.readAll();
        }
        process.close();
    qDebug() << QString::number (value/100);

}

float brightness::changeBrightPercent(float value)
{

}
