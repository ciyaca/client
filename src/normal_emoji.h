#ifndef NORMAL_EMOJI_H
#define NORMAL_EMOJI_H

#include <QWidget>

namespace Ui {
class normal_emoji;
}

class normal_emoji : public QWidget
{
    Q_OBJECT

public:
    explicit normal_emoji(QWidget *parent = nullptr);
    ~normal_emoji();

private:
    Ui::normal_emoji *ui;
};

#endif // NORMAL_EMOJI_H
