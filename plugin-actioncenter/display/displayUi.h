/********************************************************************************
** Form generated from reading UI file 'displayFSrXSR.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DISPLAYFSRXSR_H
#define DISPLAYFSRXSR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QStackedWidget>
#include <QProcess>
#include <QScreen>
#include <QDebug>
#include "display/displayconfig.h"

class displayConfig;
class Ui_Form: public QWidget
{
    Q_OBJECT
public:
    explicit Ui_Form(QWidget *parent = nullptr);
    void setupUi(QWidget *);
    void retranslateUi(QWidget*);
    QScreen * getPrimaryScreen();
    void checkoutScreen();
    QStackedWidget *getDisplayStacked() const;
    void setDisplayStacked(QStackedWidget *value);
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *backbtn;
    QLabel *displayLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QToolButton *externalbtn;
    QToolButton *laptopbtn;
    QToolButton *unifybtn;
    QToolButton *extendleftbtn;
    QToolButton *extendrigthbtn;
    QPushButton *advancedBtn;
    QSpacerItem *verticalSpacer_2;
    displayConfig *laptop;
    displayConfig *external;
    displayConfig *unify;
    displayConfig *extendLeft;
    displayConfig *extendRight;
    QStringList getOn_getDataSplit() const;
    void setOn_getDataSplit(const QStringList &value);
public slots:
    void laptop_display(QStringList  displayname);
    void monitor_display(QStringList displayname);
    void unify_display(QStringList displayname);
    void extendL_display(QStringList displayname);
    void extendR_display(QStringList displayname);
private:
    QStackedWidget * stack;
    QStringList on_getDataSplit;
};
 // namespace Ui

QT_END_NAMESPACE

#endif // DISPLAYFSRXSR_H
