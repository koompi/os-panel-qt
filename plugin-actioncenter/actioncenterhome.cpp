#include "actioncenterui.h"
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
    connect(ui->btooth_btn, &QToolButton::clicked, [&](){
        getStack()->setCurrentWidget(getBlueInstance());
    });
}
void ActionCenterHome::initDependency()
{
   actionDateTime = new ActionDateTime(this);
}

QWidget *ActionCenterHome::getBlueInstance() const
{
    return blueInstance;
}

void ActionCenterHome::setBlueInstance(QWidget *value)
{
    blueInstance = value;
}

QStackedWidget *ActionCenterHome::getStack() const
{
    return stack;
}

void ActionCenterHome::setStack(QStackedWidget *value)
{
    stack = value;
}
