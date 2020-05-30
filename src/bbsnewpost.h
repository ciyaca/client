#ifndef BBSNEWPOST_H
#define BBSNEWPOST_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QObject>

namespace Ui {
class BBSNewPost;
}

class BBSNewPost : public QWidget
{
    Q_OBJECT

public:
    explicit BBSNewPost(QWidget *parent = nullptr);
    ~BBSNewPost();

private slots:
    void on_bbs_attach_file_btn_clicked();

    void on_bbs_send_post_btn_clicked();

private:
    Ui::BBSNewPost *ui;
    QVector<QString> __file_paths;

};

#endif // BBSNEWPOST_H
