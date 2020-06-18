#ifndef BLUETOOTHSERVICE_H
#define BLUETOOTHSERVICE_H

#include <QObject>
#include <QProcess>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <QtBluetooth/QBluetoothTransferManager>
#include <QtBluetooth/QBluetoothTransferReply>
#include <QtBluetooth/QBluetoothTransferRequest>
class BluetoothService : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothService(QObject *parent = nullptr);
    ~BluetoothService();
    void connectSendDataBluetooth();
    void connectBluetooth(const QString &addresser);
    QString nameToAddress(const QString &info);
    void bluetoothScanning();
    QBluetoothAddress getCurrentAddress() const;
    void setCurrentAddress(const QBluetoothAddress &value);
signals:
private:
  QList<QBluetoothDeviceInfo> listBluetoothInfo;
  QBluetoothLocalDevice *m_localDevice = nullptr;
  QBluetoothAddress currentAddress;
private slots:
  void onPairingdisplaypincode(const QBluetoothAddress &addr, QString pin);
  void onParingdisplayconfirmation(const QBluetoothAddress &addr, QString pin);
  void pairingDone(QBluetoothAddress addr,
                   QBluetoothLocalDevice::Pairing pairing);
  void onProcessStarted();
public slots:
  void onProcessFinished(int exitCode, QProcess::ExitStatus status);
  void deviceDiscoverd(QBluetoothDeviceInfo deviceInfo);
  void addNewDevice(const QString addressdevice);
  void disConnectDevice(const QString &address);
signals:
  void notifyCurrentSelectedAddress(const QBluetoothAddress &blueAddress);
  void notifyDeviceName(const QBluetoothDeviceInfo &);
  void notifyScanFinished();
  void notifyConfinsished(int exitCode);
  void notifyProcessFinished();
  void notifyProcessFinishedError();

};

#endif // BLUETOOTHSERVICE_H
