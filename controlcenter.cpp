#include "controlcenter.h"
#include "mainwindow.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>
controlcenter::controlcenter(QWidget *parent)
    : QWidget(parent, Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint |
                          Qt::Popup | Qt::X11BypassWindowManagerHint) {
  this->setObjectName("control center applet");
  QScreen *screen = QGuiApplication::primaryScreen();
  m_width = screen->geometry().width();
  m_height = screen->geometry().height();
  resize(m_width * 0.25, m_height);
  MainWindow *windowParent = qobject_cast<MainWindow *>(parent);
  qInfo() << windowParent->getWifiBtn()->icon().name();
  timeStop = new QTimer(this);
  stackitem = new controlcenteritem(this);
  timeStop->setInterval(5000);
  networkservice *testcon = new networkservice(this);
  connect(timeStop, &QTimer::timeout, this, &controlcenter::close);
  connect(testcon, &networkservice::connectionStateChange, [&](bool status) {
    qDebug() << "Status: " << status << endl;
    if (status) {
      Q_EMIT(emitConnectedIcon());
      qInfo() << "enable state";
    } else {
      Q_EMIT(emitDisconnectedIcon());
      qInfo() << "disable state";
    }
  });
  connect(windowParent, &MainWindow::notifyWirelessPage,
          [&]() { stackitem->getStackedWidget()->setCurrentIndex(1); });
}

controlcenter::~controlcenter() {
  QString deleted_info =
      QString("%1 get destroyed in the heap").arg(this->objectName());
}

void controlcenter::testEmitSignal() {
  qInfo() << "Controlcenter Slot get called" << endl;
  Q_EMIT(sendIconChange());
}

void controlcenter::onSoundChange(int volume) {
  emit notifySoundChange(volume);
}

bool controlcenter::event(QEvent *event) {
  if (event->type() == QEvent::WindowDeactivate) {
    this->hide();
  }
  return QWidget::event(event);
}

void controlcenter::enterEvent(QEvent *event) {
  if (event->type() == QEvent::Enter) {
    qDebug() << "you enter concenter applet area";
    timeStop->stop();
  }
  return QWidget::enterEvent(event);
}

void controlcenter::leaveEvent(QEvent *event) {

  if (event->type() == QEvent::Leave) {
    qDebug() << "you left concenter applet area";
    timeStop->start();
  }
  return QWidget::leaveEvent(event);
}
