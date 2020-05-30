#ifndef POST_H
#define POST_H

#include <QObject>
#include <QString>
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QTextDocument"
#include "QDebug"
#include "QString"
#include "QDomDocument"
#include "QWidget"
#include "QBoxLayout"
#include "QLabel"
#include "QTextEdit"
#include "QPushButton"

class PostCommentBasic
{
protected:
    QMap<QString, QString> attach_file_name_id_map;
    QMap<QString, QString> attach_file_id_name_map;
protected:
    QWidget* attachtranslateWidget()
    {
        QWidget *w = new QWidget();
        //TODO
        return w;
    }
public:
    PostCommentBasic() {}
    virtual QWidget* translate() = 0;
    void insertAttach(const QString &file_name, const QString &file_id)
    {
        this->attach_file_id_name_map.insert(file_id, file_name);
        this->attach_file_name_id_map.insert(file_name, file_id);
    }
};

class Comment : public PostCommentBasic
{
public:
    const static int COMMENT_HEADER_LENGTH = 3;
private:
    QString username;
    QString reply_to_username;//if == "", comment at the master post, or reply to someone
    QString content;

public:
    Comment(const QString& username, const QString& reply_to_username, const QString& content)
    {
        this->username = username;
        this->reply_to_username = reply_to_username;
        this->content = content;
    }
    QWidget * translate() override
    {
        QVBoxLayout *layout = new QVBoxLayout();
        QString info = this->username;
        if(this->reply_to_username != "")
        {
            info += " reply " + this->reply_to_username;
        }
        info += " : " + this->content;
        QLabel *comment_label = new QLabel(info);
        layout->addWidget(comment_label);
        layout->addWidget(new QLabel(this->content));
        QWidget *widget = new QWidget();
        layout->setSizeConstraint(QLayout::SetFixedSize);
        widget->setLayout(layout);
    }
};

class Post : public PostCommentBasic
{
public:
    const static int POST_HEADER_LENGTH = 3;
private:
    QString post_id;
    QString user_name;//master post who posts
    QString content;//master post content
    QVector<QString> attach_file_id_vec;
    QVector<Comment> comments_vec;
public:
    Post(const QString& post_id, const QString& user_name, const QString& content)
    {
        this->post_id = post_id;
        this->user_name = user_name;
        this->content = content;
    }
    QString postid()const{return post_id;}
    QString masterUsername()const{return user_name;}
    QString masterContent()const{return content;}
    size_t  numberOfComments()const{return comments_vec.size();};
    //get NO. comment
    Comment getComment(const size_t& no)const{return comments_vec[no];}
    void append(const Comment comment){comments_vec.push_back(comment);}
    void append(const QString& username, const QString& reply_to_username, const QString& content)
    {
        this->comments_vec.push_back(Comment(username, reply_to_username, content));
    }

    QWidget* translate() override
    {
        //TODO
        //add user icon and info
        QLabel *user_info = new QLabel(this->masterUsername());
        //content
        QLabel *content = new QLabel(this->masterContent());

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(user_info);
        layout->addWidget(content);

        layout->addWidget(this->attachtranslateWidget());

        //comments
        for(size_t i = 0; i < this->numberOfComments(); i++)
        {
            layout->addWidget(this->getComment(i).translate());
        }

        layout->addStretch();

        QWidget *widget = new QWidget();
        layout->setSizeConstraint(QLayout::SetFixedSize);
        widget->setLayout(layout);

        return widget;
    }
};

#endif // POST_H
