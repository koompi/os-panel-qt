/********************************************************************************
** Form generated from reading UI file 'controllCenterVPlwib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/
#include "kmpcontrolcenteritem.h"
//#include "controlcenter.h"
#include <QDebug>
#include <QGuiApplication>
#include <QProcess>
#include <QScreen>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <LXQt/Settings>
KMPControlCenterItem::KMPControlCenterItem(QWidget *parent) : QWidget(parent) {
    setupUi(parent);
    retranslateUi(parent);
}

void KMPControlCenterItem::setupUi(QWidget *Form) {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    QScreen * screenSize = QGuiApplication::primaryScreen();
    Form->resize(screenSize->geometry().width() * 0.25, screenSize->geometry().height());
    verticalLayout = new QVBoxLayout(Form);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    stackedWidget = new QStackedWidget(Form);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    homePage = new ActionCenterHome(this);
    homePage->setStackWidget (stackedWidget);
    homePage->setObjectName(QString::fromUtf8("homePage"));
    LXQt::Settings settings(QStringLiteral("lxqt-config-locale"));
    localePage =new localecontrol(&settings,this);
    localePage->setStack (stackedWidget);
    localePage->setObjectName (QString::fromUtf8 ("localePage"));
    //    pushButton = new QPushButton(page);
    //    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(localePage);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    verticalLayout_3 = new QVBoxLayout(page_2);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    pushButton_2 = new QPushButton(page_2);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    verticalLayout_3->addWidget(pushButton_2);

    stackedWidget->addWidget(page_2);

    verticalLayout->addWidget(stackedWidget);

    retranslateUi(Form);

    stackedWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(Form);
} // setupUi

void KMPControlCenterItem::retranslateUi(QWidget *Form) {
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    pushButton_2->setText(QCoreApplication::translate("Form", "Page 2", nullptr));
}

QStackedWidget *KMPControlCenterItem::getStackedWidget() const
{
    return stackedWidget;
}

void KMPControlCenterItem::setStackedWidget(QStackedWidget *value)
{
    stackedWidget = value;
}

