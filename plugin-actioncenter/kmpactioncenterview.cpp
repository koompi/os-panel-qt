#include "kmpactioncenterview.h"
#include "../panel/ilxqtpanelplugin.h"
#include "../panel/lxqtpanel.h"
#include <QDebug>
#include <QEvent>
#include <QGuiApplication>
#include <QScreen>
KMPActionCenterView::KMPActionCenterView(ILXQtPanelPlugin *plugin,
                                         ILXQtPanel *m_panel, QWidget *parent)
    : QToolButton(parent), m_plugin(plugin), m_panel(plugin->panel()) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  handleActionCenterIconChanged(QStringLiteral("preferences"));
  setAutoRaise(true);
  setMouseTracking(true);
  setPanel(m_panel);
  qInfo() << panel()->position() << endl;
  m_actionPopup = new KMPActionCenterPopUP(this);
  connect(this, &QToolButton::clicked, this,
          &KMPActionCenterView::toggleActionCenter);

  connect(m_actionPopup, &KMPActionCenterPopUP::signal_show_window, this,
          &KMPActionCenterView::handleShowWindow);
}

KMPActionCenterView::~KMPActionCenterView() {}

QSize KMPActionCenterView::screenSize() const {
  QScreen *screen = QGuiApplication::primaryScreen();
  return QSize(screen->geometry().width(), screen->geometry().height());
}

void KMPActionCenterView::buildActionCenter() {
  m_actionPopup->setFixedSize(
      screenSize().width() * 0.20,
      screenSize().height() -
          (dynamic_cast<LXQtPanel *>(m_panel)->panelSize()));
  QRect showSize = m_plugin->calculatePopupWindowPos(m_actionPopup->size());
  m_actionPopup->move(showSize.x(), showSize.y());
}

ILXQtPanel *KMPActionCenterView::panel() const { return m_panel; }

void KMPActionCenterView::setPanel(ILXQtPanel *panel) { m_panel = panel; }

void KMPActionCenterView::showActionCenter() {
  if (m_actionPopup->isVisible())
    return;
  m_plugin->willShowWindow(m_actionPopup);
  m_actionPopup->updateGeometry();
  m_actionPopup->adjustSize();
  buildActionCenter();
  m_actionPopup->show();
  m_actionPopup->activateWindow();
}

void KMPActionCenterView::hideActionCenter() { m_actionPopup->hide(); }

void KMPActionCenterView::toggleActionCenter() {
  if (m_actionPopup->isVisible()) {
    hideActionCenter();
  } else {
    showActionCenter();
  }
}

void KMPActionCenterView::handleActionCenterIconChanged(
    const QString &iconName) {
  setIcon(QIcon::fromTheme(iconName));
}

void KMPActionCenterView::handleShowWindow() { buildActionCenter(); }

void KMPActionCenterView::handleHideWindow() {}

bool KMPActionCenterView::eventFilter(QObject *watched, QEvent *event) {
  if (watched == this && event != nullptr) {
    if (event->type() == QEvent::WindowDeactivate) {
      this->hide();
    } else if (event->type() == QEvent::Enter) {
      qInfo() << "you enter " << endl;
    } else if (event->type() == QEvent::Leave) {
      qInfo() << "you leave " << endl;
    } else if (event->type() == QEvent::Show) {
      qInfo() << "Window Widget show " << endl;
    } else if (event->type() == QEvent::Hide) {
      qInfo() << "Window Widget Hide " << endl;
    }
  }
  return QWidget::eventFilter(watched, event);
}
