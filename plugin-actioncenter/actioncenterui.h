/********************************************************************************
** Form generated from reading UI file 'testDialogTRaKqK.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TESTDIALOGTRAKQK_H
#define TESTDIALOGTRAKQK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_quick_center
{
public:
    QVBoxLayout *quick_center_layout;
    QHBoxLayout *header_layout;
    QToolButton *ac_profile;
    QVBoxLayout *verticalLayout_2;
    QLabel *ac_time;
    QLabel *ac_date;
    QToolButton *ac_notification;
    QSpacerItem *ac_top_spacer;
    QGridLayout *grid_btn_layout;
    QToolButton *setting_btn;
    QToolButton *btooth_btn;
    QToolButton *nightmode_btn;
    QToolButton *user_btn;
    QToolButton *airplan_btn;
    QToolButton *todo_btn;
    QToolButton *focus_btn;
    QToolButton *toolButton_6;
    QToolButton *display_btn;
    QToolButton *locale_btn;
    QSpacerItem *ac_small_spacer;
    QHBoxLayout *middle_gamma_layout;
    QToolButton *ac_icon_gamma;
    QSlider *ac_slider_gamma;
    QLabel *ac_gamma_level;
    QHBoxLayout *middle_birhgt_layout;
    QToolButton *ac_bright_icon;
    QSlider *ac_slider_bright;
    QLabel *ac_bright_level;
    QHBoxLayout *middle_sound_layout;
    QToolButton *ac_sound_icon;
    QSlider *ac_slider_sound;
    QLabel *ac_sound_level;
    QSpacerItem *ac_middle_spacer;
    QHBoxLayout *footer_layout;
    QToolButton *logout_btn;
    QToolButton *reboot_btn;
    QToolButton *lock_screen_btn;
    QToolButton *shutdown_btn;
    QToolButton *suspend_btn;
    QSpacerItem *ac_bottom_spacer;

    void setupUi(QWidget *quick_center)
    {
        if (quick_center->objectName().isEmpty())
            quick_center->setObjectName(QString::fromUtf8("quick_center"));
        quick_center->resize(330, 1546);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quick_center->sizePolicy().hasHeightForWidth());
        quick_center->setSizePolicy(sizePolicy);
        quick_center->setWindowOpacity(1.000000000000000);
        quick_center->setStyleSheet(QString::fromUtf8(""));
        quick_center_layout = new QVBoxLayout(quick_center);
        quick_center_layout->setObjectName(QString::fromUtf8("quick_center_layout"));
        header_layout = new QHBoxLayout();
        header_layout->setObjectName(QString::fromUtf8("header_layout"));
        ac_profile = new QToolButton(quick_center);
        ac_profile->setObjectName(QString::fromUtf8("ac_profile"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ac_profile->sizePolicy().hasHeightForWidth());
        ac_profile->setSizePolicy(sizePolicy1);
        ac_profile->setMinimumSize(QSize(42, 42));
        ac_profile->setMaximumSize(QSize(42, 42));
        ac_profile->setMouseTracking(false);
        ac_profile->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("user");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_profile->setIcon(icon);
        ac_profile->setIconSize(QSize(24, 24));
        ac_profile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        ac_profile->setAutoRaise(true);

        header_layout->addWidget(ac_profile);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ac_time = new QLabel(quick_center);
        ac_time->setObjectName(QString::fromUtf8("ac_time"));
        sizePolicy.setHeightForWidth(ac_time->sizePolicy().hasHeightForWidth());
        ac_time->setSizePolicy(sizePolicy);
        ac_time->setMinimumSize(QSize(50, 50));
        QFont font;
        font.setPointSize(18);
        ac_time->setFont(font);
        ac_time->setTextFormat(Qt::RichText);
        ac_time->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ac_time);

        ac_date = new QLabel(quick_center);
        ac_date->setObjectName(QString::fromUtf8("ac_date"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        ac_date->setFont(font1);
        ac_date->setStyleSheet(QString::fromUtf8(""));
        ac_date->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ac_date);


        header_layout->addLayout(verticalLayout_2);

        ac_notification = new QToolButton(quick_center);
        ac_notification->setObjectName(QString::fromUtf8("ac_notification"));
        ac_notification->setMinimumSize(QSize(42, 42));
        ac_notification->setMaximumSize(QSize(42, 42));
        ac_notification->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("preferences-system-notifications-symbolic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_notification->setIcon(icon1);
        ac_notification->setIconSize(QSize(24, 24));
        ac_notification->setAutoRaise(true);

        header_layout->addWidget(ac_notification);


        quick_center_layout->addLayout(header_layout);

        ac_top_spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        quick_center_layout->addItem(ac_top_spacer);

        grid_btn_layout = new QGridLayout();
        grid_btn_layout->setSpacing(10);
        grid_btn_layout->setObjectName(QString::fromUtf8("grid_btn_layout"));
        grid_btn_layout->setSizeConstraint(QLayout::SetFixedSize);
        grid_btn_layout->setContentsMargins(-1, -1, -1, 0);
        setting_btn = new QToolButton(quick_center);
        setting_btn->setObjectName(QString::fromUtf8("setting_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(setting_btn->sizePolicy().hasHeightForWidth());
        setting_btn->setSizePolicy(sizePolicy2);
        setting_btn->setMinimumSize(QSize(100, 100));
        setting_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("preferences");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        setting_btn->setIcon(icon2);
        setting_btn->setIconSize(QSize(48, 48));
        setting_btn->setPopupMode(QToolButton::InstantPopup);
        setting_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        setting_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(setting_btn, 0, 0, 1, 1);

        btooth_btn = new QToolButton(quick_center);
        btooth_btn->setObjectName(QString::fromUtf8("btooth_btn"));
        sizePolicy2.setHeightForWidth(btooth_btn->sizePolicy().hasHeightForWidth());
        btooth_btn->setSizePolicy(sizePolicy2);
        btooth_btn->setMinimumSize(QSize(100, 100));
        btooth_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("preferences-system-bluetooth");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btooth_btn->setIcon(icon3);
        btooth_btn->setIconSize(QSize(48, 48));
        btooth_btn->setPopupMode(QToolButton::InstantPopup);
        btooth_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btooth_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(btooth_btn, 1, 1, 1, 1);

        nightmode_btn = new QToolButton(quick_center);
        nightmode_btn->setObjectName(QString::fromUtf8("nightmode_btn"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(nightmode_btn->sizePolicy().hasHeightForWidth());
        nightmode_btn->setSizePolicy(sizePolicy3);
        nightmode_btn->setMinimumSize(QSize(100, 100));
        nightmode_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("weather-storm-night");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        nightmode_btn->setIcon(icon4);
        nightmode_btn->setIconSize(QSize(48, 48));
        nightmode_btn->setPopupMode(QToolButton::InstantPopup);
        nightmode_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        nightmode_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(nightmode_btn, 2, 1, 1, 1);

        user_btn = new QToolButton(quick_center);
        user_btn->setObjectName(QString::fromUtf8("user_btn"));
        sizePolicy2.setHeightForWidth(user_btn->sizePolicy().hasHeightForWidth());
        user_btn->setSizePolicy(sizePolicy2);
        user_btn->setMinimumSize(QSize(100, 100));
        user_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        user_btn->setIcon(icon);
        user_btn->setIconSize(QSize(48, 48));
        user_btn->setPopupMode(QToolButton::InstantPopup);
        user_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        user_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(user_btn, 2, 0, 1, 1);

        airplan_btn = new QToolButton(quick_center);
        airplan_btn->setObjectName(QString::fromUtf8("airplan_btn"));
        sizePolicy3.setHeightForWidth(airplan_btn->sizePolicy().hasHeightForWidth());
        airplan_btn->setSizePolicy(sizePolicy3);
        airplan_btn->setCheckable (true);
        airplan_btn->setMinimumSize(QSize(100, 100));
        airplan_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("network-wireless-hotspot");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        airplan_btn->setIcon(icon5);
        airplan_btn->setIconSize(QSize(48, 48));
        airplan_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        airplan_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(airplan_btn, 3, 1, 1, 1);

        todo_btn = new QToolButton(quick_center);
        todo_btn->setObjectName(QString::fromUtf8("todo_btn"));
        sizePolicy3.setHeightForWidth(todo_btn->sizePolicy().hasHeightForWidth());
        todo_btn->setSizePolicy(sizePolicy3);
        todo_btn->setMinimumSize(QSize(100, 100));
        todo_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("tag-addressbook");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        todo_btn->setIcon(icon6);
        todo_btn->setIconSize(QSize(48, 48));
        todo_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        todo_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(todo_btn, 4, 0, 1, 1);

        focus_btn = new QToolButton(quick_center);
        focus_btn->setObjectName(QString::fromUtf8("focus_btn"));
        sizePolicy3.setHeightForWidth(focus_btn->sizePolicy().hasHeightForWidth());
        focus_btn->setSizePolicy(sizePolicy3);
        focus_btn->setMinimumSize(QSize(100, 100));
        focus_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("braindump");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        focus_btn->setIcon(icon7);
        focus_btn->setIconSize(QSize(48, 48));
        focus_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        focus_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(focus_btn, 4, 1, 1, 1);

        toolButton_6 = new QToolButton(quick_center);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        sizePolicy2.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy2);
        toolButton_6->setMinimumSize(QSize(100, 100));
        toolButton_6->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("network-wireless");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        toolButton_6->setIcon(icon8);
        toolButton_6->setIconSize(QSize(48, 48));
        toolButton_6->setPopupMode(QToolButton::InstantPopup);
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_6->setAutoRaise(true);

        grid_btn_layout->addWidget(toolButton_6, 1, 0, 1, 1);

        display_btn = new QToolButton(quick_center);
        display_btn->setObjectName(QString::fromUtf8("display_btn"));
        sizePolicy2.setHeightForWidth(display_btn->sizePolicy().hasHeightForWidth());
        display_btn->setSizePolicy(sizePolicy2);
        display_btn->setMinimumSize(QSize(100, 100));
        display_btn->setAutoFillBackground(false);
        display_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("monitor");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        display_btn->setIcon(icon9);
        display_btn->setIconSize(QSize(48, 48));
        display_btn->setPopupMode(QToolButton::InstantPopup);
        display_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        display_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(display_btn, 0, 1, 1, 1);

        locale_btn = new QToolButton(quick_center);
        locale_btn->setObjectName(QString::fromUtf8("locale_btn"));
        sizePolicy3.setHeightForWidth(locale_btn->sizePolicy().hasHeightForWidth());
        locale_btn->setSizePolicy(sizePolicy3);
        locale_btn->setMinimumSize(QSize(100, 100));
        locale_btn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgba(0, 0, 0, 0.2);\n"
"border-radius:5px;\n"
"}\n"
"QToolButton::clicked{\n"
"background-color:white;\n"
"color:black;\n"
"}"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("preferences-desktop-locale");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        locale_btn->setIcon(icon10);
        locale_btn->setIconSize(QSize(48, 48));
        locale_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        locale_btn->setAutoRaise(true);

        grid_btn_layout->addWidget(locale_btn, 3, 0, 1, 1);


        quick_center_layout->addLayout(grid_btn_layout);

        ac_small_spacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        quick_center_layout->addItem(ac_small_spacer);

        middle_gamma_layout = new QHBoxLayout();
        middle_gamma_layout->setObjectName(QString::fromUtf8("middle_gamma_layout"));
        ac_icon_gamma = new QToolButton(quick_center);
        ac_icon_gamma->setObjectName(QString::fromUtf8("ac_icon_gamma"));
        ac_icon_gamma->setStyleSheet(QString::fromUtf8(""));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("brightnesssettings");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_icon_gamma->setIcon(icon11);
        ac_icon_gamma->setAutoRaise(true);

        middle_gamma_layout->addWidget(ac_icon_gamma);

        ac_slider_gamma = new QSlider(quick_center);
        ac_slider_gamma->setObjectName(QString::fromUtf8("ac_slider_gamma"));
        ac_slider_gamma->setStyleSheet(QString::fromUtf8(""));
        ac_slider_gamma->setTracking(true);
        ac_slider_gamma->setOrientation(Qt::Horizontal);

        middle_gamma_layout->addWidget(ac_slider_gamma);

        ac_gamma_level = new QLabel(quick_center);
        ac_gamma_level->setObjectName(QString::fromUtf8("ac_gamma_level"));
        sizePolicy1.setHeightForWidth(ac_gamma_level->sizePolicy().hasHeightForWidth());
        ac_gamma_level->setSizePolicy(sizePolicy1);
        ac_gamma_level->setStyleSheet(QString::fromUtf8(""));

        middle_gamma_layout->addWidget(ac_gamma_level);


        quick_center_layout->addLayout(middle_gamma_layout);

        middle_birhgt_layout = new QHBoxLayout();
        middle_birhgt_layout->setObjectName(QString::fromUtf8("middle_birhgt_layout"));
        ac_bright_icon = new QToolButton(quick_center);
        ac_bright_icon->setObjectName(QString::fromUtf8("ac_bright_icon"));
        ac_bright_icon->setStyleSheet(QString::fromUtf8(""));
        QIcon icon12;
        iconThemeName = QString::fromUtf8("lighttable");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_bright_icon->setIcon(icon12);
        ac_bright_icon->setAutoRaise(true);

        middle_birhgt_layout->addWidget(ac_bright_icon);

        ac_slider_bright = new QSlider(quick_center);
        ac_slider_bright->setObjectName(QString::fromUtf8("ac_slider_bright"));
        ac_slider_bright->setStyleSheet(QString::fromUtf8(""));
        ac_slider_bright->setTracking(true);
        ac_slider_bright->setOrientation(Qt::Horizontal);

        middle_birhgt_layout->addWidget(ac_slider_bright);

        ac_bright_level = new QLabel(quick_center);
        ac_bright_level->setObjectName(QString::fromUtf8("ac_bright_level"));
        sizePolicy1.setHeightForWidth(ac_bright_level->sizePolicy().hasHeightForWidth());
        ac_bright_level->setSizePolicy(sizePolicy1);
        ac_bright_level->setStyleSheet(QString::fromUtf8(""));

        middle_birhgt_layout->addWidget(ac_bright_level);


        quick_center_layout->addLayout(middle_birhgt_layout);

        middle_sound_layout = new QHBoxLayout();
        middle_sound_layout->setObjectName(QString::fromUtf8("middle_sound_layout"));
        ac_sound_icon = new QToolButton(quick_center);
        ac_sound_icon->setObjectName(QString::fromUtf8("ac_sound_icon"));
        ac_sound_icon->setStyleSheet(QString::fromUtf8(""));
        QIcon icon13;
        iconThemeName = QString::fromUtf8("audio");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon13 = QIcon::fromTheme(iconThemeName);
        } else {
            icon13.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_sound_icon->setIcon(icon13);
        ac_sound_icon->setAutoRaise(true);

        middle_sound_layout->addWidget(ac_sound_icon);

        ac_slider_sound = new QSlider(quick_center);
        ac_slider_sound->setObjectName(QString::fromUtf8("ac_slider_sound"));
        ac_slider_sound->setStyleSheet(QString::fromUtf8(""));
        ac_slider_sound->setTracking(true);
        ac_slider_sound->setOrientation(Qt::Horizontal);

        middle_sound_layout->addWidget(ac_slider_sound);

        ac_sound_level = new QLabel(quick_center);
        ac_sound_level->setObjectName(QString::fromUtf8("ac_sound_level"));
        sizePolicy1.setHeightForWidth(ac_sound_level->sizePolicy().hasHeightForWidth());
        ac_sound_level->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(10);
        ac_sound_level->setFont(font2);
        ac_sound_level->setStyleSheet(QString::fromUtf8(""));

        middle_sound_layout->addWidget(ac_sound_level);


        quick_center_layout->addLayout(middle_sound_layout);

        ac_middle_spacer = new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding);

        quick_center_layout->addItem(ac_middle_spacer);

        footer_layout = new QHBoxLayout();
        footer_layout->setObjectName(QString::fromUtf8("footer_layout"));
        logout_btn = new QToolButton(quick_center);
        logout_btn->setObjectName(QString::fromUtf8("logout_btn"));
        logout_btn->setMinimumSize(QSize(42, 42));
        logout_btn->setMaximumSize(QSize(42, 42));
        logout_btn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon14;
        iconThemeName = QString::fromUtf8("system-log-out");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon14 = QIcon::fromTheme(iconThemeName);
        } else {
            icon14.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        logout_btn->setIcon(icon14);
        logout_btn->setIconSize(QSize(32, 32));
        logout_btn->setAutoRaise(true);

        footer_layout->addWidget(logout_btn);

        reboot_btn = new QToolButton(quick_center);
        reboot_btn->setObjectName(QString::fromUtf8("reboot_btn"));
        reboot_btn->setMinimumSize(QSize(42, 42));
        reboot_btn->setMaximumSize(QSize(42, 42));
        reboot_btn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon15;
        iconThemeName = QString::fromUtf8("system-reboot");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon15 = QIcon::fromTheme(iconThemeName);
        } else {
            icon15.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        reboot_btn->setIcon(icon15);
        reboot_btn->setIconSize(QSize(32, 32));
        reboot_btn->setAutoRaise(true);

        footer_layout->addWidget(reboot_btn);

        lock_screen_btn = new QToolButton(quick_center);
        lock_screen_btn->setObjectName(QString::fromUtf8("lock_screen_btn"));
        lock_screen_btn->setMinimumSize(QSize(42, 42));
        lock_screen_btn->setMaximumSize(QSize(42, 42));
        lock_screen_btn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon16;
        iconThemeName = QString::fromUtf8("system-lock-screen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon16 = QIcon::fromTheme(iconThemeName);
        } else {
            icon16.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        lock_screen_btn->setIcon(icon16);
        lock_screen_btn->setIconSize(QSize(32, 32));
        lock_screen_btn->setAutoRaise(true);

        footer_layout->addWidget(lock_screen_btn);

        shutdown_btn = new QToolButton(quick_center);
        shutdown_btn->setObjectName(QString::fromUtf8("shutdown_btn"));
        shutdown_btn->setMinimumSize(QSize(42, 42));
        shutdown_btn->setMaximumSize(QSize(42, 42));
        shutdown_btn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon17;
        iconThemeName = QString::fromUtf8("system-shutdown");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon17 = QIcon::fromTheme(iconThemeName);
        } else {
            icon17.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        shutdown_btn->setIcon(icon17);
        shutdown_btn->setIconSize(QSize(32, 32));
        shutdown_btn->setAutoRaise(true);

        footer_layout->addWidget(shutdown_btn);

        suspend_btn = new QToolButton(quick_center);
        suspend_btn->setObjectName(QString::fromUtf8("suspend_btn"));
        suspend_btn->setMinimumSize(QSize(42, 42));
        suspend_btn->setMaximumSize(QSize(42, 42));
        suspend_btn->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(0, 0, 0, 0.2);"));
        QIcon icon18;
        iconThemeName = QString::fromUtf8("system-suspend");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon18 = QIcon::fromTheme(iconThemeName);
        } else {
            icon18.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        suspend_btn->setIcon(icon18);
        suspend_btn->setIconSize(QSize(32, 32));
        suspend_btn->setAutoRaise(true);

        footer_layout->addWidget(suspend_btn);


        quick_center_layout->addLayout(footer_layout);

        ac_bottom_spacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        quick_center_layout->addItem(ac_bottom_spacer);


        retranslateUi(quick_center);

        QMetaObject::connectSlotsByName(quick_center);
    } // setupUi

    void retranslateUi(QWidget *quick_center)
    {
        quick_center->setWindowTitle(QCoreApplication::translate("quick_center", "Dialog", nullptr));
        ac_profile->setText(QString());
        ac_time->setStyleSheet(QString());
        ac_time->setText(QCoreApplication::translate("quick_center", "09:30 AM", nullptr));
        ac_date->setText(QCoreApplication::translate("quick_center", "", nullptr));
        ac_notification->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        setting_btn->setText(QCoreApplication::translate("quick_center", "Settings", nullptr));
        btooth_btn->setText(QCoreApplication::translate("quick_center", "Bluetooth", nullptr));
        nightmode_btn->setText(QCoreApplication::translate("quick_center", "Night Mode", nullptr));
        user_btn->setText(QCoreApplication::translate("quick_center", "User", nullptr));
        airplan_btn->setText(QCoreApplication::translate("quick_center", "Airplane Mode", nullptr));
        todo_btn->setText(QCoreApplication::translate("quick_center", "Todo list", nullptr));
        focus_btn->setText(QCoreApplication::translate("quick_center", "Focus mode", nullptr));
        toolButton_6->setText(QCoreApplication::translate("quick_center", "Wifi", nullptr));
        display_btn->setText(QCoreApplication::translate("quick_center", "Display", nullptr));
        locale_btn->setText(QCoreApplication::translate("quick_center", "Locale", nullptr));
        ac_icon_gamma->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        ac_gamma_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
        ac_bright_icon->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        ac_bright_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
        ac_sound_icon->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        ac_sound_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
        logout_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        reboot_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        lock_screen_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        shutdown_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
        suspend_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Quick_Center: public Ui_quick_center {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TESTDIALOGTRAKQK_H
