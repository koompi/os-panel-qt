#include "customitem.h"
#include <QStyleOption>
#include <QPainter>
CustomItem::CustomItem(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
    connect(bluetoothCon, &QToolButton::clicked, [&](){
        if(bluetoothCon->text() == QString::fromUtf8("Connect"))
            emit requireBluetoothConnection(getBluetoothName()->text());
        else
            emit requireBluetoothDisconnect(getBluetoothName()->text());
    });
}

void CustomItem::retranslateUi(QWidget * Form)
{
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    bluetoothIcon->setText(QCoreApplication::translate("Form", "...", nullptr));
    bluetoothName->setText(QCoreApplication::translate("Form", "Borofone 3FD", nullptr));
    bluetoothStatus->setText(QCoreApplication::translate("Form", "Autdio Device", nullptr));
    bluetoothCon->setText(QCoreApplication::translate("Form", "Connect", nullptr));
    bluetoothInfo->setText(QString());
}

void CustomItem::setupUi(QWidget * Form)
{
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(414, 62);
    Form->setStyleSheet(QString::fromUtf8(""));
    verticalLayout_3 = new QVBoxLayout(Form);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    bluetoothIcon = new QToolButton(Form);
    bluetoothIcon->setObjectName(QString::fromUtf8("bluetoothIcon"));
    bluetoothIcon->setEnabled(true);
    bluetoothIcon->setStyleSheet(QString::fromUtf8("border:0px;"));
    QIcon icon;
    QString iconThemeName = QString::fromUtf8("preferences-system-bluetooth");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    bluetoothIcon->setIcon(icon);
    bluetoothIcon->setIconSize(QSize(32, 32));
    bluetoothIcon->setCheckable(false);
    bluetoothIcon->setChecked(false);
    bluetoothIcon->setAutoRaise(true);

    horizontalLayout_2->addWidget(bluetoothIcon);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    bluetoothName = new QLabel(Form);
    bluetoothName->setObjectName(QString::fromUtf8("bluetoothName"));
    QFont font;
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);
    bluetoothName->setFont(font);

    verticalLayout->addWidget(bluetoothName);

    bluetoothStatus = new QLabel(Form);
    bluetoothStatus->setObjectName(QString::fromUtf8("bluetoothStatus"));
    QFont font1;
    font1.setPointSize(8);
    bluetoothStatus->setFont(font1);

    verticalLayout->addWidget(bluetoothStatus);


    horizontalLayout_2->addLayout(verticalLayout);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    bluetoothCon = new QToolButton(Form);
    bluetoothCon->setObjectName(QString::fromUtf8("bluetoothCon"));
    bluetoothCon->setMinimumSize(QSize(100, 0));
    bluetoothCon->setVisible(false);
    QIcon icon1;
    iconThemeName = QString::fromUtf8("network-connect");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon1 = QIcon::fromTheme(iconThemeName);
    } else {
        icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    bluetoothCon->setIcon(icon1);
    bluetoothCon->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    bluetoothCon->setAutoRaise(false);

    horizontalLayout->addWidget(bluetoothCon);

    bluetoothInfo = new QToolButton(Form);
    bluetoothInfo->setObjectName(QString::fromUtf8("bluetoothInfo"));
    bluetoothInfo->setVisible(false);
    QIcon icon2;
    iconThemeName = QString::fromUtf8("arrow-down");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon2 = QIcon::fromTheme(iconThemeName);
    } else {
        icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    bluetoothInfo->setIcon(icon2);

    horizontalLayout->addWidget(bluetoothInfo);


    horizontalLayout_2->addLayout(horizontalLayout);


    verticalLayout_2->addLayout(horizontalLayout_2);


    verticalLayout_3->addLayout(verticalLayout_2);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
}

QToolButton *CustomItem::getBluetoothIcon() const
{
    return bluetoothIcon;
}

void CustomItem::setBluetoothIcon(QToolButton *value)
{
    bluetoothIcon = value;
}

QToolButton *CustomItem::getBluetoothCon() const
{
    return bluetoothCon;
}

void CustomItem::setBluetoothCon(QToolButton *value)
{
    bluetoothCon = value;
}

void CustomItem::changeTextAndPosition()
{
    if(bluetoothCon->text().toLower().compare(QStringLiteral("connect")))
        bluetoothCon->setText(QStringLiteral("Disconnect"));
    else
        bluetoothCon->setText(QStringLiteral("Connect"));
}

QLabel *CustomItem::getBluetoothStatus() const
{
    return bluetoothStatus;
}

void CustomItem::setBluetoothStatus(QLabel *value)
{
    bluetoothStatus = value;
}

QLabel *CustomItem::getBluetoothName() const
{
    return bluetoothName;
}

void CustomItem::setBluetoothName(QLabel *value)
{
    bluetoothName = value;
}

void CustomItem::enterEvent(QEvent *event)
{
        bluetoothCon->setVisible(true);
        bluetoothInfo->setVisible(true);
}

void CustomItem::leaveEvent(QEvent *event)
{
        bluetoothCon->setVisible(false);
        bluetoothInfo->setVisible(false);
}


void CustomItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
