#include "displayui.h"
#include <QProcess>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

displayui::displayui(QWidget *parent) : QWidget(parent)
{
    setupUi (this);
    connect (backbtn, &QToolButton::clicked, [&](){
        displayStack->setCurrentIndex (0);
    });
    connect(advancedbtn, &QToolButton::clicked, []() {
        QProcess process;
        process.startDetached("systemsettings5");
        process.waitForStarted();
        process.waitForFinished(-1);
        process.close();
    });
    laptop = new controldisplay();
    connect(laptopbtn,&QToolButton::clicked, laptop,&controldisplay::getDisplayName);
    connect (laptop, &controldisplay::onReadyGetDisplayName, this, &displayui::laptop_display);

    external = new controldisplay();
    connect(externalbtn, &QToolButton::clicked, external,&controldisplay::getDisplayName);
    connect (external, &controldisplay::onReadyGetDisplayName, this, &displayui::monitor_display);

    unify = new controldisplay();
    checkoutScreen ();
    connect(unifybtn, &QToolButton::clicked, unify,&controldisplay::getDisplayName);
    connect (unify, &controldisplay::onReadyGetDisplayName, this, &displayui::unify_display);
    extendRight = new controldisplay();
    connect(extendrigthbtn, &QToolButton::clicked, extendRight,&controldisplay::getDisplayName);
    connect (extendRight, &controldisplay::onReadyGetDisplayName, this, &displayui::extendR_display);

    extendLeft = new controldisplay();
    connect(extendleftbtn, &QToolButton::clicked, extendLeft,&controldisplay::getDisplayName);
    connect (extendLeft, &controldisplay::onReadyGetDisplayName, this, &displayui::extendL_display);
     //smartunify button
//    smartUnify = new controldisplay();
//    connect (smartunify, &QToolButton::clicked,  smartUnify, &controldisplay::getDisplayName);
//    connect (smartUnify, &controldisplay::onReadyGetDisplayName, this, &displayui::on_smartUnify);
}
void displayui::setupUi(QWidget *Form)
{
    if (Form->objectName().isEmpty())
               Form->setObjectName(QString::fromUtf8("Form"));
           Form->resize(467, 876);
           QScreen *screen = QGuiApplication::primaryScreen();
           m_width = screen->geometry().width();
           m_height = screen->geometry().height();
           resize(m_width * 0.25, m_height);
           Form->resize(m_width * 0.25, m_height * 0.95);
           QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
           sizePolicy.setHorizontalStretch(0);
           sizePolicy.setVerticalStretch(0);
           sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
           Form->setSizePolicy(sizePolicy);
           Form->setMinimumSize(QSize(300, 0));
           verticalLayout_2 = new QVBoxLayout(Form);
           verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
           horizontalLayout = new QHBoxLayout();
           horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
           backbtn = new QToolButton(Form);
           backbtn->setObjectName(QString::fromUtf8("backbtn"));
           QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
           sizePolicy1.setHorizontalStretch(0);
           sizePolicy1.setVerticalStretch(0);
           sizePolicy1.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
           backbtn->setSizePolicy(sizePolicy1);
           backbtn->setMinimumSize(QSize(0, 0));
           QIcon icon;
           QString iconThemeName = QString::fromUtf8("draw-arrow-back");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon = QIcon::fromTheme(iconThemeName);
           } else {
               icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           backbtn->setIcon(icon);
           backbtn->setAutoRaise(false);

           horizontalLayout->addWidget(backbtn);

           displayLabel = new QLabel(Form);
           displayLabel->setObjectName(QString::fromUtf8("displayLabel"));
           sizePolicy.setHeightForWidth(displayLabel->sizePolicy().hasHeightForWidth());
           displayLabel->setSizePolicy(sizePolicy);
           displayLabel->setMinimumSize(QSize(0, 0));
           displayLabel->setMaximumSize(QSize(16777215, 50));
           QFont font;
           font.setPointSize(15);
           displayLabel->setFont(font);
           displayLabel->setAlignment(Qt::AlignCenter);

           horizontalLayout->addWidget(displayLabel);

           horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

           horizontalLayout->addItem(horizontalSpacer);


           verticalLayout_2->addLayout(horizontalLayout);

           verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

           verticalLayout_2->addItem(verticalSpacer);

           verticalLayout = new QVBoxLayout();
           verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
           externalbtn = new QToolButton(Form);
           externalbtn->setObjectName(QString::fromUtf8("externalbtn"));
           sizePolicy.setHeightForWidth(externalbtn->sizePolicy().hasHeightForWidth());
           externalbtn->setSizePolicy(sizePolicy);
           QFont font1;
           font1.setPointSize(12);
           externalbtn->setFont(font1);
           externalbtn->setLayoutDirection(Qt::LeftToRight);
           externalbtn->setAutoFillBackground(false);
           externalbtn->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
           QIcon icon1;
           iconThemeName = QString::fromUtf8("osd-shutd-laptop");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon1 = QIcon::fromTheme(iconThemeName);
           } else {
               icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           externalbtn->setIcon(icon1);
           externalbtn->setIconSize(QSize(36, 36));
           externalbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           externalbtn->setAutoRaise(false);

           verticalLayout->addWidget(externalbtn);

           laptopbtn = new QToolButton(Form);
           laptopbtn->setObjectName(QString::fromUtf8("laptopbtn"));
           sizePolicy.setHeightForWidth(laptopbtn->sizePolicy().hasHeightForWidth());
           laptopbtn->setSizePolicy(sizePolicy);
           laptopbtn->setFont(font1);
           laptopbtn->setLayoutDirection(Qt::LeftToRight);
           laptopbtn->setAutoFillBackground(false);
           laptopbtn->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
           QIcon icon2;
           iconThemeName = QString::fromUtf8("osd-shutd-screen");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon2 = QIcon::fromTheme(iconThemeName);
           } else {
               icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           laptopbtn->setIcon(icon2);
           laptopbtn->setIconSize(QSize(36, 36));
           laptopbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           laptopbtn->setAutoRaise(false);

           verticalLayout->addWidget(laptopbtn);

           unifybtn = new QToolButton(Form);
           unifybtn->setObjectName(QString::fromUtf8("unifybtn"));
           sizePolicy.setHeightForWidth(unifybtn->sizePolicy().hasHeightForWidth());
           unifybtn->setSizePolicy(sizePolicy);
           unifybtn->setFont(font1);
           unifybtn->setLayoutDirection(Qt::LeftToRight);
           unifybtn->setAutoFillBackground(false);
           unifybtn->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
           QIcon icon3;
           iconThemeName = QString::fromUtf8("osd-duplicate");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon3 = QIcon::fromTheme(iconThemeName);
           } else {
               icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           unifybtn->setIcon(icon3);
           unifybtn->setIconSize(QSize(36, 36));
           unifybtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           unifybtn->setAutoRaise(false);

           verticalLayout->addWidget(unifybtn);

           extendleftbtn = new QToolButton(Form);
           extendleftbtn->setObjectName(QString::fromUtf8("extendleftbtn"));
           sizePolicy.setHeightForWidth(extendleftbtn->sizePolicy().hasHeightForWidth());
           extendleftbtn->setSizePolicy(sizePolicy);
           extendleftbtn->setFont(font1);
           extendleftbtn->setLayoutDirection(Qt::LeftToRight);
           extendleftbtn->setAutoFillBackground(false);
           extendleftbtn->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
           QIcon icon4;
           iconThemeName = QString::fromUtf8("osd-sbs-left");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon4 = QIcon::fromTheme(iconThemeName);
           } else {
               icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           extendleftbtn->setIcon(icon4);
           extendleftbtn->setIconSize(QSize(36, 36));
           extendleftbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           extendleftbtn->setAutoRaise(false);

           verticalLayout->addWidget(extendleftbtn);

           extendrigthbtn = new QToolButton(Form);
           extendrigthbtn->setObjectName(QString::fromUtf8("extendrigthbtn"));
           sizePolicy.setHeightForWidth(extendrigthbtn->sizePolicy().hasHeightForWidth());
           extendrigthbtn->setSizePolicy(sizePolicy);
           extendrigthbtn->setFont(font1);
           extendrigthbtn->setLayoutDirection(Qt::LeftToRight);
           extendrigthbtn->setAutoFillBackground(false);
           extendrigthbtn->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
           QIcon icon5;
           iconThemeName = QString::fromUtf8("osd-sbs-sright");
           if (QIcon::hasThemeIcon(iconThemeName)) {
               icon5 = QIcon::fromTheme(iconThemeName);
           } else {
               icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
           }
           extendrigthbtn->setIcon(icon5);
           extendrigthbtn->setIconSize(QSize(36, 36));
           extendrigthbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
           extendrigthbtn->setAutoRaise(false);

           verticalLayout->addWidget(extendrigthbtn);

           advancedbtn = new QToolButton(Form);
           advancedbtn->setObjectName(QString::fromUtf8("advancedbtn"));
           advancedbtn->setLayoutDirection(Qt::RightToLeft);

           verticalLayout->addWidget(advancedbtn);


           verticalLayout_2->addLayout(verticalLayout);

           verticalSpacer_2 = new QSpacerItem(20, 434, QSizePolicy::Minimum, QSizePolicy::Expanding);

           verticalLayout_2->addItem(verticalSpacer_2);


           retranslateUi(Form);

           QMetaObject::connectSlotsByName(Form);
} // setupUi

