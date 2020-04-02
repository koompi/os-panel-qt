#include "soundservice.h"
#include <QAudioDeviceInfo>
#include <QProcess>
#include <QDebug>
soundservice::soundservice(QObject *parent) : QObject(parent) {
    qInfo() << "Sound Service starting......";
}

soundservice::~soundservice()
{
    qInfo() << "Sound Service ending......";
}

int soundservice::getCurrentVolume() {
  QProcess process;
  QStringList args("--get-volume");
  process.start("pamixer", args,QIODevice::ReadOnly);
  process.waitForFinished();
  QString out(process.readAllStandardOutput());
  volume = {out.toInt()};
  process.close();
  return volume;
}

void soundservice::onVolumeChange(int volume) {
  QProcess volumePro;
  volumePro.setProgram("pactl");
  QStringList args;
  QString outputDeviceName = QAudioDeviceInfo::defaultOutputDevice().deviceName();
  QString level = QString::number(volume).append("%");
  args << "set-sink-volume" << outputDeviceName << level;
  volumePro.setArguments(args);
  volumePro.startDetached();
  volumePro.waitForFinished(-1);
  volumePro.close();
}
