#include "timeapplet.h"
#include <QDebug>
timeapplet::timeapplet(QObject *parent) : QObject(parent) {

  QTimer *time = new QTimer(this);
  connect(time, &QTimer::timeout, this, &timeapplet::calculateTime);
  time->setInterval(1000);
}

void timeapplet::calculateTime() {
  QTime time = QTime::currentTime();
  qInfo() << time << endl;
  QString time_text = time.toString("hh : mm : ss");
  emit timeout(time_text);
}
