#include "contactitem.h"
#include "ui_contactitem.h"
#include "common.h"

contactitem::contactitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactitem)
{
    ui->setupUi(this);
}
void contactitem::setContactName(QString name){
    ui->label_2->setText(name);
}
QString contactitem::getContactName(){
    return ui->label_2->text();
}
void contactitem::setContactIcon(int tag){
    QPixmap Avatar;
    QString path = QString(":/image/Avatar/%1.jpg").arg(tag);
    Avatar.load(path);
    // 将图片剪裁压缩成50*50大小的图
    QPixmap fitpixmap_avatar = Avatar.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_avatar = PixmapToRound(Avatar,25);
    ui->label->setPixmap(fitpixmap_avatar);
}
contactitem::~contactitem()
{
    delete ui;
}
