#ifndef MANAGE_H
#define MANAGE_H

#include "widget.h"
#include "mainwindow.h"

class Manage
{

public:
    Manage(Widget*,MainWindow*);
    ~Manage();
    void ChatStart(); //开启聊天
private:
    Widget* login;
    MainWindow* Chat;
};
Manage::Manage(Widget* login,MainWindow* Chat)
{
    this->login = login;
    this->Chat = Chat;
    this->login->show();
    this->Chat->hide();
}
void Manage::ChatStart(){
     this->login->hide();
     this->Chat->show();
}

#endif // MANAGE_H