void displayui ::retranslateUi(QWidget *Form)
{
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
            backbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
            displayLabel->setText(QCoreApplication::translate("Form", "Display", nullptr));
            externalbtn->setText(QCoreApplication::translate("Form", " External screen", nullptr));
            laptopbtn->setText(QCoreApplication::translate("Form", " Laptop screen", nullptr));
            unifybtn->setText(QCoreApplication::translate("Form", " Unify  output", nullptr));
            extendleftbtn->setText(QCoreApplication::translate("Form", " Extend to left", nullptr));
            extendrigthbtn->setText(QCoreApplication::translate("Form", " Extend to right", nullptr));
            advancedbtn->setText(QCoreApplication::translate("Form", "Advanced Display Settings", nullptr));
}

QScreen * displayui::getPrimaryScreen()
{
    return QGuiApplication::primaryScreen();
}

void displayui::checkoutScreen()
{
    qInfo() << "checkscreen called: ";
    QProcess *process = new QProcess(this);
    connect (process,&QProcess::readyReadStandardOutput, [&](){
        QByteArray data= process->readAllStandardOutput ();
        QString dataString(data);
        QStringList dataSplit = dataString.split ('\n');
        dataSplit.pop_back ();
        dataSplit.removeAt (1);
        setOn_getDataSplit (dataSplit);
    });
    process->start ("bash",
                            QStringList()
                            <<"-c"
                            <<"xrandr --query | grep -A 1 connected | grep -v connected | awk '{print $1}' | cut -f2 -d\"-\"",QIODevice::ReadOnly);
    process->waitForFinished ();
    process->close ();

}

