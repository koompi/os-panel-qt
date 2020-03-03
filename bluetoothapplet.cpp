#include "bluetoothapplet.h"

bluetoothapplet::bluetoothapplet(QWidget * parent):QWidget (parent)
{
    setupUi (this);
    connect (backbtn, &QToolButton::clicked, [&](){
        bluetoothstacked->setCurrentIndex (0);
    });
}

void bluetoothapplet::setupUi(QWidget *bluetooth)
{
    if (bluetooth->objectName().isEmpty())
        bluetooth->setObjectName(QString::fromUtf8("bluetooth"));
    bluetooth->resize(480, 1080);
    mainbluetoothlabel = new QLabel(bluetooth);
    mainbluetoothlabel->setObjectName(QString::fromUtf8("mainbluetoothlabel"));
    mainbluetoothlabel->setGeometry(QRect(190, 20, 100, 50));
    mainbluetoothlabel->setMaximumSize(QSize(300, 16777215));
    QFont font;
    font.setPointSize(15);
    mainbluetoothlabel->setFont(font);
    mainbluetoothlabel->setAlignment(Qt::AlignCenter);
    listbluetoothWidget = new QListWidget(bluetooth);
    listbluetoothWidget->setObjectName(QString::fromUtf8("listbluetoothWidget"));
    listbluetoothWidget->setGeometry(QRect(0, 120, 481, 531));
    listbluetoothWidget->setFrameShape(QFrame::NoFrame);
    listbluetoothWidget->setMovement(QListView::Free);
    listbluetoothWidget->setResizeMode(QListView::Fixed);
    deviceslabel = new QLabel(bluetooth);
    deviceslabel->setObjectName(QString::fromUtf8("deviceslabel"));
    deviceslabel->setGeometry(QRect(10, 130, 91, 18));
    QFont font1;
    font1.setPointSize(8);
    deviceslabel->setFont(font1);
    backbtn = new QToolButton(bluetooth);
    backbtn->setObjectName(QString::fromUtf8("backbtn"));
    backbtn->setGeometry(QRect(10, 30, 33, 34));
    QIcon icon(QIcon::fromTheme(QString::fromUtf8("draw-arrow-back")));
    backbtn->setIcon(icon);
    backbtn->setAutoRaise(true);
    widget = new QWidget(bluetooth);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(51, 80, 421, 31));
    horizontalLayout = new QHBoxLayout(widget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    childbluetoothlabel = new QLabel(widget);
    childbluetoothlabel->setObjectName(QString::fromUtf8("childbluetoothlabel"));
    QFont font2;
    font2.setPointSize(12);
    childbluetoothlabel->setFont(font2);

    horizontalLayout->addWidget(childbluetoothlabel);

    bluetoothenable = new QCheckBox(widget);
    bluetoothenable->setObjectName(QString::fromUtf8("bluetoothenable"));
    bluetoothenable->setMinimumSize(QSize(0, 20));
    bluetoothenable->setMaximumSize(QSize(50, 16));
    bluetoothenable->setLayoutDirection(Qt::LeftToRight);
    bluetoothenable->setAutoFillBackground(false);
    bluetoothenable->setTristate(false);

    horizontalLayout->addWidget(bluetoothenable);


    retranslateUi(bluetooth);

    QMetaObject::connectSlotsByName(bluetooth);
}

void bluetoothapplet::retranslateUi(QWidget *bluetooth)
{
    bluetooth->setWindowTitle(QCoreApplication::translate("bluetooth", "Form", nullptr));
    mainbluetoothlabel->setText(QCoreApplication::translate("bluetooth", "Bluetooth", nullptr));
    deviceslabel->setText(QCoreApplication::translate("bluetooth", "Paired Devices", nullptr));
    backbtn->setText(QString());
    childbluetoothlabel->setText(QCoreApplication::translate("bluetooth", "Bluetooth", nullptr));
    bluetoothenable->setText(QString());
}

QStackedWidget *bluetoothapplet::getBluetoothstacked() const
{
    return bluetoothstacked;
}

void bluetoothapplet::setBluetoothstacked(QStackedWidget *value)
{
    bluetoothstacked = value;
}
