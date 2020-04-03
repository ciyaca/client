/********************************************************************************
** Form generated from reading UI file 'come_message.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COME_MESSAGE_H
#define UI_COME_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Come_message
{
public:
    QLabel *Avatar;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Come_message)
    {
        if (Come_message->objectName().isEmpty())
            Come_message->setObjectName(QString::fromUtf8("Come_message"));
        Come_message->resize(201, 73);
        Come_message->setStyleSheet(QString::fromUtf8(""));
        Avatar = new QLabel(Come_message);
        Avatar->setObjectName(QString::fromUtf8("Avatar"));
        Avatar->setGeometry(QRect(10, 10, 50, 50));
        label = new QLabel(Come_message);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 131, 31));
        label->setStyleSheet(QString::fromUtf8("label{\n"
"   color: black;\n"
"	font: 57 18pt \"Ubuntu\";\n"
"}"));
        label_2 = new QLabel(Come_message);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 50, 131, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));

        retranslateUi(Come_message);

        QMetaObject::connectSlotsByName(Come_message);
    } // setupUi

    void retranslateUi(QWidget *Come_message)
    {
        Come_message->setWindowTitle(QCoreApplication::translate("Come_message", "Form", nullptr));
        Avatar->setText(QCoreApplication::translate("Come_message", "image", nullptr));
        label->setText(QCoreApplication::translate("Come_message", "label1", nullptr));
        label_2->setText(QCoreApplication::translate("Come_message", "label2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Come_message: public Ui_Come_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COME_MESSAGE_H
