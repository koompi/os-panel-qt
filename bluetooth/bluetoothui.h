#ifndef BLUETOOTHUI_H
#define BLUETOOTHUI_H

#include "bluetoothscaner.h"
#include <QPointer>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class bluetoothui : public QWidget {
  Q_OBJECT
public:
  explicit bluetoothui(QWidget *parent = nullptr);
  void setupUi(QWidget *FormBluetooth);
  void retranslateUi(QWidget *FormBluetooth);
  void checkBluetoothOnOff();
  void startDeviceDiscovery();
private slots:
  void deviceDiscovered(const QBluetoothDeviceInfo &device);

private:
  QVBoxLayout *verticalLayout;
  QStackedWidget *bluetoothStack;
  QWidget *bluetoothPageOne;
  QWidget *layoutWidget;
  QVBoxLayout *firstBlueLayout;
  QLabel *topTitleBluetooth;
  QToolButton *enableBluetoothBtn;
  QWidget *bluetoothPageTwo;
  QListWidget *listWidget;
  QWidget *layoutWidget1;
  QHBoxLayout *layoutTop;
  QCheckBox *checkBox;
  QHBoxLayout *layoutRight;
  QToolButton *addNewBluetooth;
  QToolButton *bluetoothSetting;
  QLabel *availableTitle;
  QLabel *bluetoothTitle;
  QToolButton *bluetoothBack;
  QPointer<bluetoothscaner> scannerPage = nullptr;
signals:
  void notifyEnableBluetoothClicked();
};

#endif // BLUETOOTHUI_H
