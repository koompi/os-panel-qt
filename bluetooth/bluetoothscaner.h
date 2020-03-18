#ifndef BLUETOOTHSCANER_H
#define BLUETOOTHSCANER_H
#include <QAbstractListModel>
#include <QMovie>
#include <QStandardItemModel>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class bluetoothscaner : public QWidget {
  Q_OBJECT
public:
  explicit bluetoothscaner(QWidget *parent = nullptr);
  ~bluetoothscaner();

  void setupUi(QWidget *Form);
  void retranslateUi(QWidget *Form);
  void constructSignalSlot(QWidget *Form);

private:
  QVBoxLayout *verticalLayout;
  QLabel *bluetoothScanTitle;
  QLabel *scannerani;
  QLabel *scannerStatus;
  QListView *bluetoothScannList;
  QHBoxLayout *pinCodeLayout;
  QCheckBox *bluetoothEnablePin;
  QLineEdit *bluetoothPin;
  QFrame *line;
  QHBoxLayout *controlLayout;
  QPushButton *bluetoothNext;
  QPushButton *bluetoothCancel;
  QStandardItemModel *model = nullptr;
public slots:
  void bluetoothAnimationScanner();
  void bluetoothScanning();
  void deviceDiscoverd(QBluetoothDeviceInfo deviceInfo);
signals:
  void notifyToBluetoothPage();
  void notifyScannerDevices();
};

#endif // BLUETOOTHSCANER_H
