/*
 * login and register
 * */

#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QFont>
#include <QHBoxLayout>
#include <QtDebug>
#include <QMessageBox>
#include <string>
#include <iostream>
using namespace std;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->state_login = EXIT;
    this->state_register = EXIT;

    //放置logo
    QPixmap *pixmap = new QPixmap(":/image/logo.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);

    //放置头像


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

/*
 * background picture
 */
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


/*
 * 注册界面的返回按钮
 * */
void Widget::on_pushButton_4_clicked()
{
    this->setWindowTitle("Login");
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * 登录界面的注册按钮
 * */
void Widget::on_pushButton_2_clicked()
{
    this->setWindowTitle("Register");
    ui->stackedWidget->setCurrentIndex(1);
}

/*
 * 在输出行右边添加按钮，也就是显示密码/隐藏密码按钮
 * */
QPushButton* Widget::createLineEditRightButton(QLineEdit *edit)
{
    QPushButton *button = new QPushButton();
    QHBoxLayout *layout = new QHBoxLayout();
    edit->setEchoMode(QLineEdit::Password);
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

/*
 * register
 * */
void Widget::on_pushButton_3_clicked()
{
    //注册用户名
    QString nickname = ui->lineEdit_3->text();
    //注册第一次密码
    QString password1 = ui->lineEdit_4->text();
    //注册第二次密码
    QString password2 = ui->lineEdit_5->text();

    QRegExp rx;
    // 首先对用户名进行判断
    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);

    if(nickname.size()==0)
    {
        QMessageBox::warning(this,tr("warning"),tr("昵称不可为空"),QMessageBox::Yes);
        ui->lineEdit_3->setFocus();
    }
    if(nickname.size() > 20){
        QMessageBox::warning(this,tr("warning"),tr("昵称长度不可大于20"),QMessageBox::Yes);
        ui->lineEdit_3->clear();
        ui->lineEdit_3->setFocus();
        return;
    }
    rx.setPattern(QString("^[A-Za-z]+$"));
    if(!rx.exactMatch(nickname))
    {
        QMessageBox::warning(this,tr("warning"),tr("用户名只能是字母"),QMessageBox::Yes);
        ui->lineEdit_3->clear();
        ui->lineEdit_3->setFocus();
        return;
    }

    //然后对密码进行判断
    //密码只包含字母和数字
    rx.setPattern(QString("^[A-Za-z0-9]+$"));
    if(password1.isEmpty()) //检测到密码输入框为空
    {
        QMessageBox::warning(this,tr("warning"),tr("密码不可为空"),QMessageBox::Yes);
        ui->lineEdit_4->setFocus();
        return;
    }
    else if(!rx.exactMatch(password1))
    {
        QMessageBox::warning(this,tr("warning"),tr("密码只能是数字或字母！"),QMessageBox::Yes);
        ui->lineEdit_4->clear();
        ui->lineEdit_4->setFocus();
        ui->lineEdit_5->clear();
        return;
    }
    else if(password1.size() < 6 || password1.size() > 12)
    {
        QMessageBox::warning(this,tr("warning"),tr("密码长度范围必须是6~12！"),QMessageBox::Yes);
        ui->lineEdit_4->setFocus();
        return;
    }
    if(password1.compare((password2)))
    {
        QMessageBox::warning(this,tr("warning"),tr("两次密码不一致"),QMessageBox::Yes);
        ui->lineEdit_4->clear();
        ui->lineEdit_4->setFocus();
        ui->lineEdit_5->clear();
        return;
    }
    //TO DO diao yong zhuce daima

    QMessageBox::warning(this,tr("Wlcome"),tr("恭喜你！成功注册"),QMessageBox::Yes);
}

/*
 * login
 * */
void Widget::on_pushButton_clicked()
{
    //这一部分直接将字符串发给后端
    //用户名
    QString nickname = ui->lineEdit->text();
    //密码
    QString password = ui->lineEdit_2->text();

    QRegExp rx;
    // 首先对用户名进行判断
    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);

    qDebug() << nickname;
    qDebug() << password;
//    qDebug() << this->state_login;
    //登录部分进行简单的验证即可
    //用户名范围
    if(nickname.size()==0)
    {
        QMessageBox::warning(this,tr("warning"),tr("昵称不可为空"),QMessageBox::Yes);
        ui->lineEdit->setFocus();
    }
    if(nickname.size() > 20){
        QMessageBox::warning(this,tr("warning"),tr("昵称长度不可大于20"),QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        return;
    }
    rx.setPattern(QString("^[A-Za-z]+$"));
    if(!rx.exactMatch(nickname))
    {
        QMessageBox::warning(this,tr("warning"),tr("用户名只能是字母"),QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        return;
    }
    //密码
    rx.setPattern(QString("^[A-Za-z0-9]+$"));
    if(password.isEmpty()) //检测到密码输入框为空
    {
        QMessageBox::warning(this,tr("warning"),tr("密码不可为空"),QMessageBox::Yes);
        ui->lineEdit_2->setFocus();
        return;
    }
    else if(!rx.exactMatch(password))
    {
        QMessageBox::warning(this,tr("warning"),tr("密码只能是数字或字母！"),QMessageBox::Yes);
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setFocus();
        return;
    }
    else if(password.size() < 6 || password.size() > 12)
    {
        QMessageBox::warning(this,tr("warning"),tr("密码长度范围必须是6~12！"),QMessageBox::Yes);
        ui->lineEdit_2->setFocus();
        return;
    }
    //转换为string类型，兼容冯开宇代码
    string nickname1 = nickname.toStdString();
    string password1 = password.toStdString();
    this->state_login = client_rpc.call<int>("login", nickname1, password1);
}
