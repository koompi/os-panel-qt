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
        qDebug() << screen->name ()<<endl;
        qRegisterMetaType<QProcess::ExitStatus>("QProcess::ExitStatus");
        process.start("xrandr",QStringList() << "--output"<< screen->name ()<< "--gamma"<< QString::number(value/100));
        while(!process.waitForFinished()){
            process.readAll();
        }
        process.close();
//    qDebug() << QString::number (value/100);
}
