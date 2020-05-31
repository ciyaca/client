#ifndef BBSPOSTRECEIVER_H
#define BBSPOSTRECEIVER_H

#include <QObject>
#include <QString>
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QTextDocument"
#include "QDebug"
#include "QString"
#include "QDomDocument"
#include <QWidget>
#include "bbspostlistwidget.h"
#include "post.h"
#include "bbsnewpostdialog.h"



class BBSPostReceiver : public QObject
{
    Q_OBJECT

private:
    QDomDocument doc;
    QVector<Post> post_vec;
    QMap<QString, int>post_index_map;
public:
    BBSPostListWidget* __bbs_post_list_widget;
    QVector<QWidget*> bbs_post_widget_vec;


private:
    void parsePosts();
    QString getContentFromNode(const QDomNode& node);
    int parseAttachFile(PostCommentBasic* p, QDomNodeList& divs, int start_divs_index);

public:
    explicit BBSPostReceiver(QObject *parent = nullptr);
    void getPostsFromServer();
    QWidget* translate();
signals:

private slots:



};

#endif // BBSPOSTRECEIVER_H
