#include "kmpactioncenter.h"
#include <LXQt/lxqtsettings.h>
#include <QDebug>
#include <QGuiApplication>
#include <QIcon>
#include <QResizeEvent>
#include <QScreen>
#include <QVBoxLayout>
void KMPActionCenter::setButtonIcon() {}

QSize KMPActionCenter::screenSize() const {
  QScreen *screen = QGuiApplication::primaryScreen();
  return QSize(screen->geometry().width(), screen->geometry().height());
}

void KMPActionCenter::buildActionCenter() {
  if (actionWidget == nullptr) {
    qInfo() << "Width: " << screenSize().width()
            << "height : " << screenSize().height() << endl;
    actionWidget = new QWidget(nullptr, Qt::FramelessWindowHint |
                                            Qt::X11BypassWindowManagerHint);
    LXQtPanel *panelobj = dynamic_cast<LXQtPanel *>(panel());
    actionWidget->setFixedSize(screenSize().width() * 0.25,
                               screenSize().height() - panelobj->panelSize());
    configWidget = new ConfigPanelWidget(panelobj);
    qInfo() << "object valid : " << endl;
  }
}

void KMPActionCenter::showActionCenter() {
  if (!actionWidget)
    return;
  willShowWindow(actionWidget);
  QRect showSize = calculatePopupWindowPos(actionWidget->size());
  actionWidget->move(showSize.x(), showSize.y());
  actionWidget->show();
}

void KMPActionCenter::showHideACtionCenter() {
  if (actionWidget && actionWidget->isVisible())
    actionWidget->hide();
  else
    showActionCenter();
}

KMPActionCenter::KMPActionCenter(const ILXQtPanelPluginStartupInfo &startupInfo)
    : QObject(), ILXQtPanelPlugin(startupInfo), mButton(new QToolButton()) {
  mButton->setText(QString());
  mButton->setIcon(QIcon::fromTheme(QStringLiteral("preferences")));

  buildActionCenter();
  QTimer::singleShot(0, [this] {
    Q_ASSERT(mButton->parentWidget());
    mButton->parentWidget()->installEventFilter(this);
  });
  connect(mButton, &QToolButton::clicked, this,
          &KMPActionCenter::showHideACtionCenter);
}

KMPActionCenter::~KMPActionCenter() {}

QDialog *KMPActionCenter::configureDialog() {}

void KMPActionCenter::realign() {}

bool KMPActionCenter::eventFilter(QObject *obj, QEvent *event) {
  //  if (mButton->parentWidget() == obj) {
  //    if (event->type() == QEvent::KeyPress) {
  //      qInfo() << "Resize event meet action " << endl;
  //      QResizeEvent *e = dynamic_cast<QResizeEvent *>(event);
  //      if (e->oldSize().isValid() && e->oldSize() != e->size()) {
  //        actionWidget->move(calculatePopupWindowPos(e->size()).topRight());
  //      }
  //    } else if (event->type() == QEvent::Enter) {
  //      qInfo() << "Enter action center " << endl;
  //    } else if (event->type() == QEvent::Leave) {
  //      qInfo() << "You action leave " << endl;
  //    }
  //  } else if (QWidget *widget = qobject_cast<QWidget *>(obj)) {
  //    qInfo() << "this is get called " << endl;
  //  }
  return false;
}
