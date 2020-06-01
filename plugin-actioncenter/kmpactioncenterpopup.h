#ifndef KMPACTIONCENTERPOPUP_H
#define KMPACTIONCENTERPOPUP_H
#include <QWidget>
class LXQtPanel;
class KMPControlCenterItem;
class KMPActionCenterPopUP : public QWidget{
  Q_OBJECT
public:
  KMPActionCenterPopUP(QWidget *parent = nullptr);

  // QObject interface
public:
  bool event(QEvent *event);
  bool eventFilter(QObject *watched, QEvent *event);
  // QWidget interface
private:
  KMPControlCenterItem *actionItem = nullptr;
signals:
  void signal_show_window();
  void signal_hide_window();
};
#endif // KMPACTIONCENTERPOPUP_H
