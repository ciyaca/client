#include "chatface.h"
#include "ui_chatface.h"
#include "common.h"
#include <emojiwidget.h>
#include <QWidget>
#include <QMainWindow>
#include <QDebug>

Chatface::Chatface(struct person_info temp):
    ui(new Ui::Chatface)
{
    ui->setupUi(this);

    ui->label->setText(temp.name);
//    qDebug() << temp.name;
    QFont ft;
    ft.setPointSize(16);
    ui->label->setFont(ft);

    //初始化
    chatface_init();
}

void Chatface::chatface_init()
{
    //添加图标
    ui->toolButton->setIcon(QIcon(":/image/emoji.png"));
    ui->toolButton_2->setIcon(QIcon(":/image/file.png"));

    this->emoji_flag = 0;
}
Chatface::~Chatface()
{
    delete ui;
}

void Chatface::on_toolButton_clicked()
{
    emojiwidget* emo = NULL;
    if (this->emoji_flag == 0) {
        emo = new emojiwidget();
        emo->parentt = (Chatface*)emo->parentt;
        emo->parentt = this;
        emo->move(210, 300);
        emo->show();
        this->emoji_flag = 1;
        connect(emo, SIGNAL(emit_emoji_path(QString)), this, SLOT(on_recv_emoji_path(QString)));
    }
    else {
        emo->close();
        this->emoji_flag = 0;
    }
}
void Chatface::on_recv_emoji_path(QString path)
{
    qDebug() << "on_recv_emoji recv path:" << path;
//    shijian = new QDateTime;
//    QString nowTime = "";
//    nowTime.append(shijian->currentDateTime().toString());
//    int row_count = ui->tableWidget_2->rowCount();
//    ui->tableWidget_2->insertRow(row_count);
//    ui->tableWidget_2->insertRow(row_count + 1);
//    ui->tableWidget_2->setItem(row_count, 0, new QTableWidgetItem(nowTime));
//    ui->tableWidget_2->setItem(row_count + 1, 0, new QTableWidgetItem(QIcon(path), ""));

//    Message msg;
//    msg.msgType = FL_CONTENT;
//    QByteArray sh = path.toUtf8();
//    strcpy(msg.content, sh.data());
//    sh = er.toUtf8();
//    strcpy(msg.sendName, sh.data());
//    sh = to_user_id.toUtf8();
//    strcpy(msg.recvName, sh.data());
//    sock.write((char*)&msg, sizeof(msg));

    this->emoji_flag = 0;
}
