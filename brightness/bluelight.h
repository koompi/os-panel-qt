#ifndef BLUELIGHT_H
#define BLUELIGHT_H

#include <QObject>
#include <QWidget>
#include <QProcess>

class bluelight : public QWidget
{
    Q_OBJECT
public:
    explicit bluelight(QWidget *parent = nullptr);

signals:
public slots:
   float getCurrentValue(float value);

private:
    QProcess process;
    float currentValue;

};

#endif // BLUELIGHT_H
