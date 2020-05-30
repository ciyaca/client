#include "creategroup.h"
#include "ui_creategroup.h"

creategroup::creategroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creategroup)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    this->setWindowTitle("创建群组");
    ui->pushButton->setText("创建");
}

creategroup::~creategroup()
{
    delete ui;
}

void creategroup::on_pushButton_clicked()
{
    //询问服务器

    //根据状态码进行操作
}
