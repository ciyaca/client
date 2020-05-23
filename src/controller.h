#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include "client.h"
#include "widget.h"
#include "mainwindow.h"
#include "common.h"

class Controller : public QObject
{
  Q_OBJECT
private:
  QThread client_thread;
  Client *client;
  QString nickname;

public:
  Widget* login_window;
  MainWindow* main_window;

public:
  explicit Controller(QObject *parent = nullptr);
  ~Controller();

  void start();
  void login();

signals:
  void startRunning(); // 用于触发新线程中的耗时操作函数

private slots:
  void recvMessage(person_info p); // 接收新线程中的结果
  void loginSuccessfully(QString nickname);
  void exit();


};

#endif // CONTROLLER_H
