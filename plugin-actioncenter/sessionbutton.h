#ifndef SESSIONBUTTON_H
#define SESSIONBUTTON_H
#include <QObject>
#include <QToolButton>
#include "actionbuttonstyle.h"
class SessionButton: public QObject{

    Q_OBJECT
private:
    QWidget *btn_parent;
    QString btn_name;
    QString btn_theme;

public:
    SessionButton(){}
    SessionButton(QWidget * parent, QString name, QString theme):
        btn_parent(parent), btn_name(name),btn_theme(theme){
    }
    QToolButton * createSessionButton(){
        QToolButton * sessionButton = new QToolButton(btn_parent);
        sessionButton->setObjectName(QString::fromUtf8("logout_btn"));
        sessionButton->setMinimumSize(QSize(45, 45));
        sessionButton->setStyleSheet(ActionButtonStyle::smButtonStyle());
        QIcon icon14;
        if (QIcon::hasThemeIcon(btn_theme)) {
            icon14 = QIcon::fromTheme(btn_theme);
        } else {
            icon14.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        sessionButton->setIcon(icon14);
        sessionButton->setIconSize(QSize(32, 32));
        sessionButton->setAutoRaise(false);
        return sessionButton;
    }
};

#endif // SESSIONBUTTON_H
