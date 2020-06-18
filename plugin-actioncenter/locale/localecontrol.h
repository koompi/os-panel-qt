#ifndef LOCALECONTROL_H
#define LOCALECONTROL_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QProcess>
#include <QLocale>
#include <QDebug>
#include <lxqt/LXQt/Settings>
#include <QComboBox>
#include "localeUi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LocaleUi;}
QT_END_NAMESPACE

class localecontrol : public QWidget
{
    Q_OBJECT
public:
    explicit localecontrol(LXQt::Settings *settings,QWidget *parent = 0);
    ~localecontrol();
    QStackedWidget *getStack() const;
    void setStack(QStackedWidget *value);
//    void setTimezone();
//    QString getTimezone_id() const;
//      void setTimezone_id(const QString &value);
    void load();
    //    void save();
    void defaults();
public slots:
    void initControls();
    void saveSettings();
signals:
    void emitRegionLists(QString regions);
    void emitLanguageLists(QString regions);
    void currentIndexChanged(int);
    void getTimeFormat();
    void save();
    void reset();

private:
    void addLocaleToCombo(QComboBox *combo, const QLocale &locale);
    void initCombo(QComboBox *combo, const QList<QLocale> &allLocales);
    void connectCombo(QComboBox *combo);
    QList<QComboBox *> m_combos;

    void readConfig();
    void writeConfig();
    //    void writeExports();

    void updateDescription();
    void updateEnabled();
    Ui::LocaleUi * ui;
    QStackedWidget * stack;
    bool hasChanged;
    LXQt::Settings *mSettings;
};

#endif // LOCALECONTROL_H
