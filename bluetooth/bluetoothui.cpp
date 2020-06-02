#include "bluetoothui.h"
#include <QBluetoothDeviceDiscoveryAgent>
#include <QDebug>
#include <QException>
#include <QMovie>
bluetoothui::bluetoothui(QWidget *parent) : QWidget(parent) {
  setupUi(this);
  initAction();
}
void bluetoothui::setupUi(QWidget *FormBluetooth) {
  if (FormBluetooth->objectName().isEmpty())
    bluetoothService = new bluetoothservice(this);
  FormBluetooth->setObjectName(QString::fromUtf8("FormBluetooth"));
  FormBluetooth->setEnabled(true);
  FormBluetooth->resize(471, 912);
  verticalLayout = new QVBoxLayout(FormBluetooth);
  verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
  bluetoothStack = new QStackedWidget(FormBluetooth);
  bluetoothStack->setObjectName(QString::fromUtf8("bluetoothStack"));
  bluetoothPageOne = new QWidget();
  bluetoothPageOne->setObjectName(QString::fromUtf8("bluetoothPageOne"));
  QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(
      bluetoothPageOne->sizePolicy().hasHeightForWidth());
  bluetoothPageOne->setSizePolicy(sizePolicy);
  bluetoothPageOne->setMinimumSize(QSize(459, 900));
  bluetoothPageOne->setLayoutDirection(Qt::RightToLeft);
  bluetoothPageOne->setAutoFillBackground(false);
  layoutWidget = new QWidget(bluetoothPageOne);
  layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
  layoutWidget->setGeometry(QRect(0, 400, 461, 62));
  firstBlueLayout = new QVBoxLayout(layoutWidget);
  firstBlueLayout->setObjectName(QString::fromUtf8("firstBlueLayout"));
  firstBlueLayout->setContentsMargins(0, 0, 0, 0);
  topTitleBluetooth = new QLabel(layoutWidget);
  topTitleBluetooth->setObjectName(QString::fromUtf8("topTitleBluetooth"));
  topTitleBluetooth->setEnabled(false);
  //  QFont font;
  //  font.setPointSize(12);
  //  font.setBold(false);
  //  font.setWeight(50);
  //  topTitleBluetooth->setFont(font);
  topTitleBluetooth->setAlignment(Qt::AlignCenter);
  firstBlueLayout->addWidget(topTitleBluetooth);

  enableBluetoothBtn = new QToolButton(layoutWidget);
  enableBluetoothBtn->setObjectName(QString::fromUtf8("enableBluetoothBtn"));
  QIcon icon;
  QString iconThemeName = QString::fromUtf8("network-bluetooth");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon = QIcon::fromTheme(iconThemeName);
  } else {
    icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  enableBluetoothBtn->setIcon(icon);
  enableBluetoothBtn->setPopupMode(QToolButton::InstantPopup);
  enableBluetoothBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  enableBluetoothBtn->setAutoRaise(false);
  firstBlueLayout->addWidget(enableBluetoothBtn, 0, Qt::AlignHCenter);

  bluetoothStack->addWidget(bluetoothPageOne);
  bluetoothPageTwo = new QWidget();
  bluetoothPageTwo->setObjectName(QString::fromUtf8("bluetoothPageTwo"));
  listWidget = new QListWidget(bluetoothPageTwo);
  listWidget->setObjectName(QString::fromUtf8("listWidget"));
  listWidget->setGeometry(QRect(0, 160, 461, 731));
  listWidget->setAutoFillBackground(true);
  listWidget->setFrameShape(QFrame::NoFrame);
  layoutWidget1 = new QWidget(bluetoothPageTwo);
  layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
  layoutWidget1->setGeometry(QRect(0, 70, 451, 40));
  layoutTop = new QHBoxLayout(layoutWidget1);
  layoutTop->setObjectName(QString::fromUtf8("layoutTop"));
  layoutTop->setContentsMargins(0, 0, 0, 0);
  checkBox = new QCheckBox(layoutWidget1);
  checkBox->setObjectName(QString::fromUtf8("checkBox"));
  checkBox->setIcon(icon);
  checkBox->setIconSize(QSize(24, 24));

  layoutTop->addWidget(checkBox);

  layoutRight = new QHBoxLayout();
  layoutRight->setObjectName(QString::fromUtf8("layoutRight"));
  loadingAnimation = new QMovie(this);
  loadingAnimation->setFileName(":/sources/blueloading.gif");
  QLabel *statusScanning = new QLabel(this);
  statusScanning->setMovie(loadingAnimation);
  layoutTop->addWidget(statusScanning);
  refreshBluetooth = new QToolButton(layoutWidget1);
  refreshBluetooth->setObjectName(QString::fromUtf8("refreshBluetooth"));
  refreshBluetooth->setText("scanning....");
  refreshBluetooth->setIconSize(QSize(24, 24));
  refreshBluetooth->setAutoRaise(true);
  //  refreshBluetooth->setIcon(QIcon::fromTheme("view-refresh"));

  layoutRight->addWidget(refreshBluetooth);

  bluetoothSetting = new QToolButton(layoutWidget1);
  bluetoothSetting->setObjectName(QString::fromUtf8("bluetoothSetting"));
  QIcon icon2;
  iconThemeName = QString::fromUtf8("gtk-preferences");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon2 = QIcon::fromTheme(iconThemeName);
  } else {
    icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  bluetoothSetting->setIcon(icon2);
  bluetoothSetting->setAutoRaise(true);
  layoutRight->addWidget(bluetoothSetting);

  layoutTop->addLayout(layoutRight);
  bluetoothTitle = new QLabel(bluetoothPageTwo);
  bluetoothTitle->setObjectName(QString::fromUtf8("bluetoothTitle"));
  bluetoothTitle->setGeometry(QRect(160, 30, 141, 20));
  QFont font3;
  font3.setPointSize(18);
  bluetoothTitle->setFont(font3);
  bluetoothBack = new QToolButton(bluetoothPageTwo);
  bluetoothBack->setObjectName(QString::fromUtf8("bluetoothBack"));
  bluetoothBack->setGeometry(QRect(0, 20, 42, 35));
  QIcon icon3(QIcon::fromTheme(QString::fromUtf8("arrow-left")));
  bluetoothBack->setIcon(icon3);
  bluetoothBack->setAutoRaise(true);
  bluetoothStack->addWidget(bluetoothPageTwo);

  verticalLayout->addWidget(bluetoothStack, 0,
                            Qt::AlignHCenter | Qt::AlignVCenter);

  bluetoothStack->setCurrentIndex(1);
  retranslateUi(FormBluetooth);
  QMetaObject::connectSlotsByName(FormBluetooth);
}
void bluetoothui::retranslateUi(QWidget *FormBluetooth) {
  FormBluetooth->setWindowTitle(
      QCoreApplication::translate("FormBluetooth", "Form", nullptr));
  topTitleBluetooth->setText(QCoreApplication::translate(
      "FormBluetooth", "Bluetooth is Disable", nullptr));
  enableBluetoothBtn->setText(QCoreApplication::translate(
      "FormBluetooth", "Enable Bluetooth", nullptr));
  checkBox->setText(QString());
  refreshBluetooth->setText(
      QCoreApplication::translate("FormBluetooth", "Scanning...", nullptr));
  bluetoothSetting->setText(
      QCoreApplication::translate("FormBluetooth", "...", nullptr));
  //  availableTitle->setText(QCoreApplication::translate(
  //      "FormBluetooth", "Available Devices", nullptr));
  bluetoothTitle->setText(
      QCoreApplication::translate("FormBluetooth", "Bluetooth", nullptr));
  bluetoothBack->setText(
      QCoreApplication::translate("FormBluetooth", "...", nullptr));
}

