#ifndef TIMEAPPLET_H
#define TIMEAPPLET_H

#include <QObject>
#include <QTime>
#include <QTimer>
class timeapplet : public QObject {
  Q_OBJECT
public:
  explicit timeapplet(QObject *parent = nullptr);
  void calculateTime();
signals:
  void timeout(QString value);
};

#endif // TIMEAPPLET_H
