#include "actioncenterhome.h"
#include <QScreen>
ActionCenterHome::ActionCenterHome(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}
void ActionCenterHome::setupUi(QWidget *quick_center)
{
    if (quick_center->objectName().isEmpty())
        quick_center->setObjectName(QString::fromUtf8("quick_center"));
    QScreen * screen = QGuiApplication::primaryScreen();
    quick_center->resize(screen->geometry().width() * 0.25, screen->geometry().height());
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(quick_center->sizePolicy().hasHeightForWidth());
    quick_center->setSizePolicy(sizePolicy);
    quick_center->setWindowOpacity(1.0);
    quick_center->setStyleSheet(QString::fromUtf8("background-color:#2f3640;"));
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
    ac_profile->setMinimumSize(QSize(48, 48));
    ac_profile->setMouseTracking(false);
    ac_profile->setStyleSheet(QString::fromUtf8("QToolButton {\n"
                                                "background-color:white;\n"
                                                "border-top: 3px transparent;\n"
                                                "border-bottom: 3px transparent; \n"
                                                "border-right: 10px transparent;\n"
                                                "border-left: 10px transparent;\n"
                                                "border-radius:24px;\n"
                                                "}"));
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
    ac_profile->setAutoRaise(false);

    header_layout->addWidget(ac_profile);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(0);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    actionDateTime = new ActionDateTime(quick_center,quick_center, QStringLiteral("ac_time"));
    ac_time = actionDateTime->createTime();

    verticalLayout_2->addWidget(ac_time);
    actionDateTime = new ActionDateTime(quick_center, quick_center, QStringLiteral("ac_date"));
    ac_date = actionDateTime->createDate();

    verticalLayout_2->addWidget(ac_date);

    header_layout->addLayout(verticalLayout_2);

    ac_notification = new QToolButton(quick_center);
    ac_notification->setObjectName(QString::fromUtf8("ac_notification"));
    ac_notification->setMinimumSize(QSize(32, 32));
    ac_notification->setStyleSheet(QString::fromUtf8("background-color:#f2f2f2;border-radius: 5px;"));
    QIcon icon1;
    iconThemeName = QString::fromUtf8("notifications-white");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon1 = QIcon::fromTheme(iconThemeName);
    } else {
        icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    ac_notification->setIcon(icon1);
    ac_notification->setIconSize(QSize(32, 32));
    ac_notification->setAutoRaise(false);

    header_layout->addWidget(ac_notification);


    quick_center_layout->addLayout(header_layout);

    ac_list_notification = new QListView(quick_center);
    ac_list_notification->setObjectName(QString::fromUtf8("ac_list_notification"));
    ac_list_notification->setStyleSheet(QString::fromUtf8("border:0px;"));

    quick_center_layout->addWidget(ac_list_notification);

    ac_top_spacer = new QSpacerItem(20, 195, QSizePolicy::Minimum, QSizePolicy::Expanding);

    quick_center_layout->addItem(ac_top_spacer);

    grid_btn_layout = new QGridLayout();
    grid_btn_layout->setSpacing(10);
    grid_btn_layout->setObjectName(QString::fromUtf8("grid_btn_layout"));
    grid_btn_layout->setSizeConstraint(QLayout::SetFixedSize);
    grid_btn_layout->setContentsMargins(-1, -1, -1, 0);
    // setting control
    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("setting_btn"),
                                  QStringLiteral("preferences"));
    setting_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(setting_btn, 0, 0, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("booth_btn"),
                                  QStringLiteral("preferences-system-bluetooth"));
    btooth_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(btooth_btn, 1, 1, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("nightmode_btn"),
                                  QStringLiteral("applications-graphics"));
    nightmode_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(nightmode_btn, 2, 1, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("user_btn"),
                                  QStringLiteral("user"));
    user_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(user_btn, 2, 0 , 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("airplay_btn"),
                                  QStringLiteral("offline"));
    airplan_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(airplan_btn, 3, 1, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("todo_btn"),
                                  QStringLiteral("tag-addressbook"));
    todo_btn =  ac_setting->createInstance();
    grid_btn_layout->addWidget(todo_btn, 4, 0, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("focus_btn"),
                                  QStringLiteral("braindump"));
    focus_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(focus_btn, 4, 1, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("wifi_btn"),
                                  QStringLiteral("network-wireless"));
    wifi_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(wifi_btn, 1, 0, 1, 1);

    ac_setting = new ActionButton(quick_center,
                                  QStringLiteral("display_btn"),
                                  QStringLiteral("monitor"));
    display_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(display_btn, 0, 1, 1, 1);

    ac_setting = new ActionButton(quick_center, QStringLiteral("locale_btn"), QStringLiteral("preferences-desktop-locale"));
    locale_btn = ac_setting->createInstance();
    grid_btn_layout->addWidget(locale_btn, 3, 0, 1, 1);

    quick_center_layout->addLayout(grid_btn_layout);

    ac_small_spacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

    quick_center_layout->addItem(ac_small_spacer);

    frame = new QFrame(quick_center);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setMinimumSize(QSize(0, 100));
    frame->setStyleSheet(QString::fromUtf8("background-color:#5b65736e;border-radius:5px;"));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    middle_layout = new QVBoxLayout(frame);
    middle_layout->setObjectName(QString::fromUtf8("middle_layout"));
    middle_sound_layout = new QHBoxLayout();
    middle_sound_layout->setObjectName(QString::fromUtf8("middle_sound_layout"));

    acSmallButton = new ActionSMButton(frame, QStringLiteral("ac_sound_icon"),QStringLiteral("audio"));
    ac_sound_icon = acSmallButton->createInstance();
    middle_sound_layout->addWidget(ac_sound_icon);
    ac_slider_sound = acSmallButton->createSlider(QStringLiteral("ac_slider_sound"));
    middle_sound_layout->addWidget(ac_slider_sound);
    ac_sound_level = acSmallButton->createLabel(QStringLiteral("ac_sound_level"));
    middle_sound_layout->addWidget(ac_sound_level);
    middle_layout->addLayout(middle_sound_layout);

    middle_birhgt_layout = new QHBoxLayout();
    middle_birhgt_layout->setObjectName(QString::fromUtf8("middle_birhgt_layout"));

    acSmallButton = new ActionSMButton(frame, QStringLiteral("ac_bright_icon"),QStringLiteral("lighttable"));
    ac_bright_icon = acSmallButton->createInstance();
    middle_birhgt_layout->addWidget(ac_bright_icon);

    ac_slider_bright = acSmallButton->createSlider(QStringLiteral("ac_slider_bright"));
    middle_birhgt_layout->addWidget(ac_slider_bright);
    ac_bright_level = acSmallButton->createLabel(QStringLiteral("ac_bright_level"));
    middle_birhgt_layout->addWidget(ac_bright_level);
    middle_layout->addLayout(middle_birhgt_layout);

    middle_gamma_layout = new QHBoxLayout();
    middle_gamma_layout->setObjectName(QString::fromUtf8("middle_gamma_layout"));

    acSmallButton = new ActionSMButton(frame, QStringLiteral("ac_icon_gamma"), QStringLiteral("brightnesssettings"));
    ac_icon_gamma = acSmallButton->createInstance();
    middle_gamma_layout->addWidget(ac_icon_gamma);

    ac_slider_gamma = acSmallButton->createSlider(QStringLiteral("ac_slider_gamma"));
    middle_gamma_layout->addWidget(ac_slider_gamma);

    ac_gamma_level = acSmallButton->createLabel(QStringLiteral("ac_gamma_level"));
    middle_gamma_layout->addWidget(ac_gamma_level);

    middle_layout->addLayout(middle_gamma_layout);

    quick_center_layout->addWidget(frame);

    ac_middle_spacer = new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding);

    quick_center_layout->addItem(ac_middle_spacer);

    footer_layout = new QHBoxLayout();
    footer_layout->setObjectName(QString::fromUtf8("footer_layout"));
    sessionButton = new SessionButton(quick_center, QStringLiteral("logout_btn"), QStringLiteral("system-log-out"));
    logout_btn = sessionButton->createSessionButton();
    footer_layout->addWidget(logout_btn);


    sessionButton = new SessionButton(quick_center, QStringLiteral("reboot_btn"), QStringLiteral("system-reboot"));
    reboot_btn = sessionButton->createSessionButton();
    footer_layout->addWidget(reboot_btn);

    sessionButton = new SessionButton(quick_center, QStringLiteral("lock_screen_btn"), QStringLiteral("system-lock-screen"));
    lock_screen_btn = sessionButton->createSessionButton();
    footer_layout->addWidget(lock_screen_btn);

    sessionButton = new SessionButton(quick_center, QStringLiteral("shutdown_btn"), QStringLiteral("system-shutdown"));
    shutdown_btn = sessionButton->createSessionButton();
    connect(shutdown_btn, &QToolButton::clicked, [](){
       QApplication::exit(0);
    });
    footer_layout->addWidget(shutdown_btn);

    sessionButton = new SessionButton(quick_center, QStringLiteral("suspend_btn"), QStringLiteral("system-suspend"));
    suspend_btn = sessionButton->createSessionButton();
    footer_layout->addWidget(suspend_btn);

    quick_center_layout->addLayout(footer_layout);

    ac_bottom_spacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

    quick_center_layout->addItem(ac_bottom_spacer);


    translateUi(quick_center);

    QMetaObject::connectSlotsByName(quick_center);
}

