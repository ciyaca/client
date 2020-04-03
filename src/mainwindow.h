#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"

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
    ~MainWindow();

private slots:
    void on_MessageButton_clicked();

    void on_ChatButton_clicked();

    void on_BBSButton_clicked();

private:
    Ui::MainWindow *ui;
    struct person_info Recv_t[50];
    int num_r = 0;
};

#endif // MAINWINDOW_H
