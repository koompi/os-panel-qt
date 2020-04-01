#ifndef WIZARDAGENT_H
#define WIZARDAGENT_H
#include <BluezQt/Agent>
#include <QBluetoothServer>
class WizardAgent : public BluezQt::Agent {
  Q_OBJECT
public:
  explicit WizardAgent(QObject *parent = nullptr);
  QString pin();
  void setPin(const QString &pin);

  bool isFromDatabase();
  QString getPin(BluezQt::DevicePtr device);
  // Agent interface
public:
  QDBusObjectPath objectPath() const override;

  void requestPinCode(BluezQt::DevicePtr device,
                      const BluezQt::Request<QString> &req) override;
  void displayPinCode(BluezQt::DevicePtr device,
                      const QString &pinCode) override;
  void requestPasskey(BluezQt::DevicePtr device,
                      const BluezQt::Request<quint32> &req) override;
  void displayPasskey(BluezQt::DevicePtr device, const QString &passkey,
                      const QString &entered) override;
  void requestConfirmation(BluezQt::DevicePtr device, const QString &passkey,
                           const BluezQt::Request<> &req) override;
Q_SIGNALS:
  void pinRequested(const QString &pin);
  void confirmationRequested(const QString &passkey,
                             const BluezQt::Request<> &req);

private:
  QString m_pin;
  bool m_fromDatabase;
};

#endif // WIZARDAGENT_H
