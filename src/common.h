#ifndef COMMON_H
#define COMMON_H

#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPushButton>
#include <QMainWindow>


QPixmap PixmapToRound(QPixmap&, int);

struct message_info{
    int tag; //头像标签，方便从本地头像库中进行寻找
    QString name=nullptr;  //姓名
    QString Message=nullptr; //消息
    QString groupname=nullptr;
    QString time = nullptr;
};

#endif // COMMON_H
