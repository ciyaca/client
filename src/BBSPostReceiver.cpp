#include "BBSPostReceiver.h"


BBSPostReceiver::BBSPostReceiver(QObject *parent) : QObject(parent)
{
    this->__bbs_post_list_widget = nullptr;
}


void BBSPostReceiver::getPostsFromServer()
{
    if(this->__bbs_post_list_widget != nullptr)
        delete this->__bbs_post_list_widget;

    this->__bbs_post_list_widget = new BBSPostListWidget();
    this->doc.clear();

    QFile file("/home/wang/Documents/ciyaca/BBS/index.html");


    if(!file.open(QFile::ReadOnly | QFile::Text))

        QMessageBox::information(NULL, QStringLiteral("提示"),

                                     QStringLiteral("打不开用户协议文件"));


    doc.setContent(&file);
}


void BBSPostReceiver::parsePosts()
{
//         qDebug() << doc.toString();
     QDomNodeList lis = doc.elementsByTagName("li");
    for(int i = 0; i < lis.size(); i++)
    {
        QDomNodeList divs = lis.item(i).childNodes();
//            qDebug() << lis.item(i).firstChildElement().text();
        Post post(getContentFromNode(divs.item(0)),//postid
                  getContentFromNode(divs.item(1)),//username
                  getContentFromNode(divs.item(2)));//content

        int start_idx = this->parseAttachFile(&post, divs, Post::POST_HEADER_LENGTH);

        for(int i = start_idx; i < divs.size(); )
        {
            QString username = getContentFromNode(divs.item(i++));
            QString reply = getContentFromNode(divs.item(i++));
            QString content = getContentFromNode(divs.item(i++));
            Comment com(post.postid(), username, reply, content);
            i = this->parseAttachFile(&com, divs, i);
            post.append(com);
        }
        post_vec.push_back(post);
        post_index_map.insert(post.postid(), post_vec.size() - 1);
    }
}

QString BBSPostReceiver::getContentFromNode(const QDomNode& node)
{
    return node.toElement().text();
}

int BBSPostReceiver::parseAttachFile(PostCommentBasic* p, QDomNodeList& divs, int start_divs_index)
{
    //Parse attach
    //insert into file_name and file_id
    int num_attach_file = getContentFromNode(divs.item(start_divs_index)).toInt();
    for(int i = start_divs_index + 1; i < start_divs_index + 1 + num_attach_file * 2; )
    {
        QString file_id = getContentFromNode(divs.item(i++));
        QString file_name = getContentFromNode(divs.item(i++));
        p->insertAttach(file_name, file_id);
    }
    return start_divs_index + 1 + num_attach_file * 2;
}

QWidget* BBSPostReceiver::translate()
{
    this->parsePosts();
    for(int i = 0; i < this->post_vec.size(); i++)
    {
        QWidget* w = post_vec[i].translate(nullptr);
        this->bbs_post_widget_vec.push_back(w);
        this->__bbs_post_list_widget->addWidget(w);

    }
    return this->__bbs_post_list_widget;
}


