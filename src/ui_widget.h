/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *login;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *register_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(553, 284);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        Widget->setFont(font);
        Widget->setAcceptDrops(false);
        Widget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(270, 0, 281, 281));
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 221, 51));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit {\n"
"  font-family: \"Microsoft YaHei\";\n"
"   font-size: 18px;\n"
"   color: rgb(50, 50, 50);\n"
"	background-color: rgba(255, 255, 255, 0%);\n"
"	border:2px solid #b9babb;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-height: 18px;   /* \345\257\271\345\272\224\351\253\230\345\272\246\345\244\247\346\246\202\346\230\25724px\357\274\214\350\277\231\351\207\214\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\350\203\275\347\255\211\344\273\267 */\n"
"    padding-right: 18px;\n"
"}\n"
"QLineEdit#lineEdit:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit:hover{\n"
"    border: 2px solid #014099;\n"
"}"));
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 100, 221, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_2 {\n"
"   font-family: \"Microsoft YaHei\";\n"
"   font-size: 18px;\n"
"   color: rgb(50, 50, 50);\n"
"	background-color: rgba(255, 255, 255, 0%);\n"
"	border:2px solid #b9babb;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-height: 18px;   /* \345\257\271\345\272\224\351\253\230\345\272\246\345\244\247\346\246\202\346\230\25724px\357\274\214\350\277\231\351\207\214\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\350\203\275\347\255\211\344\273\267 */\n"
"    padding-right: 18px;\n"
"}\n"
"QLineEdit#lineEdit_2:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit_2:hover{\n"
"    border: 2px solid #014099;\n"
"}\n"
"QLineEdit#lineEdit_2 QPushButton {\n"
"    width:  16px;\n"
"    height: 16px;\n"
"    qproperty-flat: true;\n"
"    margin-right: 4px;\n"
"    border: none;\n"
"    border-width: 0;\n"
"    background: transparent;\n"
"    border-image: url(:/image/hide_password.png) 0 0 0 0 stretch stretch;\n"
"\n"
"}\n"
" \n"
"QLineEdit#li"
                        "neEdit_2 QPushButton::checked {\n"
" 	border-image: url(:/image/show_password.png) 0 0 0 0 stretch stretch;\n"
"}"));
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 170, 221, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(0,229,238);\n"
"}\n"
"QPushButton#pushButton:hover\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(142,229,238);\n"
"}\n"
"QPushButton#pushButton:pressed\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(85,170,255);\n"
"}"));
        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 260, 151, 21));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_2\n"