void bluetoothui::onCollapseSize() {
  listWidget->takeItem(listWidget->currentRow());
}

void bluetoothui::onShowBluetoothItem(const QBluetoothDeviceInfo &blueName) {
  bluetoothItem = new bluetoothitem(this);
  switch (blueName.majorDeviceClass()) {

  case QBluetoothDeviceInfo::MiscellaneousDevice: {
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("preferences-system-bluetooth"));
    break;
  }
  case QBluetoothDeviceInfo::ComputerDevice: {
    bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme("computer"));
    break;
  }
  case QBluetoothDeviceInfo::PhoneDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme("phone"));
    break;

  case QBluetoothDeviceInfo::LANAccessDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("network-card"));
    break;

  case QBluetoothDeviceInfo::AudioVideoDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("audio-headphones"));
    break;
  case QBluetoothDeviceInfo::PeripheralDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("drive-partition"));
    break;
  case QBluetoothDeviceInfo::ImagingDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("camera-photo"));
    break;
  case QBluetoothDeviceInfo::ToyDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("input-gaming"));
    break;
  case QBluetoothDeviceInfo::HealthDevice:
    bluetoothItem->getBluetoothIcon()->setIcon(QIcon::fromTheme("scanner"));
    break;
  default: {
    bluetoothItem->getBluetoothIcon()->setIcon(
        QIcon::fromTheme("preferences-system-bluetooth"));
    break;
  }
  }
  connect(bluetoothItem, &bluetoothitem::requestData, this,
          &bluetoothui::onRequestData);
  connect(bluetoothItem, &bluetoothitem::requireBluetoothConnection,
          bluetoothService, &bluetoothservice::addNewDevice);
  connect(bluetoothItem, &bluetoothitem::requireBluetoothDisconnect,
          bluetoothService, &bluetoothservice::disConnectDevice);
  connect(bluetoothService, &bluetoothservice::notifyProcessFinished,
          bluetoothItem, &bluetoothitem::changeTextAndPosition);
  bluetoothItem->getBluetoothName()->setText(blueName.name());
  QListWidgetItem *listitem = new QListWidgetItem(listWidget);
  qDebug() << listWidget->count() << endl;
  listWidget->addItem(listitem);
  listitem->setSizeHint(bluetoothItem->sizeHint());
  listWidget->setItemWidget(listitem, bluetoothItem);
}

