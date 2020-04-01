#ifndef PINDISPLAY_H
#define PINDISPLAY_H
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtBluetooth/QBluetoothTransferReply>
#include <QtWidgets/QDialog>
QT_FORWARD_DECLARE_CLASS(QBluetoothTransferReply)
class process : public QDialog {
  Q_OBJECT
public:
  process(QWidget *parent);
  void setStatus(QString title, QString filename);
  void setupUi(QDialog *Dialog);
  void retranslateUi(QDialog *Dialog);
public Q_SLOTS:
  void finished(QBluetoothTransferReply *);
  void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
private slots:
  void on_cancelButton_clicked();

private:
  QElapsedTimer start;
  QVBoxLayout *verticalLayout;
  QLabel *titleLabel;
  QProgressBar *progressBar;
  QLabel *statusLabel;
  QPushButton *cancelButton;
};

#endif // PINDISPLAY_H
