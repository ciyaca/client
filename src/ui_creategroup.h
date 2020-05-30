/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creategroup
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *creategroup)
    {
        if (creategroup->objectName().isEmpty())
            creategroup->setObjectName(QString::fromUtf8("creategroup"));
        creategroup->resize(318, 108);
        lineEdit_2 = new QLineEdit(creategroup);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 40, 211, 41));
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
"    border-image: url(:/image/search.png) 0 0 0 0 stretch stretch;\n"
"\n"
"}\n"
" "));
        pushButton = new QPushButton(creategroup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 40, 61, 41));

        retranslateUi(creategroup);

        QMetaObject::connectSlotsByName(creategroup);
    } // setupUi

    void retranslateUi(QWidget *creategroup)
    {
        creategroup->setWindowTitle(QCoreApplication::translate("creategroup", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("creategroup", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creategroup: public Ui_creategroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
