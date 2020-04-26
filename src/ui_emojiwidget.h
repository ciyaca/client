/********************************************************************************
** Form generated from reading UI file 'emojiwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOJIWIDGET_H
#define UI_EMOJIWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_emojiwidget
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *emojiwidget)
    {
        if (emojiwidget->objectName().isEmpty())
            emojiwidget->setObjectName(QString::fromUtf8("emojiwidget"));
        emojiwidget->resize(421, 221);
        tableWidget = new QTableWidget(emojiwidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 421, 221));
        tableWidget->setRowCount(15);
        tableWidget->setColumnCount(9);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(45);
        tableWidget->horizontalHeader()->setDefaultSectionSize(45);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);
        tableWidget->verticalHeader()->setDefaultSectionSize(45);

        retranslateUi(emojiwidget);

        QMetaObject::connectSlotsByName(emojiwidget);
    } // setupUi

    void retranslateUi(QWidget *emojiwidget)
    {
        emojiwidget->setWindowTitle(QCoreApplication::translate("emojiwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class emojiwidget: public Ui_emojiwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOJIWIDGET_H
