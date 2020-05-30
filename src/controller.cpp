#include "controller.h"
#include "QDebug"


Controller::Controller(QObject *parent) : QObject(parent)
{
    printf("I'm Controller");
    fflush(stdout);
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

void Controller::recvMessage(person_info p)
{
    this->main_window->recv_message(p);
}

void Controller::login()
{
    qDebug() << "controller working in thread:" << QThread::currentThreadId();
    this->login_window->show();
}

void Controller::loginSuccessfully(QString nickname)
{
    qDebug() << nickname;
    this->nickname = nickname;
    this->main_window->nickname = nickname;
    this->client->setUsername(nickname);
    this->login_window->close();
    this->start();
    this->main_window->show();
}

void Controller::exit()
{
    client_thread.exit(0);
    delete this->client;
    delete this->login_window;
    delete this->main_window;

}
