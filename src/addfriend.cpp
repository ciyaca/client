#include "addfriend.h"
#include "ui_addfriend.h"
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

addfriend::addfriend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    //初始化
    this->flag = 0;
    this->group_name = "";
    this->person_name = "";

    this->setWindowTitle("添加好友");
    ui->tabWidget->setTabText(0,"找好友|");
    ui->tabWidget->setTabText(1,"找群组");

    ui->lineEdit->setPlaceholderText("请输入用户名");
    //加入隐藏按钮
    QPushButton *password_button1 = this->createLineEditRightButton(ui->lineEdit);
    connect(password_button1,SIGNAL(clicked()),this,SLOT(person_search()));

    QPushButton *password_button2 = this->createLineEditRightButton(ui->lineEdit_2);
    connect(password_button2,SIGNAL(clicked()),this,SLOT(group_search()));
}
QPushButton* addfriend::createLineEditRightButton(QLineEdit *edit)
{
    QPushButton *button = new QPushButton();
    QHBoxLayout *layout = new QHBoxLayout();
    button->setCursor(Qt::PointingHandCursor);
    button->setCheckable(true);
    layout->addStretch();
    layout->addWidget(button);
    layout->setContentsMargins(0, 0, 0, 0);
    edit->setLayout(layout);

    return button;
}
void addfriend::person_search(){
    qDebug()<<"search";
    //获取查询者id
    QString name = ui->lineEdit->text();
    qDebug()<<name;
    /*
     * 这里需要询问服务器是否存在此人
     * */
}

void addfriend::group_search(){
    qDebug()<<"search";
    //获取查询者id
    QString name = ui->lineEdit->text();
    qDebug()<<name;
    /*
     * 这里需要询问服务器是否存在此人
     * find flag = 1 ,not find ,flag = 0
     * */
}
addfriend::~addfriend()
{
    delete ui;
}
