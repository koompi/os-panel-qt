#include "kmpactioncenter.h"
#include "../panel/lxqtpanel.h"
#include <LXQt/lxqtsettings.h>
#include <QDebug>
#include <QGuiApplication>
#include <QIcon>
#include <QResizeEvent>
#include <QScreen>
#include <QVBoxLayout>

KMPActionCenter::KMPActionCenter(const ILXQtPanelPluginStartupInfo &startupInfo)
    : QObject(), ILXQtPanelPlugin(startupInfo) {
  m_actionButton = new KMPActionCenterView(this, panel());
}
KMPActionCenter::~KMPActionCenter() {}

QWidget *KMPActionCenter::widget() { return m_actionButton; }

QDialog *KMPActionCenter::configureDialog() {}

void KMPActionCenter::realign() {}

bool KMPActionCenter::eventFilter(QObject *obj, QEvent *event) { return false; }
