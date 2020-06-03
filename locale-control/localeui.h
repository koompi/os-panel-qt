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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QCheckBox>
#include <QStackedWidget>
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
    void setupUi(QWidget *LocaleUi);
    void retranslateUi(QWidget* LocaleUi);
    QStackedWidget *getLocaleStacked() const;
    void setLocaleStacked(QStackedWidget *value);
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *langRegionLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *backBtn;
    QLabel *title;
    QFormLayout *actionForm;
    QLabel *label;
    QComboBox *comRegion;
    QCheckBox *checkBox;
    QLabel *labelNumber;
    QComboBox *comNumbers;
    QLabel *labelTime;
    QComboBox *comTime;
    QLabel *labelCurrency;
    QComboBox *comCurrentcy;
    QLabel *labelMeasurement;
    QComboBox *comMeasurement;
    QLabel *labelCollection;
    QComboBox *comColSort;
    QLabel *descLabel;
    QFormLayout *descriptForm;
    QLabel *numberLabel;
    QLabel *numberValue;
    QLabel *timeLabel;
    QLabel *timeValue;
    QLabel *currentcyLabel;
    QLabel *currentcyValue;
    QLabel *measureLabel;
    QLabel *measureValue;
    QHBoxLayout *buttonLayout;
    QPushButton *cacelBtn;
    QPushButton *applyBtn;
    QStackedWidget *localeStack;
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

};

#endif // LOCALEUI_H
