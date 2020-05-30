#ifndef FRIENDREQUEST_H
#define FRIENDREQUEST_H

#include <QWidget>

namespace Ui {
class friendrequest;
}

class friendrequest : public QWidget
{
    Q_OBJECT

public:
    explicit friendrequest(QWidget *parent = nullptr);
    void setname(QString);
    void setmessage(QString);
    void setavatar(int);
    QString name;
    int avatar;
    int isagree;
    ~friendrequest();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
signals:
    void deleterequestline();
private:
    Ui::friendrequest *ui;
};

#endif // FRIENDREQUEST_H
