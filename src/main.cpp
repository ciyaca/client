#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    Controller controller;
    controller.login();
    a.exec();
    return 0;
}
