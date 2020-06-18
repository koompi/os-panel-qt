#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <QWidget>
#include <QObject>
#include <QStackedWidget>
#include "customitem.h"
#include "bluetoothservice.h"
QT_BEGIN_NAMESPACE
namespace Ui{ class Form;}
QT_END_NAMESPACE
class Bluetooth : public QWidget
{
    Q_OBJECT
public:
    explicit Bluetooth(QWidget * parent);
    QStackedWidget *getStack() const;
    void setStack(QStackedWidget *value);
private:
    Ui::Form * ui;
    QStackedWidget * stack;
    BluetoothService * blueservice = nullptr;
    CustomItem * bluetoothItem;
    QBluetoothLocalDevice  m_localDevice;
public Q_SLOTS:
  void onShowBluetoothItem(const QBluetoothDeviceInfo &blueName);
//  void onRequestData(bluetoothitem *);
private slots:
  void slotOncheckbluetooth(bool state);
  void slotOnrefreshblutooth();
  void slotOnHostModeChange(QBluetoothLocalDevice::HostMode mode);
private:
  void initAction();
  void reloadWifiList();
};

#endif
