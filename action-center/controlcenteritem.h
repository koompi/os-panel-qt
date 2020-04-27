#ifndef CONTROLCENTERITEM_H
#define CONTROLCENTERITEM_H

#include "bluetoothui.h"
#include "soundservice.h"
#include "wifiitemcontainer.h"
#include "brightness.h"
#include "bluelight.h"
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class controlcenteritem : public QWidget {
  Q_OBJECT
public:
  explicit controlcenteritem(QWidget *parent = nullptr);
  void setupUi(QWidget *);
  void retranslateUi(QWidget *);
  QStackedWidget *getStackedWidget() const;
  void setStackedWidget(QStackedWidget *value);

private:
  int m_width, m_height;
  QVBoxLayout *verticalLayout_4;
  QStackedWidget *stackedWidget;
  QWidget *quicksetting;
  QWidget *layoutWidget;
  QVBoxLayout *quickNotifyLayout;
  QVBoxLayout *quickSettingLayout;
  QLabel *quicksettinglabel;
  QVBoxLayout *quickchildLayout;
  QGridLayout *quickgridLayout;
  QToolButton *wifi;
  QToolButton *nightmode;
  QToolButton *bluetooth;
  QToolButton *focuse;
  QToolButton *display;
  QToolButton *allsetting;
  QToolButton *locale;
  QToolButton *airplanemode;
  QSpacerItem *verticalSpacer;
  QHBoxLayout *brightnessLayout;
  QToolButton *brightnessbtn;
  QSlider *BrightnessSlider;
  QHBoxLayout *nightModeLayout;
  QToolButton *bluelightbtn;
  QSlider *bluelightslider;
  QHBoxLayout *soundLayout;
  QToolButton *volumebtn;
  QSlider *volumeslider;
  QVBoxLayout *notifyLayout;
  QHBoxLayout *notifyClearLayout;
  QLabel *notificationlabel;
  QPushButton *clearNotifyBtn;
  QScrollArea *notifyScrollArea;
  QWidget *notifyScrollContents;
  QHBoxLayout *leaveLayout;
  QToolButton *logout;
  QToolButton *suspend;
  QToolButton *lockscreen;
  QToolButton *reboot;
  QToolButton *shutdown;
  wifiitemcontainer *wifipage;
  soundservice *soundService = nullptr;
  QLabel *audioPercentShow = nullptr;
  QLabel *brightPercentShow = nullptr;
  QLabel *bluePercentShow = nullptr;
  bluetoothui *kmpbluetooth;
  brightness *bright;
  bluelight * blue;

Q_SIGNALS:

public Q_SLOTS:
};

#endif // CONTROLCENTERITEM_H
