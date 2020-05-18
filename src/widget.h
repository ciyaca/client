#ifndef WIDGET_H
#define WIDGET_H
#include "client_rpc.hpp"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QPushButton* createLineEditRightButton(QLineEdit *);
    int state_login;
    int state_register;
    MainWindow *Chat;
    ~Widget();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
