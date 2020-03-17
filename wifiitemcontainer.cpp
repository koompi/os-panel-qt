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
  wifiListView->setGeometry(QRect(10, 140, 451, 381));
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
  // network properties:
  networkPropsName = new QLabel(Form);
  networkPropsName->setObjectName(QString::fromUtf8("networkPropsName"));
  networkPropsName->setGeometry(QRect(10, 600, 171, 19));
  widget = new QWidget(Form);
  widget->setObjectName(QString::fromUtf8("widget"));
  widget->setGeometry(QRect(10, 650, 441, 21));
  ipfourLayout = new QHBoxLayout(widget);
  ipfourLayout->setSpacing(10);
  ipfourLayout->setObjectName(QString::fromUtf8("ipfourLayout"));
  ipfourLayout->setSizeConstraint(QLayout::SetFixedSize);
  ipfourLayout->setContentsMargins(0, 0, 0, 0);
  ipfourName = new QLabel(widget);
  ipfourName->setObjectName(QString::fromUtf8("ipfourName"));
  QSizePolicy netPropertiespolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
  netPropertiespolicy.setHorizontalStretch(0);
  netPropertiespolicy.setVerticalStretch(0);
  netPropertiespolicy.setHeightForWidth(
      ipfourName->sizePolicy().hasHeightForWidth());
  ipfourName->setSizePolicy(netPropertiespolicy);

  ipfourLayout->addWidget(ipfourName);

  ipFourAddr = new QLabel(widget);
  ipFourAddr->setObjectName(QString::fromUtf8("ipFourAddr"));

  ipfourLayout->addWidget(ipFourAddr);

  widget1 = new QWidget(Form);
  widget1->setObjectName(QString::fromUtf8("widget1"));
  widget1->setGeometry(QRect(10, 690, 441, 21));
  ipsixLayout = new QHBoxLayout(widget1);
  ipsixLayout->setObjectName(QString::fromUtf8("ipsixLayout"));
  ipsixLayout->setContentsMargins(0, 0, 0, 0);
  ipSixName = new QLabel(widget1);
  ipSixName->setObjectName(QString::fromUtf8("ipSixName"));
  netPropertiespolicy.setHeightForWidth(
      ipSixName->sizePolicy().hasHeightForWidth());
  ipSixName->setSizePolicy(netPropertiespolicy);

  ipsixLayout->addWidget(ipSixName);

  ipSixAddr = new QLabel(widget1);
  ipSixAddr->setObjectName(QString::fromUtf8("ipSixAddr"));

  ipsixLayout->addWidget(ipSixAddr);

  widget2 = new QWidget(Form);
  widget2->setObjectName(QString::fromUtf8("widget2"));
  widget2->setGeometry(QRect(10, 730, 441, 21));
  subnetLayout = new QHBoxLayout(widget2);
  subnetLayout->setObjectName(QString::fromUtf8("subnetLayout"));
  subnetLayout->setContentsMargins(0, 0, 0, 0);
  subNetName = new QLabel(widget2);
  subNetName->setObjectName(QString::fromUtf8("subNetName"));
  netPropertiespolicy.setHeightForWidth(
      subNetName->sizePolicy().hasHeightForWidth());
  subNetName->setSizePolicy(netPropertiespolicy);

  subnetLayout->addWidget(subNetName);

  subNetMask = new QLabel(widget2);
  subNetMask->setObjectName(QString::fromUtf8("subNetMask"));

  subnetLayout->addWidget(subNetMask);

  widget3 = new QWidget(Form);
  widget3->setObjectName(QString::fromUtf8("widget3"));
  widget3->setGeometry(QRect(10, 770, 441, 21));
  macaddrLayout = new QHBoxLayout(widget3);
  macaddrLayout->setObjectName(QString::fromUtf8("macaddrLayout"));
  macaddrLayout->setContentsMargins(0, 0, 0, 0);
  macName = new QLabel(widget3);
  macName->setObjectName(QString::fromUtf8("macName"));
  netPropertiespolicy.setHeightForWidth(
      macName->sizePolicy().hasHeightForWidth());
  macName->setSizePolicy(netPropertiespolicy);

  macaddrLayout->addWidget(macName);

  macAddr = new QLabel(widget3);
  macAddr->setObjectName(QString::fromUtf8("macAddr"));
  macaddrLayout->addWidget(macAddr);
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
  networkPropsName->setText(
      QCoreApplication::translate("Form", "Network Properties:", nullptr));
  ipfourName->setText(
      QCoreApplication::translate("Form", "IPv4 address:", nullptr));
  ipFourAddr->setText(
      QCoreApplication::translate("Form", "no connection", nullptr));
  ipSixName->setText(
      QCoreApplication::translate("Form", "IPv6 address:", nullptr));
  ipSixAddr->setText(
      QCoreApplication::translate("Form", "no connection", nullptr));
  subNetName->setText(
      QCoreApplication::translate("Form", "sub netmask:", nullptr));
  subNetMask->setText(
      QCoreApplication::translate("Form", "no connection", nullptr));
  macName->setText(
      QCoreApplication::translate("Form", "MAC address:", nullptr));
  macAddr->setText(
      QCoreApplication::translate("Form", "no connection", nullptr));
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

void wifiitemcontainer::onNotifyAddress() {
  networkservice *networkAddressService = new networkservice(this);
  if (networkAddressService->checkIsOnline()) {
    QList<QString> fourAddresses = networkAddressService->getNetworkInfo();
    ipFourAddr->setText(fourAddresses.at(0));
    macAddr->setText(fourAddresses.at(1));
    subNetMask->setText(fourAddresses.at(2));
    ipSixAddr->setText(fourAddresses.at(3));
  } else {
    ipFourAddr->setText("Please connect to the internet");
    macAddr->setText("Please connect to the internet");
    subNetMask->setText("Please connect to the internet");
    ipSixAddr->setText("Please connect to the internet");
  }
  qInfo() << "Slot react back.....";
}

void wifiitemcontainer::callConnectWifi(const QString &ssid,
                                        const QString &pass) {
  wifiManager->connectWifi(ssid, pass);
  Q_EMIT(connectionFinished());
}
