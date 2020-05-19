#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client_rpc.hpp"
#include <QMainWindow>
#include "common.h"
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void Show_init();
    void First_recv();
    void recv_message(person_info);
    int Avatar_tag;
    ~MainWindow();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    struct person_info Recv_t[50];
    int num_r = 0;
};

#endif // MAINWINDOW_H
