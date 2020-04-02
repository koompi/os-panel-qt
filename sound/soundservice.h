#ifndef SOUNDSERVICE_H
#define SOUNDSERVICE_H

#include <QObject>

class soundservice : public QObject {
  Q_OBJECT
public:
  explicit soundservice(QObject *parent = nullptr);
  ~soundservice();
signals:

public
  Q_SLOT : int getCurrentVolume();
  void onVolumeChange(int volume);
private:
  int volume = 0;
};

#endif // SOUNDSERVICE_H
