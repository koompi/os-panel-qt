#ifndef ACTIONSMBUTTON_H
#define ACTIONSMBUTTON_H
#include <QObject>
#include <QToolButton>
#include <QSlider>
#include <QLabel>
class ActionSMButton : public QObject{
    Q_OBJECT
private:
    QWidget * btn_parent;
    QString btn_name;
    QString btn_icon;
public:
    ActionSMButton(){}
    ActionSMButton(QWidget * parent,const QString & name, QString iconName):
        btn_parent(parent),
        btn_name(name),btn_icon(iconName) {}
    virtual ~ActionSMButton(){}
    QToolButton * createInstance(){
        QToolButton * small_button = new QToolButton(btn_parent);
        small_button->setObjectName(btn_name);
        small_button->setStyleSheet(QString::fromUtf8("background-color:#f5f6fa;"));
        QIcon sm_icon;
        if (QIcon::hasThemeIcon(btn_icon)) {
            sm_icon = QIcon::fromTheme(btn_icon);
        } else {
            sm_icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        small_button->setIcon(sm_icon);
        return small_button;
    }
    QSlider * createSlider(QString sliderName){
        QSlider *  slider = new QSlider(btn_parent);
        slider->setObjectName(sliderName);
        slider->setStyleSheet(QString::fromUtf8("color:white"));
        slider->setOrientation(Qt::Horizontal);
        return slider;
    }
    QLabel * createLabel(QString labelName){
        QLabel * label = new QLabel(btn_parent);
        label->setObjectName(labelName);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color:white"));
        return label;
    }
};
#endif // ACTIONSMBUTTON_H
