#ifndef EMOJI_H
#define EMOJI_H

#include <QWidget>

namespace Ui {
class emoji;
}

class emoji : public QWidget
{
    Q_OBJECT

public:
    explicit emoji(QWidget *parent = nullptr);
    void init_emoji();
    void addEmoji(QString,QString);
    QList<QString> emoji_list;
    ~emoji();

private:
    Ui::emoji *ui;
};

#endif // EMOJI_H
