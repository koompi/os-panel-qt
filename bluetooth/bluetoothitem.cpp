#include "bluetoothitem.h"
#include <QDebug>
#include <QFrame>
#include <QPainter>
#include <QSpacerItem>
#include <QStyleOption>
QLabel *bluetoothitem::getLabel_address() const { return label_address; }

void bluetoothitem::setLabel_address(QLabel *value) { label_address = value; }

QLabel *bluetoothitem::getLabel_pair() const { return label_pair; }

void bluetoothitem::setLabel_pair(QLabel *value) { label_pair = value; }

QLabel *bluetoothitem::getLabel_trust() const { return label_trust; }

void bluetoothitem::setLabel_trust(QLabel *value) { label_trust = value; }

QLabel *bluetoothitem::getLabel_adapter() const { return label_adapter; }

void bluetoothitem::setLabel_adapter(QLabel *value) { label_adapter = value; }

void bluetoothitem::changeTextAndPosition() {
  if (BluetoothCon->text().toLower() == "connect") {
    BluetoothCon->setText(QString("Disconnect"));
  }
}

bluetoothitem::bluetoothitem(QWidget *parent) : QWidget(parent) {
  setupUi(this);
  initAction();
}

bluetoothitem::~bluetoothitem() {
  qInfo() << "bluetooth item delete: " << this;
}

void bluetoothitem::setupUi(QWidget *BluetoothItem) {
  if (BluetoothItem->objectName().isEmpty())
    BluetoothItem->setObjectName(QString::fromUtf8("BluetoothItem"));
  BluetoothItem->resize(405, 67);
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(BluetoothItem->sizePolicy().hasHeightForWidth());
  BluetoothItem->setSizePolicy(sizePolicy);
  main_layout = new QVBoxLayout(BluetoothItem);
  main_layout->setObjectName(QString::fromUtf8("main_layout"));
  blue_main_info = new QVBoxLayout();
  blue_main_info->setObjectName(QString::fromUtf8("blue_main_info"));
  BluetoothItemLayout = new QHBoxLayout();
  BluetoothItemLayout->setObjectName(QString::fromUtf8("BluetoothItemLayout"));
  BluetoothIcon = new QToolButton(BluetoothItem);
  BluetoothIcon->setObjectName(QString::fromUtf8("BluetoothIcon"));
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

  BluetoothTextLayout = new QVBoxLayout();
  BluetoothTextLayout->setSpacing(0);
  BluetoothTextLayout->setObjectName(QString::fromUtf8("BluetoothTextLayout"));
  BluetoothTextLayout->setContentsMargins(10, -1, -1, -1);
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
  BluetoothCon->setVisible(false);
  BluetoothCon->setObjectName(QString::fromUtf8("BluetoothCon"));
  QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(BluetoothCon->sizePolicy().hasHeightForWidth());
  BluetoothCon->setSizePolicy(sizePolicy1);
  BluetoothCon->setMinimumSize(QSize(0, 0));
  BluetoothCon->setMaximumSize(QSize(120, 16777215));
  BluetoothCon->setFocusPolicy(Qt::NoFocus);
  BluetoothCon->setLayoutDirection(Qt::LeftToRight);
  BluetoothCon->setStyleSheet(QString::fromUtf8("background:transparent;"));
  BluetoothCon->setFlat(false);

  BluetoothItemLayout->addWidget(BluetoothCon);
  blue_main_info->addLayout(BluetoothItemLayout);

  blue_props_layout = new QVBoxLayout();
  blue_props_layout->setObjectName(QString::fromUtf8("blue_props_layout"));
  blue_main_info->addLayout(blue_props_layout);
  main_layout->addLayout(blue_main_info);
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

void bluetoothitem::mousePressEvent(QMouseEvent *event) {
  if (!blue_info_dialog) {
    blue_info_dialog = new QDialog(this, Qt::Popup);
    connect(blue_info_dialog, &QDialog::finished, [&]() {
      this->BluetoothCon->setVisible(false);
      qDebug() << "dialog hide";
    });

    dim = QGuiApplication::primaryScreen();
    QVBoxLayout *blue_info_layout = new QVBoxLayout(blue_info_dialog);
    label_address =
        new QLabel(QString("Adress: %0").arg(getBluetoothName()->text()),
                   blue_info_dialog);
    label_pair = new QLabel(QString("Paired: %0").arg("Yes"), blue_info_dialog);
    label_trust =
        new QLabel(QString("Trusted: %0").arg("Yes"), blue_info_dialog);
    label_adapter =
        new QLabel(QString("Adapter: %0").arg("PIQT hco-5"), blue_info_dialog);
    blue_info_layout->addWidget(label_address);
    blue_info_layout->addWidget(label_pair);
    blue_info_layout->addWidget(label_trust);
    blue_info_layout->addWidget(label_adapter);

    QPushButton *pressbtn = new QPushButton("p&ress", blue_info_dialog);
    blue_info_layout->addWidget(pressbtn);
    connect(pressbtn, &QPushButton::clicked, blue_info_dialog, &QDialog::close);
    anim = new QPropertyAnimation(blue_info_dialog, "geometry", this);
  }
  anim->setDuration(500);                      // will take 500 miliseconds
  anim->setEasingCurve(QEasingCurve::OutExpo); // just demonstration, there are
                                               // a lot of curves to choose
  qDebug() << "bluetooth item width: " << this->width() << endl;
  qDebug() << "bluetooth item height: " << this->height() << endl;
  anim->setStartValue(
      QRect(dim->geometry().width() - this->width() + 60, 0, 300, 200));
  anim->setEndValue(
      QRect(dim->geometry().width() - this->width() + 60, 500, 300, 200));
  anim->start(QPropertyAnimation::DeletionPolicy::KeepWhenStopped);
  emit requestData(this);
  blue_info_dialog->raise();
  blue_info_dialog->show();
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

void bluetoothitem::paintEvent(QPaintEvent *event) {
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

  QWidget::paintEvent(event);
}

QLabel *bluetoothitem::getBluetoothName() const { return BluetoothName; }

void bluetoothitem::setBluetoothName(QLabel *value) { BluetoothName = value; }

QToolButton *bluetoothitem::getBluetoothIcon() const { return BluetoothIcon; }

void bluetoothitem::setBluetoothIcon(QToolButton *value) {
  BluetoothIcon = value;
}

void bluetoothitem::initAction() {
  connect(BluetoothCon, &QPushButton::clicked, [&]() {
    if (BluetoothCon->text() == QString("Connect"))
      emit requireBluetoothConnection(getBluetoothName()->text());
    else
      emit requireBluetoothDisconnect(getBluetoothName()->text());
  });
}
