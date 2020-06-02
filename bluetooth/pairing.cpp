#include "pairing.h"
#include "bluewizard.h"
#include "wizardagent.h"
#include <BluezQt/Adapter>
#include <BluezQt/Device>
#include <BluezQt/PendingCall>
#include <QDebug>
#include <QPushButton>
PairingPage::PairingPage(BlueWizard *parent)
    : QWizardPage(parent), m_wizard(parent), m_success(false) {}

int PairingPage::nextId() const {
  if (m_success) {
    return BlueWizard::Connect;
  }
  return BlueWizard::Fail;
}

void PairingPage::initializePage() {
  qDebug() << "Initialize Pairing Page";

  m_device = m_wizard->device();
  m_wizard->setButtonLayout(wizardButtonsLayout());

  QPushButton *cancel = new QPushButton(this);

  connect(m_wizard->agent(), &WizardAgent::pinRequested, this,
          &PairingPage::pinRequested);
  connect(m_wizard->agent(), &WizardAgent::confirmationRequested, this,
          &PairingPage::confirmationRequested);

  BluezQt::PendingCall *pairCall = m_device->pair();
  connect(pairCall, &BluezQt::PendingCall::finished, this,
          &PairingPage::pairingFinished);
}
void PairingPage::pairingFinished(BluezQt::PendingCall *call) {
  qDebug() << "Pairing finished:";
  qDebug() << "\t error     : " << (bool)call->error();
  qDebug() << "\t errorText : " << call->errorText();

  m_success = !call->error();
  m_wizard->next();
}

void PairingPage::pinRequested(const QString &pin) {
  // Don't ask user to introduce the PIN if it was used from database
  if (m_wizard->agent()->isFromDatabase()) {
    return;
  }

  m_wizard->setMinimumSize(m_wizard->sizeHint());
}

void PairingPage::confirmationRequested(const QString &passkey,
                                        const BluezQt::Request<> &req) {
  m_req = req;

  QList<QWizard::WizardButton> list;
  list << QWizard::Stretch;
  list << QWizard::CustomButton1;
  list << QWizard::CustomButton2;
  m_wizard->setButtonLayout(list);
  m_wizard->setMinimumSize(m_wizard->sizeHint());
}

void PairingPage::matchesClicked() {
  wizard()->button(QWizard::CustomButton1)->setEnabled(false);
  wizard()->button(QWizard::CustomButton2)->setEnabled(false);

  m_req.accept();
}

void PairingPage::notMatchClicked() { m_req.reject(); }

void PairingPage::cancelClicked() { m_device->cancelPairing(); }

QList<QWizard::WizardButton> PairingPage::wizardButtonsLayout() const {
  QList<QWizard::WizardButton> list;
  list << QWizard::Stretch;
  list << QWizard::CustomButton1;
  return list;
}
