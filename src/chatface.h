#ifndef CHATFACE_H
#define CHATFACE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class Chatface;
}

class Chatface : public QWidget
{
    Q_OBJECT

public:
    explicit Chatface(struct person_info);
    ~Chatface();

private:
    Ui::Chatface *ui;
};

#endif // CHATFACE_H
