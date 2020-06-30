#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QObject>
#include <QWidget>
#include <QFileDialog>

class userprofile : public QWidget
{
    Q_OBJECT
public:
    explicit userprofile(QWidget *parent = nullptr);
    void getUserprofile();
signals:
   void notify_filename(QString filename);
};

#endif // USERPROFILE_H
