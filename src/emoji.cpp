#include "emoji.h"
#include "ui_emoji.h"

#include <QLabel>
#include <QMovie>
#include <QDebug>

emoji::emoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emoji)
{
    ui->setupUi(this);
    this->init_emoji();

}

emoji::~emoji()
{
    delete ui;
}

void emoji::addEmoji(QString filename,QString tooltip)
{
     // 获取当前添加到第几行第几列
    int row = this->emoji_list.size()/ui->tableWidget->rowCount();
    int column = this->emoji_list.size()%ui->tableWidget->rowCount();

    qDebug() << row << "" << column;
    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
    tableWidgetItem->setToolTip(tooltip);
    ui->tableWidget->setItem(row, column, tableWidgetItem);

    //使用QMoive显示表情
    QLabel* emotionIcon = new QLabel;
    emotionIcon->setMargin(4);
    QMovie* movie = new QMovie;
    movie->setScaledSize(QSize(24,24));
    movie->setFileName(filename);
    movie->start();
    emotionIcon->setMovie(movie);
    ui->tableWidget->setCellWidget(row,column,emotionIcon);
    emoji_list.push_back(filename);
}
void emoji::init_emoji()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
//    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
//    QString path = ":image/emoji/%1.gif";
//    for (int i = 0; i < 16; i++)
//    {
//        addEmoji(path.arg(i + 1));
//    }
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setMouseTracking(true);
    ui->tableWidget->installEventFilter(this);
    this->installEventFilter(this);

    QString path = ":image/emoji/%1.gif";
    for (int i = 0; i < 16; i++)
    {
       addEmoji(path.arg(i + 1),"");
    }
}
