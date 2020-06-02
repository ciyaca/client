#ifndef CLIENT_H
#define CLIENT_H
#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include "info_code.h"
#include "feverrpc/feverrpc-client.hpp"
#include "feverrpc/feverrpc-factory.hpp"
#include "feverrpc/feverrpc.hpp"
#include "feverrpc/utils.hpp"
#include <string>
#include "common.h"

using namespace std;
extern FeverRPC::Client client_rpc;

class Client : public QObject
{
  Q_OBJECT

private:
    static Client* the_client;
    string username;

public:
    static Client* getInstance();
    static void initClientRpc();
    static int recvMessage(string, string);
    static string getUsername();
    static int recvFile(string source_name, string target_name, string file_name,vector<char> file_data);


private:
  explicit Client(QObject *parent = nullptr);


signals:
  void recvMessageReady(QString source_name, QString message); // 向外界发送结果
  void recvFileReady(QString source_name, QString file_path);

public slots:
  void on_doSomething(); // 耗时操作
  void setUsername(const QString& nickname);
};

#endif // CLIENT_H
