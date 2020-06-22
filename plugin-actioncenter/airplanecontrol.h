#ifndef AIRPLANECONTROL_H
#define AIRPLANECONTROL_H

#include <QObject>
#include <QWidget>

class airplaneControl : public QObject
{
    Q_OBJECT
public:
    explicit airplaneControl(QObject *parent = nullptr);

signals:

};

#endif // AIRPLANECONTROL_H
