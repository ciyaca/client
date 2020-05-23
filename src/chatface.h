#ifndef CHATFACE_H
#define CHATFACE_H
//#include "client_rpc.hpp"
#include <QWidget>
#include "common.h"
#include <emoji.h>
#include <normal_emoji.h>
#include <QList>
#include "chatmessage.h"
#include <QListWidgetItem>

namespace Ui {
class Chatface;
}

class Chatface : public QWidget
{
    Q_OBJECT

public:
    explicit Chatface(struct person_info);
    void chatface_init();
    bool emoji_flag;
    QWidget parentt;
    void showSmallEmotion(QPoint point);
    void showNormalEmotion(QPoint point);
    void onAnimationFinished();

    void dealMessage(QString text, QString time, QString path,QNChatMessage::User_Type type);
    void dealMessageTime(QString curMsgTime);
    void recv_message(QString);
    int Me_tag;
    int She_tag;
    ~Chatface();

private slots:
    void on_toolButton_clicked();
    void on_recv_emoji_path(QString path);

    void on_pushButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::Chatface *ui;
    normal_emoji* normalEmoji;
    emoji * smallEmoji;
};

#endif // CHATFACE_H
