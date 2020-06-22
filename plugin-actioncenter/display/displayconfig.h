#ifndef DISPLAYCONFIG_H
#define DISPLAYCONFIG_H

#include <QObject>
#include <QWidget>
#include "displayUi.h"
#include <QStackedWidget>
#include <QProcess>
#include <QDebug>
#include <QGuiApplication>
#include <QStringLiteral>
#include <QScreen>

class displayConfig : public QObject
{
    Q_OBJECT
public:
    explicit displayConfig(QObject *parent = nullptr);
    QStringList decorate_output(QString &output);

signals:
    void onReadyGetDisplayName(QStringList displayName);
public slots:
    void getDisplayName();
private:
    QProcess process;

};

#endif // DISPLAYCONFIG_H
