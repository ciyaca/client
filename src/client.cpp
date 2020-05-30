#include "client.h"
#include "QDebug"
#include "common.h"

FeverRPC::Client client_rpc("127.0.0.1");
Client* Client::the_client = nullptr;

Client::Client(QObject *parent) : QObject(parent)
{
}

Client* Client::getInstance()
{
    if(the_client == nullptr)
        Client::the_client = new Client();
    return Client::the_client;
}

void Client::on_doSomething()
{
  initClientRpc();
}

int Client::recvMessage(std::string source_name, std::string message)
{
    cout << "recvMessage" << endl;
    cout << source_name << endl;
    cout << message << endl;
    message_info p;
    p.tag = 5;
    p.name = QString::fromStdString(source_name);
    p.Message = QString::fromStdString(message);
    emit the_client->resultReady(p);
    return 0;
}

string Client::getUsername()
{
    cout << "getUsername: " << the_client->username << endl;
    return the_client->username;
}

void Client::initClientRpc()
{
    qDebug() << "client working in thread:" << QThread::currentThreadId();
    FeverRPC::Client client_rpc("127.0.0.1");
    qDebug() << "init rpc";
    client_rpc.bind("recvMessage", recvMessage);
    client_rpc.bind("getUsername", getUsername);
    client_rpc.s2c();
    qDebug() << "init rpc finished";
}

void Client::setUsername(const QString &nickname)
{
    the_client->username = nickname.toStdString();
}

