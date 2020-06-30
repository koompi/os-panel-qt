#ifndef ACIONCENTERHOME_H
#define ACIONCENTERHOME_H

#include <QWidget>
#include "actiondatetime.h"
#include "userprofile.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Quick_Center;}
QT_END_NAMESPACE
class ActionCenterHome : public QWidget
{
    Q_OBJECT
public:
    explicit ActionCenterHome(QWidget *parent = nullptr);
    ~ActionCenterHome();
private:
    Ui::Quick_Center * ui;
    ActionDateTime * actionDateTime;
    void initAction();
    void initDependency();
    userprofile *profile;
    QPixmap pic;
public slots:
    void on_filename(const QString &filename);

};

#endif // ACIONCENTERHOME_H