void ActionCenterHome::translateUi(QWidget *quick_center)
{
    quick_center->setWindowTitle(QCoreApplication::translate("quick_center", "Widget", nullptr));
    ac_profile->setText(QString());
    ac_time->setText(QCoreApplication::translate("quick_center", " ", nullptr));
    ac_date->setText(QCoreApplication::translate("quick_center", " ", nullptr));
    ac_notification->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    setting_btn->setText(QCoreApplication::translate("quick_center", "Settings", nullptr));
    btooth_btn->setText(QCoreApplication::translate("quick_center", "Bluetooth", nullptr));
    nightmode_btn->setText(QCoreApplication::translate("quick_center", "Night Mode", nullptr));
    user_btn->setText(QCoreApplication::translate("quick_center", "User", nullptr));
    airplan_btn->setText(QCoreApplication::translate("quick_center", "Airplane Mode", nullptr));
    todo_btn->setText(QCoreApplication::translate("quick_center", "Todo list", nullptr));
    focus_btn->setText(QCoreApplication::translate("quick_center", "Focus mode", nullptr));
    wifi_btn->setText(QCoreApplication::translate("quick_center", "Wifi", nullptr));
    display_btn->setText(QCoreApplication::translate("quick_center", "Display", nullptr));
    locale_btn->setText(QCoreApplication::translate("quick_center", "Locale", nullptr));
    ac_sound_icon->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    ac_sound_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
    ac_bright_icon->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    ac_bright_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
    ac_icon_gamma->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    ac_gamma_level->setText(QCoreApplication::translate("quick_center", "100%", nullptr));
    logout_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    reboot_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    lock_screen_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    shutdown_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
    suspend_btn->setText(QCoreApplication::translate("quick_center", "...", nullptr));
}