QStackedWidget *displayui::getDisplayStacked() const
{
    return displayStack;
}

void displayui::setDisplayStacked(QStackedWidget *value)
{
    displayStack = value;
}

void displayui::laptop_display(QStringList displayname)
{
    qDebug() << displayname<<Qt::endl;
    qDebug() <<"first:"<< displayname.first () <<Qt::endl;
    qDebug() <<"last: "<< displayname.last ()<<Qt::endl;
    QProcess * disprocess = new QProcess(this);
    // functor base signal Overload
    connect(disprocess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),

            [&]  (int exitCode, QProcess::ExitStatus exitStatus)
    {
        qDebug() << "Exit code"<< exitCode<< "\t" << "Status: " << exitStatus<<Qt::endl;//to check the process
    });
    disprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--off"<<"--output"<<displayname.first ()<<"--auto"<<"--primary");
    disprocess->waitForFinished();
    disprocess->close ();
}

void displayui::monitor_display(QStringList displayname){
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
        QProcess::execute ("xrandr",QStringList() <<"--output" << displayname.last ()<<"--mode"<< "1920x1080");
    }
    QProcess * monitorprocess = new QProcess(this);
    monitorprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--off"<<"--output"<<displayname.last ()<<"--auto"<<"--primary");
    monitorprocess->waitForFinished();
    monitorprocess->close ();
}

