#ifndef ACIONCENTERHOME_H
#define ACIONCENTERHOME_H

#include <QWidget>
#include <QStackedWidget>
#include "actiondatetime.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Quick_Center;}
QT_END_NAMESPACE
class ActionCenterHome : public QWidget
{
    Q_OBJECT
public:
    explicit ActionCenterHome(QWidget *parent = nullptr);
    ~ActionCenterHome();

    QStackedWidget *getStack() const;
    void setStack(QStackedWidget *value);

    QWidget *getBlueInstance() const;
    void setBlueInstance(QWidget *value);

private:
    Ui::Quick_Center * ui;
    ActionDateTime * actionDateTime;
    void initAction();
    void initDependency();
    QStackedWidget * stack{};
    QWidget * blueInstance{};
signals:

};

#endif // ACIONCENTERHOME_H
