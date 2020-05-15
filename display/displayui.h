#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <QObject>
#include <QWidget>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QStackedWidget>
#include "controldisplay.h"

class displayui : public QWidget
{
    Q_OBJECT
public:
    explicit displayui(QWidget *parent = nullptr);
    void setupUi(QWidget *);
    void retranslateUi(QWidget*);
    QScreen * getPrimaryScreen();
    void checkoutScreen();
    QStackedWidget *getDisplayStacked() const;
    void setDisplayStacked(QStackedWidget *value);
    int m_width, m_height;
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
    QToolButton *advancedbtn;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *displayStack;
    controldisplay *laptop;
    controldisplay *external;
    controldisplay *unify;
    controldisplay *extendLeft;
    controldisplay *extendRight;
    //    controldisplay *smartUnify;
    QStringList getOn_getDataSplit() const;
    void setOn_getDataSplit(const QStringList &value);

public slots:
    void laptop_display(QStringList  displayname);
    void monitor_display(QStringList displayname);
    void unify_display(QStringList displayname);
    void extendL_display(QStringList displayname);
    void extendR_display(QStringList displayname);
    //    void on_smartUnify(QStringList display);
private:
    QStringList on_getDataSplit;


signals:

};

#endif // DISPLAYUI_H
