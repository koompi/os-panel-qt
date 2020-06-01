#ifndef ACIONCENTERHOME_H
#define ACIONCENTERHOME_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "actionbutton.h"
#include "actionsmbutton.h"
#include "sessionbutton.h"
#include "actiondatetime.h"
class ActionCenterHome : public QWidget
{
    Q_OBJECT
public:
    explicit ActionCenterHome(QWidget *parent = nullptr);
private:
    void setupUi(QWidget * quick_center);
    void translateUi(QWidget * quick_center);
    QString addStyleSheet();
private:
    QListView *ac_list_notification;
    QVBoxLayout *quick_center_layout,
    *verticalLayout_2,
    *middle_layout;
    QHBoxLayout *header_layout,
    *middle_sound_layout,
    *middle_birhgt_layout,
    *middle_gamma_layout,
    *footer_layout;
    QGridLayout *grid_btn_layout;
    QToolButton *setting_btn,
    *btooth_btn,
    *nightmode_btn,
    *user_btn,
    *airplan_btn,
    *todo_btn,
    *focus_btn,
    *wifi_btn,
    *display_btn,
    *locale_btn,
    *ac_sound_icon,
    *ac_bright_icon,
    *ac_icon_gamma,
    *logout_btn,
    *reboot_btn,
    *lock_screen_btn,
    *shutdown_btn,
    *suspend_btn,
    *ac_profile,
    *ac_notification;
    QFrame *frame;
    QSlider *ac_slider_sound;
    QSlider *ac_slider_bright;
    QSlider *ac_slider_gamma;
    QLabel *ac_time, *ac_date,
    *ac_sound_level,
    *ac_bright_level,
    *ac_gamma_level;
    QSpacerItem *ac_top_spacer,
    *ac_small_spacer,
    *ac_middle_spacer,
    *ac_bottom_spacer;
    ActionButton * ac_setting;
    ActionSMButton * acSmallButton;
    SessionButton * sessionButton;
    ActionDateTime * actionDateTime;
signals:

};

#endif // ACIONCENTERHOME_H
