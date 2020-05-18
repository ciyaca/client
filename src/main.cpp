#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <chatface.h>
#include <emojiwidget.h>
#include "client_rpc.hpp"


int main(int argc, char *argv[])
{
    initClientRpc();
    QApplication a(argc, argv);

//    Widget* login = new Widget();
//    login->show();
    MainWindow m;
    m.show();

    a.exec();
    return 0;
}
