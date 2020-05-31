#include "bbsnewpostdialog.h"
#include "ui_bbsnewpostdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "controller.h"


BBSNewPostDialog::BBSNewPostDialog(const QString&postid, const QString post, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BBSNewPostDialog)
{
    this->postid = postid;
    this->post = post;
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
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

//    QMessageBox::information(this, "sending...",
//                             "Sending...");

    this->packetPost();
    this->sendPost();

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

QString BBSNewPostDialog::packetWithLi(const QString &entry)
{
    return "<li>" + entry + "</li>";
}

void BBSNewPostDialog::packetPost()
{
    this->post += this->packetWithLi(Controller::username);
    if(this->post == "" && this->postid == "")
    {
        //new post
    }
    else
    {
        //comment
        this->post += packetWithLi("");//reply to
    }
    this->post += ui->textEdit->toPlainText();
    this->post += this->packetWithLi(QString::number(this->__file_paths.size()));
    for(int i = 0; i < this->__file_paths.size(); i++)
    {
        QString path = __file_paths[i];
        int index = path.lastIndexOf('/');//查找最后一次出现'/'在字符串中的索引,
        path = path.mid(index+1);//截取字符串str,起始索引位置为index+1,截取字符到字符串结束
        this->post += this->packetWithLi("");//file_id
        this->post += packetWithLi(path);//file_name
    }
}

void BBSNewPostDialog::sendPost()
{
    if(this->postid == "")
    {
        //new post
    }
    else
    {
        //comment
    }
    qDebug() << this->post;
    return;
}



