#ifndef BBSPOSTLISTWIDGET_H
#define BBSPOSTLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class BBSPostListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *__layout;
public:
    explicit BBSPostListWidget(QWidget *parent = nullptr);
    void addWidget(QWidget* w);
signals:

};

#endif // BBSPOSTLISTWIDGET_H
