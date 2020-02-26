#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QProcess>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
class controlcenter : public QWidget {
    Q_OBJECT
public:
    explicit controlcenter(QWidget *parent = nullptr);
    ~controlcenter();
signals:

private:
    int m_width, m_height;
    QTimer *timeStop = nullptr;

public:
    bool event(QEvent *event);

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // controlcenter_H
