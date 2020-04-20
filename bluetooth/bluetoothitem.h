#ifndef BLUETOOTHITEM_H
#define BLUETOOTHITEM_H
#include <QDialog>
#include <QFormLayout>
#include <QPropertyAnimation>
#include <QScreen>
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
  QVBoxLayout *main_layout, *blue_main_info, *blue_props_layout,
      *BluetoothTextLayout;
  QHBoxLayout *BluetoothItemLayout;
  QToolButton *BluetoothIcon;
  QDialog *blue_info_dialog = nullptr;
  QPushButton *newPush, *BluetoothCon;
  QLabel *BluetoothName, *BluetoothStatus, *label_address, *label_pair,
      *label_trust, *label_adapter;
  QPropertyAnimation *anim;
  QScreen *dim;

public:
  explicit bluetoothitem(QWidget *parent = nullptr);
  ~bluetoothitem();
  QLabel *getBluetoothName() const;
  void setBluetoothName(QLabel *value);
  void setupUi(QWidget *BluetoothItem);
  QToolButton *getBluetoothIcon() const;
  void setBluetoothIcon(QToolButton *value);
  QLabel *getLabel_address() const;
  void setLabel_address(QLabel *value);

  QLabel *getLabel_pair() const;
  void setLabel_pair(QLabel *value);

  QLabel *getLabel_trust() const;
  void setLabel_trust(QLabel *value);

  QLabel *getLabel_adapter() const;
  void setLabel_adapter(QLabel *value);
public Q_SLOTS:
  void changeTextAndPosition();
signals:
  void requireBluetoothConnection(const QString bluetoothName);
  void requireBluetoothDisconnect(const QString bluetoothName);
  void notifiyExtendSize();
  void notifyCollapseSize();
  void requestData(bluetoothitem *);

private:
  void retranslateUi(QWidget *BluetoothItem);
  void initAction();

protected:
  void mousePressEvent(QMouseEvent *event);

  // QWidget interface
protected:
  void enterEvent(QEvent *event);
  void leaveEvent(QEvent *event);

  // QWidget interface
protected:
  void paintEvent(QPaintEvent *event);
};

#endif // BLUETOOTHITEM_H
