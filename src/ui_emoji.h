/********************************************************************************
** Form generated from reading UI file 'emoji.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOJI_H
#define UI_EMOJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_emoji
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *emoji)
    {
        if (emoji->objectName().isEmpty())
            emoji->setObjectName(QString::fromUtf8("emoji"));
        emoji->resize(136, 136);
        tableWidget = new QTableWidget(emoji);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 161, 141));
        tableWidget->setRowCount(4);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->horizontalHeader()->setDefaultSectionSize(34);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setDefaultSectionSize(34);

        retranslateUi(emoji);

        QMetaObject::connectSlotsByName(emoji);
    } // setupUi

    void retranslateUi(QWidget *emoji)
    {
        emoji->setWindowTitle(QCoreApplication::translate("emoji", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class emoji: public Ui_emoji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOJI_H
