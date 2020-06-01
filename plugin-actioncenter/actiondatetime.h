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
public:
    explicit ActionDateTime(QObject *parent = nullptr, QWidget * timeparent= nullptr, QString name=QStringLiteral("action_time"));
    QLabel * createTime();
    QLabel * createDate();
signals:
    void timeChanged(QString time);
    void dateChanged(QString date);
public slots:
    void showTime();
    void showDate();
    void chnageDateFormat(const QString & formatString);
};

#endif // ACTIONDATETIME_H
