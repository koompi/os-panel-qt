#include "userprofile.h"
#include <QDir>
#include <QDebug>
userprofile::userprofile(QWidget *parent) : QWidget (parent)
{

}

void userprofile::getUserprofile()
{
    QFileDialog *dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::FileMode::ExistingFile);
    QString filename = dialog->getOpenFileName (this, tr("Open File"),   QDir::homePath ().append(QStringLiteral ("/Pictures")));
    dialog->setNameFilter(QStringLiteral ("*.png *.jpg *.svg"));
    emit notify_filename (filename);
    qDebug() << filename <<Qt::endl;

}
