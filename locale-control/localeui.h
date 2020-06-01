#ifndef LOCALEUI_H
#define LOCALEUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QStackedWidget>
#include "localecontrol.h"
#include <QLocale>
#include <QTimeZone>
#include <QProcess>
#include <QDateTime>
#include <QtCore>
#include "localeconfig.h"
class localeUi : public QWidget
{
    Q_OBJECT
public:
    explicit localeUi(QWidget *parent = nullptr);
    void setupUi(QWidget *Form);
    void retranslateUi(QWidget*Form);
    QStackedWidget *getLocaleStacked() const;
    void setLocaleStacked(QStackedWidget *value);
    QVBoxLayout *verticalLayout;
        QHBoxLayout *localehorizontalLayout;
        QToolButton *backbtn;
        QLabel *localeLabel;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        QHBoxLayout *RegionLayout;
        QLabel *region;
        QSpacerItem *horizontalSpacer_2;
        QComboBox *regionBox;
        QHBoxLayout *LanguageLayout;
        QLabel *languages;
        QSpacerItem *horizontalSpacer_3;
        QComboBox *LanguageBox;
        QHBoxLayout *timeFormatLayout;
        QLabel *timeformat;
        QSpacerItem *horizontalSpacer_4;
        QComboBox *timeformatBox;
        QHBoxLayout *timezoneLayout;
        QLabel *timezone;
        QSpacerItem *horizontalSpacer_6;
        QComboBox *timezoneBox;
        QSpacerItem *verticalSpacer_3;
        QHBoxLayout *horizontalLayout;
        QSpacerItem *horizontalSpacer_5;
        QPushButton *advancedBtn;
        QPushButton *applyBtn;
        QSpacerItem *verticalSpacer_4;
        QFrame *descframe;
        QVBoxLayout *verticalLayout_3;
        QHBoxLayout *horizontalLayout_6;
        QLabel *description;
        QSpacerItem *horizontalSpacer_10;
        QHBoxLayout *horizontalLayout_7;
        QSpacerItem *horizontalSpacer_11;
        QVBoxLayout *verticalLayout_2;
        QHBoxLayout *horizontalLayout_2;
        QLabel *regionlabel;
        QSpacerItem *horizontalSpacer_7;
        QLabel *regionValue;
        QHBoxLayout *horizontalLayout_3;
        QLabel *languagelabel;
        QSpacerItem *horizontalSpacer_8;
        QLabel *langValue;
        QHBoxLayout *horizontalLayout_4;
        QLabel *timeformatlabel;
        QLabel *timeformValue;
        QHBoxLayout *horizontalLayout_5;
        QLabel *timezonelabel;
        QSpacerItem *horizontalSpacer_9;
        QLabel *timezoneValue;
        QSpacerItem *verticalSpacer_5;
        QSpacerItem *verticalSpacer;
    QStackedWidget *localeStack;
    localecontrol *localeCon;
    QString timezone_id;
public:
    void setRegionName();
    void setLanguageName();
    void setTimezone();
    void setTimeFormat();
    QList<QComboBox *> listcombos();
    void updateDescription();
    const std::tuple<QString, QString>  currentLang();
//    QLocale::Country getCurrentTimeZone();

    QString getTimezone_id() const;
    void setTimezone_id(const QString &value);

signals:
    void onCurrentTextChanged(QString text);

private:
    localeconfig * localeSetting;
};

#endif // LOCALEUI_H
