/*
 * name: chatface.cpp
 * description: 聊天界面窗体
 * */

#include "chatface.h"
#include "ui_chatface.h"
#include "chatmessage.h"
#include "common.h"
#include <emojiwidget.h>
#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include "client_rpc.hpp"
#include <QImageReader>
#include <QMovie>
#include <QTextDocumentFragment>
#include <QMessageBox>
#include <QDateTime>
#include <QVBoxLayout>
#include <QFileDialog>

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

    ui->lineEdit->setPlaceholderText("文件名");
    ui->progressBar->setValue(0);

//    recv_message("1 :/image/emoji/23.gif");
//    recv_message("2 :/image/add.png");
}
Chatface::~Chatface()
{
    delete ui;
}

/*
 * 表情包按键
 * */
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
/*
 * 点击表情包之后的动作
 * */
void Chatface::on_recv_emoji_path(QString path)
{
    // 表情包直接发送
    QString msg = "        ";
    //在这边显示消息
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    dealMessageTime(time);
    dealMessage(msg,time,path, QNChatMessage::User_Meemjio);
    /*
     * 这里需要将path直接发送
     */
    this->emoji_flag = 0;
}

/*
 * send message
 * */
void Chatface::on_pushButton_clicked()
{
    QString sendStr = ui->textEdit->toPlainText();

    if(sendStr == ""){
        if(ui->lineEdit->text() == ""){
            QMessageBox::warning(this,tr("warning"),tr("发送信息为空"),QMessageBox::Yes);
        }
    }
    else{
        //在这边显示消息
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
//        qDebug()<<"addMessage" << sendStr << time << ui->listWidget->count();
        dealMessageTime(time);
        dealMessage(sendStr, time, "",QNChatMessage::User_Me);
        /*
         *  发送sendstr字符串
        */
    }
    if(ui->lineEdit->text() != ""){
        /*
         * 发送文件
         * 文件名称在lineEdit中
         * */
    }
    ui->lineEdit->clear();
    ui->progressBar->setValue(0);
    ui->textEdit->clear();
}

/*
 * 消息处理函数，界面显示
 * */
void Chatface::dealMessage(QString text, QString time, QString path, QNChatMessage::User_Type type)
{
    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    messageW->Me_tag = this->Me_tag;
    messageW->She_tag = this->She_tag;
    messageW->setFixedWidth(this->width());
    QSize size;
    if(type == QNChatMessage::User_Mepic || type == QNChatMessage::User_Shepic){
        size = messageW->picRect(path);
    }
    else{
        size = messageW->fontRect(text);
    }
    item->setSizeHint(size);
    messageW->setText(text, path,time, size, type);
    ui->listWidget->setItemWidget(item, messageW);
}
/*
 * 显示时间
 * */
void Chatface::dealMessageTime(QString curMsgTime)
{
//    qDebug()<<curMsgTime;

    bool isShowTime = false;
    if(ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
        messageW->Me_tag = this->Me_tag;
        messageW->She_tag = this->She_tag;
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 120); // 两个消息相差两分钟
//        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(ui->listWidget);
        messageTime->Me_tag = this->Me_tag;
        messageTime->She_tag = this->She_tag;
        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, "",curMsgTime, size, QNChatMessage::User_Time);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}

/*
 * 接收消息后的处理函数
 * */
void Chatface::recv_message(QString msg){
    if(msg[0] == '0'){// 假设是表情包  0 path
        msg = msg.mid(2,msg.size());
        QString message = "        ";
        //在这边显示消息
        qDebug()<<msg;
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
        dealMessageTime(time);
        dealMessage(message,time,msg, QNChatMessage::User_Sheemjio);
    }
    else if(msg[0] == '1'){//如果是文字 1 msg
        msg = msg.mid(2,msg.size());
        //在这边显示消息
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
        qDebug()<<"addMessage" << msg << time << ui->listWidget->count();
        dealMessageTime(time);
        dealMessage(msg, time, "",QNChatMessage::User_She);
    }
    else if(msg[0] == '2'){//如果是图片 2
        msg = msg.mid(2,msg.size());
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
        qDebug()<<"addMessage" << msg << time << ui->listWidget->count();
        dealMessageTime(time);
        dealMessage("", time, msg,QNChatMessage::User_Shepic);
    }
    else if(msg[0] == '3'){//如果是文件
        msg = msg.mid(2,msg.size());
    }
}

/*
 * 发送文件
 * */
void Chatface::on_toolButton_2_clicked()
{
    ui->progressBar->setValue(0);
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", "/", "files (*)");
    ui->lineEdit->setText(filename);
    if(filename.endsWith(".png")||filename.endsWith(".jpg")){//发送图片
        qDebug() << filename;
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
        dealMessageTime(time);
        dealMessage("",time,filename,QNChatMessage::User_Mepic);
    }
}
