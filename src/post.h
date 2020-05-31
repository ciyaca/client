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
#include "bbsnewpostdialog.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QGridLayout"

class BBSPostCommentButton : public QPushButton
{
    Q_OBJECT
private:
    QString post_id;
    QString post;

public:
    explicit BBSPostCommentButton(const QString& post_id, const QString& post, QWidget* parent) : QPushButton(parent)
    {
        this->post_id = post_id;
        this->post = post;
        this->setText("comment");
        connect(this, SIGNAL(clicked(bool)), this, SLOT(newComment(bool)));
    }
//    virtual ~BBSPostCommentButton();

public slots:
    void newComment(bool clicked)
    {
        qDebug() << "new Comment";
        BBSNewPostDialog* dialog = new BBSNewPostDialog(this->post_id, this->post, nullptr);
        dialog->setModal(true);
        dialog->exec();
//        dialog->show();
//        delete dialog;
    }
public:
    void setPost(const QString& post)
    {
        this->post = post;
        qDebug() << this->post;
    }
};

class PostCommentBasic
{
public:
    QVector<QPushButton*> attach_download_btn_vec;
protected:
    QMap<QString, QString> attach_file_name_id_map;
    QMap<QString, QString> attach_file_id_name_map;
    QVector<QString> attach_file_name_vec;
    QWidget* _attachs_widget = nullptr;
protected:
    QString packetWithDiv(const QString &entry)
    {
        return "<div>" + entry + "</div>";
    }
    QString packetAttachInfo()
    {
        QString info = packetWithDiv(QString::number(this->attach_file_name_vec.size()));
        for(int i = 0; i < this->attach_file_name_vec.size(); i++)
        {
            info += this->packetWithDiv("");//file_id
            info += this->packetWithDiv(this->attach_file_name_vec[i]);
        }
        return info;
    }
    QWidget* attachtranslateWidget(const QString& post_id, QWidget* parent)
    {
        if(this->attach_file_name_vec.size() == 0)
            return nullptr;
        this->_attachs_widget = new QWidget(parent);
        QVBoxLayout* v_layout = new QVBoxLayout(this->_attachs_widget);

        //TODO

        for(int i = 0; i < attach_file_name_vec.size(); i++)
        {
            QWidget* w_tmp = new QWidget(this->_attachs_widget);
            QHBoxLayout *h_layout = new QHBoxLayout(w_tmp);

            for(int j = 0; j < 3 && i < attach_file_name_vec.size(); j++)
             {
                QPushButton *btn = new QPushButton(w_tmp);
                 btn->setText(attach_file_name_vec[i++]);
                 btn->setFlat(true);
                 btn->setAutoFillBackground(true);
                 btn->setStyleSheet("color:blue");
                 h_layout->addWidget(btn);
                 this->attach_download_btn_vec.push_back(btn);
            }
            h_layout->addStretch();
            w_tmp->setLayout(h_layout);

            v_layout->addWidget(w_tmp);
        }

        v_layout->addStretch();
        this->_attachs_widget->setLayout(v_layout);

        return this->_attachs_widget;
    }
public:
    PostCommentBasic() {}
    ~PostCommentBasic()
    {
        if(this->_attachs_widget != nullptr)
        {
            delete this->_attachs_widget;
            this->_attachs_widget = nullptr;
        }
        this->attach_file_name_vec.clear();
        this->attach_download_btn_vec.clear();
        this->attach_file_id_name_map.clear();
        this->attach_file_name_id_map.clear();
    }
    virtual QWidget* translate(QWidget *parent = nullptr) = 0;
    void insertAttach(const QString &file_name, const QString &file_id)
    {
        //due to not use file_id, so only insert into file_name
//        this->attach_file_id_name_map.insert(file_id, file_name);
//        this->attach_file_name_id_map.insert(file_name, file_id);
        this->attach_file_name_vec.push_back(file_name);

    }
};

class Comment : public PostCommentBasic
{
public:
    const static int COMMENT_HEADER_LENGTH = 3;
private:
    QString post_id;
    QString username;
    QString reply_to_username = "";//if == "", comment at the master post, or reply to someone
    QString content;
    QWidget *__comment_widget = nullptr;

public:
    Comment(const QString& post_id, const QString& username, const QString& reply_to_username, const QString& content)
    {
        this->post_id = post_id;
        this->username = username;
        this->reply_to_username = reply_to_username;
        this->content = content;
        this->__comment_widget = nullptr;
    }
    ~Comment()
    {
        if(this->__comment_widget != nullptr)
        {
            delete  this->__comment_widget;
            this->__comment_widget = nullptr;
        }
    }

