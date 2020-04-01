#ifndef BLUETOOTHITEM_H
#define BLUETOOTHITEM_H
#include <QFormLayout>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
class bluetoothitem : public QWidget {
  Q_OBJECT
private:
  QHBoxLayout *BluetoothLayout;
  QHBoxLayout *BluetoothItemLayout;
  QToolButton *BluetoothIcon;
  QVBoxLayout *BluetoothTextLayout;
  QLabel *BluetoothName;
  QLabel *BluetoothStatus;
  QVBoxLayout *topConainer;
  QFormLayout *formInfoLayout;
  QPushButton *BluetoothCon;
  bool toggleState = false;

public:
  explicit bluetoothitem(QWidget *parent = nullptr);
  ~bluetoothitem();
  void extendHeightLayout();
  void resetHeightLayout();

  QLabel *getBluetoothName() const;
  void setBluetoothName(QLabel *value);

  QToolButton *getBluetoothIcon() const;
  void setBluetoothIcon(QToolButton *value);

signals:
  void requireBluetoothConnection(const QString bluetoothName);
  void requireBluetoothDisconnect(const QString bluetoothName);

private:
  void setupUi(QWidget *BluetoothItem);
  void retranslateUi(QWidget *BluetoothItem);
  void init();
  void initAction();

protected:
  void mousePressEvent(QMouseEvent *event);

  // QWidget interface
protected:
  void enterEvent(QEvent *event);
  void leaveEvent(QEvent *event);
};

#endif // BLUETOOTHITEM_H
