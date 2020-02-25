#ifndef SOUNDAPPLET_H
#define SOUNDAPPLET_H

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QProcess>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
class soundapplet : public QDialog {
  Q_OBJECT
public:
  explicit soundapplet(QWidget *parent = nullptr);
  ~soundapplet();
signals:
private
  Q_SLOT : int getCurrentVolume();

private:
  int m_width, m_height;
  int volume = 0;
  QSlider *volumeSound = nullptr;
  QTimer *timeStop = nullptr;

  // QObject interface
public:
  bool event(QEvent *event);

  // QObject interface
  bool eventFilter(QObject *watched, QEvent *event);

  // QWidget interface
protected:
  void enterEvent(QEvent *event);
  void leaveEvent(QEvent *event);
};

#endif // SOUNDAPPLET_H
