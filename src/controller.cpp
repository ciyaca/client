#include "controller.h"
#include "QDebug"


Controller::Controller(QObject *parent) : QObject(parent)
{
  qDebug() << "Controller's thread is :" << QThread::currentThreadId();

  this->client = Client::getInstance();
  client->moveToThread(&client_thread);

  this->login_window = new Widget();
  this->main_window = new MainWindow();

  connect(this, &Controller::startRunning, client, &Client::on_doSomething);
  connect(&client_thread, &QThread::finished, client, &QObject::deleteLater);
  connect(client, &Client::resultReady, this, &Controller::recvMessage);
  client_thread.start();


  connect(login_window, &Widget::loginSuccessfully, this, &Controller::loginSuccessfully);
  connect(login_window, &Widget::close, this, &Controller::exit);


}


Controller::~Controller()
{
  client_thread.quit();
  client_thread.wait();
}

void Controller::start()
{
  emit startRunning();
}

void Controller::recvMessage(const QString &str)
{
  qDebug() << str;
}

void Controller::login()
{
    this->login_window->show();
}

void Controller::loginSuccessfully(QString nickname)
{
    this->nickname = nickname;
    this->main_window->nickname = nickname;
    this->client->setUsername(nickname);
    this->login_window->close();
    this->main_window->show();
}

void Controller::exit()
{
    client_thread.exit(0);
    delete this->client;
    delete this->login_window;
    delete this->main_window;
}
