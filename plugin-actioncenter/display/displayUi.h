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

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(330, 1015);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(250, 0));
        Form->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backbtn = new QToolButton(Form);
        backbtn->setObjectName(QString::fromUtf8("backbtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
        backbtn->setSizePolicy(sizePolicy1);
        backbtn->setMinimumSize(QSize(0, 0));
        backbtn->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("draw-arrow-back");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        backbtn->setIcon(icon);
        backbtn->setAutoRaise(true);

        horizontalLayout->addWidget(backbtn);

        displayLabel = new QLabel(Form);
        displayLabel->setObjectName(QString::fromUtf8("displayLabel"));
        sizePolicy.setHeightForWidth(displayLabel->sizePolicy().hasHeightForWidth());
        displayLabel->setSizePolicy(sizePolicy);
        displayLabel->setMinimumSize(QSize(0, 0));
        displayLabel->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        displayLabel->setFont(font);
        displayLabel->setStyleSheet(QString::fromUtf8(""));
        displayLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(displayLabel);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        externalbtn = new QToolButton(Form);
        externalbtn->setObjectName(QString::fromUtf8("externalbtn"));
        sizePolicy.setHeightForWidth(externalbtn->sizePolicy().hasHeightForWidth());
        externalbtn->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        externalbtn->setFont(font1);
        externalbtn->setLayoutDirection(Qt::LeftToRight);
        externalbtn->setAutoFillBackground(false);
        externalbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("osd-shutd-laptop");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        externalbtn->setIcon(icon1);
        externalbtn->setIconSize(QSize(64, 64));
        externalbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        externalbtn->setAutoRaise(false);

        verticalLayout->addWidget(externalbtn);

        laptopbtn = new QToolButton(Form);
        laptopbtn->setObjectName(QString::fromUtf8("laptopbtn"));
        sizePolicy.setHeightForWidth(laptopbtn->sizePolicy().hasHeightForWidth());
        laptopbtn->setSizePolicy(sizePolicy);
        laptopbtn->setFont(font1);
        laptopbtn->setLayoutDirection(Qt::LeftToRight);
        laptopbtn->setAutoFillBackground(false);
        laptopbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("osd-shutd-screen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        laptopbtn->setIcon(icon2);
        laptopbtn->setIconSize(QSize(64, 64));
        laptopbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        laptopbtn->setAutoRaise(false);

        verticalLayout->addWidget(laptopbtn);

        unifybtn = new QToolButton(Form);
        unifybtn->setObjectName(QString::fromUtf8("unifybtn"));
        sizePolicy.setHeightForWidth(unifybtn->sizePolicy().hasHeightForWidth());
        unifybtn->setSizePolicy(sizePolicy);
        unifybtn->setFont(font1);
        unifybtn->setLayoutDirection(Qt::LeftToRight);
        unifybtn->setAutoFillBackground(false);
        unifybtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("osd-duplicate");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        unifybtn->setIcon(icon3);
        unifybtn->setIconSize(QSize(64, 64));
        unifybtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        unifybtn->setAutoRaise(false);

        verticalLayout->addWidget(unifybtn);

        extendleftbtn = new QToolButton(Form);
        extendleftbtn->setObjectName(QString::fromUtf8("extendleftbtn"));
        sizePolicy.setHeightForWidth(extendleftbtn->sizePolicy().hasHeightForWidth());
        extendleftbtn->setSizePolicy(sizePolicy);
        extendleftbtn->setFont(font1);
        extendleftbtn->setLayoutDirection(Qt::LeftToRight);
        extendleftbtn->setAutoFillBackground(false);
        extendleftbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("osd-sbs-left");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        extendleftbtn->setIcon(icon4);
        extendleftbtn->setIconSize(QSize(64, 64));
        extendleftbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        extendleftbtn->setAutoRaise(false);

        verticalLayout->addWidget(extendleftbtn);

        extendrigthbtn = new QToolButton(Form);
        extendrigthbtn->setObjectName(QString::fromUtf8("extendrigthbtn"));
        sizePolicy.setHeightForWidth(extendrigthbtn->sizePolicy().hasHeightForWidth());
        extendrigthbtn->setSizePolicy(sizePolicy);
        extendrigthbtn->setFont(font1);
        extendrigthbtn->setLayoutDirection(Qt::LeftToRight);
        extendrigthbtn->setAutoFillBackground(false);
        extendrigthbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("osd-sbs-sright");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        extendrigthbtn->setIcon(icon5);
        extendrigthbtn->setIconSize(QSize(64, 64));
        extendrigthbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        extendrigthbtn->setAutoRaise(false);

        verticalLayout->addWidget(extendrigthbtn);

        advancedBtn = new QPushButton(Form);
        advancedBtn->setObjectName(QString::fromUtf8("advancedBtn"));
        sizePolicy1.setHeightForWidth(advancedBtn->sizePolicy().hasHeightForWidth());
        advancedBtn->setSizePolicy(sizePolicy1);
        advancedBtn->setMinimumSize(QSize(115, 0));
        advancedBtn->setLayoutDirection(Qt::RightToLeft);
        advancedBtn->setStyleSheet(QString::fromUtf8(" backgroun-color:#5b65736e\n"
""));

        verticalLayout->addWidget(advancedBtn);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 434, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        backbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
        displayLabel->setText(QCoreApplication::translate("Form", "Display", nullptr));
        externalbtn->setText(QCoreApplication::translate("Form", " External screen", nullptr));
        laptopbtn->setText(QCoreApplication::translate("Form", " Laptop screen", nullptr));
        unifybtn->setText(QCoreApplication::translate("Form", " Unify  output", nullptr));
        extendleftbtn->setText(QCoreApplication::translate("Form", " Extend to left", nullptr));
        extendrigthbtn->setText(QCoreApplication::translate("Form", " Extend to right", nullptr));
        advancedBtn->setText(QCoreApplication::translate("Form", "Advanced Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DISPLAYFSRXSR_H
