#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <chatface.h>
#include <emojiwidget.h>
#include <QThread>
#include <QEventLoop>
#include <QTimer>
#include "controller.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Controller controller;
    controller.login();
    a.exec();
    return 0;
}
