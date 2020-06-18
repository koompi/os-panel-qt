#include "bluetoothservice.h"
#include <QDebug>
#include <QtBluetooth/QBluetoothAddress>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <QtBluetooth/QBluetoothTransferManager>
#include <QtBluetooth/QBluetoothTransferReply>
#include <QtBluetooth/QBluetoothTransferRequest>
BluetoothService::BluetoothService(QObject *parent) : QObject(parent),m_localDevice(new QBluetoothLocalDevice(this))
{
    connect(m_localDevice, &QBluetoothLocalDevice::pairingDisplayPinCode,
            this, &BluetoothService::onPairingdisplaypincode);
    connect(m_localDevice, &QBluetoothLocalDevice::pairingDisplayConfirmation,
            this, &BluetoothService::onParingdisplayconfirmation);
    connect(m_localDevice, &QBluetoothLocalDevice::pairingFinished,
            this, &BluetoothService::pairingDone);

}

BluetoothService::~BluetoothService()
{

}

void BluetoothService::connectBluetooth(const QString &addresser)
{
    qDebug() << nameToAddress(addresser);
    QProcess *m_process = new QProcess(this);
    connect(m_process, &QProcess::started, this,
            &BluetoothService::onProcessStarted);
    connect(m_process,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
            &BluetoothService::onProcessFinished);

    QStringList args;
    m_process->setProgram(QString::fromUtf8("bluetoothctl"));
    args <<QString::fromUtf8("connect") << nameToAddress(addresser);
    m_process->setArguments(args);
    m_process->start(QIODevice::ReadOnly);
}

QString BluetoothService::nameToAddress(const QString &info)
{
    QString address;
    for (auto &devInfo : listBluetoothInfo) {
        if (devInfo.name() == info) {
            address = devInfo.address().toString();
            break;
        }
    }
    return address;
}


QBluetoothAddress BluetoothService::getCurrentAddress() const
{
    return currentAddress;
}

void BluetoothService::setCurrentAddress(const QBluetoothAddress &value)
{
    currentAddress = value;
}

void BluetoothService::onPairingdisplaypincode(const QBluetoothAddress &addr, QString pin)
{
    qDebug() << "#DISPLAY_PIN: " << pin << "for" << addr;
}

void BluetoothService::onParingdisplayconfirmation(const QBluetoothAddress &addr, QString pin)
{
    qDebug() << "#PAIRING_DISPLAY_CONFIRMATION_PIN: " << pin << "for" << addr;
}

void BluetoothService::pairingDone(QBluetoothAddress addr, QBluetoothLocalDevice::Pairing pairing)
{
    if (pairing == QBluetoothLocalDevice::Paired) {
        connectBluetooth(addr.toString());
    }
}

void BluetoothService::onProcessStarted()
{
    qInfo() << "Process starting ......";
}

void BluetoothService::onProcessFinished(int exitCode, QProcess::ExitStatus status)
{
    qDebug() << "Process finished with status : " << status
             << "The exit code : " << exitCode << Qt::endl;
    if (exitCode == 0 && status == QProcess::NormalExit)
        Q_EMIT notifyProcessFinished();
    else
        Q_EMIT notifyProcessFinishedError();
}

void BluetoothService::bluetoothScanning()
{
    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent =
            new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this,
            SLOT(deviceDiscoverd(QBluetoothDeviceInfo)));
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            [&]() { emit notifyScanFinished(); });
    // Start a discovery
    discoveryAgent->start();
}
void BluetoothService::deviceDiscoverd(QBluetoothDeviceInfo deviceInfo)
{
    listBluetoothInfo.push_back(deviceInfo);
    emit notifyDeviceName(deviceInfo);
}

void BluetoothService::addNewDevice(const QString addressdevice)
{
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

void BluetoothService::disConnectDevice(const QString &address)
{
    QProcess *discon_process = new QProcess(this);
    discon_process->setProgram(QString::fromUtf8("bluetoothctl"));
    discon_process->setArguments(QStringList()
                                 << QString::fromUtf8("disconnect") << nameToAddress(address));
    discon_process->startDetached();
    connect(discon_process, &QProcess::started, this,
            &BluetoothService::onProcessStarted);
    connect(discon_process,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
            &BluetoothService::onProcessFinished);
}
