#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QWidget>

class CustomItem : public QWidget
{
    Q_OBJECT
public:
    explicit CustomItem(QWidget *parent = nullptr);
    void retranslateUi(QWidget * );
    void setupUi(QWidget * );
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *bluetoothIcon;
    QVBoxLayout *verticalLayout;
    QLabel *bluetoothName;
    QLabel *bluetoothStatus;
    QHBoxLayout *horizontalLayout;
    QToolButton *bluetoothCon;
    QToolButton *bluetoothInfo;

    QLabel *getBluetoothName() const;
    void setBluetoothName(QLabel *value);

    QLabel *getBluetoothStatus() const;
    void setBluetoothStatus(QLabel *value);

    QToolButton *getBluetoothCon() const;
    void setBluetoothCon(QToolButton *value);

    QToolButton *getBluetoothIcon() const;
    void setBluetoothIcon(QToolButton *value);

public slots:
    void changeTextAndPosition();
    // QWidget interface
protected:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
signals:
    void requireBluetoothConnection(const QString bluetoothName);
    void requireBluetoothDisconnect(const QString bluetoothName);
};

#endif // CUSTOMITEM_H
