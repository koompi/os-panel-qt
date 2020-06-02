#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <QObject>
#include <QWidget>
#include <QProcess>

class brightness : public QObject
{
    Q_OBJECT
public:
    explicit brightness(QObject *parent = nullptr);

signals:
public slots:
   float getCurrentValue(float value);
   float changeBrightPercent(float value);

private:
    QProcess process;
    float currentValue;


};

#endif // BRIGHTNESS_H
