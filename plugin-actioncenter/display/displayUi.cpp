#include "displayUi.h"

Ui_Form::Ui_Form(QWidget *parent): QWidget (parent)
{
     setupUi (this);
     connect (backbtn, &QToolButton::clicked, [&](){
             stack->setCurrentIndex (0);
         });
         connect(advancedBtn, &QToolButton::clicked, []() {
             QProcess process;
             process.startDetached(QStringLiteral("systemsettings5"));
             process.waitForStarted();
             process.waitForFinished(-1);
             process.close();
         });
         laptop = new displayConfig();
         connect(laptopbtn,&QToolButton::clicked, laptop,&displayConfig::getDisplayName);
         connect (laptop, &displayConfig::onReadyGetDisplayName, this, &Ui_Form::laptop_display);

         external = new displayConfig();
         connect(externalbtn, &QToolButton::clicked, external,&displayConfig::getDisplayName);
         connect (external, &displayConfig::onReadyGetDisplayName, this, &Ui_Form::monitor_display);

         unify = new displayConfig();
         checkoutScreen ();
         connect(unifybtn, &QToolButton::clicked, unify,&displayConfig::getDisplayName);
         connect (unify, &displayConfig::onReadyGetDisplayName, this, &Ui_Form::unify_display);
         extendRight = new displayConfig();
         connect(extendrigthbtn, &QToolButton::clicked, extendRight,&displayConfig::getDisplayName);
         connect (extendRight, &displayConfig::onReadyGetDisplayName, this, &Ui_Form::extendR_display);

         extendLeft = new displayConfig();
         connect(extendleftbtn, &QToolButton::clicked, extendLeft,&displayConfig::getDisplayName);
         connect (extendLeft, &displayConfig::onReadyGetDisplayName, this, &Ui_Form::extendL_display);
}
void Ui_Form::setupUi(QWidget *Form){
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(330, 1015);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
    Form->setSizePolicy(sizePolicy);
    Form->setMinimumSize(QSize(250, 0));
    Form->setStyleSheet(QString::fromUtf8(""));
    verticalLayout_2 = new QVBoxLayout(Form);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    backbtn = new QToolButton(Form);
    backbtn->setObjectName(QString::fromUtf8("backbtn"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
    backbtn->setSizePolicy(sizePolicy1);
    backbtn->setMinimumSize(QSize(0, 0));
    backbtn->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
    QIcon icon;
    QString iconThemeName = QString::fromUtf8("draw-arrow-back");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    backbtn->setIcon(icon);
    backbtn->setAutoRaise(true);

    horizontalLayout->addWidget(backbtn);

    displayLabel = new QLabel(Form);
    displayLabel->setObjectName(QString::fromUtf8("displayLabel"));
    sizePolicy.setHeightForWidth(displayLabel->sizePolicy().hasHeightForWidth());
    displayLabel->setSizePolicy(sizePolicy);
    displayLabel->setMinimumSize(QSize(0, 0));
    displayLabel->setMaximumSize(QSize(16777215, 50));
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setWeight(75);
    displayLabel->setFont(font);
    displayLabel->setStyleSheet(QString::fromUtf8(""));
    displayLabel->setAlignment(Qt::AlignCenter);

    horizontalLayout->addWidget(displayLabel);

    horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);


    verticalLayout_2->addLayout(horizontalLayout);

    verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout_2->addItem(verticalSpacer);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(20);
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
    externalbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
    QIcon icon1;
    iconThemeName = QString::fromUtf8("osd-shutd-laptop");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon1 = QIcon::fromTheme(iconThemeName);
    } else {
        icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    externalbtn->setIcon(icon1);
    externalbtn->setIconSize(QSize(64, 64));
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
    laptopbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
    QIcon icon2;
    iconThemeName = QString::fromUtf8("osd-shutd-screen");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon2 = QIcon::fromTheme(iconThemeName);
    } else {
        icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    laptopbtn->setIcon(icon2);
    laptopbtn->setIconSize(QSize(64, 64));
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
    unifybtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
    QIcon icon3;
    iconThemeName = QString::fromUtf8("osd-duplicate");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon3 = QIcon::fromTheme(iconThemeName);
    } else {
        icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    unifybtn->setIcon(icon3);
    unifybtn->setIconSize(QSize(64, 64));
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
    extendleftbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
    QIcon icon4;
    iconThemeName = QString::fromUtf8("osd-sbs-left");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon4 = QIcon::fromTheme(iconThemeName);
    } else {
        icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    extendleftbtn->setIcon(icon4);
    extendleftbtn->setIconSize(QSize(64, 64));
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
    extendrigthbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: #5b65736e;\n"
"radius:10px;border-radius:5px;\n"
"}"));
    QIcon icon5;
    iconThemeName = QString::fromUtf8("osd-sbs-sright");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon5 = QIcon::fromTheme(iconThemeName);
    } else {
        icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    extendrigthbtn->setIcon(icon5);
    extendrigthbtn->setIconSize(QSize(64, 64));
    extendrigthbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    extendrigthbtn->setAutoRaise(false);

    verticalLayout->addWidget(extendrigthbtn);

    advancedBtn = new QPushButton(Form);
    advancedBtn->setObjectName(QString::fromUtf8("advancedBtn"));
    sizePolicy1.setHeightForWidth(advancedBtn->sizePolicy().hasHeightForWidth());
    advancedBtn->setSizePolicy(sizePolicy1);
    advancedBtn->setMinimumSize(QSize(115, 0));
    advancedBtn->setLayoutDirection(Qt::RightToLeft);
    advancedBtn->setStyleSheet(QString::fromUtf8(" backgroun-color:#5b65736e\n"
""));

    verticalLayout->addWidget(advancedBtn);


    verticalLayout_2->addLayout(verticalLayout);

    verticalSpacer_2 = new QSpacerItem(20, 434, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_2);


    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
} // setupUi

