#include "emojiwidget.h"
#include "ui_emojiwidget.h"
#include <QDebug>
#include <QLabel>
#include <QMovie>

emojiwidget::emojiwidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::emojiwidget)
{
    ui->setupUi(this);
    this->init_emotion();
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(getItem_now(int, int)));
}

emojiwidget::~emojiwidget()
{
    delete ui;
}

void emojiwidget::addEmotionItem(QString fileName)
{
    // 获取当前添加到第几行第几列

   int row = this->emoji_list.size()/9;
   int column = this->emoji_list.size()%9;

//   qDebug() << row << "" << column;
//   qDebug() << fileName;
   QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
   ui->tableWidget->setItem(row, column, tableWidgetItem);

   //使用QMoive显示表情
   QLabel* emotionIcon = new QLabel;
   emotionIcon->setMargin(4);
   QMovie* movie = new QMovie;
   movie->setScaledSize(QSize(24,24));
   movie->setFileName(fileName);
   movie->start();
   emotionIcon->setMovie(movie);
   ui->tableWidget->setCellWidget(row,column,emotionIcon);
   emoji_list.push_back(fileName);
}
void emojiwidget::init_emotion()
{

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString path = ":image/emoji/%1.gif";
    for (int i = 1; i <= 132; i++) {
        addEmotionItem(path.arg(i));
    }
}
void emojiwidget::getItem_now(int row, int column)
{
    long k;
    k = row * 9 + column + 1;

    QString path = ":/image/emoji/";
    path.append(QString::number(k));
    path.append(".gif");
    emit emit_emoji_path(path);
//    qDebug() << path;
    this->close();
}
