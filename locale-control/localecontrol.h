#ifndef LOCALECONTROL_H
#define LOCALECONTROL_H

#include <QWidget>
#include <QLocale>
#include <QDebug>
#include <lxqt/LXQt/Settings>
#include "localeui.h"
#include <QComboBox>
class localecontrol : public QWidget
{
    Q_OBJECT
public:

    explicit localecontrol(LXQt::Settings *settings, QWidget *parent = 0);
    ~localecontrol();

    void load();
//    void save();
    void defaults();

    QStackedWidget *getLocaleStacked() const;
    void setLocaleStacked(QStackedWidget *value);

public slots:
    void initControls();
    void saveSettings();
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
    bool hasChanged;
    LXQt::Settings *mSettings;
    localeUi *   m_ui = nullptr;
    QStackedWidget *LocaleStacked;
signals:
    void emitRegionLists(QString regions);
    void emitLanguageLists(QString regions);
    void currentIndexChanged(int);
    void getTimeFormat();
    void save();
    void reset();
};
#endif // LOCALECONTROL_H
