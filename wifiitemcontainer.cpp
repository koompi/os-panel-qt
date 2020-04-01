#include "wifiitemcontainer.h"
#include <QMovie>
wifiitemcontainer::wifiitemcontainer(QWidget *parent) : QWidget(parent) {
  setupUi(this);
  connect(networkBackBtn, &QToolButton::clicked,
          [&]() { parentStacked->setCurrentIndex(0); });
  wifiManager = new wifiapplet(this);
  connect(wifiManager, &wifiapplet::sendwifiList, this,
          &wifiitemcontainer::getwifiList,
          Qt::ConnectionType::QueuedConnection);
}
void wifiitemcontainer::setupUi(QWidget *Form) {
  if (Form->objectName().isEmpty())
    Form->setObjectName(QString::fromUtf8("Form"));
  Form->setEnabled(true);
  Form->resize(471, 891);
  layoutWidget = new QWidget(Form);
  layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
  layoutWidget->setGeometry(QRect(10, 70, 451, 36));
  wificontrolLayout = new QHBoxLayout(layoutWidget);
  wificontrolLayout->setObjectName(QString::fromUtf8("wificontrolLayout"));
  wificontrolLayout->setContentsMargins(0, 0, 0, 0);
  checkGroupLayout = new QHBoxLayout();
  checkGroupLayout->setObjectName(QString::fromUtf8("checkGroupLayout"));
  wifiCheck = new QCheckBox(layoutWidget);
  wifiCheck->setObjectName(QString::fromUtf8("wifiCheck"));
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(wifiCheck->sizePolicy().hasHeightForWidth());
  wifiCheck->setSizePolicy(sizePolicy);
  wifiCheck->setChecked(true);

  checkGroupLayout->addWidget(wifiCheck);

  airplaneCheck = new QCheckBox(layoutWidget);
  airplaneCheck->setObjectName(QString::fromUtf8("airplaneCheck"));

  checkGroupLayout->addWidget(airplaneCheck);

  wificontrolLayout->addLayout(checkGroupLayout);

  searchBtn = new QToolButton(layoutWidget);
  searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
  QIcon icon;
  QString iconThemeName = QString::fromUtf8("search");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon = QIcon::fromTheme(iconThemeName);
  } else {
    icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
  }
  searchBtn->setIcon(icon);
  searchBtn->setAutoRaise(true);

  wificontrolLayout->addWidget(searchBtn);

  label = new QLabel(Form);
  label->setObjectName(QString::fromUtf8("label"));
  label->setGeometry(QRect(190, 20, 101, 21));
  QFont font;
  font.setPointSize(18);
  label->setFont(font);
  label->setAlignment(Qt::AlignCenter);
  wifiListView = new QListWidget(Form);
  wifiListView->setObjectName(QString::fromUtf8("wifiListView"));
  wifiListView->setGeometry(QRect(10, 140, 451, 890));
  wifiListView->setFrameShape(QFrame::NoFrame);
  wifiListView->setFrameShadow(QFrame::Raised);
  layoutWidget_2 = new QWidget(Form);
  layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
  layoutWidget_2->setGeometry(QRect(10, 540, 451, 36));

  networkBackBtn = new QToolButton(Form);
  networkBackBtn->setObjectName(QString::fromUtf8("networkBackBtn"));
  networkBackBtn->setGeometry(QRect(10, 20, 41, 34));
  QIcon icon1(QIcon::fromTheme(QString::fromUtf8("draw-arrow-back")));
  networkBackBtn->setIcon(icon1);
  networkBackBtn->setAutoRaise(true);
  retranslateUi(Form);

  QMetaObject::connectSlotsByName(Form);
}

void wifiitemcontainer::retranslateUi(QWidget *Form) {

  Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
  //  wifiCheck->setText(QCoreApplication::translate("Form", "Wifi", nullptr));
  //  airplaneCheck->setText(
  //      QCoreApplication::translate("Form", "Airplane", nullptr));
  wifiCheck->setIcon(
      QIcon::fromTheme(QString::fromUtf8("network-wireless-connected-100")));
  airplaneCheck->setIcon(
      QIcon::fromTheme(QString::fromUtf8("network-wireless-disconnected")));
  searchBtn->setText(QCoreApplication::translate("Form", "...", nullptr));
  label->setText(QCoreApplication::translate("Form", "Network", nullptr));
  networkBackBtn->setText(QCoreApplication::translate("Form", "...", nullptr));
}

QStackedWidget *wifiitemcontainer::getParentStacked() const {
  return parentStacked;
}

void wifiitemcontainer::setParentStacked(QStackedWidget *value) {
  parentStacked = value;
}

QList<QStringList> wifiitemcontainer::getActiveWireless_signal() const {
  return activeWireless_signal;
}

void wifiitemcontainer::setActiveWireless_signal(
    const QList<QStringList> &value) {
  activeWireless_signal = value;
}

void wifiitemcontainer::getwifiList(QList<QStringList> list) {
  qDebug() << list << endl;
  activeWireless_signal = list;
  foreach (QStringList name, list) {
    QListWidgetItem *listWidgetItem = new QListWidgetItem(wifiListView);
    listItem.push_back(*listWidgetItem);
    wifiListView->addItem(listWidgetItem);
    wifiItemModel *customWifi = new wifiItemModel(this);
    customWifi->setWificontainer(listWidgetItem);
    connect(customWifi, &wifiItemModel::requireConnection, this,
            &wifiitemcontainer::callConnectWifi);
    connect(customWifi, &wifiItemModel::notifyItemModelPress, this,
            &wifiitemcontainer::onNotifyAddress);
    int signal_level = name.last().toInt();
    if (signal_level == 0) {
      customWifi->getWifiIcon()->setIcon(
          QIcon::fromTheme("network-wireless-connected-00"));
    } else if (signal_level > 0 && name.last() < 25) {
      customWifi->getWifiIcon()->setIcon(
          QIcon::fromTheme("network-wireless-connected-25"));
    } else if (signal_level > 25 && signal_level <= 50) {
      customWifi->getWifiIcon()->setIcon(
          QIcon::fromTheme("network-wireless-connected-50"));
    } else if (signal_level > 50 && signal_level <= 75) {
      customWifi->getWifiIcon()->setIcon(
          QIcon::fromTheme("network-wireless-connected-75"));
    } else {
      customWifi->getWifiIcon()->setIcon(
          QIcon::fromTheme("network-wireless-connected-100"));
    }
    customWifi->getLabelWifi()->setText(name.first());
    listWidgetItem->setSizeHint(customWifi->sizeHint());
    wifiListView->setItemWidget(listWidgetItem, customWifi);
  }
}

void wifiitemcontainer::onNotifyAddress() {}

void wifiitemcontainer::callConnectWifi(const QString &ssid,
                                        const QString &pass) {
  wifiManager->connectWifi(ssid, pass);
  Q_EMIT(connectionFinished());
}
