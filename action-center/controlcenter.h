#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include "controlcenteritem.h"
#include "networkservice.h"
#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QProcess>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
class controlcenter : public QWidget {
  Q_OBJECT
public:
  explicit controlcenter(QWidget *parent = nullptr);
  ~controlcenter();
Q_SIGNALS:
  void sendIconChange();
  void notifySoundChange(int volume);
  void emitConnectedIcon();
  void emitDisconnectedIcon();
public
  Q_SLOT : void testEmitSignal();
  void onSoundChange(int volume);

private:
  int m_width, m_height;
//  QTimer *timeStop = nullptr;
  controlcenteritem *stackitem = nullptr;

public:
  bool event(QEvent *event);

protected:
  void enterEvent(QEvent *event);
  void leaveEvent(QEvent *event);
};

#endif // controlcenter_H
