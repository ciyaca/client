/********************************************************************************
** Form generated from reading UI file 'contactitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTITEM_H
#define UI_CONTACTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contactitem
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *contactitem)
    {
        if (contactitem->objectName().isEmpty())
            contactitem->setObjectName(QString::fromUtf8("contactitem"));
        contactitem->resize(241, 50);
        label = new QLabel(contactitem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 50, 50));
        label_2 = new QLabel(contactitem);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 81, 31));

        retranslateUi(contactitem);

        QMetaObject::connectSlotsByName(contactitem);
    } // setupUi

    void retranslateUi(QWidget *contactitem)
    {
        contactitem->setWindowTitle(QCoreApplication::translate("contactitem", "Form", nullptr));
        label->setText(QCoreApplication::translate("contactitem", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("contactitem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contactitem: public Ui_contactitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTITEM_H