"{\n"
"  border-style:none none solid none;\n"
"}\n"
"QPushButton#pushButton_2:hover\n"
"{\n"
"  border-width:1px;\n"
"  border-style:none none solid none;\n"
"  color:  rgb(239, 41, 41);\n"
"  border-color:#1093cb;\n"
"}\n"
"QPushButton#pushButton_2:pressed\n"
"{\n"
"  border-width:1px;\n"
"  border-style:none none solid none;\n"
"  color: rgb(204, 0, 0);\n"
"  border-color:#1093cb;\n"
"}\n"
""));
        stackedWidget->addWidget(login);
        register_2 = new QWidget();
        register_2->setObjectName(QString::fromUtf8("register_2"));
        lineEdit_3 = new QLineEdit(register_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(30, 30, 221, 51));
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_3 {\n"
"  font-family: \"Microsoft YaHei\";\n"
"   font-size: 18px;\n"
"   color: rgb(50, 50, 50);\n"
"	background-color: rgba(255, 255, 255, 0%);\n"
"	border:2px solid #b9babb;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-height: 18px;   /* \345\257\271\345\272\224\351\253\230\345\272\246\345\244\247\346\246\202\346\230\25724px\357\274\214\350\277\231\351\207\214\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\350\203\275\347\255\211\344\273\267 */\n"
"    padding-right: 18px;\n"
"}\n"
"QLineEdit#lineEdit_3:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit_3:hover{\n"
"    border: 2px solid #014099;\n"
"}"));
        lineEdit_4 = new QLineEdit(register_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(30, 80, 221, 51));
        lineEdit_4->setAutoFillBackground(false);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_4 {\n"
"   font-family: \"Microsoft YaHei\";\n"
"   font-size: 18px;\n"
"   color: rgb(50, 50, 50);\n"
"	background-color: rgba(255, 255, 255, 0%);\n"
"	border:2px solid #b9babb;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-height: 18px;   /* \345\257\271\345\272\224\351\253\230\345\272\246\345\244\247\346\246\202\346\230\25724px\357\274\214\350\277\231\351\207\214\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\350\203\275\347\255\211\344\273\267 */\n"
"    padding-right: 18px;\n"
"}\n"
"QLineEdit#lineEdit_4:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit_4:hover{\n"
"    border: 2px solid #014099;\n"
"}\n"
"QLineEdit#lineEdit_4 QPushButton {\n"
"    width:  16px;\n"
"    height: 16px;\n"
"    qproperty-flat: true;\n"
"    margin-right: 4px;\n"
"    border: none;\n"
"    border-width: 0;\n"
"    background: transparent;\n"
"    border-image: url(:/image/hide_password.png) 0 0 0 0 stretch stretch;\n"
"\n"
"}\n"
" \n"
"QLineEdit#li"
                        "neEdit_4 QPushButton::checked {\n"
" 	border-image: url(:/image/show_password.png) 0 0 0 0 stretch stretch;\n"
"}"));
        lineEdit_5 = new QLineEdit(register_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(30, 130, 221, 51));
        lineEdit_5->setAutoFillBackground(false);
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_5 {\n"
"   font-family: \"Microsoft YaHei\";\n"
"   font-size: 18px;\n"
"   color: rgb(50, 50, 50);\n"
"	background-color: rgba(255, 255, 255, 0%);\n"
"	border:2px solid #b9babb;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-height: 18px;   /* \345\257\271\345\272\224\351\253\230\345\272\246\345\244\247\346\246\202\346\230\25724px\357\274\214\350\277\231\351\207\214\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\350\203\275\347\255\211\344\273\267 */\n"
"    padding-right: 18px;\n"
"}\n"
"QLineEdit#lineEdit_5:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit_5:hover{\n"
"    border: 2px solid #014099;\n"
"}\n"
"QLineEdit#lineEdit_5 QPushButton {\n"
"    width:  16px;\n"
"    height: 16px;\n"
"    qproperty-flat: true;\n"
"    margin-right: 4px;\n"
"    border: none;\n"
"    border-width: 0;\n"
"    background: transparent;\n"
"    border-image: url(:/image/hide_password.png) 0 0 0 0 stretch stretch;\n"
"\n"
"}\n"
" \n"
"QLineEdit#li"
                        "neEdit_5 QPushButton::checked {\n"
" 	border-image: url(:/image/show_password.png) 0 0 0 0 stretch stretch;\n"
"}"));
        pushButton_3 = new QPushButton(register_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 200, 101, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_3\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(0,229,238);\n"
"}\n"
"QPushButton#pushButton_3:hover\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(142,229,238);\n"
"}\n"
"QPushButton#pushButton_3:pressed\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(85,170,255);\n"
"}"));
        pushButton_4 = new QPushButton(register_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 200, 101, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_4\n"
"{\n"
"border: none;\n"
"color: white;\n"
"font-size:32px;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(0,229,238);\n"
"}\n"
"QPushButton#pushButton_4:hover\n"
"{\n"
"border: none;\n"
"color: white;\n"
"font-size:32px;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(142,229,238);\n"
"}\n"
"QPushButton#pushButton_4:pressed\n"
"{\n"
"border: none;\n"
"color: white;\n"
"font-size:32px;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(85,170,255);\n"
"}"));
        stackedWidget->addWidget(register_2);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 221, 201));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Login", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\346\263\250\345\206\214\344\270\200\344\270\252", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\342\206\220", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
