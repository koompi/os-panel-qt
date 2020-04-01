#include "bluetoothservice.h"
#include <QDebug>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QBluetoothServer>
#include <QtConcurrent>
bluetoothservice::bluetoothservice(QObject *parent)
    : QObject(parent), m_localDevice(new QBluetoothLocalDevice(this)) {

  connect(m_localDevice,
          SIGNAL(pairingDisplayPinCode(const QBluetoothAddress &, QString)),
          this,
          SLOT(onPairingdisplaypincode(const QBluetoothAddress &, QString)));
  connect(
      m_localDevice,
      SIGNAL(pairingDisplayConfirmation(const QBluetoothAddress &, QString)),
      this,
      SLOT(onParingdisplayconfirmation(const QBluetoothAddress &, QString)));
  connect(m_localDevice,
          SIGNAL(pairingFinished(QBluetoothAddress,
                                 QBluetoothLocalDevice::Pairing)),
          this,
          SLOT(pairingDone(QBluetoothAddress, QBluetoothLocalDevice::Pairing)));
}

bluetoothservice::~bluetoothservice() {}

void bluetoothservice::connectSendDataBluetooth() {
  // Create a transfer manager
  QBluetoothTransferManager transferManager;

  // Create the transfer request and file to be sent
  QBluetoothTransferRequest request(currentAddress);
  QFile *file = new QFile("/home/sna/Pictures/nai.jpg", this);
  //  p = new process(this);
  //  p->setStatus("Sending to: " + currentAddress.toString(), "Waiting for
  //  start"); p->show();
  QBluetoothTransferReply *reply = transferManager.put(request, file);
  // mgr is default parent
  // ensure that mgr doesn't take reply down when leaving scope
  reply->setParent(this);
  if (reply->error()) {
    qDebug() << "Failed to send file";
    p->finished(reply);
    reply->deleteLater();
    return;
  }
  //  connect(reply, SIGNAL(transferProgress(qint64, qint64)), p,
  //          SLOT(uploadProgress(qint64, qint64)));
  //  connect(reply, SIGNAL(finished(QBluetoothTransferReply *)), p,
  //          SLOT(finished(QBluetoothTransferReply *)));
  //  connect(p, SIGNAL(rejected()), reply, SLOT(abort()));
  // Ask the transfer manager to send it
}

void bluetoothservice::connectBluetooth(const QString &addresser) {
  QtConcurrent::run([addresser, this]() {
    QProcess bluepro;
    QStringList args;
    args << "connect" << nameToAddress(addresser);
    bluepro.start("bluetoothctl", args);
    bluepro.waitForFinished();
    bluepro.close();
    emit notifyConfinsished(bluepro.exitCode());
  });
}

QString bluetoothservice::nameToAddress(const QString &info) {
  QString address;
  for (auto &devInfo : listBluetoothInfo) {
    if (devInfo.name() == info) {
      address = devInfo.address().toString();
      break;
    }
  }
  return address;
}

QBluetoothAddress bluetoothservice::getCurrentAddress() const {
  return currentAddress;
}

void bluetoothservice::setCurrentAddress(const QBluetoothAddress &value) {
  currentAddress = value;
}

void bluetoothservice::onPairingdisplaypincode(const QBluetoothAddress &addr,
                                               QString pin) {
  qDebug() << "#DISPLAY_PIN: " << pin << "for" << addr;
}

void bluetoothservice::onParingdisplayconfirmation(
    const QBluetoothAddress &addr, QString pin) {
  qDebug() << "#PAIRING_DISPLAY_CONFIRMATION_PIN: " << pin << "for" << addr;
}

void bluetoothservice::pairingDone(QBluetoothAddress addr,
                                   QBluetoothLocalDevice::Pairing pairing) {
  if (pairing == QBluetoothLocalDevice::Paired) {
    connectBluetooth(addr.toString());
  }
}

void bluetoothservice::bluetoothScanning() {
  // Create a discovery agent and connect to its signals
  QBluetoothDeviceDiscoveryAgent *discoveryAgent =
      new QBluetoothDeviceDiscoveryAgent(this);
  connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this,
          SLOT(deviceDiscoverd(QBluetoothDeviceInfo)));
  connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
          [&]() { emit notifyScanFinished(); });
  // Start a discovery
  discoveryAgent->start();
  //...
}

void bluetoothservice::deviceDiscoverd(QBluetoothDeviceInfo deviceInfo) {
  listBluetoothInfo.push_back(deviceInfo);
  emit notifyDeviceName(deviceInfo);
}

void bluetoothservice::addNewDevice(QString addressdevice) {
  qInfo() << "click on me ......" << this << endl;
  QBluetoothLocalDevice::Pairing paring = m_localDevice->pairingStatus(
      QBluetoothAddress(nameToAddress(addressdevice)));
  if (paring == QBluetoothLocalDevice::Paired ||
      paring == QBluetoothLocalDevice::AuthorizedPaired) {
    connectBluetooth(addressdevice);
  } else {
    qInfo() << "not paired and unauthorized";
    m_localDevice->requestPairing(
        QBluetoothAddress(nameToAddress(addressdevice)),
        QBluetoothLocalDevice::Paired);
  }
}
