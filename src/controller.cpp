#include "controller.h"
#include "QDebug"

QString Controller::username = "";
Controller::Controller(QObject *parent) : QObject(parent)
{
    printf("I'm Controller");
    fflush(stdout);
  qDebug() << "Controller's thread is :" << QThread::currentThreadId();

  this->client = Client::getInstance();
  client->moveToThread(&client_thread);

  this->login_window = new Widget();
  this->main_window = new MainWindow(nullptr);
  this->main_window->setParentController((void*)this);



  connect(this, &Controller::startRunning, client, &Client::on_doSomething);
  connect(&client_thread, &QThread::finished, client, &QObject::deleteLater);
//  connect(client, &Client::resultReady, this, &Controller::recvMessage, Qt::QueuedConnection);
  connect(client, &Client::recvMessageReady, this, &Controller::recvMessage);
  connect(client, &Client::recvFileReady, this, &Controller::recvFile);

  client_thread.start();

  connect(login_window, &Widget::loginSuccessfully, this, &Controller::loginSuccessfully);

  connect(login_window, &Widget::close, this, &Controller::exitController);
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

void Controller::recvMessage(QString source_name, QString message)
{
    qDebug() << "Controller::recvMessage";
    message_info p;
    p.tag = 5;
    p.name = source_name;
    p.Message = message;
    qDebug() << p.name;
    qDebug() << p.Message;
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
    Controller::username = nickname;
    this->main_window->nickname = nickname;
    this->client->setUsername(nickname);
    this->login_window->close();
    this->start();
    this->main_window->Show_init();
    this->main_window->show();
}

void Controller::recvFile(QString source_name, QString file_path)
{
    qDebug() << "Controller::recvFile";
    qDebug() << file_path;
    message_info p;
    p.name = source_name;
    if(file_path.endsWith(".png") || file_path.endsWith(".jpg"))
    {
        p.Message = "2 " + file_path;
    }
    else
    {
        p.Message = "3 " + file_path;
    }
    this->main_window->recv_message(p);
}



void Controller::exitController()
{
    qDebug() << "exitController";
    client_thread.exit(0);
    delete this->client;
    delete this->login_window;
    delete this->main_window;

    exit(0);
}
