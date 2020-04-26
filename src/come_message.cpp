#include "come_message.h"
#include "ui_come_message.h"
#include "come_message.h"
#include <QDebug>
#include "common.h"
#include "client_rpc.hpp"

Come_message::Come_message(struct person_info temp) :
    ui(new Ui::Come_message)
{
    ui->setupUi(this);
    //根据信息构建头像、用户名、消息部分内容
    //添加来信人头像
    QPixmap Avatar;
    Avatar.load(":/image/bg.jpg");
    // 将图片剪裁压缩成50*50大小的图
    QPixmap fitpixmap_avatar = Avatar.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_avatar = PixmapToRound(Avatar,25);
    ui->Avatar->setPixmap(fitpixmap_avatar);

    ui->label->setText(temp.name);
//    qDebug() << temp.name;
    QFont ft;
    ft.setPointSize(15);
    ui->label->setFont(ft);
    //截取部分信息
    QString msg;
    if(temp.Message.size() > 10)
    {
        msg = temp.Message.mid(0,10);
        msg = msg + "...";
    }
    else
        msg = temp.Message;
    ui->label_2->setText(msg);
}

Come_message::~Come_message()
{
    delete ui;
}
