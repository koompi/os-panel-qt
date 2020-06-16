#include "actioncenterui.h"
#include "actioncenterhome.h"
#include "brightness/brightness.h"
#include <QThread>
#include <QDebug>
ActionCenterHome::ActionCenterHome(QWidget *parent) :
    QWidget(parent),ui(new Ui::Quick_Center)
{
   ui->setupUi(this);
   initDependency();
   initAction();
}

ActionCenterHome::~ActionCenterHome()
{
    delete ui;
}

void ActionCenterHome::initAction()
{
    connect(ui->shutdown_btn, &QToolButton::clicked, [](){
        QApplication::exit(0);
    });
    connect(actionDateTime, &ActionDateTime::timeChanged, ui->ac_time, &QLabel::setText);
    connect(actionDateTime, &ActionDateTime::dateChanged, ui->ac_date, &QLabel::setText);
    bright = new brightness(this);
    connect (ui->ac_slider_gamma, &QSlider::valueChanged,bright, &brightness::getCurrentValue);
    connect(ui->ac_slider_gamma, &QSlider::valueChanged, [&](const int & value) {
           ui->ac_gamma_level->setText(QString::number (value).append (QStringLiteral("%")));
        });
    blue = new bluelight(this);
        connect (ui->ac_slider_bright,&QSlider::valueChanged, blue,&bluelight::getCurrentValue );
        connect (ui->ac_slider_bright,&QSlider::valueChanged, [&](const int & value){
            ui->ac_bright_level->setText (
            QString::number(value).append (QStringLiteral("%")));
        });
}
void ActionCenterHome::initDependency()
{
   actionDateTime = new ActionDateTime();
}
