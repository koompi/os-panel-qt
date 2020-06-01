#include "kmpactioncenterpopup.h"
#include "../panel/lxqtpanel.h"
#include "kmpcontrolcenteritem.h"
#include <QDebug>
#include <QEvent>
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
KMPActionCenterPopUP::KMPActionCenterPopUP(QWidget *parent)
    : QWidget(parent, Qt::Dialog | Qt::WindowStaysOnTopHint |
                          Qt::CustomizeWindowHint | Qt::Popup |
                          Qt::X11BypassWindowManagerHint) {
  installEventFilter(this);
  actionItem = new KMPControlCenterItem(this);
  QVBoxLayout *actionLayout = new QVBoxLayout(actionItem);
  setStyleSheet(QStringLiteral("background-color:#2f3640;"));
  setLayout(actionLayout);
}

bool KMPActionCenterPopUP::event(QEvent *event) {

  if (event->type() == QEvent::WindowDeactivate) {
    hide();
  }
  return QWidget::event(event);
}

bool KMPActionCenterPopUP::eventFilter(QObject *watched, QEvent *event) {

  if (watched == this) {
    if (event->type() == QEvent::Show) {
      qInfo() << "SHOW:";
      emit signal_show_window();
    } else if (event->type() == QEvent::Hide) {
      qInfo() << "HIDE:";
      emit signal_hide_window();
    } else if (event->type() == QEvent::Enter) {
      qInfo() << "ENTER:";
    } else if (event->type() == QEvent::Leave) {
      qInfo() << "LEAVE:";
    }
  }
  return QWidget::eventFilter(this, event);
}
