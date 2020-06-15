#ifndef ACTIONDATETIME_H
#define ACTIONDATETIME_H

#include <QObject>
#include <QLabel>
class ActionDateTime : public QObject
{
    Q_OBJECT
private:
    QWidget * timeParent;
    QString timeObjName;
    int duration;
public:
    explicit ActionDateTime(QObject *parent = nullptr, int duration = 2000);
    QLabel * createTime();
    QLabel * createDate();
    int getDuration() const;
    void setDuration(int value);

signals:
    void timeChanged(QString time);
    void dateChanged(QString date);
public slots:
    void showTime();
    void showDate();
    void chnageDateFormat(const QString & formatString);
};

#endif // ACTIONDATETIME_H