void Ui_Form::retranslateUi(QWidget *Form)
{
    Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    backbtn->setText(QCoreApplication::translate("Form", "...", nullptr));
    displayLabel->setText(QCoreApplication::translate("Form", "Display", nullptr));
    externalbtn->setText(QCoreApplication::translate("Form", " External screen", nullptr));
    laptopbtn->setText(QCoreApplication::translate("Form", " Laptop screen", nullptr));
    unifybtn->setText(QCoreApplication::translate("Form", " Unify  output", nullptr));
    extendleftbtn->setText(QCoreApplication::translate("Form", " Extend to left", nullptr));
    extendrigthbtn->setText(QCoreApplication::translate("Form", " Extend to right", nullptr));
    advancedBtn->setText(QCoreApplication::translate("Form", "Advanced Setting", nullptr));
}

QScreen *Ui_Form::getPrimaryScreen()
{
    return QGuiApplication::primaryScreen();
}

void Ui_Form::checkoutScreen()
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

QStackedWidget *Ui_Form::getDisplayStacked() const
{
     return stack;
}

void Ui_Form::setDisplayStacked(QStackedWidget *value)
{
    stack = value;

}

QStringList Ui_Form::getOn_getDataSplit() const
{
    return on_getDataSplit;
}

void Ui_Form::setOn_getDataSplit(const QStringList &value)
{
    on_getDataSplit = value;
}

void Ui_Form::laptop_display(QStringList displayname)
{
    QProcess * disprocess = new QProcess(this);
    // functor base signal Overload
    connect(disprocess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),

            [&]  (int exitCode, QProcess::ExitStatus exitStatus)
    {
        qDebug() << "Exit code"<< exitCode<< "\t" << "Status: " << exitStatus<<Qt::endl;//to check the process
    });
    disprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--off")<<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--auto")<<QStringLiteral("--primary"));
    disprocess->waitForFinished();
    disprocess->close ();

}

void Ui_Form::monitor_display(QStringList displayname)
{
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

void Ui_Form::unify_display(QStringList displayname)
{
    qInfo() << "unify called";
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ()) == 0){
        qInfo() << "Both sreen equal "<<Qt::endl;
        QProcess * unifyprocess = new QProcess(this);
        if(displayname.first () == getPrimaryScreen()->name()){
            unifyprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.first ());
            unifyprocess->waitForFinished();
            unifyprocess->close ();
            return;
        }
        if(displayname.last () == getPrimaryScreen ()->name ()){
            unifyprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.last ());
            unifyprocess->waitForFinished();
            unifyprocess->close ();
            return;
        }
    }else{
        qInfo() << "Both screen not equal" <<Qt::endl;
        qInfo() << on_getDataSplit.first ()<<Qt::endl;
        QProcess::execute (QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--addmode")<<displayname.last ()<<on_getDataSplit.first ());
        QProcess::execute (QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--mode")<<QString(on_getDataSplit.first ()));
        QProcess::execute (QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--mode")<<QString(on_getDataSplit.first ()));
        QProcess::execute (QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--same-as")<<displayname.first ());

    }
    checkoutScreen ();
}

void Ui_Form::extendL_display(QStringList displayname)
{
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
        QProcess::execute (QStringLiteral("xrandr"),QStringList() <<QStringLiteral("--output") << displayname.last ()<<QStringLiteral("--mode")<<QStringLiteral("1920x1080"));
    }
    QProcess * extendRprocess = new QProcess(this);
    if(displayname.first () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--right-of")<<displayname.last ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
    if(displayname.last () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--right-of")<<displayname.first ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
}

void Ui_Form::extendR_display(QStringList displayname)
{
    if(on_getDataSplit.first ().compare (on_getDataSplit.last ())){
        QProcess::execute (QStringLiteral("xrandr"),QStringList() <<QStringLiteral("--output") << displayname.last ()<<QStringLiteral("--mode")<<QStringLiteral("1920x1080"));
    }
    QProcess * extendRprocess = new QProcess(this);
    if(displayname.first () == getPrimaryScreen ()->name ()){

        extendRprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.first ()<<QStringLiteral("--left-of")<<displayname.last ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
    if(displayname.last () == getPrimaryScreen ()->name ()){
        extendRprocess->startDetached(QStringLiteral("xrandr"), QStringList() <<QStringLiteral("--auto")<<QStringLiteral("--output")<<displayname.last ()<<QStringLiteral("--left-of")<<displayname.first ());
        extendRprocess->waitForFinished();
        extendRprocess->close ();
        return;
    }
} // retranslateUi

