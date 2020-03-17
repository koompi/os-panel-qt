#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controlcenter.h"
#include "soundapplet.h"
#include "timeapplet.h"
#include "wifiapplet.h"
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QProcess>
#include <QPropertyAnimation>
#include <QThread>
#include <QToolButton>
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void setStrut();
  void showWifiList();
  QToolButton *setPanelButton(QToolButton *trayButton, const QString &icon);
  bool showStartMenu();
  void timefunction();
  void setUpControlCenter();
public Q_SLOTS:
  void setTime(QString value);
  void showSoundPopup();
  void showControlcenter();
  void receiveChangeIcon();
  void onSoundChange(int volume);

private:
  timeapplet *time = nullptr;
  soundapplet *sound = nullptr;
  controlcenter *concenter = nullptr;
  QLabel *panelDate = nullptr;
  QThread newThread;
  QToolButton *wifiBtn = nullptr;
  QToolButton *soundBtn = nullptr;
  QToolButton *startMenuBtn = nullptr;
  QToolButton *batterBtn = nullptr;
  QToolButton *actionCenter = nullptr;
  QRect screen;
  int primaryWidth, perfectSize;
  QPropertyAnimation *animation = nullptr;

  // QObject interface
public:
  bool event(QEvent *event);
  QToolButton *getWifiBtn();
  void setWifiBtn(QToolButton *value);
Q_SIGNALS:
  void notifyWirelessPage();
};
#endif // MAINWINDOW_H
