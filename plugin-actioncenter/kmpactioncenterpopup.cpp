#include "kmpactioncenterpopup.h"
#include "../panel/lxqtpanel.h"
#include <QDebug>
#include <QEvent>

#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
KMPActionCenterPopUP::KMPActionCenterPopUP(QWidget *parent)
    : QDialog(parent, Qt::Dialog | Qt::WindowStaysOnTopHint |
                          Qt::CustomizeWindowHint | Qt::Popup |
                          Qt::X11BypassWindowManagerHint) {
  installEventFilter(this);
  QVBoxLayout *actionLayout = new QVBoxLayout(this);
  QGridLayout *actionGridLayout = new QGridLayout(this);
  actionLayout->addLayout(actionGridLayout, 10);
  for (int i = 0; i < 5; i++) {
    QToolButton *item = new QToolButton(this);
    item->setFixedSize(100, 100);
    item->setAutoRaise(true);
    item->setIcon(QIcon::fromTheme(QStringLiteral("network-wireless")));
    actionGridLayout->addWidget(item);
  }
}

bool KMPActionCenterPopUP::event(QEvent *event) {

  if (event->type() == QEvent::WindowDeactivate) {
    hide();
  }
  return QDialog::event(event);
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
  return QDialog::eventFilter(this, event);
}
