#include "controlcenter.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>
controlcenter::controlcenter(QWidget *parent)
    :  QWidget(parent, Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint |
               Qt::Popup | Qt::X11BypassWindowManagerHint) {
    this->setObjectName("control center applet");
    QScreen *screen = QGuiApplication::primaryScreen();
    m_width = screen->geometry().width();
    m_height = screen->geometry().height();
    resize(m_width * 0.25, m_height);
    // ui component declarations


    // ui component configurations
    timeStop = new QTimer(this);
    timeStop->setInterval(5000);
    connect(timeStop, &QTimer::timeout, this, &controlcenter::hide);
}

controlcenter::~controlcenter() {
    QString deleted_info =
            QString("%1 get destroyed in the heap").arg(this->objectName());
    qDebug() << deleted_info;
}


bool controlcenter::event(QEvent *event) {
    if (event->type() == QEvent::WindowDeactivate) {
        this->hide();
    } else if (event->type() == QEvent::ToolTip) {
        qDebug() << "you hover on sound applet";
    }
    return QWidget::event(event);
}

void controlcenter::enterEvent(QEvent *event) {
    if (event->type() == QEvent::Enter) {
        qDebug() << "you enter concenter applet area";
        timeStop->stop();
    }
    return QWidget::enterEvent(event);
}

void controlcenter::leaveEvent(QEvent *event) {

    if (event->type() == QEvent::Leave) {
        qDebug() << "you left concenter applet area";
        timeStop->start();
    }
    return QWidget::leaveEvent(event);
}
