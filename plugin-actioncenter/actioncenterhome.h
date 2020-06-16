#ifndef ACIONCENTERHOME_H
#define ACIONCENTERHOME_H

#include <QWidget>
#include "actiondatetime.h"
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Quick_Center;}
QT_END_NAMESPACE
class ActionCenterHome : public QWidget
{
    Q_OBJECT
public:
    explicit ActionCenterHome(QWidget *parent = nullptr);
    ~ActionCenterHome();
    QStackedWidget *getStackWidget() const;
    void setStackWidget(QStackedWidget *value);

private:
    Ui::Quick_Center * ui;
    ActionDateTime * actionDateTime;
    QStackedWidget * stackWidget;
    void initAction();
    void initDependency();
signals:

};

#endif // ACIONCENTERHOME_H
