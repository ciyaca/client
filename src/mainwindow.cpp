#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "chatface.h"
#include "come_message.h"
#include <QDebug>
#include <QDateTime>
#include "contactitem.h"
#include "addfriend.h"
#include "friendrequest.h"
#include "creategroup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置界面初始化
    this->Show_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show_init(){

    this->set_Avatar(10);
    this->set_name("ifpop");

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

    //初始化BBS

    //显示好友列表
    struct message_info temp;
    temp.name = "q";
    temp.Message = "";
    temp.tag = 1;
    person_list.append(temp);
    temp.name = "w";
    temp.Message = "";
    temp.tag = 2;
    person_list.append(temp);
    group_list.append(temp);

    this->initContactTree();
    this->initGroupChatTree();
    //读取历史聊天记录

    //初始化，添加好友按钮
    QAction *addfriend = new QAction("添加好友或群组", this);
    QAction *create_group = new QAction("创建群聊", this);
    QMenu *mfile = new QMenu;
    mfile->addAction(addfriend);
    mfile->addAction(create_group);
    ui->pushButton->setMenu(mfile);
    //绑定槽函数
    connect( addfriend, SIGNAL(triggered()), this, SLOT(Add_friend()));
    connect( create_group, SIGNAL(triggered()), this, SLOT(Create_group()));
    this->addfriendrequest("ifpop","111111111111111111111111");
    this->addfriendrequest("de","111111111111111111111111");

}
void MainWindow::addfriendrequest(QString name, QString message){
    QListWidgetItem* item = new QListWidgetItem;
    friendrequest* fr = new friendrequest(ui->listWidget_2);
    fr->setname(name);
    fr->setmessage(message);
    //获取tag
    fr->setavatar(10);

     item->setSizeHint(QSize(575,80));
     ui->listWidget_2->addItem(item);
     ui->listWidget_2->setItemWidget(item,fr);
     connect(fr, &friendrequest::deleterequestline, this, &MainWindow::deleterequestline);
}
void MainWindow::set_Avatar(int tag){
    //用户头像
    QPixmap Avatar;
    QString path = ":/image/Avatar/%1.jpg";
    path = path.arg(tag);
    Avatar.load(path);
    this->Avatar_tag = 10;
    // 将图片剪裁压缩成50*50大小的图
    QPixmap fitpixmap_avatar = Avatar.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fitpixmap_avatar = PixmapToRound(Avatar,25);
    ui->Avatar->setPixmap(fitpixmap_avatar);
}
void MainWindow::set_name(QString name){
    ui->name->setText(name);
}

//第一次收到消息
void MainWindow::First_recv(){
    qDebug()<<"first_recv";
    qDebug()<<this->Recv_t[this->num_r-1].name;
    qDebug()<<this->Recv_t[this->num_r-1].tag;

    //在tab左边新建一行list
    QListWidgetItem* item = new QListWidgetItem;
    //从头像库中进行寻找
    QString Message;
    Come_message* witem = new Come_message(this->Recv_t[this->num_r-1]);
    item->setSizeHint(QSize(198,75));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,witem);

    Chatface* chat_temp = new Chatface(this->nickname, this->Recv_t[this->num_r-1]);
    chat_temp->Me_tag = this->Avatar_tag;

//    qDebug()<<chat_temp->Me_tag;
//    chat_temp->recv_message("0 :/image/emoji/23.gif");
//    chat_temp->recv_message("2 :/image/bg.jpg");

    ui->stackedWidget->addWidget(chat_temp);
    ui->stackedWidget->setCurrentIndex(this->num_r+1);
    ui->listWidget->setCurrentRow(this->num_r-1);
    recv_message(this->Recv_t[this->num_r-1]);
}

