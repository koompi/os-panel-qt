#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "soundapplet.h"
#include "timeapplet.h"
#include "wifiapplet.h"
#include "controlcenter.h"
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QProcess>
#include <QThread>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QPropertyAnimation>
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

public Q_SLOTS:
  void setTime(QString value);
  void showSoundPopup();
  void showControlcenter();

private:
  wifiapplet *wifi = nullptr;
  timeapplet *time = nullptr;
  soundapplet *sound = nullptr;
  controlcenter* concenter = nullptr;
  QLabel *panelDate = nullptr;
  QThread newThread;
  QToolButton *soundBtn = nullptr;
  QRect screen;
  int primaryWidth, perfectSize;
  QPropertyAnimation *  animation = nullptr;

  // QObject interface
public:
  bool event(QEvent *event);
};
#endif // MAINWINDOW_H
