#include "displayconfig.h"
#include <QString>



displayConfig::displayConfig(QWidget *parent) : QWidget(parent),ui(new Ui::Form())
{
    ui->setupUi (this);
    connect (ui->backbtn, &QToolButton::clicked, [&](){
       getStack ()->setCurrentIndex (0);
    });
    connect(ui->advancedBtn, &QToolButton::clicked, []() {
            QProcess process;
            process.startDetached (QStringLiteral("systemsettings5"));
            process.waitForStarted();
            process.waitForFinished(-1);
            process.close();
    });
    connect(ui->laptopbtn,&QToolButton::clicked, this,&displayConfig::getDisplayName);
    connect (this,&displayConfig::onReadyGetDisplayName,this, &displayConfig::laptop_display);

//    connect(ui->externalbtn,&QToolButton::clicked, this,&displayConfig::getDisplayName);
//    connect (this,&displayConfig::onReadyGetDisplayName,this,&displayConfig::monitor_display);
}
QScreen *displayConfig::getPrimaryScreen()
{
     return QGuiApplication::primaryScreen();
}

QStringList displayConfig::decorate_output(QString &output)
{
       qDebug() << output<<Qt::endl;
       QStringList displayList = output.split (QStringLiteral ("\n"));
       displayList.pop_back ();
       return displayList;

}
void displayConfig::checkoutScreen()
{
    qInfo() << "checkscreen called: ";
        QProcess *process = new QProcess(this);
        connect (process,&QProcess::readyReadStandardOutput, [&](){
            QByteArray data= process->readAllStandardOutput ();
            QString dataString(QString::fromLatin1 (data));
            QStringList dataSplit = dataString.split (QStringLiteral ("\n"));
            dataSplit.pop_back ();
            dataSplit.removeAt (1);
            setOn_getDataSplit (dataSplit);
        });
        process->start (QStringLiteral("bash"),
                                QStringList()
                                <<QStringLiteral("-c")
                                <<QStringLiteral("xrandr --query | grep -A 1 connected | grep -v connected | awk '{print $1}' | cut -f2 -d\"-\""),QIODevice::ReadOnly);
        process->waitForFinished ();
        process->close ();
}


void displayConfig::getDisplayName()
{
    QProcess *display2 = new QProcess(this);
        connect(display2, &QProcess::readyReadStandardOutput, [&]() {
            QByteArray display_name =  display2->readAllStandardOutput ();
            QString output(QString::fromLatin1 (display_name));
            emit onReadyGetDisplayName(decorate_output(output));
        });
        display2->start(QStringLiteral("bash"),
                        QStringList()
                        << QStringLiteral("-c")
                        << QStringLiteral(" xrandr |  grep \"connected\" | cut -f1 -d\" \""), QIODevice::ReadOnly
                        );
        display2->setReadChannel(QProcess::ProcessChannel::StandardOutput );
        display2->waitForReadyRead ();
        display2->waitForFinished();
        display2->close ();
}
void displayConfig::laptop_display(QStringList displayname)
{
    QProcess * disprocess = new QProcess(this);
    // functor base signal Overload
        connect(disprocess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),

                [&]  (int exitCode, QProcess::ExitStatus exitStatus)
        {
            qDebug() << "Exit code"<< exitCode<< "\t" << "Status: " << exitStatus<<endl;//to check the process
        });
        disprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--off")<<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--auto")<<QStringLiteral("--primary"));
        disprocess->waitForFinished();
        disprocess->close ();
}

void displayConfig::monitor_display(QStringList displayname){

    if(displayname.first ().compare (displayname.last ())){
            QProcess::execute (QStringLiteral("xrandr"),QStringList() <<QStringLiteral("--output") << displayname.last ()<<QStringLiteral("--mode")<<QStringLiteral( "1920x1080"));
        }
        QProcess * monitorprocess = new QProcess(this);
        connect(monitorprocess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [=](int exitCode, QProcess::ExitStatus exitStatus){
            qInfo() << "Process exit: "  << exitCode << "Status: " << exitStatus<<Qt::endl;
        });
        monitorprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--off")<<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--auto")<<QStringLiteral("--primary"));
        monitorprocess->waitForFinished();
        monitorprocess->close ();
}

//void displayConfig::unify_display(QStringList displayname)
//{
//    qInfo() << "unify called";
//    if(on_getDataSplit.first ().compare (on_getDataSplit.last ()) == 0){
//        qInfo() << "Both sreen equal "<<Qt::endl;
//        QProcess * unifyprocess = new QProcess(this);
//        if(displayname.first () == getPrimaryScreen()){
//            unifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--auto"<<"--output"<<displayname.first ());
//            unifyprocess->waitForFinished();
//            unifyprocess->close ();
//            return;
//        }
//        if(displayname.last () == getPrimaryScreen ()->name ()){
//            unifyprocess->startDetached("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--auto"<<"--output"<<displayname.last ());
//            unifyprocess->waitForFinished();
//            unifyprocess->close ();
//            return;
//        }
//    }else{
//        qInfo() << "Both screen not equal" <<Qt::endl;
//        qInfo() << on_getDataSplit.first ()<<Qt::endl;
//        QProcess::execute ("xrandr", QStringList() <<"--addmode"<<displayname.last ()<<on_getDataSplit.first ());
//        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--mode"<<QString(on_getDataSplit.first ()));
//        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.first ()<<"--mode"<<QString(on_getDataSplit.first ()));
//        QProcess::execute ("xrandr", QStringList() <<"--output"<<displayname.last ()<<"--same-as"<<displayname.first ());

//    }
//    checkoutScreen ();
//}

//void displayConfig::extendL_display(QStringList displayname)
//{
//    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
//        QProcess::execute ("xrandr",QStringList() <<"--output" << displayname.last ()<<"--mode"<< "1920x1080");
//    }
//    QProcess * extendRprocess = new QProcess(this);
//    if(displayname.first () == getPrimaryScreen ()->name ()){
//        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.first ()<<"--right-of"<<displayname.last ());
//        extendRprocess->waitForFinished();
//        extendRprocess->close ();
//        return;
//    }
//    if(displayname.last () == getPrimaryScreen ()->name ()){
//        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.last ()<<"--right-of"<<displayname.first ());
//        extendRprocess->waitForFinished();
//        extendRprocess->close ();
//        return;
//    }
//}

//void displayConfig::extendR_display(QStringList displayname)
//{
//    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
//        QProcess::execute ("xrandr",QStringList() <<"--output" << displayname.last ()<<"--mode"<< "1920x1080");
//    }
//    QProcess * extendRprocess = new QProcess(this);
//    if(displayname.first () == getPrimaryScreen ()->name ()){

//        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.first ()<<"--left-of"<<displayname.last ());
//        extendRprocess->waitForFinished();
//        extendRprocess->close ();
//        return;
//    }
//    if(displayname.last () == getPrimaryScreen ()->name ()){
//        extendRprocess->startDetached("xrandr", QStringList() <<"--auto"<<"--output"<<displayname.last ()<<"--left-of"<<displayname.first ());
//        extendRprocess->waitForFinished();
//        extendRprocess->close ();
//        return;
//    }
//}
QStackedWidget *displayConfig::getStack() const
{
    return stack;
}

void displayConfig::setStack(QStackedWidget *value)
{
    stack = value;
}
QStringList displayConfig::getOn_getDataSplit() const
{
    return on_getDataSplit;
}
void displayConfig::setOn_getDataSplit(const QStringList &value)
{
    on_getDataSplit = value;
}


