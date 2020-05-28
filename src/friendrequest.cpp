#include "friendrequest.h"
#include "ui_friendrequest.h"
#include "common.h"

friendrequest::friendrequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::friendrequest)
{
    ui->setupUi(this);
    ui->pushButton->setText("接受");
    ui->pushButton_2->setText("拒绝");

    this->isagree = -1;
}

void friendrequest::setname(QString name){
    ui->label->setText(name);
    this->name = name;
}

void friendrequest::setavatar(int tag){
    QPixmap Avatar;
    QString path = ":/image/Avatar/%1.jpg";
    path = path.arg(tag);
    Avatar.load(path);

    // 将图片剪裁压缩成50*50大小的图
    QPixmap fitpixmap_avatar = Avatar.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_avatar = PixmapToRound(Avatar,25);
    ui->Avatar->setPixmap(fitpixmap_avatar);

    this->avatar = tag;
}

void friendrequest::setmessage(QString message){
    ui->textEdit->setText(message);
    ui->textEdit->setReadOnly(true);
}

friendrequest::~friendrequest()
{
    delete ui;
}

/*
 * 同意好友申请
 * */
void friendrequest::on_pushButton_clicked()
{
    this->isagree  = 1;
    emit deleterequestline();
}
/*
 * 拒绝好友申请
 * */

void friendrequest::on_pushButton_2_clicked()
{
    this->isagree = 2;
    emit deleterequestline();
}
