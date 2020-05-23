#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include<QLineEdit>
#include<QPushButton>

namespace Ui {
class addfriend;
}

class addfriend : public QWidget
{
    Q_OBJECT

public:
    explicit addfriend(QWidget *parent = nullptr);
    QPushButton* createLineEditRightButton(QLineEdit*);
    QString person_name;
    QString group_name;
    bool flag;
    ~addfriend();
private slots:
    void person_search();
    void group_search();
private:
    Ui::addfriend *ui;
};

#endif // ADDFRIEND_H
