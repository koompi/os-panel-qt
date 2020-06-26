#include "actioncenterui.h"
#include "actioncenterhome.h"
#include <QThread>
#include <QDebug>
ActionCenterHome::ActionCenterHome(QWidget *parent) :
    QWidget(parent),ui(new Ui::Quick_Center)
{
   ui->setupUi(this);
   airplane = new airplaneConfig(this);
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
    connect (ui->airplan_btn,&QToolButton::toggled, [&](bool state){
        qDebug()<<"state:" <<state<<Qt::endl ;
        if(state ){

            airplane->airplaneModeon();
            ui->airplan_btn->setStyleSheet (QStringLiteral ("background-color:rgba(0, 0, 0, 0.5);border-radius:5px;"));
        }
        else{
            airplane->airplaneModeoff ();
             ui->airplan_btn->setStyleSheet (QStringLiteral ("background-color:rgba(0, 0, 0, 0.2);border-radius:5px;"));
        }
    });

}
void ActionCenterHome::initDependency()
{
   actionDateTime = new ActionDateTime();
}
