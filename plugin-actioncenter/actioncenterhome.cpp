#include "actioncenterui.h"
#include "actioncenterhome.h"
#include <QThread>
#include <QDebug>
ActionCenterHome::ActionCenterHome(QWidget *parent) :
    QWidget(parent),ui(new Ui::Quick_Center)
{
   ui->setupUi(this);
   night = new nightmodeconfig(this);
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
    connect (ui->nightmode_btn, &QToolButton::toggled, [&](bool state){
       if  (state){
           qDebug()<<"state"<<state<<Qt::endl;
           night->nightmodeon ();
       }
       else {
           night->nightmodeoff ();
       }
    });

}
void ActionCenterHome::initDependency()
{
   actionDateTime = new ActionDateTime();
}
