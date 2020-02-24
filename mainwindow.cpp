#include "mainwindow.h"
#include <KWindowSystem>
#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QTime>
#include <QtNetwork/QNetworkConfiguration>
#include <QtNetwork/QNetworkConfigurationManager>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  wifi = new wifiapplet(this);
  setFixedSize(QSize(1920, 32));
  qDebug() << layout() << endl;
  setStrut();
  // declare variable
  QWidget *mainWidget = new QWidget;
  QTimer *time = new QTimer(this);
  connect(time, &QTimer::timeout, this, &MainWindow::timefunction);
  time->start(1000);
  setCentralWidget(mainWidget);
  QToolButton *startMenuBtn = new QToolButton(this);
  QToolButton *wifiBtn = new QToolButton(this);
  QToolButton *batterBtn = new QToolButton(this);
  QToolButton *soundBtn = new QToolButton(this);
  panelDate = new QLabel(this);
  QHBoxLayout *panelLayout = new QHBoxLayout(mainWidget);
  //    QLabel * panelDate = new QLabel(this);
  startMenuBtn->resize(24, 24);
  startMenuBtn->setIcon(QIcon::fromTheme("preferences"));
  startMenuBtn->autoRaise();
  startMenuBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
  startMenuBtn->setIconSize(QSize(24, 24));
  wifiBtn->setIconSize(QSize(24, 24));
  batterBtn->setIconSize(QSize(24, 24));
  soundBtn->setIconSize(QSize(24, 24));
  startMenuBtn->move(4, 2);
  // Datatime setup
  // hello world my name is Ma Veasna
  // time
  panelDate->setText(QTime::currentTime().toString("hh : mm : ss"));
  mainWidget->setLayout(panelLayout);
  panelLayout->addWidget(startMenuBtn);
  panelLayout->addStretch(1000);
  qDebug() << panelLayout->stretch(1);
  panelLayout->addWidget(setPanelButton(wifiBtn, "network-wireless-acquiring"));
  panelLayout->addWidget(setPanelButton(batterBtn, "battery-100"));
  panelLayout->addWidget(setPanelButton(soundBtn, "audio-volume-high"));
  panelLayout->addWidget(panelDate);

  //  connect(startMenuBtn, &QToolButton::clicked, [&]() { QApplication::quit();
  //  });
  connect(startMenuBtn, &QPushButton::clicked, this,
          &MainWindow::showStartMenu);
  connect(batterBtn, &QToolButton::clicked, []() { QApplication::exit(); });

  connect(wifiBtn, &QToolButton::clicked, wifi, &wifiapplet::showWifiList);
}

MainWindow::~MainWindow() {}

void MainWindow::setStrut() {
  try {

    if (KWindowSystem::isPlatformWayland()) {
      throw QString("Your platform is not supported");
    }
    move(0, 0);
    KWindowSystem::setType(this->winId(), NET::Dock);
    WId wid = effectiveWinId();
    // this function is used to allocate preserving space which is strut for
    // taskbar
    KWindowSystem::setExtendedStrut(wid, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0);
    qDebug() << "set up sucessfully" << endl;

  } catch (QString &error) {
    qDebug() << error << endl;
  }
}

QToolButton *MainWindow::setPanelButton(QToolButton *trayButton,
                                        const QString &icon) {
  trayButton->setIcon(QIcon::fromTheme(icon));
  trayButton->resize(24, 24);
  trayButton->setStyleSheet("border: 0px;");
  return trayButton;
}

bool MainWindow::showStartMenu() {
  QProcess startMenu;
  startMenu.setProgram("qml-launcher");
  startMenu.startDetached();
  startMenu.waitForFinished(-1);
  startMenu.close();
  qInfo() << "Start Menu closed" << endl;
  return true;
}

void MainWindow::timefunction() {
  QTime time = QTime::currentTime();
  qInfo() << time << endl;
  QString time_text = time.toString("hh : mm : ss");
  panelDate->setText(time_text);
}

void MainWindow::setTime(QString value) { panelDate->setText(value); }
