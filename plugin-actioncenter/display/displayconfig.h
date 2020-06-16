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

QT_BEGIN_NAMESPACE
namespace Ui { class Form;}
QT_END_NAMESPACE
class displayConfig : public QWidget
{
    Q_OBJECT
public:
    explicit displayConfig(QWidget *parent = nullptr);
    QStackedWidget *getStack() const;
    void setStack(QStackedWidget *value);
    QStringList decorate_output(QString &output);
    QStringList getOn_getDataSplit() const;
    void setOn_getDataSplit(const QStringList &value);
    void checkoutScreen();
    QScreen * getPrimaryScreen();
signals:
    void onReadyGetDisplayName(QStringList displayName);

public slots:
    void getDisplayName();
    void laptop_display(QStringList  displayname);
    void monitor_display(QStringList displayname);
//    void unify_display(QStringList displayname);
//    void extendL_display(QStringList displayname);
//    void extendR_display(QStringList displayname);
    //    void on_smartUnify(QStringList display);


private:
    Ui::Form *ui;
    QStackedWidget * stack;
    QProcess process;
    QStringList on_getDataSplit;
};

#endif // DISPLAYCONFIG_H
