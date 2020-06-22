#ifndef KMPControlCenterItem_H
#define KMPControlCenterItem_H

//#include "bluelight.h"
//#include "bluetoothui.h"
//#include "brightness.h"
//#include "displayui.h"
//#include "soundservice.h"
//#include "wifiitemcontainer.h"
#include "actioncenterhome.h"
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "display/displayUi.h"
class KMPControlCenterItem : public QWidget {
  Q_OBJECT
public:
  explicit KMPControlCenterItem(QWidget *parent = nullptr);
  void setupUi(QWidget *Form);
  void retranslateUi(QWidget *Form);

  QStackedWidget *getStackedWidget() const;
  void setStackedWidget(QStackedWidget *value);

private:
  QVBoxLayout *verticalLayout;
  QStackedWidget *stackedWidget;
  QWidget *page_2;
  QVBoxLayout *verticalLayout_3;
  QPushButton *pushButton_2;
  // custome widget used inside action center.
  ActionCenterHome * homePage =nullptr;
  Ui_Form * display {};
Q_SIGNALS:

public Q_SLOTS:
};

#endif // KMPControlCenterItem_H
