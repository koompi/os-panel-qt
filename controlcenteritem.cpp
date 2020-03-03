/********************************************************************************
** Form generated from reading UI file 'controllCenterVPlwib.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/


#include "controlcenteritem.h"

#include <QProcess>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
controlcenteritem::controlcenteritem(QWidget * parent):QWidget (parent){
    setupUi (this);

    connect (allsetting, &QToolButton::clicked, [](){
        QProcess process;
        process.startDetached ("systemsettings5");
        process.waitForStarted ();
        process.waitForFinished (-1);
        process.close ();
        qDebug() << process.exitCode ()<<endl;
    });
    connect (bluetooth,&QToolButton::clicked, [&](){
       stackedWidget->setCurrentIndex (2);
    });
}
void controlcenteritem::setupUi(QWidget *Form)
{
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    QScreen *screen = QGuiApplication::primaryScreen();
    m_width = screen->geometry().width();
    m_height = screen->geometry().height();
//    resize(m_width * 0.25, m_height);
    Form->resize(m_width * 0.25, m_height * 0.95);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
    Form->setSizePolicy(sizePolicy);
    Form->setMouseTracking(false);
    Form->setToolTipDuration(-3);
    Form->setAutoFillBackground(false);
    verticalLayout_4 = new QVBoxLayout(Form);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    stackedWidget = new QStackedWidget(Form);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    quicksetting = new QWidget();
    quicksetting->setObjectName(QString::fromUtf8("quicksetting"));
    layoutWidget = new QWidget(quicksetting);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(8, 0, 451, 811));
    quickNotifyLayout = new QVBoxLayout(layoutWidget);
    quickNotifyLayout->setObjectName(QString::fromUtf8("quickNotifyLayout"));
    quickNotifyLayout->setContentsMargins(0, 0, 0, 0);
    quickSettingLayout = new QVBoxLayout();
    quickSettingLayout->setObjectName(QString::fromUtf8("quickSettingLayout"));
    quicksettinglabel = new QLabel(layoutWidget);
    quicksettinglabel->setObjectName(QString::fromUtf8("quicksettinglabel"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(quicksettinglabel->sizePolicy().hasHeightForWidth());
    quicksettinglabel->setSizePolicy(sizePolicy1);
    QFont font;
    font.setPointSize(15);
    quicksettinglabel->setFont(font);
    quicksettinglabel->setScaledContents(false);
    quicksettinglabel->setAlignment(Qt::AlignCenter);
    quicksettinglabel->setWordWrap(false);

    quickSettingLayout->addWidget(quicksettinglabel);

    quickchildLayout = new QVBoxLayout();
    quickchildLayout->setObjectName(QString::fromUtf8("quickchildLayout"));
    quickgridLayout = new QGridLayout();
    quickgridLayout->setObjectName(QString::fromUtf8("quickgridLayout"));
    quickgridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    wifi = new QToolButton(layoutWidget);
    wifi->setObjectName(QString::fromUtf8("wifi"));
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(wifi->sizePolicy().hasHeightForWidth());
    wifi->setSizePolicy(sizePolicy2);
    wifi->setMinimumSize(QSize(100, 100));
    wifi->setMaximumSize(QSize(120, 120));
    QFont font1;
    font1.setPointSize(8);
    wifi->setFont(font1);
    wifi->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon;
    QString iconThemeName = QString::fromUtf8("network-wireless-connected-100");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    wifi->setIcon(icon);
    wifi->setIconSize(QSize(50, 50));
    wifi->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    wifi->setAutoRaise(true);

    quickgridLayout->addWidget(wifi, 0, 4, 1, 1);

    nightmode = new QToolButton(layoutWidget);
    nightmode->setObjectName(QString::fromUtf8("nightmode"));
    sizePolicy2.setHeightForWidth(nightmode->sizePolicy().hasHeightForWidth());
    nightmode->setSizePolicy(sizePolicy2);
    nightmode->setMinimumSize(QSize(100, 100));
    nightmode->setMaximumSize(QSize(120, 120));
    nightmode->setFont(font1);
    nightmode->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon1;
    iconThemeName = QString::fromUtf8("night-light-symbolic");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon1 = QIcon::fromTheme(iconThemeName);
    } else {
        icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    nightmode->setIcon(icon1);
    nightmode->setIconSize(QSize(50, 50));
    nightmode->setAutoExclusive(false);
    nightmode->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    nightmode->setAutoRaise(true);

    quickgridLayout->addWidget(nightmode, 1, 2, 1, 1);

    bluetooth = new QToolButton(layoutWidget);
    bluetooth->setObjectName(QString::fromUtf8("bluetooth"));
    sizePolicy2.setHeightForWidth(bluetooth->sizePolicy().hasHeightForWidth());
    bluetooth->setSizePolicy(sizePolicy2);
    bluetooth->setMinimumSize(QSize(100, 100));
    bluetooth->setMaximumSize(QSize(120, 120));
    bluetooth->setFont(font1);
    bluetooth->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon2;
    iconThemeName = QString::fromUtf8("preferences-system-bluetooth");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon2 = QIcon::fromTheme(iconThemeName);
    } else {
        icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    bluetooth->setIcon(icon2);
    bluetooth->setIconSize(QSize(50, 50));
    bluetooth->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    bluetooth->setAutoRaise(true);

    quickgridLayout->addWidget(bluetooth, 1, 1, 1, 1);

    focuse = new QToolButton(layoutWidget);
    focuse->setObjectName(QString::fromUtf8("focuse"));
    sizePolicy2.setHeightForWidth(focuse->sizePolicy().hasHeightForWidth());
    focuse->setSizePolicy(sizePolicy2);
    focuse->setMinimumSize(QSize(100, 100));
    focuse->setMaximumSize(QSize(120, 120));
    focuse->setFont(font1);
    focuse->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon3;
    iconThemeName = QString::fromUtf8("im-facebook");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon3 = QIcon::fromTheme(iconThemeName);
    } else {
        icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    focuse->setIcon(icon3);
    focuse->setIconSize(QSize(50, 50));
    focuse->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    focuse->setAutoRaise(true);

    quickgridLayout->addWidget(focuse, 1, 4, 1, 1);

    display = new QToolButton(layoutWidget);
    display->setObjectName(QString::fromUtf8("display"));
    sizePolicy2.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
    display->setSizePolicy(sizePolicy2);
    display->setMinimumSize(QSize(100, 100));
    display->setMaximumSize(QSize(120, 120));
    display->setFont(font1);
    display->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon4;
    iconThemeName = QString::fromUtf8("preferences-desktop-display");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon4 = QIcon::fromTheme(iconThemeName);
    } else {
        icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    display->setIcon(icon4);
    display->setIconSize(QSize(50, 50));
    display->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    display->setAutoRaise(true);
    display->setArrowType(Qt::NoArrow);

    quickgridLayout->addWidget(display, 1, 0, 1, 1);

    allsetting = new QToolButton(layoutWidget);
    allsetting->setObjectName(QString::fromUtf8("allsetting"));
    sizePolicy2.setHeightForWidth(allsetting->sizePolicy().hasHeightForWidth());
    allsetting->setSizePolicy(sizePolicy2);
    allsetting->setMinimumSize(QSize(100, 100));
    allsetting->setMaximumSize(QSize(120, 120));
    allsetting->setFont(font1);
    allsetting->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon5;
    iconThemeName = QString::fromUtf8("preferences-setting");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon5 = QIcon::fromTheme(iconThemeName);
    } else {
        icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    allsetting->setIcon(icon5);
    allsetting->setIconSize(QSize(50, 50));
    allsetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    allsetting->setAutoRaise(true);

    quickgridLayout->addWidget(allsetting, 0, 0, 1, 1);

    locale = new QToolButton(layoutWidget);
    locale->setObjectName(QString::fromUtf8("locale"));
    sizePolicy2.setHeightForWidth(locale->sizePolicy().hasHeightForWidth());
    locale->setSizePolicy(sizePolicy2);
    locale->setMinimumSize(QSize(100, 100));
    locale->setMaximumSize(QSize(120, 120));
    locale->setFont(font1);
    locale->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon6;
    iconThemeName = QString::fromUtf8("preferences-desktop-locale");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon6 = QIcon::fromTheme(iconThemeName);
    } else {
        icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    locale->setIcon(icon6);
    locale->setIconSize(QSize(50, 50));
    locale->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    locale->setAutoRaise(true);

    quickgridLayout->addWidget(locale, 0, 2, 1, 1);

    airplanemode = new QToolButton(layoutWidget);
    airplanemode->setObjectName(QString::fromUtf8("airplanemode"));
    sizePolicy2.setHeightForWidth(airplanemode->sizePolicy().hasHeightForWidth());
    airplanemode->setSizePolicy(sizePolicy2);
    airplanemode->setMinimumSize(QSize(100, 100));
    airplanemode->setMaximumSize(QSize(120, 120));
    airplanemode->setFont(font1);
    airplanemode->setStyleSheet(QString::fromUtf8("QToolButton {background: #ebeef5}"));
    QIcon icon7;
    iconThemeName = QString::fromUtf8("airplane-mode");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon7 = QIcon::fromTheme(iconThemeName);
    } else {
        icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    airplanemode->setIcon(icon7);
    airplanemode->setIconSize(QSize(50, 50));
    airplanemode->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    airplanemode->setAutoRaise(true);

    quickgridLayout->addWidget(airplanemode, 0, 1, 1, 1);


    quickchildLayout->addLayout(quickgridLayout);

    verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

    quickchildLayout->addItem(verticalSpacer);

    brightnessLayout = new QHBoxLayout();
    brightnessLayout->setObjectName(QString::fromUtf8("brightnessLayout"));
    brightnessbtn = new QToolButton(layoutWidget);
    brightnessbtn->setObjectName(QString::fromUtf8("brightnessbtn"));
    QIcon icon8;
    iconThemeName = QString::fromUtf8("brightnesssettings");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon8 = QIcon::fromTheme(iconThemeName);
    } else {
        icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    brightnessbtn->setIcon(icon8);
    brightnessbtn->setIconSize(QSize(20, 20));
    brightnessbtn->setAutoRaise(true);

    brightnessLayout->addWidget(brightnessbtn);

    BrightnessSlider = new QSlider(layoutWidget);
    BrightnessSlider->setObjectName(QString::fromUtf8("BrightnessSlider"));
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(4);
    sizePolicy3.setHeightForWidth(BrightnessSlider->sizePolicy().hasHeightForWidth());
    BrightnessSlider->setSizePolicy(sizePolicy3);
    BrightnessSlider->setMaximumSize(QSize(420, 16777215));
    BrightnessSlider->setOrientation(Qt::Horizontal);

    brightnessLayout->addWidget(BrightnessSlider);


    quickchildLayout->addLayout(brightnessLayout);

    nightModeLayout = new QHBoxLayout();
    nightModeLayout->setObjectName(QString::fromUtf8("nightModeLayout"));
    bluelightbtn = new QToolButton(layoutWidget);
    bluelightbtn->setObjectName(QString::fromUtf8("bluelightbtn"));
    QIcon icon9;
    iconThemeName = QString::fromUtf8("redshift-status-on");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon9 = QIcon::fromTheme(iconThemeName);
    } else {
        icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    bluelightbtn->setIcon(icon9);
    bluelightbtn->setIconSize(QSize(20, 20));
    bluelightbtn->setAutoRaise(true);

    nightModeLayout->addWidget(bluelightbtn);

    bluelightslider = new QSlider(layoutWidget);
    bluelightslider->setObjectName(QString::fromUtf8("bluelightslider"));
    sizePolicy3.setHeightForWidth(bluelightslider->sizePolicy().hasHeightForWidth());
    bluelightslider->setSizePolicy(sizePolicy3);
    bluelightslider->setMaximumSize(QSize(420, 16777215));
    bluelightslider->setOrientation(Qt::Horizontal);

    nightModeLayout->addWidget(bluelightslider);


    quickchildLayout->addLayout(nightModeLayout);

    soundLayout = new QHBoxLayout();
    soundLayout->setObjectName(QString::fromUtf8("soundLayout"));
    volumebtn = new QToolButton(layoutWidget);
    volumebtn->setObjectName(QString::fromUtf8("volumebtn"));
    QIcon icon10;
    iconThemeName = QString::fromUtf8("audio-volume-high");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon10 = QIcon::fromTheme(iconThemeName);
    } else {
        icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    volumebtn->setIcon(icon10);
    volumebtn->setIconSize(QSize(20, 20));
    volumebtn->setAutoRaise(true);

    soundLayout->addWidget(volumebtn);

    volumeslider = new QSlider(layoutWidget);
    volumeslider->setObjectName(QString::fromUtf8("volumeslider"));
    sizePolicy3.setHeightForWidth(volumeslider->sizePolicy().hasHeightForWidth());
    volumeslider->setSizePolicy(sizePolicy3);
    volumeslider->setMaximumSize(QSize(420, 16777215));
    volumeslider->setOrientation(Qt::Horizontal);

    soundLayout->addWidget(volumeslider);


    quickchildLayout->addLayout(soundLayout);


    quickSettingLayout->addLayout(quickchildLayout);


    quickNotifyLayout->addLayout(quickSettingLayout);

    notifyLayout = new QVBoxLayout();
    notifyLayout->setObjectName(QString::fromUtf8("notifyLayout"));
    notifyClearLayout = new QHBoxLayout();
    notifyClearLayout->setObjectName(QString::fromUtf8("notifyClearLayout"));
    notificationlabel = new QLabel(layoutWidget);
    notificationlabel->setObjectName(QString::fromUtf8("notificationlabel"));
    QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(notificationlabel->sizePolicy().hasHeightForWidth());
    notificationlabel->setSizePolicy(sizePolicy4);
    notificationlabel->setMaximumSize(QSize(16777211, 16777215));
    notificationlabel->setLayoutDirection(Qt::LeftToRight);

    notifyClearLayout->addWidget(notificationlabel);

    clearNotifyBtn = new QPushButton(layoutWidget);
    clearNotifyBtn->setObjectName(QString::fromUtf8("clearNotifyBtn"));
    QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(clearNotifyBtn->sizePolicy().hasHeightForWidth());
    clearNotifyBtn->setSizePolicy(sizePolicy5);
    clearNotifyBtn->setMaximumSize(QSize(80, 50));
    clearNotifyBtn->setFlat(true);

    notifyClearLayout->addWidget(clearNotifyBtn);


    notifyLayout->addLayout(notifyClearLayout);

    notifyScrollArea = new QScrollArea(layoutWidget);
    notifyScrollArea->setObjectName(QString::fromUtf8("notifyScrollArea"));
    notifyScrollArea->setFrameShape(QFrame::NoFrame);
    notifyScrollArea->setWidgetResizable(true);
    notifyScrollContents = new QWidget();
    notifyScrollContents->setObjectName(QString::fromUtf8("notifyScrollContents"));
    notifyScrollContents->setGeometry(QRect(0, 0, 447, 377));
    notifyScrollArea->setWidget(notifyScrollContents);

    notifyLayout->addWidget(notifyScrollArea);


    quickNotifyLayout->addLayout(notifyLayout);

    stackedWidget->addWidget(quicksetting);
    wifipage = new QWidget();
    wifipage->setObjectName(QString::fromUtf8("wifipage"));
    label = new QLabel(wifipage);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(170, 240, 58, 18));
    stackedWidget->addWidget(wifipage);
    bluetoothpage = new bluetoothapplet(this);
    bluetoothpage->setBluetoothstacked (stackedWidget);
    stackedWidget->addWidget(bluetoothpage);


    verticalLayout_4->addWidget(stackedWidget);

    leaveLayout = new QHBoxLayout();
    leaveLayout->setObjectName(QString::fromUtf8("leaveLayout"));
    logout = new QToolButton(Form);
    logout->setObjectName(QString::fromUtf8("logout"));
    QIcon icon11;
    iconThemeName = QString::fromUtf8("system-log-out");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon11 = QIcon::fromTheme(iconThemeName);
    } else {
        icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    logout->setIcon(icon11);
    logout->setIconSize(QSize(32, 32));
    logout->setAutoRaise(true);

    leaveLayout->addWidget(logout);

    suspend = new QToolButton(Form);
    suspend->setObjectName(QString::fromUtf8("suspend"));
    QIcon icon12;
    iconThemeName = QString::fromUtf8("system-suspend");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon12 = QIcon::fromTheme(iconThemeName);
    } else {
        icon12.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    suspend->setIcon(icon12);
    suspend->setIconSize(QSize(32, 32));
    suspend->setAutoRaise(true);

    leaveLayout->addWidget(suspend);

    lockscreen = new QToolButton(Form);
    lockscreen->setObjectName(QString::fromUtf8("lockscreen"));
    QIcon icon13;
    iconThemeName = QString::fromUtf8("system-lock-screen");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon13 = QIcon::fromTheme(iconThemeName);
    } else {
        icon13.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    lockscreen->setIcon(icon13);
    lockscreen->setIconSize(QSize(32, 32));
    lockscreen->setAutoRaise(true);

    leaveLayout->addWidget(lockscreen);

    reboot = new QToolButton(Form);
    reboot->setObjectName(QString::fromUtf8("reboot"));
    QIcon icon14;
    iconThemeName = QString::fromUtf8("system-reboot");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon14 = QIcon::fromTheme(iconThemeName);
    } else {
        icon14.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    reboot->setIcon(icon14);
    reboot->setIconSize(QSize(32, 32));
    reboot->setAutoRaise(true);

    leaveLayout->addWidget(reboot);

    shutdown = new QToolButton(Form);
    shutdown->setObjectName(QString::fromUtf8("shutdown"));
    QIcon icon15;
    iconThemeName = QString::fromUtf8("system-shutdown");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon15 = QIcon::fromTheme(iconThemeName);
    } else {
        icon15.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    shutdown->setIcon(icon15);
    shutdown->setIconSize(QSize(32, 32));
    shutdown->setAutoRaise(true);

    leaveLayout->addWidget(shutdown);


    verticalLayout_4->addLayout(leaveLayout);


    retranslateUi(Form);

    stackedWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(Form);
} // setupUi

void controlcenteritem::retranslateUi(QWidget *Form)
{
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    quicksettinglabel->setText(QCoreApplication::translate("Form", "Quick Setting", nullptr));
    wifi->setText(QCoreApplication::translate("Form", "Wifi", nullptr));
    nightmode->setText(QCoreApplication::translate("Form", "Night Mode", nullptr));
    bluetooth->setText(QCoreApplication::translate("Form", "Bluetooth", nullptr));
    focuse->setText(QCoreApplication::translate("Form", "Focuse", nullptr));
    display->setText(QCoreApplication::translate("Form", "Display", nullptr));
    allsetting->setText(QCoreApplication::translate("Form", "All Setting", nullptr));
    locale->setText(QCoreApplication::translate("Form", "Locale", nullptr));
    airplanemode->setText(QCoreApplication::translate("Form", "Airplane Mode", nullptr));
    brightnessbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
    bluelightbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
    volumebtn->setText(QCoreApplication::translate("Form", "...", nullptr));
    notificationlabel->setText(QCoreApplication::translate("Form", "Notification", nullptr));
    clearNotifyBtn->setText(QCoreApplication::translate("Form", "Clear all", nullptr));
    label->setText(QCoreApplication::translate("Form", "Wifi", nullptr));
    logout->setText(QCoreApplication::translate("Form", "...", nullptr));
    suspend->setText(QCoreApplication::translate("Form", "...", nullptr));
    lockscreen->setText(QCoreApplication::translate("Form", "...", nullptr));
    reboot->setText(QCoreApplication::translate("Form", "...", nullptr));
    shutdown->setText(QCoreApplication::translate("Form", "...", nullptr));
} // retranslateUi




