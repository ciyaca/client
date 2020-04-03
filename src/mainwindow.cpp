#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "chatface.h"
#include "come_message.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置界面初始化
    this->Show_init();

    //test ->recv
    this->Recv_t[this->num_r].tag = 1;
    this->Recv_t[this->num_r].name = "IFpop";
    this->Recv_t[this->num_r++].Message = "123";
//    qDebug() << this->Recv_t[0].name;
    this->First_recv();
    this->Recv_t[this->num_r].tag = 2;
    this->Recv_t[this->num_r].name = "Derek";
    this->Recv_t[this->num_r++].Message = "4984984984465646";
    this->First_recv();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show_init(){
    //用户头像
    QPixmap Avatar;
    Avatar.load(":/image/Test_Avatar.jpg");
    // 将图片剪裁压缩成50*50大小的图
    QPixmap fitpixmap_avatar = Avatar.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_avatar = PixmapToRound(Avatar,25);
    ui->Avatar->setPixmap(fitpixmap_avatar);

    //添加切换按钮icon
    ui->tabWidget->setTabIcon(0,QIcon(":/image/chat.png"));
    ui->tabWidget->setTabText(0,"");
    ui->tabWidget->setTabIcon(1,QIcon(":/image/list.png"));
    ui->tabWidget->setTabText(1,"");
    ui->tabWidget->setTabIcon(2,QIcon(":/image/bbs.png"));
    ui->tabWidget->setTabText(2,"");

    //固定窗口大小
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    //显示初始状态背景图
    ui->page->setAutoFillBackground(true);  // 不加上, 可能显示不出背景图.
    QPalette palette = ui->page->palette();
    palette.setBrush(QPalette::Window,
    QBrush(QPixmap(":/image/bg1.jpg").scaled(  // 缩放背景图.
        ui->page->size(),
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation)));  // 使用平滑的缩放方式
    ui->page->setPalette(palette);         // 给widget加上背景图

    //显示初始状态背景图
    ui->widget_tab_2->setAutoFillBackground(true);  // 不加上, 可能显示不出背景图.
    palette = ui->widget_tab_2->palette();
    palette.setBrush(QPalette::Window,
    QBrush(QPixmap(":/image/bg.jpg").scaled(  // 缩放背景图.
        ui->widget_tab_2->size(),
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation)));  // 使用平滑的缩放方式
    ui->widget_tab_2->setPalette(palette);         // 给widget加上背景图

    //初始化BBS

    //显示好友列表

    //读取历史聊天记录

    //初始化list
}

//第一次收到消息
void MainWindow::First_recv(){
    //在tab左边新建一行list
    QListWidgetItem* item = new QListWidgetItem;
    //从头像库中进行寻找
    QString Message;
    Come_message* witem = new Come_message(this->Recv_t[this->num_r-1]);
    item->setSizeHint(QSize(198,75));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,witem);

    Chatface* chat_temp = new Chatface(this->Recv_t[this->num_r-1]);
    ui->stackedWidget->addWidget(chat_temp);
    ui->stackedWidget->setCurrentIndex(this->num_r);
    ui->listWidget->setCurrentRow(this->num_r-1);
}

void MainWindow::on_MessageButton_clicked()
{
}

void MainWindow::on_ChatButton_clicked()
{
}

void MainWindow::on_BBSButton_clicked()
{
}
