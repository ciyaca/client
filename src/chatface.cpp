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
//    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
//    dealMessageTime(time);
//    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
//    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
//    dealMessage(messageW,item,"",time,":image/bg.jpg",QNChatMessage::User_pic);
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
    // 表情包直接发送
//    qDebug() << "on_recv_emoji recv path:" << path;
//    QUrl Uri ( QString ( "file://%1" ).arg ( path ) );
//    QImage image = QImageReader ( path ).read();
//    QTextDocument * textDocument = ui->textEdit->document();
//    textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
//    QTextCursor cursor = ui->textEdit->textCursor();
//    QTextImageFormat imageFormat;
//    imageFormat.setWidth( image.width() );
//    imageFormat.setHeight( image.height() );
//    imageFormat.setName( Uri.toString() );
//    cursor.insertImage(imageFormat);
//    this->emjio_list.append(path);
//    QTextDocumentFragment fragment;
//    QString file_path = "<img src='"+path+"'>";
//    qDebug() << file_path;
//    fragment = QTextDocumentFragment::fromHtml(file_path);
//    ui->textEdit->textCursor().insertFragment(fragment);
//    ui->textEdit->setVisible(true);
    QString msg = "        ";
    //在这边显示消息
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    dealMessageTime(time);
    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    dealMessage(messageW, item, msg,time,path, QNChatMessage::User_Meemjio);
    this->emoji_flag = 0;
}

/*
 * send message
 * */
void Chatface::on_pushButton_clicked()
{
    // null|null
    int flag = 0;
    QString sendStr = ui->textEdit->toPlainText();
    QString message;
    if(!this->emjio_list.isEmpty()){
        while(!this->emjio_list.isEmpty()){
            message += this->emjio_list.first();
            this->emjio_list.pop_front();
            message +=";";
        }
        message +="|";
        flag = 1;
    }
    else{
        message +="null;|";
    }
    if(sendStr == ""){
        message += "null";
    }
    else{
        message += sendStr;
        flag = 1;
    }
    if(!flag){
        QMessageBox::warning(this,tr("warning"),tr("发送信息为空"),QMessageBox::Yes);
    }
    else{
        //在这边显示消息
        QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
        message += "\n";
        qDebug()<<"addMessage" << message << time << ui->listWidget->count();
        dealMessageTime(time);
        QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        dealMessage(messageW, item, message, time, "",QNChatMessage::User_Me);
        //need to do send message
    }
    qDebug()<<"addMessage" << message ;
}

void Chatface::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time, QString path, QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(this->width());
    QSize size;
    if(type == QNChatMessage::User_pic){
        size = messageW->picRect(path);
    }
    else{
        size = messageW->fontRect(text);
    }
    item->setSizeHint(size);
    messageW->setText(text, path,time, size, type);
    ui->listWidget->setItemWidget(item, messageW);
}

void Chatface::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
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

        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, "",curMsgTime, size, QNChatMessage::User_Time);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}
