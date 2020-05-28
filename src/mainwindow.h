#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include <QListWidgetItem>
#include<QTreeWidgetItem>

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
    void recv_message(person_info);
    void initContactTree();
    void initGroupChatTree();
    void addMyFriendInfo(QTreeWidgetItem* pRootGroupItem,person_info,int);

    void set_Avatar(int);
    void set_name(QString);
    int Avatar_tag;
    QList<person_info> person_list;
    QList<person_info> group_list;
    ~MainWindow();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void Add_friend();
    void Create_group();

private:
    Ui::MainWindow *ui;
    struct person_info Recv_t[50];
    int num_r = 0;
};

#endif // MAINWINDOW_H
