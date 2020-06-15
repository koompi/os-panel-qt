#include "actiondatetime.h"
#include <QTime>
#include <QTimer>
#include <QDate>
#include <QDebug>
int ActionDateTime::getDuration() const
{
    return duration;
}

void ActionDateTime::setDuration(int value)
{
        qInfo() << "set duration value after 2000 millis"<<Qt::endl;
        duration = value;
}

ActionDateTime::ActionDateTime(QObject *parent, int timeset) :
    QObject(parent), duration(timeset)
{
    QTimer * timer = new QTimer(parent);
    connect(timer, &QTimer::timeout, this, &ActionDateTime::showTime);
    connect(timer, &QTimer::timeout, this, &ActionDateTime::showDate);
    timer->start(duration);
}

QLabel *ActionDateTime::createDate()
{
    QLabel * date = new QLabel(timeParent);
    connect(this, &ActionDateTime::dateChanged, date, &QLabel::setText);

    date->setObjectName(timeObjName);
    QFont font1;
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setItalic(false);
    font1.setWeight(75);
    date->setFont(font1);
    date->setStyleSheet(QString::fromUtf8("color:white"));
    date->setAlignment(Qt::AlignCenter);
    return date;
}

QLabel *ActionDateTime::createTime()
{
    QLabel * time = new QLabel(timeParent);
    connect(this, &ActionDateTime::timeChanged, time, &QLabel::setText);
    time->setObjectName(timeObjName);
    QFont font1;
    font1.setPointSize(14);
    font1.setBold(true);
    font1.setItalic(false);
    font1.setWeight(75);
    time->setFont(font1);
    time->setStyleSheet(QString::fromUtf8("color:white"));
    time->setAlignment(Qt::AlignCenter);
    return time;
}

void ActionDateTime::showTime()
{
    QTime currentTime;
    qInfo() << "this is function run after 30 mins"<<Qt::endl;
    QString time = currentTime.currentTime().toString(QString::fromUtf8("hh:mm AP"));
    emit timeChanged(time);
}

void ActionDateTime::showDate()
{
    QDate currentDate;
    qInfo() << "this is function run after 30 mins"<<Qt::endl;
    QString date = currentDate.currentDate().toString(Qt::DateFormat::TextDate);
    emit dateChanged(date);
}

void ActionDateTime::chnageDateFormat(const QString &formatString)
{

}
