#include "wifiitemmodel.h"
#include <QDebug>
#include <QProcess>
wifiItemModel::wifiItemModel(QWidget *parent) : QWidget(parent) {
  setupUi(this);
}

void wifiItemModel::setupUi(QWidget *Form) {
  if (Form->objectName().isEmpty())
    Form->setObjectName(QString::fromUtf8("Form"));
  Form->resize(486, 104);
  horizontalLayout_4 = new QHBoxLayout(Form);
  horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
  verticalLayout_2 = new QVBoxLayout();
  verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
  horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
  horizontalLayout = new QHBoxLayout();
  horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
  wifiIcon = new QToolButton(Form);
  wifiIcon->setObjectName(QString::fromUtf8("wifiIcon"));
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(wifiIcon->sizePolicy().hasHeightForWidth());
  wifiIcon->setSizePolicy(sizePolicy);
  QIcon icon;
  QString iconThemeName = QString::fromUtf8("network-wireless");
  if (QIcon::hasThemeIcon(iconThemeName)) {
    icon = QIcon::fromTheme(iconThemeName);
  } else {
    icon.addFile(QString::fromUtf8("../../.designer/backup"), QSize(),
                 QIcon::Normal, QIcon::Off);
  }
  wifiIcon->setIcon(icon);
  wifiIcon->setIconSize(QSize(32, 32));
  wifiIcon->setCheckable(false);
  wifiIcon->setAutoRaise(true);
  wifiIcon->setArrowType(Qt::NoArrow);

  horizontalLayout->addWidget(wifiIcon);

  verticalLayout = new QVBoxLayout();
  verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
  labelWifi = new QLabel(Form);
  labelWifi->setObjectName(QString::fromUtf8("labelWifi"));

  verticalLayout->addWidget(labelWifi);

  connectState = new QLabel(Form);
  connectState->setObjectName(QString::fromUtf8("connectState"));

  verticalLayout->addWidget(connectState);

  horizontalLayout->addLayout(verticalLayout);

  horizontalLayout_2->addLayout(horizontalLayout);

  wifiConnectBtn = new QPushButton(Form);
  wifiConnectBtn->setObjectName(QString::fromUtf8("wifiConnectBtn"));
  QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
  sizePolicy1.setHorizontalStretch(100);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(
      wifiConnectBtn->sizePolicy().hasHeightForWidth());
  wifiConnectBtn->setSizePolicy(sizePolicy1);
  wifiConnectBtn->setMinimumSize(QSize(0, 0));
  wifiConnectBtn->setMaximumSize(QSize(120, 16777215));
  wifiConnectBtn->setCheckable(false);
  //  wifiConnectBtn->setFlat(true);
  horizontalLayout_2->addWidget(wifiConnectBtn);

  verticalLayout_2->addLayout(horizontalLayout_2);

  connect(wifiConnectBtn, &QPushButton::clicked, [&]() {
    //    passEdit->setPlaceholderText(
    //        QCoreApplication::translate("Form", "Password . . .", nullptr));
    wifiConnectBtn->setEnabled(false);
    if (!passEdit) {
      horizontalLayout_3 = new QHBoxLayout();
      horizontalLayout_3->setObjectName(
          QString::fromUtf8("horizontalLayout_3"));
      passEdit = new QLineEdit(Form);
      passEdit->setObjectName(QString::fromUtf8("passEdit"));
      passEdit->setFrame(true);
      passEdit->setClearButtonEnabled(true);
      passEdit->setEchoMode(QLineEdit::EchoMode::Password);
      passEdit->setFocus();
      toolButton = new QToolButton(Form);
      toolButton->setObjectName(QString::fromUtf8("toolButton"));
      QIcon icon1(QIcon::fromTheme(QString::fromUtf8("password-show-off")));
      toolButton->setIcon(icon1);
      toolButton->setAutoRaise(true);
      toolButton->setText(QCoreApplication::translate("Form", "...", nullptr));
      connect(passEdit, &QLineEdit::textChanged, [&]() {
        if (passEdit->text().length() < 8) {
          wifiConnectBtn->setEnabled(false);
        } else if (passEdit->text().length() == 0) {
          toolButton->setIcon(QIcon::fromTheme("password-show-off"));
        } else {
          QPushButton *validConnecBtn = new QPushButton("connect");
          horizontalLayout_2->removeItem(horizontalLayout_2->takeAt(1));
          QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
          sizePolicy2.setHorizontalStretch(100);
          sizePolicy2.setVerticalStretch(0);
          sizePolicy2.setHeightForWidth(
              validConnecBtn->sizePolicy().hasHeightForWidth());
          validConnecBtn->setSizePolicy(sizePolicy2);
          validConnecBtn->setMinimumSize(QSize(0, 0));
          validConnecBtn->setMaximumSize(QSize(120, 16777215));
          horizontalLayout_2->addWidget(validConnecBtn);

          connect(validConnecBtn, &QPushButton::clicked, [&]() {
            if (validConnecBtn->text() == "disconnect") {
              networkService = new networkservice(this);
              connect(this, &wifiItemModel::requstDisconnect, networkService,
                      &networkservice::disconnectState);
              wifiConnectBtn->setText("Connect");
              Q_EMIT requstDisconnect(labelWifi->text());
              return;
            }
            validConnecBtn->setText("disconnect");
            Q_EMIT requireConnection(labelWifi->text(), passEdit->text());
            connectState->setText("connected");
          });
        }
      });
      connect(toolButton, &QToolButton::clicked, [&]() {
        if (toolButton->icon().name() ==
            QIcon::fromTheme("password-show-off").name()) {
          toolButton->setIcon(QIcon::fromTheme("password-show-on"));
          passEdit->setEchoMode(QLineEdit::Normal);
        } else {
          toolButton->setIcon(QIcon::fromTheme("password-show-off"));
          passEdit->setEchoMode(QLineEdit::Password);
          horizontalLayout_3->removeItem(toolButton->layout());
          horizontalLayout_3->removeItem(toolButton->layout());
        }
      });
    }
    horizontalLayout_3->addWidget(passEdit);
    horizontalLayout_3->addWidget(toolButton);
    verticalLayout_2->addLayout(horizontalLayout_3);
    wificontainer->setSizeHint(QSize(this->minimumWidth(), 104));
    if (passEdit->text().length() >= 8) {
      wifiConnectBtn->setText("Disconnect");
    }
  });

  horizontalLayout_4->addLayout(verticalLayout_2);

  retranslateUi(Form);
  QMetaObject::connectSlotsByName(Form);
}

