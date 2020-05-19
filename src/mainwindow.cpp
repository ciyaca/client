#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "chatface.h"
#include "come_message.h"
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置界面初始化
    this->Show_init();

    //来信格式样例
    struct person_info temp;
    temp.name = "Derek";
    temp.Message = "1 4984984984465646";
    temp.tag = 1;
    this->recv_message(temp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show_init(){
    //用户头像
    QPixmap Avatar;
    Avatar.load(":/image/Avatar/10.jpg");
    this->Avatar_tag = 10;
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
    QBrush(QPixmap(":/image/logo.png").scaled(  // 缩放背景图.
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
    chat_temp->Me_tag = this->Avatar_tag;
    chat_temp->She_tag = this->Recv_t[this->num_r-1].tag;
    ui->stackedWidget->addWidget(chat_temp);
    ui->stackedWidget->setCurrentIndex(this->num_r+1);
    ui->listWidget->setCurrentRow(this->num_r-1);
    recv_message(this->Recv_t[this->num_r-1]);
}

void MainWindow::recv_message(person_info recv_person){
    QString msg = recv_person.Message;
    int cur_index = 0; //标记是否在左边找到，没有则新建
    //遍历左边tab列表
    qDebug()<<recv_person.name;
    for(int i = 0 ; i < this->num_r ; i++){
        if(this->Recv_t[i].name == recv_person.name){
            //显示消息
            cur_index = i;
        }
    }
    qDebug()<<cur_index<<this->num_r;
    if(cur_index != this->num_r){
        if(msg[0] == '0'){// 假设是表情包  0 path
            msg = msg.mid(2,msg.size());
            QString message = "        ";
            //在这边显示消息
            QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
            ui->stackedWidget->setCurrentIndex(cur_index+2);
            Chatface* chat_temp = (Chatface*)ui->stackedWidget->widget(cur_index+2);
            chat_temp->dealMessageTime(time);
            chat_temp->dealMessage(message,time,msg, QNChatMessage::User_Sheemjio);
        }
        else if(msg[0] == '1'){//如果是文字 1 msg
            msg = msg.mid(2,msg.size());
            //在这边显示消息
            ui->stackedWidget->setCurrentIndex(cur_index+2);
            Chatface* chat_temp = (Chatface*)ui->stackedWidget->widget(cur_index+2);
            QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
            chat_temp->dealMessageTime(time);
            chat_temp->dealMessage(msg, time, "",QNChatMessage::User_She);
            qDebug()<<msg;
        }
        else if(msg[0] == '2'){//如果是图片 2
            msg = msg.mid(2,msg.size());
            ui->stackedWidget->setCurrentIndex(cur_index+2);
            Chatface* chat_temp = (Chatface*)ui->stackedWidget->widget(cur_index+2);
            QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
            chat_temp->dealMessageTime(time);
            chat_temp->dealMessage("", time, msg,QNChatMessage::User_Shepic);
        }
        else if(msg[0] == '3'){
            msg = msg.mid(2,msg.size());
        }
    }
    else{
        this->Recv_t[this->num_r++] = recv_person;
        this->First_recv();
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
//    qDebug() << ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(ui->listWidget->currentRow()+2);
}
