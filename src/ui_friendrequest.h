/********************************************************************************
** Form generated from reading UI file 'friendrequest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDREQUEST_H
#define UI_FRIENDREQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendrequest
{
public:
    QLabel *Avatar;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *friendrequest)
    {
        if (friendrequest->objectName().isEmpty())
            friendrequest->setObjectName(QString::fromUtf8("friendrequest"));
        friendrequest->resize(581, 74);
        Avatar = new QLabel(friendrequest);
        Avatar->setObjectName(QString::fromUtf8("Avatar"));
        Avatar->setGeometry(QRect(10, 10, 50, 50));
        label = new QLabel(friendrequest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 81, 31));
        label->setStyleSheet(QString::fromUtf8("font: 57 17pt \"Ubuntu\";"));
        pushButton = new QPushButton(friendrequest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 10, 71, 31));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(friendrequest);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 40, 71, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        textEdit = new QTextEdit(friendrequest);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(170, 10, 301, 61));

        retranslateUi(friendrequest);

        QMetaObject::connectSlotsByName(friendrequest);
    } // setupUi

    void retranslateUi(QWidget *friendrequest)
    {
        friendrequest->setWindowTitle(QCoreApplication::translate("friendrequest", "Form", nullptr));
        Avatar->setText(QCoreApplication::translate("friendrequest", "image", nullptr));
        label->setText(QCoreApplication::translate("friendrequest", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("friendrequest", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("friendrequest", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendrequest: public Ui_friendrequest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDREQUEST_H
