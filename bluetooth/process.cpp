#include "process.h"

process::process(QWidget *parent) : QDialog(parent) {
  setupUi(this);
  progressBar->setRange(0, 1);
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void process::setStatus(QString title, QString filename) {
  titleLabel->setText(title);
  statusLabel->setText(filename);
}

void process::setupUi(QDialog *Dialog) {
  if (Dialog->objectName().isEmpty())
    Dialog->setObjectName(QString::fromUtf8("Dialog"));
  Dialog->resize(466, 146);
  verticalLayout = new QVBoxLayout(Dialog);
  verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
  titleLabel = new QLabel(Dialog);
  titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
  QFont font;
  font.setPointSize(12);
  titleLabel->setFont(font);
  titleLabel->setAutoFillBackground(false);
  titleLabel->setStyleSheet(QString::fromUtf8(""));
  titleLabel->setFrameShape(QFrame::NoFrame);
  titleLabel->setFrameShadow(QFrame::Raised);

  verticalLayout->addWidget(titleLabel);

  progressBar = new QProgressBar(Dialog);
  progressBar->setObjectName(QString::fromUtf8("progressBar"));
  progressBar->setFont(font);
  progressBar->setValue(0);

  verticalLayout->addWidget(progressBar);

  statusLabel = new QLabel(Dialog);
  statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
  statusLabel->setFont(font);

  verticalLayout->addWidget(statusLabel);

  cancelButton = new QPushButton(Dialog);
  cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
  cancelButton->setSizePolicy(sizePolicy);
  cancelButton->setFont(font);

  verticalLayout->addWidget(cancelButton);

  retranslateUi(Dialog);

  QMetaObject::connectSlotsByName(Dialog);
}

void process::retranslateUi(QDialog *Dialog) {
  Dialog->setWindowTitle(
      QCoreApplication::translate("Dialog", "Dialog", nullptr));
  titleLabel->setText(
      QCoreApplication::translate("Dialog", "Filename", nullptr));
  statusLabel->setText(
      QCoreApplication::translate("Dialog", "Status", nullptr));
  cancelButton->setText(
      QCoreApplication::translate("Dialog", "Cancel", nullptr));
}

void process::finished(QBluetoothTransferReply *reply) {
  if (reply->error() != QBluetoothTransferReply::NoError) {
    progressBar->setDisabled(true);
    statusLabel->setText(tr("Failed: %1").arg(reply->errorString()));
  } else {
    statusLabel->setText(tr("Transfer complete"));
  }
  cancelButton->setText(tr("Dismiss"));
}

void process::uploadProgress(qint64 bytesSent, qint64 bytesTotal) {
  if (bytesSent == 0) {
    start.start();
  }

  progressBar->setMaximum(bytesTotal);
  progressBar->setValue(bytesSent);
  if (bytesSent && bytesTotal && (start.elapsed() > 1000) &&
      (bytesSent > start.elapsed() / 1000)) {

    statusLabel->setText(tr("Transferring...ETA: %1s")
                             .arg(((bytesTotal - bytesSent) /
                                   (bytesSent / (start.elapsed() / 1000)))));
  }
}

void process::on_cancelButton_clicked() {}
