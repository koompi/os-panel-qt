#ifndef WIFIITEMMODEL_H
#define WIFIITEMMODEL_H
#include "networkservice.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
class wifiItemModel : public QWidget {
  Q_OBJECT
public:
  explicit wifiItemModel(QWidget *parent = nullptr);
  void setupUi(QWidget *Form);
  void retranslateUi(QWidget *Form);
  QLabel *getLabelWifi() const;
  void setLabelWifi(QLabel *value);

  QToolButton *getWifiIcon() const;
  void setWifiIcon(QToolButton *value);

  QListWidgetItem *getWificontainer() const;
  void setWificontainer(QListWidgetItem *value);

private:
  QHBoxLayout *horizontalLayout_4;
  QVBoxLayout *verticalLayout_2;
  QHBoxLayout *horizontalLayout_2;
  QHBoxLayout *horizontalLayout;
  QToolButton *wifiIcon;
  QVBoxLayout *verticalLayout;
  QLabel *labelWifi;
  QLabel *connectState;
  QPushButton *wifiConnectBtn = nullptr;
  QHBoxLayout *horizontalLayout_3;
  QLineEdit *passEdit = nullptr;
  QToolButton *toolButton = nullptr;
  QListWidgetItem *wificontainer = nullptr;

  networkservice *networkService = nullptr;

  // QObject interface
public:
  bool event(QEvent *event);
  void connectWifi(const QString &name, const QString &password);
  // QWidget interface
protected:
  void mousePressEvent(QMouseEvent *event);
Q_SIGNALS:
  void requireConnection(const QString &ssid, const QString &pass);
  void requstDisconnect(const QString &ssid);
  void notifyItemModelPress();
};

#endif // WIFIITEMMODEL_H
