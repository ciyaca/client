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
#include <QtWidgets/QHBoxLayout>
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
    QTextEdit *textEdit;
    QToolButton *toolButton_4;
    QLabel *label;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *Chatface)
    {
        if (Chatface->objectName().isEmpty())
            Chatface->setObjectName(QString::fromUtf8("Chatface"));
        Chatface->resize(658, 603);
        textEdit = new QTextEdit(Chatface);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 430, 638, 141));
        toolButton_4 = new QToolButton(Chatface);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(560, 400, 81, 31));
        label = new QLabel(Chatface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 81, 31));
        pushButton = new QPushButton(Chatface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 570, 51, 31));
        listWidget = new QListWidget(Chatface);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 40, 638, 361));
        progressBar = new QProgressBar(Chatface);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(420, 400, 118, 31));
        progressBar->setValue(24);
        lineEdit = new QLineEdit(Chatface);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 400, 221, 31));
        widget = new QWidget(Chatface);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 400, 92, 26));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout_2->addWidget(toolButton_3);


        retranslateUi(Chatface);

        QMetaObject::connectSlotsByName(Chatface);
    } // setupUi

    void retranslateUi(QWidget *Chatface)
    {
        Chatface->setWindowTitle(QCoreApplication::translate("Chatface", "Form", nullptr));
        toolButton_4->setText(QCoreApplication::translate("Chatface", "\346\266\210\346\201\257\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Chatface", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Chatface", "\345\217\221\351\200\201", nullptr));
        toolButton->setText(QCoreApplication::translate("Chatface", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Chatface", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("Chatface", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chatface: public Ui_Chatface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFACE_H
