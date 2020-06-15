#include "ui_actioncenterhome.h"
#include "actioncenterhome.h"
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

}
void ActionCenterHome::initDependency()
{
   actionDateTime = new ActionDateTime();
}

