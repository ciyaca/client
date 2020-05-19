#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <QWidget>

class QPaintEvent;
class QPainter;
class QLabel;
class QMovie;

class QNChatMessage : public QWidget
{
    Q_OBJECT
public:
    explicit QNChatMessage(QWidget *parent = nullptr);

    enum User_Type{
        User_System,//系统
        User_Me,    //自己
        User_She,   //用户
        User_Time,  //时间
        User_Meemjio, //emjio
        User_Sheemjio,
        User_Mepic,
        User_Shepic
    };
    void setTextSuccess();
    void setText(QString text, QString path,QString time, QSize allSize, User_Type userType);
    QSize getRealString(QString src);
    QSize fontRect(QString str);
    QSize picRect(QString path);

    inline QString text() {return m_msg;}
    inline QString time() {return m_time;}
    inline User_Type userType() {return m_userType;}
    int Me_tag;
    int She_tag;
protected:
    void paintEvent(QPaintEvent *event);
private:
    QString m_msg;
    QString m_time;
    QString m_curTime;

    QSize m_allSize;
    User_Type m_userType = User_System;

    int m_kuangWidth;
    int m_textWidth;
    int m_spaceWid;
    int m_lineHeight;

    QRect m_iconLeftRect;
    QRect m_iconRightRect;
    QRect m_sanjiaoLeftRect;
    QRect m_sanjiaoRightRect;
    QRect m_kuangLeftRect;
    QRect m_kuangRightRect;
    QRect m_textLeftRect;
    QRect m_textRightRect;
    QPixmap m_leftPixmap;
    QPixmap m_rightPixmap;
    QPixmap pic;
    QLabel* m_loading = Q_NULLPTR;
    QMovie* m_loadingMovie = Q_NULLPTR;
    bool m_isSending = false;
};


#endif // CHATMESSAGE_H