void MainWindow::recv_message(message_info recv_person){
    int cur_index = -1; //标记是否在左边找到，没有则新建

    if(recv_person.groupname==nullptr){//单聊
        for(int i = 0 ; i < this->num_r ; i++){
            if(this->Recv_t[i].name == recv_person.name){
                //显示消息
                cur_index = i;
            }
        }
    }
    else{// 群聊
        for(int i = 0 ; i < this->num_r ; i++){
            if(this->Recv_t[i].name == recv_person.groupname){
                //显示消息
                cur_index = i;
            }
        }
    }

    if(cur_index != -1){//不在消息列表
        ui->stackedWidget->setCurrentIndex(cur_index+2);
        Chatface* chat_temp = (Chatface*)ui->stackedWidget->widget(cur_index+2);
        if(recv_person.time == nullptr){//显示时间
            QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
            chat_temp->dealMessageTime(time);
        }
        else{
            chat_temp->dealMessageTime(recv_person.time);
        }
        chat_temp->recv_message(recv_person.Message);
    }
    else{//新建
        this->Recv_t[this->num_r++] = recv_person;
        this->First_recv();
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
//    qDebug() << ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(ui->listWidget->currentRow()+2);
}
void MainWindow::initContactTree()
{
    ui->treeWidget->clear();
    //分组节点
    this->pRootFriendItem = new QTreeWidgetItem();
    //设置Data用于区分，Item是分组节点还是子节点，0代表分组节点，1代表子节点
    pRootFriendItem->setData(0, Qt::UserRole, 0);
    QLabel *pItemName = new QLabel(ui->treeWidget);
    int nMyFriendNum = person_list.size();
    QString qsGroupName = QString(tr("我的好友 [%1/%2]")).arg(0).arg(nMyFriendNum);
    pItemName->setText(qsGroupName);
    //擦入分组节点
    ui->treeWidget->addTopLevelItem(pRootFriendItem);
    ui->treeWidget->setItemWidget(pRootFriendItem, 0, pItemName);

    for (int nIndex = 0; nIndex < nMyFriendNum; ++nIndex)
    {
        //添加子节点
        addMyFriendInfo(pRootFriendItem,person_list[nIndex],nIndex+1);
    }
}

void MainWindow::initGroupChatTree()
{
    QTreeWidgetItem *pRootFriendItem = new QTreeWidgetItem();
    int nMyGrouprNum = group_list.size();
    ////设置Data用于区分，Item是分组节点还是子节点，0代表分组节点
    pRootFriendItem->setData(0, Qt::UserRole, 100);
    QLabel *pItemName = new QLabel(ui->treeWidget);
    QString qsGroupName = QString(tr("我的群组 [%1/%2]")).arg(0).arg(nMyGrouprNum);
    pItemName->setText(qsGroupName);

    for (int nIndex = 0; nIndex < nMyGrouprNum; ++nIndex)
    {
        //添加子节点
        addMyFriendInfo(pRootFriendItem,group_list[nIndex],nIndex+101);
    }
    ui->treeWidget->addTopLevelItem(pRootFriendItem);
    ui->treeWidget->setItemWidget(pRootFriendItem, 0, pItemName);
}

void MainWindow::addMyFriendInfo(QTreeWidgetItem* pRootGroupItem,message_info pi,int num)
{
    QTreeWidgetItem *pChild = new QTreeWidgetItem();
    pChild->setSizeHint(0,QSize(241,50));
    //添加子节点
    pChild->setData(0, Qt::UserRole, num);
    contactitem* pContactItem = new contactitem(ui->treeWidget);
    pContactItem->setContactName(pi.name);
    pContactItem->setContactIcon(pi.tag);
//    pContactItem->setContactIcon(USER_ICON);
    pRootGroupItem->addChild(pChild);
    ui->treeWidget->setItemWidget(pChild, 0, pContactItem);
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QVariant temp = item->data(0,Qt::UserRole);
    int num = temp.toInt();
    //如果此时双击的是群组名称，则不做处理
    if(num == 0){
        qDebug()<<"我的好友";
    }
    else if(num == 100){
        qDebug()<<"我的群组";
    }
    else if(num >= 1 && num < 100){//好友上限100
        qDebug()<<person_list[num-1].name;
        qDebug()<<person_list[num-1].tag;
        int cur_index = -1;
        //从消息列表中进行寻找
        for(int i = 0 ; i < this->num_r ; i++){
            if(this->Recv_t[i].name == person_list[num-1].name){
                //显示消息
                cur_index = i;
            }
        }
        if(cur_index != -1){
            ui->tabWidget->setCurrentIndex(0);
            ui->stackedWidget->setCurrentIndex(cur_index+2);
        }
        else{
//            qDebug()<<"new";
            this->Recv_t[this->num_r++] = person_list[num-1];
            this->First_recv();
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    else{//群组
        int cur_index = -1;
        //从消息列表中进行寻找
        for(int i = 0 ; i < this->num_r ; i++){
            if(this->Recv_t[i].name == group_list[num-101].name){
                //显示消息
                cur_index = i;
            }
        }
        qDebug()<<cur_index;
        if(cur_index != -1){
            ui->tabWidget->setCurrentIndex(0);
            ui->stackedWidget->setCurrentIndex(cur_index+2);
        }
        else{
//            qDebug()<<"new";
            this->Recv_t[this->num_r++] = group_list[num-101];
            this->First_recv();
            ui->tabWidget->setCurrentIndex(0);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::on_pushButton_2_clicked()
{
}
void MainWindow::Add_friend(){
    addfriend* af = new addfriend();
    af->show();


}
void MainWindow::Create_group(){
    creategroup* cg = new creategroup();
    cg->show();
}
void MainWindow::deleterequestline(){
    int row = ui->listWidget_2->currentRow();
    QListWidgetItem* item = ui->listWidget_2->currentItem();
    friendrequest* fr = (friendrequest*)ui->listWidget_2->itemWidget(item);

    if(fr->isagree == 1){//agree
        struct message_info temp;
        temp.name = fr->name;
        temp.Message = "";
        temp.tag = fr->avatar;
        person_list.append(temp);
        qDebug()<<person_list.last().name;
        addMyFriendInfo(this->pRootFriendItem,person_list.last(),person_list.size());
    }
    ui->listWidget_2->takeItem(row);
    delete fr;
}
