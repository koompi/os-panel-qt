#ifndef AIRPLANECONFIG_H
#define AIRPLANECONFIG_H

#include <QObject>
#include <QWidget>
#include <QProcess>
#include <QDebug>
#include "actioncenterui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Quick_Center;}
QT_END_NAMESPACE
class airplaneConfig : public QObject
{
    Q_OBJECT
public:
    explicit airplaneConfig(QObject *parent = nullptr);
    bool airplaneModeon();
    bool airplaneModeoff();

signals:
private:
    Ui::Quick_Center * ui;
    QProcess process;

};

#endif // AIRPLANECONFIG_H
