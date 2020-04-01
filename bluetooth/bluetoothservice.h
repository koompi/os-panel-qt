#ifndef bluetoothservice_H
#define bluetoothservice_H
#include "process.h"
#include <QObject>
#include <QPointer>
#include <QProcess>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <QtBluetooth/QBluetoothTransferManager>
#include <QtBluetooth/QBluetoothTransferReply>
#include <QtBluetooth/QBluetoothTransferRequest>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
class bluetoothservice : public QObject {
  Q_OBJECT
public:
  explicit bluetoothservice(QObject *parent = nullptr);
  ~bluetoothservice();
  void connectSendDataBluetooth();
  void connectBluetooth(const QString &addresser);
  QString nameToAddress(const QString &info);
  void bluetoothScanning();
  QBluetoothAddress getCurrentAddress() const;
  void setCurrentAddress(const QBluetoothAddress &value);

private:
  QList<QBluetoothDeviceInfo> listBluetoothInfo;
  QBluetoothLocalDevice *m_localDevice = nullptr;
  QBluetoothAddress currentAddress;
  //  QString addresser;
  process *p;

private slots:
  void onPairingdisplaypincode(const QBluetoothAddress &addr, QString pin);
  void onParingdisplayconfirmation(const QBluetoothAddress &addr, QString pin);
  void pairingDone(QBluetoothAddress addr,
                   QBluetoothLocalDevice::Pairing pairing);
public slots:
  void deviceDiscoverd(QBluetoothDeviceInfo deviceInfo);
  void addNewDevice(const QString addressdevice);
signals:
  void notifyCurrentSelectedAddress(const QBluetoothAddress &blueAddress);
  void notifyDeviceName(const QBluetoothDeviceInfo &);
  void notifyScanFinished();
  void notifyConfinsished(int exitCode);
};

#endif // bluetoothservice_H
