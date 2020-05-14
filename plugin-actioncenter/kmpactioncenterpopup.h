#ifndef KMPACTIONCENTERPOPUP_H
#define KMPACTIONCENTERPOPUP_H
#include <QDialog>
class LXQtPanel;
class KMPActionCenterPopUP : public QDialog {
  Q_OBJECT
public:
  KMPActionCenterPopUP(QWidget *parent = nullptr);
  // QObject interface
public:
  bool event(QEvent *event);
  bool eventFilter(QObject *watched, QEvent *event);
  // QWidget interface

signals:
  void signal_show_window();
  void signal_hide_window();
};
#endif // KMPACTIONCENTERPOPUP_H
