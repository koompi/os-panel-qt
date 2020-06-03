#include "localeui.h"
#include <QDebug>
#include <tuple>
#include <QSettings>
#include <QTranslator>
#include <QFile>
#include <locale>
#include <QtGlobal>
localeUi::localeUi(QWidget *parent) : QWidget(parent)
{
<<<<<<< HEAD
//    //to check when item combobox changed
//    connect (comRegion, &QComboBox::textActivated, [&](QString text){
//        emit onCurrentTextChanged (text);
//    });
//    connect (LanguageBox, &QComboBox::textActivated, [&](QString text){
//        emit onCurrentTextChanged (text);
//    });
//    connect (timezoneBox, &QComboBox::textActivated, [&](QString text){
//        emit onCurrentTextChanged (text);
//    });
//    connect (this, &localeUi::onCurrentTextChanged, [&](QString text){
//        qInfo() << text<<endl;
//        applyBtn->setEnabled (true);
//    });
//    localeCon = new localecontrol(this);
//    connect (applyBtn, &QToolButton::clicked, [&](){
//        if(localeSetting->isCreated ()){
//            localeSetting->updateSettings (listcombos ());
//            updateDescription ();
//            applyBtn->setEnabled (false);
//        }else{
//            localeSetting->saveSettings ();
//        }
//    });
//    connect (localeCon, &localecontrol::emitRegionLists, this, &localeUi::setRegionName);
//    connect (localeCon, &localecontrol::emitLanguageLists,this,&localeUi::setLanguageName);
//    connect(localeCon, &localecontrol::currentIndexChanged,this,&localeUi::setTimezone);
//    connect(localeCon, &localecontrol::getTimeFormat,this,&localeUi::setTimeFormat);
//    // get default value into each comboboxs
//    setRegionName ();
//    setLanguageName ();
//    setTimeFormat ();
//    setTimezone ();
//    // set the right data into combox
//    LanguageBox->setCurrentText (std::get<0>(currentLang ()));
//    regionBox->setCurrentText (std::get<1>(currentLang ()));
//    timezoneBox->setCurrentText (getTimezone_id ());
//    // put combox data into description labels
//    regionValue->setText (regionBox->currentText ());
//    langValue->setText (LanguageBox->currentText ());
//    timeformValue->setText (timeformatBox->currentText ());
//    timezoneValue->setText (timezoneBox->currentText ());
//    // create locale setting configuration file
//    localeSetting = new localeconfig(listcombos (), this);
//    localeSetting->loadSettings ();
//    updateDescription ();
=======
    setupUi (this);
    connect (backbtn, &QToolButton::clicked, [&](){
        localeStack->setCurrentIndex (0);
    });
    connect(advancedBtn, &QToolButton::clicked, []() {
        QProcess process;
        process.startDetached("systemsettings5");
        process.waitForStarted();
        process.waitForFinished(-1);
        process.close();
    });
    //to check when item combobox changed
    connect (regionBox, &QComboBox::textActivated, [&](QString text){
        emit onCurrentTextChanged (text);
    });
    connect (LanguageBox, &QComboBox::textActivated, [&](QString text){
        emit onCurrentTextChanged (text);
    });
    connect (timezoneBox, &QComboBox::textActivated, [&](QString text){
        emit onCurrentTextChanged (text);
    });
    connect (this, &localeUi::onCurrentTextChanged, [&](QString text){
        qInfo() << text<<endl;
        applyBtn->setEnabled (true);
    });
    localeCon = new localecontrol(this);
    connect (applyBtn, &QToolButton::clicked, [&](){
        if(localeSetting->isCreated ()){
            localeSetting->updateSettings (listcombos ());
            updateDescription ();
            applyBtn->setEnabled (false);
        }else{
            localeSetting->saveSettings ();
        }
    });
    connect (localeCon, &localecontrol::emitRegionLists, this, &localeUi::setRegionName);
    connect (localeCon, &localecontrol::emitLanguageLists,this,&localeUi::setLanguageName);
    connect(localeCon, &localecontrol::currentIndexChanged,this,&localeUi::setTimezone);
    connect(localeCon, &localecontrol::getTimeFormat,this,&localeUi::setTimeFormat);
    // get default value into each comboboxs
    setRegionName ();
    setLanguageName ();
    setTimeFormat ();
    setTimezone ();
    // set the right data into combox
    LanguageBox->setCurrentText (std::get<0>(currentLang ()));
    regionBox->setCurrentText (std::get<1>(currentLang ()));
    timezoneBox->setCurrentText (getTimezone_id ());
    // put combox data into description labels
    regionValue->setText (regionBox->currentText ());
    langValue->setText (LanguageBox->currentText ());
    timeformValue->setText (timeformatBox->currentText ());
    timezoneValue->setText (timezoneBox->currentText ());
    // create locale setting configuration file
    localeSetting = new localeconfig(listcombos (), this);
    if (localeSetting->isCreated()){
        localeSetting->loadSettings();
        qInfo() << "Locale config files created" <<endl;
    }
    else{
        qInfo() << "Locale config files not created" <<endl;
        localeSetting->saveSettings();
    }
    updateDescription ();
>>>>>>> b150f9d2b2255535ae5ea7a2aacc8ebe6e2f5e34
}

