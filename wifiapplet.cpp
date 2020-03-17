#include "wifiapplet.h"
#include <QDebug>
#include <QDir>
#include <QLabel>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHostInfo>

wifiapplet::wifiapplet(QWidget *parent) : QWidget(parent) {
    QtConcurrent::run([&]() {
    getActiveConnection();
    emit sendwifiList(getWirelessName_signal());
  });
}

wifiapplet::~wifiapplet() { qInfo() << "QMenu get destroyed" << endl; }

void wifiapplet::getActiveConnection() {
  QProcess activeWifi;
  activeWifi.setProgram("nmcli");
  QStringList args;
  args << "-t"
       << "-f"
       << "SSID,SIGNAL"
       << "device"
       << "wifi"
       << "list";
  activeWifi.setArguments(args);
  activeWifi.start(QIODevice::ReadOnly);
  activeWifi.waitForStarted();
  activeWifi.waitForFinished();
  qDebug() << activeWifi.exitCode() << endl;
  QString output(activeWifi.readAllStandardOutput());
  QList<QStringList> list_signal;
  foreach (QString wifi,
           output.split('\n', QString::SplitBehavior::SkipEmptyParts,
                        Qt::CaseSensitivity::CaseSensitive)) {
    list_signal.push_back(
        wifi.split(':', QString::SplitBehavior::SkipEmptyParts));
  }
  activeWifi.waitForReadyRead();
  setWirelessName_signal(list_signal);
  activeWifi.close();
}

QList<QStringList> wifiapplet::getWirelessName_signal() const {
  return WirelessName_signal;
}

void wifiapplet::setWirelessName_signal(const QList<QStringList> &value) {
    WirelessName_signal = value;
}




int wifiapplet::connectWifi(const QString &name, const QString &password) {

  QProcess wifiConnPro;
  if (!password.isEmpty()) {
    qDebug() << "password validate" << password << endl;
  }
  wifiConnPro.waitForStarted();
  wifiConnPro.setProgram("nmcli");
  wifiConnPro.setArguments(QStringList() <<"device"<<"wifi"<<"connect"<< name <<"password"<< password);
  wifiConnPro.start();
  wifiConnPro.waitForFinished();
  wifiConnPro.close();
  return wifiConnPro.exitCode();
}
