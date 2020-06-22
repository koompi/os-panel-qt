#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include <QObject>

class displaycontrol : public QObject
{
    Q_OBJECT
public:
    explicit displaycontrol(QObject *parent = nullptr);

signals:

};

#endif // DISPLAYCONTROL_H