void displayui::unify_display(QStringList displayname)
{
    qInfo() << "unify called";
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ()) == 0){
        qInfo() << "Both sreen equal "<<Qt::endl;
        QProcess * unifyprocess = new QProcess(this);
        if(displayname.first () == getPrimaryScreen ()->name ()){
            unifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--auto"<<"--output"<<displayname.first ());
            unifyprocess->waitForFinished();
            unifyprocess->close ();
            return;
        }
        if(displayname.last () == getPrimaryScreen ()->name ()){
            unifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--auto"<<"--output"<<displayname.last ());
            unifyprocess->waitForFinished();
            unifyprocess->close ();
            return;
        }
    }else{
        qInfo() << "Both screen not equal" <<Qt::endl;
        qInfo() << on_getDataSplit.first ()<<Qt::endl;
        QProcess::execute ("xrandr", QStringList() <<"--addmode"<<displayname.last ()<<on_getDataSplit.first ());
        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--mode"<<QString(on_getDataSplit.first ()));
        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--mode"<<QString(on_getDataSplit.first ()));
        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--same-as"<<displayname.first ());

    }
    checkoutScreen ();
}

void displayui::extendL_display(QStringList displayname)
{
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
        QProcess::execute ("xrandr",QStringList() <<"--output" << displayname.last ()<<"--mode"<< "1920x1080");
    }
    QProcess * extendRprocess = new QProcess(this);
    if(displayname.first () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.first ()<<"--right-of"<<displayname.last ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
    if(displayname.last () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.last ()<<"--right-of"<<displayname.first ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
}

void displayui::extendR_display(QStringList displayname)
{
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
        QProcess::execute ("xrandr",QStringList() <<"--output" << displayname.last ()<<"--mode"<< "1920x1080");
    }
    QProcess * extendRprocess = new QProcess(this);
    if(displayname.first () == getPrimaryScreen ()->name ()){

        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.first ()<<"--left-of"<<displayname.last ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
    if(displayname.last () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.last ()<<"--left-of"<<displayname.first ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
}
    //for smart unify display
//void displayui::on_smartUnify(QStringList displayname)
//{
//    qInfo() << "smart unify called";
//    if(on_getDataSplit.first ().compare (on_getDataSplit.last ()) == 0){
//        qInfo() << "Both sreen equal "<<endl;
//        QProcess * smartunifyprocess = new QProcess(this);
//        if(displayname.first () == getPrimaryScreen ()->name ()){
//            smartunifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--auto"<<"--output"<<displayname.first ());
//           smartunifyprocess->waitForFinished();
//            smartunifyprocess->close ();
//            return;
//        }
//        if(displayname.last () == getPrimaryScreen ()->name ()){
//            smartunifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--auto"<<"--output"<<displayname.last ());
//            smartunifyprocess->waitForFinished();
//            smartunifyprocess->close ();
//            return;
//        }
//    }else{
//        qInfo() << "Both screen not equal" <<endl;
//        qInfo() << on_getDataSplit.first ()<<endl;
//        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--mode"<<QString(on_getDataSplit.first ()));
//        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--mode"<<QString(on_getDataSplit.last ()));
//    }
//}

QStringList displayui::getOn_getDataSplit() const
{

    return on_getDataSplit;
}

void displayui::setOn_getDataSplit(const QStringList &value)
{
    on_getDataSplit = value;
}
