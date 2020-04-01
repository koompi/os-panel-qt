#ifndef WIFIITEMCONTAINER_H
#define WIFIITEMCONTAINER_H

#include "wifiapplet.h"
#include "wifiitemmodel.h"
#include <QCoreApplication>
#include <QStackedWidget>

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
class wifiitemcontainer : public QWidget {
  Q_OBJECT
public:
  explicit wifiitemcontainer(QWidget *parent = nullptr);
  void setupUi(QWidget *Form);
  void retranslateUi(QWidget *Form);

  QStackedWidget *getParentStacked() const;
  void setParentStacked(QStackedWidget *value);

  QList<QStringList> getActiveWireless_signal() const;
  void setActiveWireless_signal(const QList<QStringList> &value);
  void callConnectWifi(const QString &ssid, const QString &pass);

private:
  QWidget *layoutWidget;
  QHBoxLayout *wificontrolLayout;
  QHBoxLayout *checkGroupLayout;
  QCheckBox *wifiCheck;
  QCheckBox *airplaneCheck;
  QToolButton *searchBtn;
  QLabel *label;
  QListWidget *wifiListView;
  QWidget *layoutWidget_2;
  QToolButton *networkBackBtn;
  QStackedWidget *parentStacked;
  QList<QStringList> activeWireless_signal;
  QList<QListWidgetItem> listItem;
  wifiapplet *wifiManager = nullptr;
public
  Q_SLOT : void getwifiList(QList<QStringList> list);
  void onNotifyAddress();
Q_SIGNALS:
  void connectionFinished();
};

#endif // WIFIITEMCONTAINER_H
