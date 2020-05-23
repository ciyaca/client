/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addfriend
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QWidget *tab_2;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *addfriend)
    {
        if (addfriend->objectName().isEmpty())
            addfriend->setObjectName(QString::fromUtf8("addfriend"));
        addfriend->resize(318, 108);
        tabWidget = new QTabWidget(addfriend);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-4, -1, 331, 111));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget{\n"
"	background-color:none;\n"
"}\n"
"/*\350\256\276\347\275\256\347\252\227\344\275\223\346\240\267\345\274\217*/\n"
"QTabWidget#tabWidget::pane{ \n"
"	/*border:none;*/\n"
"}\n"
"/*\350\256\276\347\275\256QTabWidget \347\232\204Tab\346\240\207\347\255\276\346\211\200\345\234\250\351\202\243\344\270\200\350\241\214\347\232\204\346\240\267\345\274\217\344\270\213*/\n"
"QTabWidget#tabWidget::tab-bar{\n"
"	alignment:center;	\n"
"}\n"
"/*\350\256\276\347\275\256QTabWidget \347\232\204Tab\346\240\207\347\255\276\347\232\204\346\240\267\345\274\217*/\n"
"QTabWidget#tabWidget QTabBar::tab{\n"
"	border-color: black;\n"
"	border-bottom:none;\n"
"	border-top-left-radius: 6px;\n"
"	border-top-right-radius: 6px;\n"
"	background:transparent;\n"
"	min-width:5ex;\n"
"	min-height:5ex;\n"
"}\n"
"QTabWidget#tabWidget>QTabBar::tab:!selected:hover{\n"
"	border:3px solid #C589C3;\n"
"	background:rgb(255, 255, 255, 100);\n"
"	border-color: black;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"QTabWidget#tabWidge"
                        "t>QTabBar::tab:selected{\n"
"background: none;\n"
"border:none;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(62, 14, 211, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit {\n"
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
"QLineEdit#lineEdit:focus{\n"
"    border: 2px solid #014099;\n"
"}\n"
" \n"
"QLineEdit#lineEdit_2:hover{\n"
"    border: 2px solid #014099;\n"
"}\n"
"QLineEdit#lineEdit QPushButton {\n"
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 10, 211, 41));
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
        tabWidget->addTab(tab_2, QString());

        retranslateUi(addfriend);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(addfriend);
    } // setupUi

    void retranslateUi(QWidget *addfriend)
    {
        addfriend->setWindowTitle(QCoreApplication::translate("addfriend", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("addfriend", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("addfriend", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addfriend: public Ui_addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
