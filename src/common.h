#ifndef COMMON_H
#define COMMON_H

#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPushButton>
#include <QMainWindow>


QPixmap PixmapToRound(QPixmap&, int);

struct person_info{
    int tag; //头像标签，方便从本地头像库中进行寻找
    QString name;  //姓名
    QString Message; //消息
};

#endif // COMMON_H
