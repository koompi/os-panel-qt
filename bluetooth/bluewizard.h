#ifndef BLUEWIZARD_H
#define BLUEWIZARD_H
#include <BluezQt/Manager>
#include <QWizard>
class WizardAgent;

class BlueWizard : public QWizard {

  Q_OBJECT

public:
  explicit BlueWizard();

  BluezQt::DevicePtr device() const;
  void setDevice(BluezQt::DevicePtr device);

  WizardAgent *agent() const;
  BluezQt::Manager *manager() const;

  enum { Discover, Pairing, Success, Fail, Connect };

private Q_SLOTS:
  void initJobResult(BluezQt::InitManagerJob *job);
  void operationalChanged(bool operational);

private:
  void done(int result) override;

  BluezQt::Manager *m_manager;
  WizardAgent *m_agent;

  BluezQt::DevicePtr m_device;
};

#endif // BLUEWIZARD_H
