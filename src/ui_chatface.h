/********************************************************************************
** Form generated from reading UI file 'chatface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATFACE_H
#define UI_CHATFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chatface
{
public:
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QTextEdit *textEdit;
    QToolButton *toolButton_4;
    QLabel *label;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Chatface)
    {
        if (Chatface->objectName().isEmpty())
            Chatface->setObjectName(QString::fromUtf8("Chatface"));
        Chatface->resize(661, 641);
        toolButton = new QToolButton(Chatface);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 470, 31, 31));
        toolButton_2 = new QToolButton(Chatface);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(40, 470, 31, 31));
        toolButton_3 = new QToolButton(Chatface);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(70, 470, 31, 31));
        textEdit = new QTextEdit(Chatface);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 500, 651, 141));
        toolButton_4 = new QToolButton(Chatface);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(570, 470, 81, 31));
        label = new QLabel(Chatface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 81, 31));
        pushButton = new QPushButton(Chatface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 600, 51, 31));
        listWidget = new QListWidget(Chatface);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(5, 41, 641, 431));
        progressBar = new QProgressBar(Chatface);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(420, 470, 118, 31));
        progressBar->setValue(24);
        lineEdit = new QLineEdit(Chatface);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(162, 470, 221, 31));

        retranslateUi(Chatface);

        QMetaObject::connectSlotsByName(Chatface);
    } // setupUi

    void retranslateUi(QWidget *Chatface)
    {
        Chatface->setWindowTitle(QCoreApplication::translate("Chatface", "Form", nullptr));
        toolButton->setText(QCoreApplication::translate("Chatface", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Chatface", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("Chatface", "...", nullptr));
        toolButton_4->setText(QCoreApplication::translate("Chatface", "\346\266\210\346\201\257\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Chatface", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Chatface", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chatface: public Ui_Chatface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFACE_H
