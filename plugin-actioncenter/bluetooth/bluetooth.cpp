#include "bluetooth.h"
#include "bluetoothui.h"
#include <QListWidgetItem>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QDebug>
Bluetooth::Bluetooth(QWidget * parent):
    QWidget(parent),
    ui(new Ui::Form),
    blueservice(new BluetoothService(this)){
    ui->setupUi(this);
    connect(ui->backBtn, &QToolButton::clicked, [&](){
        getStack()->setCurrentIndex(0);
    });
    initAction();
}

QStackedWidget *Bluetooth::getStack() const
{
    return stack;
}

void Bluetooth::setStack(QStackedWidget *value)
{
    stack = value;
}

void Bluetooth::onShowBluetoothItem(const QBluetoothDeviceInfo &blueName)
{
    bluetoothItem = new CustomItem(this);
    bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme(QStringLiteral("phone")));
    switch (blueName.majorDeviceClass()) {
    case QBluetoothDeviceInfo::MiscellaneousDevice: {
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("preferences-system-bluetooth")));
        break;
    }
    case QBluetoothDeviceInfo::ComputerDevice: {
        bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme(QString::fromUtf8("computer")));
        break;
    }
    case QBluetoothDeviceInfo::PhoneDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme(QString::fromUtf8("phone")));
        break;

    case QBluetoothDeviceInfo::LANAccessDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("network-card")));
        break;

    case QBluetoothDeviceInfo::AudioVideoDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("audio-headphones")));
        break;
    case QBluetoothDeviceInfo::PeripheralDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("drive-partition")));
        break;
    case QBluetoothDeviceInfo::ImagingDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("camera-photo")));
        break;
    case QBluetoothDeviceInfo::ToyDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("input-gaming")));
        break;
    case QBluetoothDeviceInfo::HealthDevice:
        bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme(QString::fromUtf8("scanner")));
        break;
    default: {
        bluetoothItem->getBluetoothIcon()->setIcon(
                    QIcon::fromTheme(QString::fromUtf8("preferences-system-bluetooth")));
        break;
            }
    }
    //      connect(bluetoothItem, &bluetoothitem::requestData, this,
    //              &bluetoothui::onRequestData);
    connect(bluetoothItem, &CustomItem::requireBluetoothConnection,
            blueservice, &BluetoothService::addNewDevice);
    connect(bluetoothItem, &CustomItem::requireBluetoothDisconnect,
            blueservice, &BluetoothService::disConnectDevice);
    connect(blueservice, &BluetoothService::notifyProcessFinished,
            bluetoothItem, &CustomItem::changeTextAndPosition);
    qInfo() << "BLUTOOTH NAME: " << blueName.name()<<Qt::endl;
    bluetoothItem->getBluetoothName()->setText(blueName.name());
    QListWidgetItem * item = new QListWidgetItem(ui->blueListView);
    item->setSizeHint(bluetoothItem->sizeHint());
    ui->blueListView->addItem(item);
    ui->blueListView->setItemWidget(item, bluetoothItem);
}

void Bluetooth::slotOncheckbluetooth(bool state)
{
    if (state)
        m_localDevice.powerOn();
    else
        m_localDevice.setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}

void Bluetooth::slotOnrefreshblutooth()
{
    reloadWifiList();
}

void Bluetooth::slotOnHostModeChange(QBluetoothLocalDevice::HostMode mode)
{
    if (mode == QBluetoothLocalDevice::HostMode::HostPoweredOff) {
        ui->blueCheck->setChecked(false);
        ui->blueListView->clear();
    } else {
        ui->blueCheck->setChecked(true);
        reloadWifiList();
    }
}

void Bluetooth::initAction()
{
    blueservice->bluetoothScanning();
    connect(blueservice, &BluetoothService::notifyDeviceName, this, &Bluetooth::onShowBluetoothItem);
    connect(ui->blueCheck, &QCheckBox::stateChanged, this,
            &Bluetooth::slotOncheckbluetooth);
    //    connect(ui->backBtn, &QToolButton::clicked,
    //            [&]() { emit notifyEnableBluetoothClicked(); });
    //    connect(blueservice, &BluetoothService::notifyConfinsished,
    //            [&]() { refreshBluetooth->setEnabled(true); });

        connect(ui->blueRefresh, &QToolButton::clicked, this,
                &Bluetooth::slotOnrefreshblutooth);

    connect(&m_localDevice, &QBluetoothLocalDevice::hostModeStateChanged, this,
            &Bluetooth::slotOnHostModeChange);

    connect(ui->blueListView, &QListWidget::currentRowChanged,
            [&](int value) { qDebug() << value << endl; });
}

void Bluetooth::reloadWifiList()
{
    ui->blueListView->clear();
    if (ui->blueListView->count() == 0) {
        qDebug() << "List clear then rescan bluetooth list..";
        blueservice->bluetoothScanning();
    }
}
