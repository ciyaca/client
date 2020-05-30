#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QWidget>

namespace Ui {
class creategroup;
}

class creategroup : public QWidget
{
    Q_OBJECT

public:
    explicit creategroup(QWidget *parent = nullptr);
    ~creategroup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::creategroup *ui;
};

#endif // CREATEGROUP_H
