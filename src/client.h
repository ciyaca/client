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


private:
  explicit Client(QObject *parent = nullptr);


signals:
  void resultReady(person_info); // 向外界发送结果

public slots:
  void on_doSomething(); // 耗时操作
  void setUsername(const QString& nickname);
};

#endif // CLIENT_H
