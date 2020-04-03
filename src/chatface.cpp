#include "chatface.h"
#include "ui_chatface.h"
#include "common.h"

Chatface::Chatface(struct person_info temp):
    ui(new Ui::Chatface)
{
    ui->setupUi(this);

    ui->label->setText(temp.name);
//    qDebug() << temp.name;
    QFont ft;
    ft.setPointSize(16);
    ui->label->setFont(ft);

    ui->toolButton->setIcon(QIcon(":/image/emoji.png"));
    ui->toolButton_2->setIcon(QIcon(":/image/file.png"));
}

Chatface::~Chatface()
{
    delete ui;
}
