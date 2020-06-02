#ifndef CONTROLDISPLAY_H
#define CONTROLDISPLAY_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QWidget>

class controldisplay : public QObject
{
    Q_OBJECT
public:
    explicit controldisplay(QObject *parent = nullptr);
    QStringList decorate_output(QString &output);
signals:
    void onReadyGetDisplayName(QStringList displayName);

public slots:
    void getDisplayName();

private:
    QProcess process;


};

#endif // CONTROLDISPLAY_H