    QString packetCommentInfo()
    {
        QString info = this->packetWithDiv(this->username);
        info += this->packetWithDiv(this->reply_to_username);
        info += this->packetAttachInfo();
        return info;
    }

    QWidget * translate(QWidget* parent) override
    {
        this->__comment_widget = new QWidget(parent);
        QVBoxLayout *layout = new QVBoxLayout(__comment_widget);
        QString info = this->username;
        if(this->reply_to_username != "")
        {
            info += " reply " + this->reply_to_username;
        }

        info += " : " + this->content;

        QLabel *comment_label = new QLabel(info, __comment_widget);
        layout->addWidget(comment_label);



//        layout->addWidget(new QLabel(this->content));

//        layout->addWidget(this->attachtranslateWidget(this->post_id));

//        layout->setSizeConstraint(QLayout::SetFixedSize);



        this->__comment_widget->setLayout(layout);
        qDebug() << "comment widget address = " << this->__comment_widget;
        return this->__comment_widget;
    }
};

class Post : public PostCommentBasic
{
public:
    const static int POST_HEADER_LENGTH = 3;
public:
    BBSPostCommentButton* comment_btn = nullptr;
private:
    QString post_id;
    QString user_name;//master post who posts
    QString content;//master post content
    QVector<QString> attach_file_id_vec;
    QVector<Comment> comments_vec;
public:
    QWidget * __post_widget = nullptr;

private:
    QString translateIntoPostString()
    {
        QString post_str = packetWithDiv(this->user_name);
        post_str += packetWithDiv(this->content);
        post_str += this->packetAttachInfo();
        for(int i = 0; i < this->comments_vec.size(); i++)
        {
            post_str += this->comments_vec[i].packetCommentInfo();
        }
        return post_str;
    }

public:
    Post(const QString& post_id, const QString& user_name, const QString& content)
    {
        this->post_id = post_id;
        this->user_name = user_name;
        this->content = content;
        this->__post_widget = nullptr;
    }
    ~Post()
    {
        if(comment_btn != nullptr)
            delete comment_btn;
        if(this->__post_widget != nullptr)
            delete this->__post_widget;
        comment_btn = nullptr;
        this->__post_widget = nullptr;
        comments_vec.clear();
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
        this->comments_vec.push_back(Comment(this->post_id, username, reply_to_username, content));
    }



    QWidget* translate(QWidget* parent) override
    {
        this->__post_widget = new QWidget(parent);
        this->comment_btn = new BBSPostCommentButton(this->post_id, "", this->__post_widget);
//        this->comment_btn = new QPushButton;
        this->comment_btn->setText("Comment");

        QVBoxLayout *layout = new QVBoxLayout(this->__post_widget);

        QWidget *w_tmp = new QWidget(this->__post_widget);
        QHBoxLayout *h_layout = new QHBoxLayout(w_tmp);
        //add user icon and info
        QLabel *user_info = new QLabel(this->masterUsername(), w_tmp);
        h_layout->addWidget(user_info);
        h_layout->addWidget(comment_btn);
        h_layout->addStretch();
        w_tmp->setLayout(h_layout);
        layout->addWidget(w_tmp);


        //content
        QLabel *content = new QLabel(this->masterContent(), this->__post_widget);
        layout->addWidget(content);

        QWidget *widget_tmp = this->attachtranslateWidget(this->postid(), this->__post_widget);
        if(w_tmp != nullptr)
        {
            layout->addWidget(widget_tmp);
//            layout->addWidget(widget_tmp);
//            QWidget* tmp = new QWidget();
//            layout->addWidget(tmp);

        }


        //comments
        for(size_t i = 0; i < this->numberOfComments(); i++)
        {
            QWidget *w_tmp = this->comments_vec[i].translate(nullptr);
            if(w_tmp != nullptr)
                layout->addWidget(w_tmp);
//            qDebug() << "hello world";
        }



        layout->addStretch();

//        layout->setSizeConstraint(QLayout::SetFixedSize);
        this->__post_widget->setLayout(layout);


        this->comment_btn->setPost(this->translateIntoPostString());
        return this->__post_widget;
    }

};

#endif // POST_H
