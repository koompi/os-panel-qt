#ifndef BLUETOOTHAPPLET_H
#define BLUETOOTHAPPLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QToolButton>
#include <QStackedWidget>
class bluetoothapplet :public QWidget
{
    Q_OBJECT
public:
    bluetoothapplet(QWidget * parent);
    void setupUi(QWidget*);
    void retranslateUi(QWidget*);
    QLabel *mainbluetoothlabel;
    QListWidget *listbluetoothWidget;
    QLabel *deviceslabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *childbluetoothlabel;
    QCheckBox *bluetoothenable;
    QToolButton *backbtn;
    QStackedWidget *bluetoothstacked;
    QStackedWidget *getBluetoothstacked() const;
    void setBluetoothstacked(QStackedWidget *value);
};

#endif // BLUETOOTHAPPLET_H
