#include "bluewizard.h"
#include "pairing.h"
#include "wizardagent.h"
#include <BluezQt/InitManagerJob>
#include <QApplication>
#include <QDebug>
#include <QtDBus/QDBusConnection>
BlueWizard::BlueWizard() : QWizard(), m_agent(new WizardAgent(this)) {
  setOption(QWizard::IndependentPages, true);
  setPage(Pairing, new PairingPage(this));

  // Initialize BluezQt
  m_manager = new BluezQt::Manager(this);
  BluezQt::InitManagerJob *initJob = m_manager->init();
  initJob->start();
  connect(initJob, &BluezQt::InitManagerJob::result, this,
          &BlueWizard::initJobResult);

  // When Finished page is opened, close wizard automatically
  connect(
      this, &QWizard::currentIdChanged, this,
      [this](int id) {
        if (id == Success) {
          done(QDialog::Accepted);
        }
        // Sending notification in SuccessPage is asynchronous, so this needs to
        // be queued.
      },
      Qt::QueuedConnection);
}

BluezQt::DevicePtr BlueWizard::device() const { return m_device; }

void BlueWizard::setDevice(BluezQt::DevicePtr device) { m_device = device; }

WizardAgent *BlueWizard::agent() const { return m_agent; }

BluezQt::Manager *BlueWizard::manager() const { return m_manager; }

void BlueWizard::initJobResult(BluezQt::InitManagerJob *job) {
  if (job->error()) {
    qWarning() << "Error initializing manager:" << job->errorText();
    qApp->exit(1);
    return;
  }

  qDebug() << "Manager initialized";

  // Make sure to register agent when bluetoothd starts
  operationalChanged(m_manager->isOperational());
  connect(m_manager, &BluezQt::Manager::operationalChanged, this,
          &BlueWizard::operationalChanged);

  // Only show wizard after init is completed
  show();
}

void BlueWizard::operationalChanged(bool operational) {
  if (operational) {
    m_manager->registerAgent(m_agent);
  } else {
    // Attempt to start bluetoothd
    BluezQt::Manager::startService();
  }
}

void BlueWizard::done(int result) {
  qDebug() << "Wizard done: " << result;

  QWizard::done(result);
  qApp->exit(result);
}
