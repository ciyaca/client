#include "client.h"
#include "QDebug"

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
  qDebug() << "I'm working in thread:" << QThread::currentThreadId();
  initClientRpc();
}

int Client::recvMessage(std::string source_name, std::string message)
{
    cout << source_name << endl;
    cout << message << endl;
    emit the_client->resultReady(message.c_str());
    return 0;
}

string Client::getUsername()
{
    return the_client->username;
}

void Client::initClientRpc()
{
    client_rpc.bind("recvMessage", recvMessage);
    client_rpc.bind("getUsername", getUsername);
    client_rpc.s2c();
}

void Client::setUsername(const QString &nickname)
{
    the_client->username = nickname.toStdString();
}

