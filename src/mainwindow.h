#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include <QListWidgetItem>
#include<QTreeWidgetItem>
#include <QCloseEvent>
#include <signal.h>
#include <unistd.h>
#include "bbsnewpostdialog.h"
#include "BBSPostReceiver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString nickname;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void Show_init();
    void First_recv();
    void recv_message(message_info);
    void initContactTree();
    void initGroupChatTree();
    void addMyFriendInfo(QTreeWidgetItem* pRootGroupItem,message_info,int);

    void addfriendrequest(QString,QString);

    void set_Avatar(int);
    void set_name(QString);
    int Avatar_tag;
    QList<message_info> person_list;
    QList<message_info> group_list;

    ~MainWindow();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void Add_friend();
    void Create_group();
    void deleterequestline();

    void on_bbs_new_post_btn_clicked();

    void on_refresh_clicked();

public:
    void closeEvent(QCloseEvent *event);
    void setParentController(void*);


public:
    BBSPostReceiver* bbs_post_receiver;
private:
    Ui::MainWindow *ui;
    struct message_info Recv_t[50];
    QTreeWidgetItem *pRootFriendItem;

    int num_r = 0;


    BBSNewPostDialog* __bbs_new_post_dialog;

    void* parent_controller;
};

#endif // MAINWINDOW_H
