#include "wifiapplet.h"
#include <QDebug>
#include <QDir>
#include <QLabel>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
wifiapplet::wifiapplet(QWidget *parent) : QWidget(parent) {
  menuWifi = new QMenu(parent);
  password_dialog = new QInputDialog(parent);
  password_dialog->setWindowIcon(
      QIcon::fromTheme("preferences-desktop-display"));
  password_dialog->move(1500, 40);
  this->load_nmcli_list();
  menuWifi->popup(QPoint(400, 500));
}

wifiapplet::~wifiapplet() { qInfo() << "QMenu get destroyed" << endl; }

bool wifiapplet::load_nmcli_list() {
  QProcess loader_wifi;
  QString args1{"device"}, args2{"wifi"}, args3{"list"};
  QStringList list_args;
  list_args.push_back(args1);
  list_args.push_back(args2);
  list_args.push_back(args3);
  loader_wifi.setProgram("nmcli");
  loader_wifi.setArguments(list_args);
  loader_wifi.startDetached();
  loader_wifi.waitForFinished();

  loader_wifi.close();
  return true;
}

void wifiapplet::showWifiList() {
  QNetworkConfigurationManager ncm;

  auto netcfgList = ncm.allConfigurations();

  menuWifi->clear();
  for (auto &x : netcfgList) {
    if (x.bearerType() == QNetworkConfiguration::BearerWLAN) {
      if (x.name() == "") {
        qWarning() << "Unknown" << endl;
      } else {
        menuWifi->addAction(QIcon::fromTheme("network-wireless"), x.name(),
                            [=]() { this->connectWifi(x.name()); });
      }
    }
  }

  menuWifi->popup(QPoint(QCursor::pos().x(), QCursor::pos().y() + 20));
}

void wifiapplet::connectWifi(const QString &actionName) {

  bool is_ok;
  QProcess wifi_connection_process;
  password_dialog->setWindowIcon(QIcon::fromTheme("network-wireless"));
  qDebug() << password_dialog->width();
  QString password = password_dialog->getText(
      nullptr, nullptr, nullptr, QLineEdit::Password, nullptr, &is_ok);
  if (is_ok && !password.isEmpty()) {
    qDebug() << "password validate" << password << endl;
  }
  wifi_connection_process.waitForStarted();
  wifi_connection_process.start(QString("nmcli"),
                                QStringList() << "device"
                                              << "wifi"
                                              << "connect" << actionName
                                              << "password" << password);
  wifi_connection_process.waitForFinished();
  qDebug() << wifi_connection_process.exitCode();
  wifi_connection_process.close();
  menuWifi->clear();
}
