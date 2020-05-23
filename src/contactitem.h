#ifndef CONTACTITEM_H
#define CONTACTITEM_H

#include <QWidget>

namespace Ui {
class contactitem;
}

class contactitem : public QWidget
{
    Q_OBJECT

public:
    explicit contactitem(QWidget *parent = nullptr);
    void setContactName(QString);
    void setContactIcon(int);
    QString getContactName();
    ~contactitem();

private:
    Ui::contactitem *ui;
};

#endif // CONTACTITEM_H
