#include "actioncenterui.h"
#include "actioncenterhome.h"
#include <QThread>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
ActionCenterHome::ActionCenterHome(QWidget *parent) :
    QWidget(parent),ui(new Ui::Quick_Center)
{
    ui->setupUi(this);
    profile=new userprofile(this);
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
    connect (profile, &userprofile::notify_filename, this, &ActionCenterHome::on_filename);
    connect(ui->ac_profile,&QToolButton::clicked, profile,&userprofile::getUserprofile );
}
void ActionCenterHome::initDependency()
{
    actionDateTime = new ActionDateTime();
}

void ActionCenterHome::on_filename(const QString &filename)
{
    pic.load(filename);
    QPixmap rounded = QPixmap(ui->ac_profile->width (),ui->ac_profile->height ());
    rounded.fill(Qt::transparent);

    QPainterPath path;
    path.addEllipse(rounded.rect());
    QPainter painter(&rounded);
    painter.setClipPath(path);
    painter.fillRect(rounded.rect(), Qt::darkGray);
    int x = 0;
    int y = 0;
    painter.drawPixmap(x, y, pic.width(), pic.height(), pic);
    ui->ac_profile->setIconSize (rounded.size ());
    ui->ac_profile->setIcon(pic);
}
