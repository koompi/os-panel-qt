#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H
#include <QObject>
#include <QToolButton>
#include "actionbuttonstyle.h"
class ActionButton : public QObject
{
    Q_OBJECT
private:
    QWidget * parent = nullptr;
    QString iconName;
    QString name;
    QSize size;
public:
    ActionButton() {}
    ActionButton(QWidget * parent, QString name ,const QString & iconName, QSize size={100, 100}){
        this->parent = parent;
        this->iconName = iconName;
        this->name = name;
        this->size = size;
    }
    QToolButton * createInstance(){
        QToolButton * button_name = new QToolButton(parent);
        button_name->setObjectName(name);
        QSizePolicy button_sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        button_sizePolicy.setHorizontalStretch(0);
        button_sizePolicy.setVerticalStretch(0);
        button_sizePolicy.setHeightForWidth(button_name->sizePolicy().hasHeightForWidth());
        button_name->setSizePolicy(button_sizePolicy);
        button_name->setMinimumSize(size);
        button_name->setStyleSheet(ActionButtonStyle::bgButtonStyle());
        QIcon icon2;
        if (QIcon::hasThemeIcon(iconName)) {
            icon2 = QIcon::fromTheme(iconName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        button_name->setIcon(icon2);
        button_name->setIconSize(QSize(size.width() / 2, size.height() / 2));
        button_name->setPopupMode(QToolButton::InstantPopup);
        button_name->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        button_name->setAutoRaise(false);
        return button_name;
    }
    virtual ~ActionButton() {}

};

#endif // ACTIONBUTTON_H
