#include "bluetoothitem.h"
#include <QDebug>
#include <QSpacerItem>

bluetoothitem::bluetoothitem(QWidget *parent) : QWidget(parent) {
  setupUi(this);
  init();
  initAction();
}

bluetoothitem::~bluetoothitem() {
  qInfo() << "bluetooth item delete: " << this;
}

void bluetoothitem::setupUi(QWidget *BluetoothItem) {

  if (BluetoothItem->objectName().isEmpty())
    BluetoothItem->setObjectName(QString::fromUtf8("BluetoothItem"));
  BluetoothItem->resize(400, 63);

  BluetoothLayout = new QHBoxLayout(BluetoothItem);
  BluetoothLayout->setObjectName(QString::fromUtf8("BluetoothLayout"));
  BluetoothItemLayout = new QHBoxLayout();
  BluetoothItemLayout->setObjectName(QString::fromUtf8("BluetoothItemLayout"));
  BluetoothIcon = new QToolButton(BluetoothItem);
  BluetoothIcon->setObjectName(QString::fromUtf8("BluetoothIcon"));
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(BluetoothIcon->sizePolicy().hasHeightForWidth());
  BluetoothIcon->setSizePolicy(sizePolicy);
  BluetoothIcon->setMaximumSize(QSize(50, 16777215));
  BluetoothIcon->setStyleSheet(QString::fromUtf8("border:0px;"));
  QIcon icon;
  QString iconThemeName = QString::fromUtf8("preferences-system-bluetooth");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon = QIcon::fromTheme(iconThemeName);
  } else {
    icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  BluetoothIcon->setIcon(icon);
  BluetoothIcon->setIconSize(QSize(32, 32));
  BluetoothIcon->setAutoRaise(true);

  BluetoothItemLayout->addWidget(BluetoothIcon);
  BluetoothItemLayout->addSpacing(10);
  BluetoothTextLayout = new QVBoxLayout();
  BluetoothTextLayout->setSpacing(0);
  BluetoothTextLayout->setObjectName(QString::fromUtf8("BluetoothTextLayout"));
  BluetoothName = new QLabel(BluetoothItem);
  BluetoothName->setObjectName(QString::fromUtf8("BluetoothName"));
  QFont font;
  font.setPointSize(12);
  font.setBold(true);
  font.setWeight(75);
  BluetoothName->setFont(font);

  BluetoothTextLayout->addWidget(BluetoothName);

  BluetoothStatus = new QLabel(BluetoothItem);
  BluetoothStatus->setObjectName(QString::fromUtf8("BluetoothStatus"));

  BluetoothTextLayout->addWidget(BluetoothStatus);

  BluetoothItemLayout->addLayout(BluetoothTextLayout);

  BluetoothCon = new QPushButton(BluetoothItem);
  BluetoothCon->setObjectName(QString::fromUtf8("BluetoothCon"));
  BluetoothCon->setVisible(false);
  QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(BluetoothCon->sizePolicy().hasHeightForWidth());
  BluetoothCon->setSizePolicy(sizePolicy1);
  BluetoothCon->setMinimumSize(QSize(0, 0));
  BluetoothCon->setMaximumSize(QSize(120, 16777215));
  BluetoothCon->setFocusPolicy(Qt::NoFocus);
  BluetoothCon->setLayoutDirection(Qt::LeftToRight);
  BluetoothCon->setStyleSheet(QString::fromUtf8("background:white;"));
  BluetoothCon->setFlat(false);

  BluetoothItemLayout->addWidget(BluetoothCon);

  BluetoothLayout->addLayout(BluetoothItemLayout);

  retranslateUi(BluetoothItem);

  QMetaObject::connectSlotsByName(BluetoothItem);
}

void bluetoothitem::retranslateUi(QWidget *BluetoothItem) {
  BluetoothItem->setWindowTitle(
      QCoreApplication::translate("BluetoothItem", "Form", nullptr));
  BluetoothIcon->setText(
      QCoreApplication::translate("BluetoothItem", "...", nullptr));
  BluetoothName->setText(
      QCoreApplication::translate("BluetoothItem", "OPP F11 Pro", nullptr));
  BluetoothStatus->setText(QCoreApplication::translate(
      "BluetoothItem", "send file, network", nullptr));
  BluetoothCon->setText(
      QCoreApplication::translate("BluetoothItem", "Connect", nullptr));
}

void bluetoothitem::extendHeightLayout() {}

void bluetoothitem::resetHeightLayout() {}

void bluetoothitem::mousePressEvent(QMouseEvent *event) {
  toggleState = true;
  if (toggleState) {
    extendHeightLayout();
    toggleState = !toggleState;
  } else {
    resetHeightLayout();
    toggleState = !toggleState;
  }
  return QWidget::mousePressEvent(event);
}

void bluetoothitem::enterEvent(QEvent *event) {
  if (event->type() == QEvent::Enter) {
    BluetoothCon->setVisible(true);
  }
  return QWidget::enterEvent(event);
}

void bluetoothitem::leaveEvent(QEvent *event) {
  if (event->type() == QEvent::Leave) {
    BluetoothCon->setVisible(false);
  }
  return QWidget::enterEvent(event);
}

QLabel *bluetoothitem::getBluetoothName() const { return BluetoothName; }

void bluetoothitem::setBluetoothName(QLabel *value) { BluetoothName = value; }

QToolButton *bluetoothitem::getBluetoothIcon() const { return BluetoothIcon; }

void bluetoothitem::setBluetoothIcon(QToolButton *value) {
  BluetoothIcon = value;
}
void bluetoothitem::init() {}

void bluetoothitem::initAction() {
  connect(BluetoothCon, &QPushButton::clicked, [&]() {
    if (BluetoothCon->text() == QString("Connect"))
      emit requireBluetoothConnection(getBluetoothName()->text());
    else
      emit requireBluetoothDisconnect(getBluetoothName()->text());
  });
}
