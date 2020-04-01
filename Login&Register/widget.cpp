#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QFont>
#include <QHBoxLayout>
#include <QtDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //放置logo
    QPixmap *pixmap = new QPixmap(":/image/snapchat.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);

    //登录提示符
    ui->lineEdit->setPlaceholderText("用户名");
    ui->lineEdit_2->setPlaceholderText("密码");

    //注册提示符
    ui->lineEdit_3->setPlaceholderText("请输入用户名");
    ui->lineEdit_4->setPlaceholderText("请输入密码");
    ui->lineEdit_5->setPlaceholderText("请重复密码");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    //加入隐藏按钮
    QPushButton *password_button1 = this->createLineEditRightButton(ui->lineEdit_2);
    QPushButton *password_button2= this->createLineEditRightButton(ui->lineEdit_4);
    QPushButton *password_button3 = this->createLineEditRightButton(ui->lineEdit_5);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *){
    this->setAutoFillBackground(true);  // 不加上, 可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
    QBrush(QPixmap(":/image/bg2.jpg").scaled(  // 缩放背景图.
        this->size(),
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation)));  // 使用平滑的缩放方式
    this->setPalette(palette);         // 给widget加上背景图
}


void Widget::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

QPushButton* Widget::createLineEditRightButton(QLineEdit *edit)
{
    QPushButton *button = new QPushButton();
    QHBoxLayout *layout = new QHBoxLayout();
    button->setCursor(Qt::PointingHandCursor);
    button->setCheckable(true);
    connect(button, &QPushButton::toggled, [edit](bool checked) {
                if (checked)
                {
                    edit->setEchoMode(QLineEdit::Normal);
                }
                else
                {
                    edit->setEchoMode(QLineEdit::Password);
                }
            });
    layout->addStretch();
    layout->addWidget(button);
    layout->setContentsMargins(0, 0, 0, 0);
    edit->setLayout(layout);

    return button;
}

bool Widget::on_pushButton_3_clicked()
{
    //注册用户名
    QString nickname = ui->lineEdit_3->text();
    //注册第一次密码
    QString password1 = ui->lineEdit_4->text();
    //注册第二次密码
    QString password2 = ui->lineEdit_5->text();
    QRegExp rx;

    if(nickname.size()==0)
    {
        QMessageBox::warning(this,tr("warning"),tr("昵称不可为空"),QMessageBox::Yes);
        ui->lineEdit_3->setFocus();
    }
    if(nickname.size() > 20){
        QMessageBox::warning(this,tr("warning"),tr("昵称长度大于20"),QMessageBox::Yes);
        ui->lineEdit_3->clear();
        ui->lineEdit_3->setFocus();
    }
    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //密码长度为8-16位，且必须为数字、大小写字母或符号中至少2种
    rx.setPattern(QString("^(?:(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])).{6,12}$"));


}