void wifiItemModel::retranslateUi(QWidget *Form) {
  Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
  wifiIcon->setText(QCoreApplication::translate("Form", "...", nullptr));
  labelWifi->setText(QCoreApplication::translate("Form", "Wifi Name", nullptr));
  connectState->setText(
      QCoreApplication::translate("Form", "Never used", nullptr));
  QFont font;
  font.setPixelSize(10);
  connectState->setStyleSheet("color:grey;");
  connectState->setFont(font);
  wifiConnectBtn->setText(
      QCoreApplication::translate("Form", "Connect", nullptr));
}

QLabel *wifiItemModel::getLabelWifi() const { return labelWifi; }

void wifiItemModel::setLabelWifi(QLabel *value) { labelWifi = value; }

QToolButton *wifiItemModel::getWifiIcon() const { return wifiIcon; }

void wifiItemModel::setWifiIcon(QToolButton *value) { wifiIcon = value; }

QListWidgetItem *wifiItemModel::getWificontainer() const {
  return wificontainer;
}

void wifiItemModel::setWificontainer(QListWidgetItem *value) {
  wificontainer = value;
}

bool wifiItemModel::event(QEvent *event) {
  if (event->type() == QEvent::HoverMove) {
    qDebug() << "event called ";
  }
  return QWidget::event(event);
}

void wifiItemModel::mousePressEvent(QMouseEvent *event) {
  emit notifyItemModelPress();
  return QWidget::mousePressEvent(event);
}
