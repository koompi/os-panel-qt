#include "bluetoothui.h"
#include <QBluetoothDeviceDiscoveryAgent>
#include <QDebug>
bluetoothui::bluetoothui(QWidget *parent) : QWidget(parent) {
  //  checkBluetoothOnOff();
  setupUi(this);
  connect(enableBluetoothBtn, &QToolButton::clicked, [&]() {
    checkBox->setChecked(true);
    bluetoothStack->setCurrentIndex(1);
  });
  connect(checkBox, &QCheckBox::stateChanged, [&](int state) {
    if (state == 2) {
      checkBox->setChecked(true);
    }
    bluetoothStack->setCurrentIndex(0);
  });
  connect(bluetoothBack, &QToolButton::clicked,
          [&]() { emit notifyEnableBluetoothClicked(); });
  connect(addNewBluetooth, &QToolButton::clicked, [this]() {
    if (scannerPage == nullptr) {
      scannerPage = new bluetoothscaner(this);
    }
    scannerPage->show();
  });
  connect(scannerPage, &bluetoothscaner::notifyToBluetoothPage,
          [this]() { this->show(); });
}
void bluetoothui::setupUi(QWidget *FormBluetooth) {
  if (FormBluetooth->objectName().isEmpty())
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
  QFont font;
  font.setPointSize(12);
  font.setBold(false);
  font.setWeight(50);
  topTitleBluetooth->setFont(font);
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
  addNewBluetooth = new QToolButton(layoutWidget1);
  addNewBluetooth->setObjectName(QString::fromUtf8("addNewBluetooth"));
  QFont font1;
  font1.setPointSize(12);
  font1.setBold(true);
  font1.setWeight(75);
  addNewBluetooth->setFont(font1);
  QIcon icon1;
  iconThemeName = QString::fromUtf8("list-add");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon1 = QIcon::fromTheme(iconThemeName);
  } else {
    icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  addNewBluetooth->setIcon(icon1);
  addNewBluetooth->setIconSize(QSize(24, 24));
  addNewBluetooth->setAutoRaise(true);

  layoutRight->addWidget(addNewBluetooth);

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

  availableTitle = new QLabel(bluetoothPageTwo);
  availableTitle->setObjectName(QString::fromUtf8("availableTitle"));
  availableTitle->setGeometry(QRect(120, 130, 221, 20));
  availableTitle->setAlignment(Qt::AlignCenter);

  bluetoothTitle = new QLabel(bluetoothPageTwo);
  bluetoothTitle->setObjectName(QString::fromUtf8("bluetoothTitle"));
  bluetoothTitle->setGeometry(QRect(160, 30, 141, 20));
  QFont font3;
  font3.setFamily(QString::fromUtf8("Fira Code"));
  font3.setPointSize(19);
  font3.setBold(false);
  font3.setWeight(50);
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

  retranslateUi(FormBluetooth);

  bluetoothStack->setCurrentIndex(1);

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
  addNewBluetooth->setText(
      QCoreApplication::translate("FormBluetooth", "...", nullptr));
  bluetoothSetting->setText(
      QCoreApplication::translate("FormBluetooth", "...", nullptr));
  availableTitle->setText(QCoreApplication::translate(
      "FormBluetooth", "Available Devices", nullptr));
  bluetoothTitle->setText(
      QCoreApplication::translate("FormBluetooth", "Bluetooth", nullptr));
  bluetoothBack->setText(
      QCoreApplication::translate("FormBluetooth", "...", nullptr));
}

void bluetoothui::checkBluetoothOnOff() {
  QBluetoothLocalDevice localDevice;
  if (localDevice.isValid()) {
    checkBox->setCheckState(Qt::CheckState::Checked);
  } else {
    checkBox->setEnabled(false);
    bluetoothTitle->setEnabled(false);
    addNewBluetooth->setEnabled(false);
    bluetoothSetting->setEnabled(false);
  }
}

void bluetoothui::startDeviceDiscovery() {

  // Create a discovery agent and connect to its signals
  QBluetoothDeviceDiscoveryAgent *discoveryAgent =
      new QBluetoothDeviceDiscoveryAgent(this);
  connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this,
          SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

  // Start a discovery
  discoveryAgent->start();
}

void bluetoothui::deviceDiscovered(const QBluetoothDeviceInfo &device) {
  qDebug() << "Found new device:" << device.name() << '('
           << device.address().toString() << ')';
}
