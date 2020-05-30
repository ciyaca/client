#include "bbsnewpostdialog.h"
#include "ui_bbsnewpostdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


BBSNewPostDialog::BBSNewPostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BBSNewPostDialog)
{
    ui->setupUi(this);
//    this->__progress_dialog = new QProgressDialog(this);
}

BBSNewPostDialog::~BBSNewPostDialog()
{
    delete ui;
}

void BBSNewPostDialog::on_bbs_attach_file_btn_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open .pacp"), ".", tr("All files(*.*)"));
    if (path.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    }
    else
    {
        this->__file_paths.append(path);
    }
}

void BBSNewPostDialog::on_bbs_send_post_btn_clicked()
{
    //diao yong jie kou

    QMessageBox::information(this, "sending...",
                             "Don't close the dialog.");

    for(int i = 0;i <= 10;i += 1)
    {
        sleep(1000);
//        this->changeProcessDialogValue();
    }

//    this->__progress_dialog->close();
    this->close();
}

void BBSNewPostDialog::sleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);

}

void BBSNewPostDialog::showProcess(int range)
{
    this->__progress_dialog->setWindowModality(Qt::WindowModal);
    this->__progress_dialog->setMinimumDuration(0);//dialog出现需等待的时间
    this->__progress_dialog->setWindowTitle("Please Wait...");
    this->__progress_dialog->setRange(0,range);
    this->__progress_dialog->setLabelText("sending...");
    this->__progress_dialog->setCancelButtonText("Cancel");
    this->__progress_dialog->setValue(0);
}

void BBSNewPostDialog::changeProcessDialogValue()
{
    this->__progress_dialog->setValue(this->__progress_dialog->value() + 1);
}


