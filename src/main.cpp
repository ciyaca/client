#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <chatface.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Widget* login = new Widget();
//    login->show();
    MainWindow m;
    m.show();

    a.exec();
    return 0;
}
