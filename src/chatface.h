#ifndef CHATFACE_H
#define CHATFACE_H

#include <QWidget>
#include "common.h"
#include <emoji.h>
#include <normal_emoji.h>

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
    ~Chatface();

private slots:
    void on_toolButton_clicked();
    void on_recv_emoji_path(QString path);

private:
    Ui::Chatface *ui;
    normal_emoji* normalEmoji;
    emoji * smallEmoji;
};

#endif // CHATFACE_H
