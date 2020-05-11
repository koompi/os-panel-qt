#ifndef AIRPLANECONTROL_H
#define AIRPLANECONTROL_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class airplaneControl : public QObject
{
    Q_OBJECT
public :
    explicit airplaneControl(QObject *parent = nullptr);
    bool airplaneModeOn();
    bool airplaneModeOff();
signals:
private:
    QProcess process;
};

#endif // AIRPLANECONTROL_H
