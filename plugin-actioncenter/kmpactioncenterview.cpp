#include "kmpactioncenterview.h"
#include <QDebug>
#include <QEvent>
#include <QGuiApplication>
#include <QScreen>
KMPActionCenterView::KMPActionCenterView(QWidget *parent) : QWidget(parent) {}

QSize KMPActionCenterView::screenSize() const {
  QScreen *screen = QGuiApplication::primaryScreen();
  return QSize(screen->geometry().width(), screen->geometry().height());
}

bool KMPActionCenterView::eventFilter(QObject *watched, QEvent *event) {
  if (watched == this && event != nullptr) {
    if (event->type() == QEvent::WindowDeactivate) {
      this->hide();
    } else if (event->type() == QEvent::Enter) {
      qInfo() << "you enter " << endl;
    } else if (event->type() == QEvent::Leave) {
      qInfo() << "you leave " << endl;
    }
  }
  return QWidget::eventFilter(watched, event);
}
