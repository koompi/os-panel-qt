#include "soundapplet.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>
soundapplet::soundapplet(QWidget *parent)
    : QDialog(parent, Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint |
                          Qt::Popup | Qt::X11BypassWindowManagerHint) {
  this->setObjectName("sound applet");
  QScreen *screen = QGuiApplication::primaryScreen();
  m_width = screen->geometry().width();
  m_height = screen->geometry().height();
  resize(m_width * 0.25, m_height * 0.25);
  // ui component declarations
  QPushButton *MixerButton = new QPushButton("Mixer", this);
  volumeSound = new QSlider(Qt::Orientation::Horizontal);
  QVBoxLayout *audioLayout = new QVBoxLayout();
  // when label name was set we will initialize the current volume of the sound
  // system.
  QLabel *soundPercent =
      new QLabel(QString::number(getCurrentVolume()).append("%"), this);
  QComboBox *listSoundBox = new QComboBox(this);

  // ui component configurations
  timeStop = new QTimer(this);
  timeStop->setInterval(5000);
  listSoundBox->addItem(QIcon::fromTheme("audio-on"), "Speaker");
  listSoundBox->addItem(QIcon::fromTheme("audio-headphones"), "Headphone");
  listSoundBox->addItem(QIcon::fromTheme("monitor"), "Monitor");
  volumeSound->setRange(0, 150);

  volumeSound->setValue(getCurrentVolume());
  volumeSound->setToolTip("sound level");
  MixerButton->setIcon(QIcon::fromTheme("preferences-desktop-sound"));
  MixerButton->setFlat(true);
  MixerButton->setToolTip(QString("launcher mixer"));
  audioLayout->addWidget(MixerButton);
  audioLayout->addWidget(volumeSound);
  audioLayout->addWidget(soundPercent);
  audioLayout->addWidget(listSoundBox);
  setStyleSheet("background");
  setLayout(audioLayout);
  connect(timeStop, &QTimer::timeout, this, &soundapplet::hide);
}

soundapplet::~soundapplet() {
  QString deleted_info =
      QString("%1 get destroyed in the heap").arg(this->objectName());
  qDebug() << deleted_info;
}

int soundapplet::getCurrentVolume() {
  QProcess process;
  QStringList args("--get-volume");
  process.start("pamixer", args);
  process.waitForFinished();
  QString out(process.readAllStandardOutput());
  volume = {out.toInt()};
  process.close();
  return out.toInt();
}

bool soundapplet::event(QEvent *event) {
  if (event->type() == QEvent::WindowDeactivate) {
    this->hide();
  } else if (event->type() == QEvent::ToolTip) {
    qDebug() << "you hover on sound applet";
  }
  return QDialog::event(event);
}

bool soundapplet::eventFilter(QObject *watched, QEvent *event) {

  if (watched == volumeSound) {
    if (event->type() == QEvent::Wheel) {
      //            handleWheelEvent(dynamic_cast<QWheelEvent *>(event));
      return true;
    }
    return false;
  }
  return QDialog::eventFilter(watched, event);
}

void soundapplet::enterEvent(QEvent *event) {
  if (event->type() == QEvent::Enter) {
    qDebug() << "you enter sound applet area";
    timeStop->stop();
  }
  return QDialog::enterEvent(event);
}

void soundapplet::leaveEvent(QEvent *event) {

  if (event->type() == QEvent::Leave) {
    qDebug() << "you left sound applet area";
    timeStop->start();
  }
  return QDialog::leaveEvent(event);
}
