#include "client.h"
#include "QDebug"
#include "common.h"
#include "controller.h"
#include "common.h"
#include "QMessageBox"

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
    emit the_client->recvMessageReady(QString::fromStdString(source_name), QString::fromStdString(message));
    return 0;
}

int Client::recvFile(string source_name, string target_name, string file_name, vector<char> file_data)
{
    qDebug() << "Client::recvFile ";
//    std::vector<char> bytes = client_rpc.call<std::vector<char>>("downloadFile", this->file_name.toStdString());
    std::string path = SAVE_FILE_ROOT_PATH.toStdString() + file_name;

    std::ofstream outputFile( path, ios::binary );

    outputFile.write( &file_data[0], file_data.size() );
    outputFile.close();

    emit the_client->recvFileReady(QString::fromStdString(source_name), QString::fromStdString(path));
//    QMessageBox::information(nullptr, "info", "file saved into " + QString::fromStdString(path));
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
    client_rpc.bind("recvFile", recvFile);
    client_rpc.s2c();
    qDebug() << "init rpc finished";
}

void Client::setUsername(const QString &nickname)
{
    the_client->username = nickname.toStdString();
}

