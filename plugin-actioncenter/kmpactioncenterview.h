#ifndef KMPACTIONCENTERVIEW_H
#define KMPACTIONCENTERVIEW_H

#include <QWidget>
class KMPActionCenterView : public QWidget {
  Q_OBJECT
public:
  explicit KMPActionCenterView(QWidget *parent = nullptr);

private:
  QSize screenSize() const;
signals:

  // QObject interface
public:
  bool eventFilter(QObject *watched, QEvent *event);
};

#endif // KMPACTIONCENTERVIEW_H
