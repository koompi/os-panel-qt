#ifndef DISPLAYCONFIG_H
#define DISPLAYCONFIG_H

#include <QObject>
#include <QWidget>

class displayConfig : public QObject
{
    Q_OBJECT
public:
    explicit displayConfig(QObject *parent = nullptr);

signals:

};

#endif // DISPLAYCONFIG_H