void localeUi::setupUi(QWidget *LocaleUi)
{
    if (LocaleUi->objectName().isEmpty())
        LocaleUi->setObjectName(QString::fromUtf8("LocaleUi"));
    LocaleUi->resize(287, 840);
    verticalLayout_2 = new QVBoxLayout(LocaleUi);
    verticalLayout_2->setSpacing(20);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    langRegionLayout = new QVBoxLayout();
    langRegionLayout->setSpacing(30);
    langRegionLayout->setObjectName(QString::fromUtf8("langRegionLayout"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(-1, -1, 48, -1);
    backBtn = new QToolButton(LocaleUi);
    backBtn->setObjectName(QString::fromUtf8("backBtn"));
    QIcon icon(QIcon::fromTheme(QString::fromUtf8("arrow-left")));
    backBtn->setIcon(icon);
    backBtn->setAutoRaise(true);

<<<<<<< HEAD
    horizontalLayout_2->addWidget(backBtn);
=======
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(481, 1001);
    Form->setMinimumSize(QSize(100, 0));
    verticalLayout = new QVBoxLayout(Form);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    localehorizontalLayout = new QHBoxLayout();
    localehorizontalLayout->setObjectName(QString::fromUtf8("localehorizontalLayout"));
    backbtn = new QToolButton(Form);
    backbtn->setObjectName(QString::fromUtf8("backbtn"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
    backbtn->setSizePolicy(sizePolicy);
    backbtn->setMinimumSize(QSize(0, 0));
    QIcon icon;
    QString iconThemeName = QString::fromUtf8("draw-arrow-back");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
    }
    backbtn->setIcon(icon);
    backbtn->setPopupMode(QToolButton::DelayedPopup);
    backbtn->setAutoRaise(true);

    localehorizontalLayout->addWidget(backbtn);

    localeLabel = new QLabel(Form);
    localeLabel->setObjectName(QString::fromUtf8("localeLabel"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(localeLabel->sizePolicy().hasHeightForWidth());
    localeLabel->setSizePolicy(sizePolicy1);
    localeLabel->setMinimumSize(QSize(0, 0));
    localeLabel->setMaximumSize(QSize(16777215, 50));
    QFont font;
    font.setPointSize(15);
    localeLabel->setFont(font);
    localeLabel->setAlignment(Qt::AlignCenter);

    localehorizontalLayout->addWidget(localeLabel);

    horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    localehorizontalLayout->addItem(horizontalSpacer);


    verticalLayout->addLayout(localehorizontalLayout);

    verticalSpacer_2 = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_2);

    RegionLayout = new QHBoxLayout();
    RegionLayout->setObjectName(QString::fromUtf8("RegionLayout"));
    region = new QLabel(Form);
    region->setObjectName(QString::fromUtf8("region"));
    sizePolicy.setHeightForWidth(region->sizePolicy().hasHeightForWidth());
    region->setSizePolicy(sizePolicy);
    QFont font1;
    font1.setPointSize(11);
    region->setFont(font1);

    RegionLayout->addWidget(region);

    horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    RegionLayout->addItem(horizontalSpacer_2);

    regionBox = new QComboBox(Form);
    regionBox->setObjectName(QString::fromUtf8("regionBox"));
    sizePolicy1.setHeightForWidth(regionBox->sizePolicy().hasHeightForWidth());
    regionBox->setSizePolicy(sizePolicy1);

    RegionLayout->addWidget(regionBox);


    verticalLayout->addLayout(RegionLayout);

    LanguageLayout = new QHBoxLayout();
    LanguageLayout->setObjectName(QString::fromUtf8("LanguageLayout"));
    languages = new QLabel(Form);
    languages->setObjectName(QString::fromUtf8("languages"));
    sizePolicy.setHeightForWidth(languages->sizePolicy().hasHeightForWidth());
    languages->setSizePolicy(sizePolicy);
    languages->setFont(font1);
    languages->setFrameShape(QFrame::NoFrame);

    LanguageLayout->addWidget(languages);

    horizontalSpacer_3 = new QSpacerItem(61, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    LanguageLayout->addItem(horizontalSpacer_3);

    LanguageBox = new QComboBox(Form);
    LanguageBox->setObjectName(QString::fromUtf8("LanguageBox"));
    sizePolicy1.setHeightForWidth(LanguageBox->sizePolicy().hasHeightForWidth());
    LanguageBox->setSizePolicy(sizePolicy1);

    LanguageLayout->addWidget(LanguageBox);


    verticalLayout->addLayout(LanguageLayout);

    timeFormatLayout = new QHBoxLayout();
    timeFormatLayout->setObjectName(QString::fromUtf8("timeFormatLayout"));
    timeformat = new QLabel(Form);
    timeformat->setObjectName(QString::fromUtf8("timeformat"));
    sizePolicy.setHeightForWidth(timeformat->sizePolicy().hasHeightForWidth());
    timeformat->setSizePolicy(sizePolicy);
    timeformat->setFont(font1);

    timeFormatLayout->addWidget(timeformat);

    horizontalSpacer_4 = new QSpacerItem(42, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
>>>>>>> b150f9d2b2255535ae5ea7a2aacc8ebe6e2f5e34

    title = new QLabel(LocaleUi);
    title->setObjectName(QString::fromUtf8("title"));
    title->setMinimumSize(QSize(0, 0));
    title->setAlignment(Qt::AlignCenter);

    horizontalLayout_2->addWidget(title);


    langRegionLayout->addLayout(horizontalLayout_2);

    actionForm = new QFormLayout();
    actionForm->setObjectName(QString::fromUtf8("actionForm"));
    actionForm->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    actionForm->setRowWrapPolicy(QFormLayout::WrapAllRows);
    actionForm->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    actionForm->setHorizontalSpacing(0);
    actionForm->setVerticalSpacing(10);
    label = new QLabel(LocaleUi);
    label->setObjectName(QString::fromUtf8("label"));

    actionForm->setWidget(0, QFormLayout::LabelRole, label);

    comRegion = new QComboBox(LocaleUi);
    comRegion->setObjectName(QString::fromUtf8("comRegion"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(comRegion->sizePolicy().hasHeightForWidth());
    comRegion->setSizePolicy(sizePolicy);
    comRegion->setFrame(true);

    actionForm->setWidget(0, QFormLayout::FieldRole, comRegion);

    checkBox = new QCheckBox(LocaleUi);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
    checkBox->setSizePolicy(sizePolicy1);

    actionForm->setWidget(1, QFormLayout::LabelRole, checkBox);

    labelNumber = new QLabel(LocaleUi);
    labelNumber->setObjectName(QString::fromUtf8("labelNumber"));
    labelNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    actionForm->setWidget(2, QFormLayout::LabelRole, labelNumber);

    comNumbers = new QComboBox(LocaleUi);
    comNumbers->setObjectName(QString::fromUtf8("comNumbers"));
    sizePolicy.setHeightForWidth(comNumbers->sizePolicy().hasHeightForWidth());
    comNumbers->setSizePolicy(sizePolicy);
    comNumbers->setFrame(true);

    actionForm->setWidget(2, QFormLayout::FieldRole, comNumbers);

    labelTime = new QLabel(LocaleUi);
    labelTime->setObjectName(QString::fromUtf8("labelTime"));
    labelTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    actionForm->setWidget(3, QFormLayout::LabelRole, labelTime);

    comTime = new QComboBox(LocaleUi);
    comTime->setObjectName(QString::fromUtf8("comTime"));
    sizePolicy.setHeightForWidth(comTime->sizePolicy().hasHeightForWidth());
    comTime->setSizePolicy(sizePolicy);
    comTime->setFrame(true);

    actionForm->setWidget(3, QFormLayout::FieldRole, comTime);

    labelCurrency = new QLabel(LocaleUi);
    labelCurrency->setObjectName(QString::fromUtf8("labelCurrency"));
    labelCurrency->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    actionForm->setWidget(4, QFormLayout::LabelRole, labelCurrency);

    comCurrentcy = new QComboBox(LocaleUi);
    comCurrentcy->setObjectName(QString::fromUtf8("comCurrentcy"));
    sizePolicy.setHeightForWidth(comCurrentcy->sizePolicy().hasHeightForWidth());
    comCurrentcy->setSizePolicy(sizePolicy);
    comCurrentcy->setFrame(true);

    actionForm->setWidget(4, QFormLayout::FieldRole, comCurrentcy);

    labelMeasurement = new QLabel(LocaleUi);
    labelMeasurement->setObjectName(QString::fromUtf8("labelMeasurement"));

    actionForm->setWidget(5, QFormLayout::LabelRole, labelMeasurement);

    comMeasurement = new QComboBox(LocaleUi);
    comMeasurement->setObjectName(QString::fromUtf8("comMeasurement"));
    sizePolicy.setHeightForWidth(comMeasurement->sizePolicy().hasHeightForWidth());
    comMeasurement->setSizePolicy(sizePolicy);
    comMeasurement->setFrame(true);

    actionForm->setWidget(5, QFormLayout::FieldRole, comMeasurement);

    labelCollection = new QLabel(LocaleUi);
    labelCollection->setObjectName(QString::fromUtf8("labelCollection"));

    actionForm->setWidget(6, QFormLayout::LabelRole, labelCollection);

    comColSort = new QComboBox(LocaleUi);
    comColSort->setObjectName(QString::fromUtf8("comColSort"));
    sizePolicy.setHeightForWidth(comColSort->sizePolicy().hasHeightForWidth());
    comColSort->setSizePolicy(sizePolicy);
    comColSort->setFrame(true);

    actionForm->setWidget(6, QFormLayout::FieldRole, comColSort);


    langRegionLayout->addLayout(actionForm);


    verticalLayout_2->addLayout(langRegionLayout);

    descLabel = new QLabel(LocaleUi);
    descLabel->setObjectName(QString::fromUtf8("descLabel"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(descLabel->sizePolicy().hasHeightForWidth());
    descLabel->setSizePolicy(sizePolicy2);

    verticalLayout_2->addWidget(descLabel);

    descriptForm = new QFormLayout();
    descriptForm->setObjectName(QString::fromUtf8("descriptForm"));
    descriptForm->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    descriptForm->setVerticalSpacing(20);
    descriptForm->setContentsMargins(20, -1, -1, -1);
    numberLabel = new QLabel(LocaleUi);
    numberLabel->setObjectName(QString::fromUtf8("numberLabel"));

    descriptForm->setWidget(0, QFormLayout::LabelRole, numberLabel);

    numberValue = new QLabel(LocaleUi);
    numberValue->setObjectName(QString::fromUtf8("numberValue"));
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(numberValue->sizePolicy().hasHeightForWidth());
    numberValue->setSizePolicy(sizePolicy3);

    descriptForm->setWidget(0, QFormLayout::FieldRole, numberValue);

    timeLabel = new QLabel(LocaleUi);
    timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

    descriptForm->setWidget(1, QFormLayout::LabelRole, timeLabel);

    timeValue = new QLabel(LocaleUi);
    timeValue->setObjectName(QString::fromUtf8("timeValue"));
    sizePolicy3.setHeightForWidth(timeValue->sizePolicy().hasHeightForWidth());
    timeValue->setSizePolicy(sizePolicy3);

    descriptForm->setWidget(1, QFormLayout::FieldRole, timeValue);

    currentcyLabel = new QLabel(LocaleUi);
    currentcyLabel->setObjectName(QString::fromUtf8("currentcyLabel"));

    descriptForm->setWidget(2, QFormLayout::LabelRole, currentcyLabel);

    currentcyValue = new QLabel(LocaleUi);
    currentcyValue->setObjectName(QString::fromUtf8("currentcyValue"));
    sizePolicy3.setHeightForWidth(currentcyValue->sizePolicy().hasHeightForWidth());
    currentcyValue->setSizePolicy(sizePolicy3);

    descriptForm->setWidget(2, QFormLayout::FieldRole, currentcyValue);

    measureLabel = new QLabel(LocaleUi);
    measureLabel->setObjectName(QString::fromUtf8("measureLabel"));

    descriptForm->setWidget(3, QFormLayout::LabelRole, measureLabel);

    measureValue = new QLabel(LocaleUi);
    measureValue->setObjectName(QString::fromUtf8("measureValue"));
    sizePolicy3.setHeightForWidth(measureValue->sizePolicy().hasHeightForWidth());
    measureValue->setSizePolicy(sizePolicy3);

    descriptForm->setWidget(3, QFormLayout::FieldRole, measureValue);


    verticalLayout_2->addLayout(descriptForm);

    buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(6);
    buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
    buttonLayout->setContentsMargins(100, -1, -1, -1);
    cacelBtn = new QPushButton(LocaleUi);
    cacelBtn->setObjectName(QString::fromUtf8("cacelBtn"));
    QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(cacelBtn->sizePolicy().hasHeightForWidth());
    cacelBtn->setSizePolicy(sizePolicy4);
    cacelBtn->setFlat(false);

    buttonLayout->addWidget(cacelBtn);

    applyBtn = new QPushButton(LocaleUi);
    applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
    sizePolicy4.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
    applyBtn->setSizePolicy(sizePolicy4);
    applyBtn->setFlat(false);

    buttonLayout->addWidget(applyBtn);


    verticalLayout_2->addLayout(buttonLayout);


    retranslateUi(LocaleUi);

    QMetaObject::connectSlotsByName(LocaleUi);

}

void localeUi::retranslateUi(QWidget *LocaleUi)
{
    LocaleUi->setWindowTitle(QCoreApplication::translate("LocaleUi", "LocaleUi", nullptr));
    backBtn->setText(QCoreApplication::translate("LocaleUi", "...", nullptr));
    title->setText(QCoreApplication::translate("LocaleUi", "Language & Region", nullptr));
    label->setText(QCoreApplication::translate("LocaleUi", "Region:", nullptr));
    checkBox->setText(QCoreApplication::translate("LocaleUi", "Detailed Settings", nullptr));
    labelNumber->setText(QCoreApplication::translate("LocaleUi", "Numbers:", nullptr));
    labelTime->setText(QCoreApplication::translate("LocaleUi", "Time:", nullptr));
    labelCurrency->setText(QCoreApplication::translate("LocaleUi", "Currency:", nullptr));
    labelMeasurement->setText(QCoreApplication::translate("LocaleUi", "Measurement unit:", nullptr));
    labelCollection->setText(QCoreApplication::translate("LocaleUi", "Colleciton and Sorting:", nullptr));
    descLabel->setText(QCoreApplication::translate("LocaleUi", "Description:", nullptr));
    numberLabel->setText(QCoreApplication::translate("LocaleUi", "Numbers:", nullptr));
    numberValue->setText(QString());
    timeLabel->setText(QCoreApplication::translate("LocaleUi", "Time:", nullptr));
    timeValue->setText(QString());
    currentcyLabel->setText(QCoreApplication::translate("LocaleUi", "Currentcy:", nullptr));
    currentcyValue->setText(QString());
    measureLabel->setText(QCoreApplication::translate("LocaleUi", "Measurement Unit", nullptr));
    measureValue->setText(QString());
    cacelBtn->setText(QCoreApplication::translate("LocaleUi", "Cancel", nullptr));
    applyBtn->setText(QCoreApplication::translate("LocaleUi", "Apply", nullptr));

}

QStackedWidget *localeUi::getLocaleStacked() const
{
    return localeStack;
}

void localeUi::setLocaleStacked(QStackedWidget *value)
{
    localeStack=value;
}

QString localeUi::getTimezone_id() const
{
    return timezone_id;
}

void localeUi::setTimezone_id(const QString &value)
{
    timezone_id = value;
}

<<<<<<< HEAD
//void localeUi::setRegionName()
//{
//    qDebug() << "setRegionName called"<<endl;
//    for (int i = 1; i < QLocale::LastCountry-1; ++i)
//    {
//        //        qDebug()<<QLocale::countryToString((QLocale::Country)i);
//        regionBox->addItem ((QLocale::countryToString((QLocale::Country)i)));
//    }
//}

//void localeUi::setLanguageName()
//{
//    qDebug()<< "set language called" <<endl ;
//    QList<QLocale> allLocales = QLocale::matchingLocales(
//                QLocale::AnyLanguage,
//                QLocale::AnyScript,
//                QLocale::AnyCountry);
//    QSet<QString> iso639Languages;

//    for(const QLocale &locale : allLocales) {
//        iso639Languages.insert(QLocale::languageToString(locale.language()));
//        LanguageBox->addItem (QLocale::languageToString(locale.language()));
//    }
//    //    rqDebug() << iso639Languages;
//}

//void localeUi::setTimezone()
//{
//    QByteArray id =timezoneBox->currentText().toLatin1();
//    QTimeZone zone = QTimeZone(id);
//    QList<QByteArray> ids = QTimeZone::availableTimeZoneIds();
//    foreach (QByteArray id, ids) {
//        timezoneBox->addItem(id);
//    }
//}

//void localeUi::setTimeFormat()
//{
//    QDateTime dateTime = dateTime.currentDateTime();
//    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
//    timeformatBox->addItem (dateTimeString);
//    setTimezone_id (QString(dateTime.timeZone ().id()));
//}

//QList<QComboBox *> localeUi::listcombos()
//{
//    return {regionBox,LanguageBox, timeformatBox, timezoneBox};
//}

//void localeUi::updateDescription()
//{
//    regionValue->setText (regionBox->currentText ());
//    langValue->setText (LanguageBox->currentText ());
//    timeformValue->setText (timeformatBox->currentText ());
//    timezoneValue->setText (timezoneBox->currentText ());

//}
//
//const std::tuple<QString, QString>  localeUi::currentLang()
//{
//    QLocale locale;
//    QString curlang = locale.languageToString (locale.language ());
//    locale.countryToString (QLocale::Country::UnitedStates);
//    qDebug() << curlang<<endl;
//    return std::tuple(curlang, locale.countryToString (QLocale::Country::UnitedStates));
//}
=======
void localeUi::setRegionName()
{
    qDebug() << "setRegionName called"<<endl;
    for (int i = 1; i < QLocale::LastCountry-1; ++i)
    {
        //         qDebug() << QLocale::languageToString(QLocale::English);
        regionBox->addItem ((QLocale::countryToString((QLocale::Country)i)));
    }
}

void localeUi::setLanguageName()
{
    qDebug()<< "set language called" <<endl ;
    QList<QLocale> allLocales = QLocale::matchingLocales(
                QLocale::AnyLanguage,
                QLocale::AnyScript,
                QLocale::AnyCountry);
    QSet<QString> iso639Languages;
    QFile file("/home/sna/Documents/locale.txt", this);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append )){
        return;
    }
    QTextStream out(&file);
    QStringList tempList;
    int count_lang = 0;
    for(const QLocale &locale : allLocales) {
        iso639Languages.insert(QLocale::languageToString(locale.language()));
        if(!locale.uiLanguages().first().isEmpty()){
//            tempList.append(locale.uiLanguages().filter(QRegExp("^[A-Za-z]+ [-]{1}[A-Za-z]+$")));
            tempList.append(locale.uiLanguages().first());
        }
        LanguageBox->addItem(QLocale::languageToString(locale.language()));
        out << locale.nativeLanguageName()<<"-"<<locale.nativeCountryName()<<endl;
        count_lang +=1;
    }
    qDebug() << "List locale: " << tempList<<endl;
    for (QString &locale : tempList) {
        locale.replace('-', '_');
        qDebug() << locale<<endl;
        out << locale<<endl;
    }
//    for(int i =0;i!=LanguageBox->count();++i){
//        qDebug() << "Item added" <<endl;
//        if(!tempList.at(i).isEmpty()){
//        LanguageBox->setItemText(i, LanguageBox->itemText(i).append(tempList.at(i)));
//        }else{

//        }
//    }
    file.flush();
    file.close();
}

void localeUi::setTimezone()
{
    QByteArray id =timezoneBox->currentText().toLatin1();
    QTimeZone zone = QTimeZone(id);
    QList<QByteArray> ids = QTimeZone::availableTimeZoneIds();
    foreach (QByteArray id, ids) {
        timezoneBox->addItem(id);
    }
}

void localeUi::setTimeFormat()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    timeformatBox->addItem (dateTimeString);
    setTimezone_id (QString(dateTime.timeZone ().id()));
}

QList<QComboBox *> localeUi::listcombos()
{
    return {regionBox,LanguageBox,timeformatBox,timezoneBox};
}

void localeUi::updateDescription()
{
    regionValue->setText(regionBox->currentText ());
    langValue->setText(LanguageBox->currentText ());
    timeformValue->setText(timeformatBox->currentText ());
    timezoneValue->setText(timezoneBox->currentText ());

}
//
const std::tuple<QString, QString>  localeUi::currentLang()
{
    QLocale locale;
    qDebug() << "output in tuple" <<endl;

    QString curlang = locale.languageToString (locale.language ());
    locale.countryToString (QLocale::Country::UnitedStates);
    return std::tuple(curlang, locale.countryToString (QLocale::Country::UnitedStates));
}
>>>>>>> b150f9d2b2255535ae5ea7a2aacc8ebe6e2f5e34


