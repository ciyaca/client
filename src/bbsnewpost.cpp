#include "bbsnewpost.h"
#include "ui_bbsnewpost.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

BBSNewPost::BBSNewPost(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BBSNewPost)
{
    ui->setupUi(this);
}

BBSNewPost::~BBSNewPost()
{
    delete ui;
}

void BBSNewPost::on_bbs_attach_file_btn_clicked()
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

void BBSNewPost::on_bbs_send_post_btn_clicked()
{
    //diao yong rpc fasong wenjian

    //get filename and insert into post

}
