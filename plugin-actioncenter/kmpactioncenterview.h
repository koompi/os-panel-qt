#ifndef KMPACTIONCENTERVIEW_H
#define KMPACTIONCENTERVIEW_H

#include "kmpactioncenterpopup.h"
#include <QToolButton>
// class KMPActionCenterPopUP;
class ILXQtPanel;
class KMPActionCenter;
class ILXQtPanelPlugin;
class KMPActionCenterView : public QToolButton {
  Q_OBJECT
public:
  KMPActionCenterView(ILXQtPanelPlugin *plugin, ILXQtPanel *m_panel,
                      QWidget *parent = nullptr);
  ~KMPActionCenterView();
  bool eventFilter(QObject *watched, QEvent *event);

  ILXQtPanel *panel() const;
  void setPanel(ILXQtPanel *panel);

private:
  QSize screenSize() const;
  ILXQtPanelPlugin *m_plugin;
  ILXQtPanel *m_panel;
  KMPActionCenterPopUP *m_actionPopup;
  void buildActionCenter();
  void hideActionCenter();
  void showActionCenter();
  void toggleActionCenter();
  void handleActionCenterIconChanged(const QString &iconName);
  // CONSTANT VARIABLE
  const float ACTION_CENTER_WIDTH = 0.20;

private slots:
  void handleShowWindow();
  void handleHideWindow();
signals:
  // QObject interface

protected:
  //  void leaveEvent(QEvent *event);
  //  void enterEvent(QEvent *) override;
  //  void mousePressEvent(QMouseEvent *) override;
  //  void mouseReleaseEvent(QMouseEvent *) override;
};

#endif // KMPACTIONCENTERVIEW_H
