#ifndef COME_MESSAGE_H
#define COME_MESSAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class Come_message;
}

class Come_message : public QWidget
{
    Q_OBJECT

public:
    explicit Come_message(struct person_info);
    ~Come_message();

private:
    Ui::Come_message *ui;
};

#endif // COME_MESSAGE_H
