/********************************************************************************
** Form generated from reading UI file 'ui_bluetoothwzrGJP.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHWZRGJP_H
#define UI_BLUETOOTHWZRGJP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *blueCheck;
    QToolButton *blueRefresh;
    QToolButton *blueSetting;
    QListWidget *blueListView;
    QToolButton *backBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(332, 888);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        blueCheck = new QCheckBox(frame);
        blueCheck->setObjectName(QString::fromUtf8("blueCheck"));
        QFont font1;
        font1.setPointSize(10);
        blueCheck->setFont(font1);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("preferences-system-bluetooth");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        blueCheck->setIcon(icon);
        blueCheck->setIconSize(QSize(16, 16));
        blueCheck->setChecked(true);

        horizontalLayout->addWidget(blueCheck);

        blueRefresh = new QToolButton(frame);
        blueRefresh->setObjectName(QString::fromUtf8("blueRefresh"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("view-refresh")));
        blueRefresh->setIcon(icon1);

        horizontalLayout->addWidget(blueRefresh);

        blueSetting = new QToolButton(frame);
        blueSetting->setObjectName(QString::fromUtf8("blueSetting"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("settings-configure");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        blueSetting->setIcon(icon2);
        blueSetting->setAutoRaise(false);

        horizontalLayout->addWidget(blueSetting);


        verticalLayout->addWidget(frame);

        blueListView = new QListWidget(Form);
        blueListView->setObjectName(QString::fromUtf8("blueListView"));
        blueListView->setFrameShape(QFrame::StyledPanel);
        blueListView->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(blueListView);

        backBtn = new QToolButton(Form);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("arrow-left");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        backBtn->setIcon(icon3);
        backBtn->setIconSize(QSize(50, 16));
        backBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        backBtn->setAutoRaise(false);

        verticalLayout->addWidget(backBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Bluetooth", nullptr));
#if QT_CONFIG(tooltip)
        blueCheck->setToolTip(QCoreApplication::translate("Form", "This control is used to turn on/off bluetooth adapter.", nullptr));
#endif // QT_CONFIG(tooltip)
        blueCheck->setText(QString());
#if QT_CONFIG(tooltip)
        blueRefresh->setToolTip(QCoreApplication::translate("Form", "This control is used to refresh bluetooth in th list.", nullptr));
#endif // QT_CONFIG(tooltip)
        blueRefresh->setText(QString());
#if QT_CONFIG(tooltip)
        blueSetting->setToolTip(QCoreApplication::translate("Form", "This contorl is used to show the bluetooth setting.", nullptr));
#endif // QT_CONFIG(tooltip)
        blueSetting->setText(QCoreApplication::translate("Form", "...", nullptr));
        backBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHWZRGJP_H
