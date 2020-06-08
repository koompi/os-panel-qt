#ifndef NIGHTMODECONTROL_H
#define NIGHTMODECONTROL_H

#include <QObject>
#include <QProcess>
#include <QStateMachine>

class nightmodecontrol : public QObject
{
    Q_OBJECT
public:
    explicit nightmodecontrol(QObject *parent = nullptr);
    QStringList decorate_output(QString &output);

public slots:
    bool startNightmode();
    bool stopNightmode();
    
private:
    QProcess process;
};

#endif // NIGHTMODECONTROL_H
