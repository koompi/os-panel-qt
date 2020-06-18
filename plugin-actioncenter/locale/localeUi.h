/********************************************************************************
** Form generated from reading UI file 'newlocaleWpNocc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NEWLOCALEWPNOCC_H
#define NEWLOCALEWPNOCC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocaleUi
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *backbtn;
    QLabel *title;
    QToolButton *ac_notification;
    QFormLayout *actionForm;
    QLabel *label;
    QComboBox *comRegion;
    QCheckBox *checkBox;
    QLabel *labelNumber;
    QComboBox *comNumbers;
    QLabel *labelTime;
    QComboBox *comTime;
    QLabel *labelCurrency;
    QComboBox *comCurrentcy;
    QLabel *labelMeasurement;
    QComboBox *comMeasurement;
    QLabel *labelCollection;
    QComboBox *comColSort;
    QSpacerItem *horizontalSpacer;
    QLabel *descLabel;
    QFormLayout *descriptForm;
    QLabel *numberLabel;
    QLabel *numberValue;
    QLabel *timeLabel;
    QLabel *timeValue;
    QLabel *currentcyLabel;
    QLabel *CurrentcyValue;
    QLabel *measureLabel;
    QLabel *measureValue;
    QHBoxLayout *buttonLayout;
    QPushButton *cacelBtn;
    QPushButton *applyBtn;
    QString *timezone_id;

    void setupUi(QWidget *LocaleUi)
    {
        if (LocaleUi->objectName().isEmpty())
            LocaleUi->setObjectName(QString::fromUtf8("LocaleUi"));
        LocaleUi->resize(330, 897);
        LocaleUi->setMinimumSize(QSize(250, 0));
        verticalLayout = new QVBoxLayout(LocaleUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backbtn = new QToolButton(LocaleUi);
        backbtn->setObjectName(QString::fromUtf8("backbtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
        backbtn->setSizePolicy(sizePolicy);
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

        title = new QLabel(LocaleUi);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(15);
        title->setFont(font);
        title->setLayoutDirection(Qt::LeftToRight);
        title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(title);

        ac_notification = new QToolButton(LocaleUi);
        ac_notification->setObjectName(QString::fromUtf8("ac_notification"));
        ac_notification->setMinimumSize(QSize(42, 42));
        ac_notification->setMaximumSize(QSize(42, 42));
        ac_notification->setLayoutDirection(Qt::LeftToRight);
        ac_notification->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("preferences-system-notifications-symbolic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ac_notification->setIcon(icon1);
        ac_notification->setIconSize(QSize(22, 22));
        ac_notification->setAutoRaise(true);

        horizontalLayout->addWidget(ac_notification);


        verticalLayout->addLayout(horizontalLayout);

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
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comRegion->sizePolicy().hasHeightForWidth());
        comRegion->setSizePolicy(sizePolicy2);
        comRegion->setFrame(true);

        actionForm->setWidget(0, QFormLayout::FieldRole, comRegion);

        checkBox = new QCheckBox(LocaleUi);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy3);

        actionForm->setWidget(1, QFormLayout::LabelRole, checkBox);

        labelNumber = new QLabel(LocaleUi);
        labelNumber->setObjectName(QString::fromUtf8("labelNumber"));
        labelNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        actionForm->setWidget(2, QFormLayout::LabelRole, labelNumber);

        comNumbers = new QComboBox(LocaleUi);
        comNumbers->setObjectName(QString::fromUtf8("comNumbers"));
        sizePolicy2.setHeightForWidth(comNumbers->sizePolicy().hasHeightForWidth());
        comNumbers->setSizePolicy(sizePolicy2);
        comNumbers->setFrame(true);

        actionForm->setWidget(2, QFormLayout::FieldRole, comNumbers);

        labelTime = new QLabel(LocaleUi);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        actionForm->setWidget(3, QFormLayout::LabelRole, labelTime);

        comTime = new QComboBox(LocaleUi);
        comTime->setObjectName(QString::fromUtf8("comTime"));
        sizePolicy2.setHeightForWidth(comTime->sizePolicy().hasHeightForWidth());
        comTime->setSizePolicy(sizePolicy2);
        comTime->setFrame(true);

        actionForm->setWidget(3, QFormLayout::FieldRole, comTime);

        labelCurrency = new QLabel(LocaleUi);
        labelCurrency->setObjectName(QString::fromUtf8("labelCurrency"));
        labelCurrency->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        actionForm->setWidget(4, QFormLayout::LabelRole, labelCurrency);

        comCurrentcy = new QComboBox(LocaleUi);
        comCurrentcy->setObjectName(QString::fromUtf8("comCurrentcy"));
        sizePolicy2.setHeightForWidth(comCurrentcy->sizePolicy().hasHeightForWidth());
        comCurrentcy->setSizePolicy(sizePolicy2);
        comCurrentcy->setFrame(true);

        actionForm->setWidget(4, QFormLayout::FieldRole, comCurrentcy);

        labelMeasurement = new QLabel(LocaleUi);
        labelMeasurement->setObjectName(QString::fromUtf8("labelMeasurement"));

        actionForm->setWidget(5, QFormLayout::LabelRole, labelMeasurement);

        comMeasurement = new QComboBox(LocaleUi);
        comMeasurement->setObjectName(QString::fromUtf8("comMeasurement"));
        sizePolicy2.setHeightForWidth(comMeasurement->sizePolicy().hasHeightForWidth());
        comMeasurement->setSizePolicy(sizePolicy2);
        comMeasurement->setFrame(true);

        actionForm->setWidget(5, QFormLayout::FieldRole, comMeasurement);

        labelCollection = new QLabel(LocaleUi);
        labelCollection->setObjectName(QString::fromUtf8("labelCollection"));

        actionForm->setWidget(6, QFormLayout::LabelRole, labelCollection);

        comColSort = new QComboBox(LocaleUi);
        comColSort->setObjectName(QString::fromUtf8("comColSort"));
        sizePolicy2.setHeightForWidth(comColSort->sizePolicy().hasHeightForWidth());
        comColSort->setSizePolicy(sizePolicy2);
        comColSort->setFrame(true);

        actionForm->setWidget(6, QFormLayout::FieldRole, comColSort);


        verticalLayout->addLayout(actionForm);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        descLabel = new QLabel(LocaleUi);
        descLabel->setObjectName(QString::fromUtf8("descLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(descLabel->sizePolicy().hasHeightForWidth());
        descLabel->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(descLabel);

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
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(numberValue->sizePolicy().hasHeightForWidth());
        numberValue->setSizePolicy(sizePolicy5);

        descriptForm->setWidget(0, QFormLayout::FieldRole, numberValue);

        timeLabel = new QLabel(LocaleUi);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        descriptForm->setWidget(1, QFormLayout::LabelRole, timeLabel);

        timeValue = new QLabel(LocaleUi);
        timeValue->setObjectName(QString::fromUtf8("timeValue"));
        sizePolicy5.setHeightForWidth(timeValue->sizePolicy().hasHeightForWidth());
        timeValue->setSizePolicy(sizePolicy5);

        descriptForm->setWidget(1, QFormLayout::FieldRole, timeValue);

        currentcyLabel = new QLabel(LocaleUi);
        currentcyLabel->setObjectName(QString::fromUtf8("currentcyLabel"));

        descriptForm->setWidget(2, QFormLayout::LabelRole, currentcyLabel);

        CurrentcyValue = new QLabel(LocaleUi);
        CurrentcyValue->setObjectName(QString::fromUtf8("CuirrentcyValue"));
        sizePolicy5.setHeightForWidth(CurrentcyValue->sizePolicy().hasHeightForWidth());
        CurrentcyValue->setSizePolicy(sizePolicy5);

        descriptForm->setWidget(2, QFormLayout::FieldRole, CurrentcyValue);

        measureLabel = new QLabel(LocaleUi);
        measureLabel->setObjectName(QString::fromUtf8("measureLabel"));

        descriptForm->setWidget(3, QFormLayout::LabelRole, measureLabel);

        measureValue = new QLabel(LocaleUi);
        measureValue->setObjectName(QString::fromUtf8("measureValue"));
        sizePolicy5.setHeightForWidth(measureValue->sizePolicy().hasHeightForWidth());
        measureValue->setSizePolicy(sizePolicy5);

        descriptForm->setWidget(3, QFormLayout::FieldRole, measureValue);


        verticalLayout->addLayout(descriptForm);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(6);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonLayout->setContentsMargins(100, -1, -1, -1);
        cacelBtn = new QPushButton(LocaleUi);
        cacelBtn->setObjectName(QString::fromUtf8("cacelBtn"));
        sizePolicy.setHeightForWidth(cacelBtn->sizePolicy().hasHeightForWidth());
        cacelBtn->setSizePolicy(sizePolicy);
        cacelBtn->setFlat(false);

        buttonLayout->addWidget(cacelBtn);

        applyBtn = new QPushButton(LocaleUi);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        sizePolicy.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
        applyBtn->setSizePolicy(sizePolicy);
        applyBtn->setFlat(false);

        buttonLayout->addWidget(applyBtn);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(LocaleUi);

        QMetaObject::connectSlotsByName(LocaleUi);
    } // setupUi

    void retranslateUi(QWidget *LocaleUi)
    {
        LocaleUi->setWindowTitle(QCoreApplication::translate("LocaleUi", "Form", nullptr));
        backbtn->setText(QCoreApplication::translate("LocaleUi", "...", nullptr));
        title->setText(QCoreApplication::translate("LocaleUi", "Language & Region", nullptr));
        ac_notification->setText(QCoreApplication::translate("LocaleUi", "...", nullptr));
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
        CurrentcyValue->setText(QString());
        measureLabel->setText(QCoreApplication::translate("LocaleUi", "Measurement Unit:", nullptr));
        measureValue->setText(QString());
        cacelBtn->setText(QCoreApplication::translate("LocaleUi", "Cancel", nullptr));
        applyBtn->setText(QCoreApplication::translate("LocaleUi", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
class LocaleUi: public Ui_LocaleUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NEWLOCALEWPNOCC_H
