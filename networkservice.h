#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QHostAddress>
#include <QNetworkConfigurationManager>
#include <QNetworkInterface>
#include <QProcess>
#include <QWidget>

class networkservice : public QObject {
  Q_OBJECT
public:
  explicit networkservice(QObject *parent = nullptr);
  bool checkIsOnline();
  QList<QString> getNetworkInfo();
public Q_SLOTS:
  void disconnectState(const QString &ssid);
signals:
  void connectionStateChange(bool status);
};

#endif // NETWORKSERVICE_H
