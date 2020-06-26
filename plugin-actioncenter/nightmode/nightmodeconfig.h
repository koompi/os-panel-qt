#ifndef NIGHTMODECONFIG_H
#define NIGHTMODECONFIG_H

#include <QObject>
#include <QWidget>
#include <QProcess>
#include <QDebug>
#include "actioncenterui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Quick_Center;}
QT_END_NAMESPACE
class nightmodeconfig : public QObject
{
    Q_OBJECT
public:
    explicit nightmodeconfig(QObject *parent = nullptr);
    bool nightmodeon();
    bool nightmodeoff();
signals:
private:
    Ui::Quick_Center * ui;
    QProcess process;

};

#endif // NIGHTMODECONFIG_H
