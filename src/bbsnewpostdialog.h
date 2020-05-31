#ifndef BBSNEWPOSTDIALOG_H
#define BBSNEWPOSTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVector>
#include <QString>
#include <QObject>
#include <QProgressDialog>

namespace Ui {
class BBSNewPostDialog;
}

class BBSNewPostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BBSNewPostDialog(const QString&postid, const QString post, QWidget *parent = nullptr);
    ~BBSNewPostDialog();


private slots:
    void on_bbs_attach_file_btn_clicked();

    void on_bbs_send_post_btn_clicked();

    void changeProcessDialogValue();

private:
    void sleep(int ms);
    void showProcess(int range);
    void sendPost();
    void packetPost();
    QString packetWithLi(const QString &entry);

private:
    Ui::BBSNewPostDialog *ui;

    QVector<QString> __file_paths;
//    int __progress_dialog_range;
    QProgressDialog *__progress_dialog;

    QString postid;
    QString post;

};

#endif // BBSNEWPOSTDIALOG_H