void bluetoothui::onRequestData(bluetoothitem *entity) {

  QString address =
      bluetoothService->nameToAddress(entity->getBluetoothName()->text());
  QString addressOnDialog =
      bluetoothService->nameToAddress(entity->getBluetoothName()->text());
  entity->getLabel_address()->setText(
      QString("Address: %0").arg(addressOnDialog));
  QBluetoothLocalDevice::Pairing status =
      m_localDevice.pairingStatus(QBluetoothAddress(address));
  switch (status) {
  case QBluetoothLocalDevice::Paired:
    entity->getLabel_pair()->setText(QString("Paired: %0").arg("Yes"));
    break;
  case QBluetoothLocalDevice::Unpaired:
    entity->getLabel_pair()->setText(QString("Paired: %0").arg("No"));
    break;
  case QBluetoothLocalDevice::AuthorizedPaired:
    entity->getLabel_trust()->setText(QString("Paired: %0").arg("Yes"));
  default:
    entity->getLabel_address()->setText(QString("Paired: %0").arg("Default"));
    entity->getLabel_pair()->setText(QString("Paired: %0").arg("Default"));
    entity->getLabel_trust()->setText(QString("Paired: %0").arg("Default"));
    entity->getLabel_adapter()->setText(QString("Paired: %0").arg("Default"));
  }
  entity->getLabel_adapter()->setText(
      QString("Adapter: %0").arg(m_localDevice.name()));
  qDebug() << "Status: " << status << endl;
}

void bluetoothui::slotOncheckbluetooth(bool state) {
  if (state)
    m_localDevice.powerOn();
  else
    m_localDevice.setHostMode(QBluetoothLocalDevice::HostPoweredOff);
}

void bluetoothui::slotOnrefreshblutooth() { reloadWifiList(); }

void bluetoothui::slotOnHostModeChange(QBluetoothLocalDevice::HostMode mode) {
  if (mode == QBluetoothLocalDevice::HostMode::HostPoweredOff) {
    checkBox->setChecked(false);
    listWidget->clear();
  } else {
    checkBox->setChecked(true);
    reloadWifiList();
  }
}

void bluetoothui::initAction() {
  if (m_localDevice.hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    checkBox->setChecked(false);
  else {
    checkBox->setChecked(true);
  }
  bluetoothService->bluetoothScanning();
  connect(bluetoothService, &bluetoothservice::notifyDeviceName, this,
          &bluetoothui::onShowBluetoothItem);
  connect(checkBox, &QCheckBox::stateChanged, this,
          &bluetoothui::slotOncheckbluetooth);
  connect(bluetoothBack, &QToolButton::clicked,
          [&]() { emit notifyEnableBluetoothClicked(); });
  connect(bluetoothService, &bluetoothservice::notifyConfinsished,
          [&]() { refreshBluetooth->setEnabled(true); });

  connect(refreshBluetooth, &QToolButton::clicked, this,
          &bluetoothui::slotOnrefreshblutooth);

  connect(&m_localDevice, &QBluetoothLocalDevice::hostModeStateChanged, this,
          &bluetoothui::slotOnHostModeChange);

  connect(listWidget, &QListWidget::currentRowChanged,
          [&](int value) { qDebug() << value << endl; });
}
void bluetoothui::reloadWifiList() {
  listWidget->clear();
  if (listWidget->count() == 0) {
    qDebug() << "List clear then rescan bluetooth list..";
    bluetoothService->bluetoothScanning();
  }
}
