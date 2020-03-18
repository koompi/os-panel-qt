#include "bluetoothscaner.h"
#include <QDebug>
bluetoothscaner::bluetoothscaner(QWidget *parent) : QWidget(parent) {
  setupUi(this);
  constructSignalSlot(this);
  bluetoothAnimationScanner();
}

bluetoothscaner::~bluetoothscaner() {}

void bluetoothscaner::setupUi(QWidget *Form) {
  if (Form->objectName().isEmpty())
    Form->setObjectName(QString::fromUtf8("Form"));
  Form->resize(471, 465);
  verticalLayout = new QVBoxLayout(Form);
  verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
  bluetoothScanTitle = new QLabel(Form);
  bluetoothScanTitle->setObjectName(QString::fromUtf8("bluetoothScanTitle"));
  QFont font;
  font.setPointSize(14);
  bluetoothScanTitle->setFont(font);

  verticalLayout->addWidget(bluetoothScanTitle);

  bluetoothScannList = new QListView(Form);
  bluetoothScannList->setObjectName(QString::fromUtf8("bluetoothScannList"));

  verticalLayout->addWidget(bluetoothScannList);

  pinCodeLayout = new QHBoxLayout();
  pinCodeLayout->setObjectName(QString::fromUtf8("pinCodeLayout"));
  scannerani = new QLabel(Form);
  scannerani->setObjectName(QString::fromUtf8("scannerani"));
  QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(scannerani->sizePolicy().hasHeightForWidth());
  scannerani->setSizePolicy(sizePolicy1);

  pinCodeLayout->addWidget(scannerani);
  scannerStatus = new QLabel(Form);
  scannerStatus->setObjectName(QString::fromUtf8("scannerStatus"));
  QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy2.setHorizontalStretch(0);
  sizePolicy2.setVerticalStretch(0);
  sizePolicy2.setHeightForWidth(
      scannerStatus->sizePolicy().hasHeightForWidth());
  scannerStatus->setSizePolicy(sizePolicy2);

  pinCodeLayout->addWidget(scannerStatus);
  bluetoothEnablePin = new QCheckBox(Form);
  bluetoothEnablePin->setObjectName(QString::fromUtf8("bluetoothEnablePin"));
  bluetoothEnablePin->setLayoutDirection(Qt::RightToLeft);
  bluetoothEnablePin->setCheckable(true);

  pinCodeLayout->addWidget(bluetoothEnablePin);

  bluetoothPin = new QLineEdit(Form);
  bluetoothPin->setObjectName(QString::fromUtf8("bluetoothPin"));
  bluetoothPin->setEnabled(false);
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(bluetoothPin->sizePolicy().hasHeightForWidth());
  bluetoothPin->setSizePolicy(sizePolicy);
  bluetoothPin->setMaximumSize(QSize(100, 16777215));
  QFont font1;
  font1.setPointSize(12);
  bluetoothPin->setFont(font1);

  pinCodeLayout->addWidget(bluetoothPin);

  verticalLayout->addLayout(pinCodeLayout);

  line = new QFrame(Form);
  line->setObjectName(QString::fromUtf8("line"));
  line->setFrameShape(QFrame::HLine);
  line->setFrameShadow(QFrame::Sunken);

  verticalLayout->addWidget(line);

  controlLayout = new QHBoxLayout();
  controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
  bluetoothNext = new QPushButton(Form);
  bluetoothNext->setObjectName(QString::fromUtf8("bluetoothNext"));
  bluetoothNext->setStyleSheet(QString::fromUtf8(""));
  QIcon icon;
  QString iconThemeName = QString::fromUtf8("arrow-left");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon = QIcon::fromTheme(iconThemeName);
  } else {
    icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  bluetoothNext->setIcon(icon);
  bluetoothNext->setFlat(false);

  controlLayout->addWidget(bluetoothNext);

  bluetoothCancel = new QPushButton(Form);
  bluetoothCancel->setObjectName(QString::fromUtf8("bluetoothCancel"));

  controlLayout->addWidget(bluetoothCancel);

  verticalLayout->addLayout(controlLayout);

  retranslateUi(Form);

  QMetaObject::connectSlotsByName(Form);
}

void bluetoothscaner::retranslateUi(QWidget *Form) {
  Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
  bluetoothScanTitle->setText(
      QCoreApplication::translate("Form", "Select Devices", nullptr));
  scannerStatus->setText(
      QCoreApplication::translate("Form", "scanning....", nullptr));
  bluetoothEnablePin->setText(
      QCoreApplication::translate("Form", "Manual PIN", nullptr));
  bluetoothPin->setPlaceholderText(
      QCoreApplication::translate("Form", "0000", nullptr));
  bluetoothNext->setText(QCoreApplication::translate("Form", "Next", nullptr));
  bluetoothCancel->setText(
      QCoreApplication::translate("Form", "Cancel", nullptr));
}

void bluetoothscaner::constructSignalSlot(QWidget *Form) {
  Q_UNUSED(Form);
  connect(bluetoothCancel, &QPushButton::clicked, [this]() {
    this->hide();
    emit notifyToBluetoothPage();
  });
  connect(this, &bluetoothscaner::notifyScannerDevices, this,
          &bluetoothscaner::bluetoothScanning);
}

void bluetoothscaner::bluetoothAnimationScanner() {
  QMovie *movie = new QMovie(this);
  movie->setFileName(":/sources/bluescanner.gif");
  movie->setSpeed(70);
  scannerani->setMovie(movie);
  movie->start();
  Q_EMIT(notifyScannerDevices());
}

void bluetoothscaner::bluetoothScanning() {
  // Create a discovery agent and connect to its signals
  QBluetoothDeviceDiscoveryAgent *discoveryAgent =
      new QBluetoothDeviceDiscoveryAgent(this);
  connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this,
          SLOT(deviceDiscoverd(QBluetoothDeviceInfo)));
  connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
          []() { qInfo() << "device discover finished "; });
  // Start a discovery
  discoveryAgent->start();

  //...
}

void bluetoothscaner::deviceDiscoverd(QBluetoothDeviceInfo deviceInfo) {
  QFont font;
  font.setPixelSize(18);
  bluetoothScannList->setFont(font);
  if (deviceInfo.isValid()) {
    if (model == nullptr) {
      model = new QStandardItemModel(this);
    }
    //    int row = model->rowCount();
    //    int colum = model->columnCount();
    //    model->insertRows(row, 1);
    //    QModelIndex index = model->index(row, colum);
    //    model->setData(index, deviceInfo.name(), Qt::TextEditable);
    bluetoothScannList->setModel(model);
    QIcon icon;
    model->appendRow(new QStandardItem(
        icon.fromTheme("preferences-system-bluetooth"), deviceInfo.name()));
  }
}
