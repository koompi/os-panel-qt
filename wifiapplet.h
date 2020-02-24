#ifndef WIFIAPPLET_H
#define WIFIAPPLET_H

#include <QFont>
#include <QFrame>
#include <QInputDialog>
#include <QMenu>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QObject>
#include <QPointer>
#include <QProcess>
#include <QThread>
#include <QWidget>
#include <QWidgetAction>
class wifiapplet : public QWidget {
  Q_OBJECT
public:
  explicit wifiapplet(QWidget *parent = nullptr);
  virtual ~wifiapplet();
  bool load_nmcli_list();
public slots:
  void showWifiList();
  void connectWifi(const QString &);
signals:

private:
  QMenu *menuWifi = nullptr;
  QInputDialog *password_dialog = nullptr;
};

#endif // WIFIAPPLET_H
