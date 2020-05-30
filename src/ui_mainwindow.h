/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QListWidget *listWidget;
    QWidget *tab_2;
    QWidget *widget_tab_2;
    QListWidget *listWidget_2;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;
    QWidget *tab_3;
    QLabel *Avatar;
    QLabel *name;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(875, 673);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 851, 681));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget{\n"
"	background-color:none;\n"
"}\n"
"/*\350\256\276\347\275\256\347\252\227\344\275\223\346\240\267\345\274\217*/\n"
"QTabWidget#tabWidget::pane{ \n"
"	/*border:none;*/\n"
"   border-image: url(:/image/bg3.jpg) 0 0 0 0     stretch stretch;\n"
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
"	border-color: "
                        "black;\n"
"	width:40px;\n"
"	height:40px;\n"
"}\n"
"QTabWidget#tabWidget>QTabBar::tab:selected{\n"
"background: none;\n"
"border:none;\n"
"}"));
        tabWidget->setIconSize(QSize(40, 40));
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(199, 0, 643, 600));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 1, 201, 631));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	border:1px solid gray; \n"
"	outline:0px;\n"
"	/*background: rgb(186, 189, 182);*/\n"
"}\n"
"QListWidget::Item:hover{\n"
"  /* background-color: rgb(136, 138, 133);*/\n"
"}\n"
"QListWidget::Item:selected {\n"
"	/*background-color: rgb(136, 138, 133);*/\n"
"}\n"
"QListWidget::Item:selected:!active {\n"
"   /* background-color:rgb(211, 215, 207);*/\n"
"}\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget_tab_2 = new QWidget(tab_2);
        widget_tab_2->setObjectName(QString::fromUtf8("widget_tab_2"));
        widget_tab_2->setGeometry(QRect(250, 0, 611, 641));
        widget_tab_2->setStyleSheet(QString::fromUtf8(""));
        listWidget_2 = new QListWidget(widget_tab_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 40, 581, 531));
        treeWidget = new QTreeWidget(tab_2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 241, 601));
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget\n"
"{\n"
"   border-style:none;   \n"
"}\n"
"\n"
"QTreeWidget::item\n"
"{\n"
"   height: 26;\n"
"   color:rgba(255, 255, 255, 0);    \n"
"}\n"
"\n"
"QTreeWidget::item:selected:active\n"
"{\n"
"    background-color: rgba(135, 206, 250, 153);\n"
"}\n"
"\n"
"QTreeWidget::item:selected:!active, QTreeView::item:hover \n"
"{\n"
"    background-color: rgba(135, 206, 250, 50);\n"
"}"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 570, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(0,229,238);\n"
"border-image: url(:/image/add.png);\n"
"}\n"
"QPushButton#pushButton:hover\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(142,229,238);\n"
"}\n"
"QPushButton#pushButton:pressed\n"
"{\n"
"border: none;\n"
"color: white;\n"
"padding: 15px 32px;\n"
"text-align: center;\n"
"border-radius: 20px;\n"
"text-decoration: none;\n"
"background-color: rgb(85,170,255);\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8(":/image/chat.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tabWidget->addTab(tab_3, icon, QString());
        Avatar = new QLabel(centralwidget);
        Avatar->setObjectName(QString::fromUtf8("Avatar"));
        Avatar->setGeometry(QRect(20, 0, 51, 51));
        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(80, 0, 71, 41));
        name->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Start To Chat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\350\201\224\347\263\273\344\272\272", nullptr));
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "3", nullptr));
        Avatar->setText(QCoreApplication::translate("MainWindow", "image", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
