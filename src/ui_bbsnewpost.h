/********************************************************************************
** Form generated from reading UI file 'bbsnewpost.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BBSNEWPOST_H
#define UI_BBSNEWPOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BBSNewPost
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bbs_send_post_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *bbs_attach_file_btn;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *bbs_post_editor;

    void setupUi(QWidget *BBSNewPost)
    {
        if (BBSNewPost->objectName().isEmpty())
            BBSNewPost->setObjectName(QString::fromUtf8("BBSNewPost"));
        BBSNewPost->resize(700, 507);
        verticalLayout = new QVBoxLayout(BBSNewPost);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(BBSNewPost);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        bbs_send_post_btn = new QPushButton(widget);
        bbs_send_post_btn->setObjectName(QString::fromUtf8("bbs_send_post_btn"));

        horizontalLayout->addWidget(bbs_send_post_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bbs_attach_file_btn = new QPushButton(widget);
        bbs_attach_file_btn->setObjectName(QString::fromUtf8("bbs_attach_file_btn"));

        horizontalLayout->addWidget(bbs_attach_file_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        bbs_post_editor = new QTextEdit(BBSNewPost);
        bbs_post_editor->setObjectName(QString::fromUtf8("bbs_post_editor"));

        verticalLayout->addWidget(bbs_post_editor);


        retranslateUi(BBSNewPost);

        QMetaObject::connectSlotsByName(BBSNewPost);
    } // setupUi

    void retranslateUi(QWidget *BBSNewPost)
    {
        BBSNewPost->setWindowTitle(QCoreApplication::translate("BBSNewPost", "Form", nullptr));
        bbs_send_post_btn->setText(QCoreApplication::translate("BBSNewPost", "send", nullptr));
        bbs_attach_file_btn->setText(QCoreApplication::translate("BBSNewPost", "attach file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BBSNewPost: public Ui_BBSNewPost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BBSNEWPOST_H
