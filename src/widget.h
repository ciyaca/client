#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QPushButton* createLineEditRightButton(QLineEdit *);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    bool on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
