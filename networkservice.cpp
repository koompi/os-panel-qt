#include "networkservice.h"
#include <QtConcurrent/QtConcurrent>
networkservice::networkservice(QObject *parent) : QObject(parent) {
  qInfo() << "network service starting.....";
  checkIsOnline();
}
QVector<QString> networkservice::getNetworkInfo() {
  QVector<QString> arrayOfaddress;
  QString macAddress;
  foreach (const QNetworkInterface &netInterface,
           QNetworkInterface::allInterfaces()) {
    QNetworkInterface::InterfaceFlags flags = netInterface.flags();
    if ((bool)(flags & QNetworkInterface::IsRunning) &&
        !(bool)(flags & QNetworkInterface::IsLoopBack)) {
      foreach (const QNetworkAddressEntry &address,
               netInterface.addressEntries()) {
        if (address.ip().protocol() == QAbstractSocket::IPv4Protocol) {

          arrayOfaddress.push_back(address.ip().toString());
          arrayOfaddress.push_back(netInterface.hardwareAddress());
          arrayOfaddress.push_back(address.netmask().toString());
        }
        if (address.ip().protocol() == QAbstractSocket::IPv6Protocol) {

          QStringList ip6andinterface = address.ip().toString().split('%');
          arrayOfaddress.push_back(ip6andinterface.first());
          arrayOfaddress.push_back(ip6andinterface.last());
        }
      }
    }
  }
  return arrayOfaddress;
}

void networkservice::disconnectState(const QString &ssid) {
  QProcess process;
  process.setProgram("nmcli");
  process.setArguments(QStringList() << "con"
                                     << "down" << ssid);
  process.start();
  process.waitForFinished(-1);
  process.close();
}

bool networkservice::checkIsOnline() {
  QNetworkConfigurationManager *testInternet =
      new QNetworkConfigurationManager(this);
  connect(testInternet, &QNetworkConfigurationManager::onlineStateChanged,
          [&]() { emit connectionStateChange(testInternet->isOnline()); });
  return testInternet->isOnline();
}
