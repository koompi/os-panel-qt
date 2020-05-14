#ifndef LXQTACENTER_H
#define LXQTACENTER_H
#include "../panel/ilxqtpanelplugin.h"
#include "kmpactioncenterview.h"
#include <QObject>
#include <QPointer>
#include <QTimer>
#include <QToolButton>

class KMPActionCenterView;
class LXQtPanel;
class KMPActionCenter : public QObject, public ILXQtPanelPlugin {
  Q_OBJECT
public:
  KMPActionCenter(const ILXQtPanelPluginStartupInfo &startupInfo);
  ~KMPActionCenter();

  QString themeId() const { return QStringLiteral("TaskBar"); }
  virtual Flags flags() const {
    return HaveConfigDialog | PreferRightAlignment;
  }

  QWidget *widget();
  QDialog *configureDialog();

  void realign();

  bool isSeparate() const { return true; }

protected:
  bool eventFilter(QObject *obj, QEvent *event);

private:
  void setButtonIcon();
  KMPActionCenterView *m_actionButton;
  //  QPointer<ConfigPanelWidget> configWidget;
};

class KMPActionCenterPluginLibrary : public QObject,
                                     public ILXQtPanelPluginLibrary {
  Q_OBJECT
  //  Q_PLUGIN_METADATA(IID "lxqt.org/Panel/PluginInterface/3.0")
  Q_INTERFACES(ILXQtPanelPluginLibrary)
public:
  ILXQtPanelPlugin *
  instance(const ILXQtPanelPluginStartupInfo &startupInfo) const {
    return new KMPActionCenter(startupInfo);
  }
};

#endif // LXQTACENTER_H
