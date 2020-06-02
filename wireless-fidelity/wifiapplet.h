#ifndef WIFIAPPLET_H
#define WIFIAPPLET_H

#include <QNetworkConfiguration>
#include <QtGui/QFont>

#include <QNetworkSession>
#include <QPointer>
#include <QProcess>
#include <QThread>
#include <QToolButton>
#include <QWidget>
#include <QWidgetAction>
#include <QtConcurrent/QtConcurrent>

#include <QNetworkConfigurationManager>

class wifiapplet : public QWidget {
  Q_OBJECT

public:
  explicit wifiapplet(QWidget *parent = nullptr);

  virtual ~wifiapplet();
  QThread newThread;

  void getActiveConnection();
  QList<QStringList> getWirelessName_signal() const;
  void setWirelessName_signal(const QList<QStringList> &value);
  QList<QStringList> WirelessName_signal;

signals:
  void sendwifiList(QList<QStringList> list);
  void requiredIconChanged();

public
  Q_SLOT : int connectWifi(const QString &, const QString &);

private:
  QToolButton *recwifiBtn;
};

#endif // WIFIAPPLET_H
