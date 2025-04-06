/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_add;
    QPushButton *btn_6;
    QPushButton *btn_subtract;
    QPushButton *btn_div;
    QPushButton *btn_comma;
    QPushButton *btn_5;
    QPushButton *btn_multiply;
    QPushButton *btn_mode;
    QPushButton *btn_1;
    QPushButton *btn_pm;
    QPushButton *btn_AC;
    QPushButton *btn_7;
    QPushButton *btn_4;
    QPushButton *btn_equals;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QPushButton *btn_percent;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_8;
    QLCDNumber *display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(415, 434);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 130, 362, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_add = new QPushButton(gridLayoutWidget);
        btn_add->setObjectName("btn_add");

        gridLayout->addWidget(btn_add, 3, 4, 1, 1);

        btn_6 = new QPushButton(gridLayoutWidget);
        btn_6->setObjectName("btn_6");

        gridLayout->addWidget(btn_6, 2, 2, 1, 1);

        btn_subtract = new QPushButton(gridLayoutWidget);
        btn_subtract->setObjectName("btn_subtract");

        gridLayout->addWidget(btn_subtract, 2, 4, 1, 1);

        btn_div = new QPushButton(gridLayoutWidget);
        btn_div->setObjectName("btn_div");

        gridLayout->addWidget(btn_div, 0, 4, 1, 1);

        btn_comma = new QPushButton(gridLayoutWidget);
        btn_comma->setObjectName("btn_comma");

        gridLayout->addWidget(btn_comma, 4, 2, 1, 1);

        btn_5 = new QPushButton(gridLayoutWidget);
        btn_5->setObjectName("btn_5");

        gridLayout->addWidget(btn_5, 2, 1, 1, 1);

        btn_multiply = new QPushButton(gridLayoutWidget);
        btn_multiply->setObjectName("btn_multiply");

        gridLayout->addWidget(btn_multiply, 1, 4, 1, 1);

        btn_mode = new QPushButton(gridLayoutWidget);
        btn_mode->setObjectName("btn_mode");

        gridLayout->addWidget(btn_mode, 4, 0, 1, 1);

        btn_1 = new QPushButton(gridLayoutWidget);
        btn_1->setObjectName("btn_1");

        gridLayout->addWidget(btn_1, 3, 0, 1, 1);

        btn_pm = new QPushButton(gridLayoutWidget);
        btn_pm->setObjectName("btn_pm");

        gridLayout->addWidget(btn_pm, 0, 1, 1, 1);

        btn_AC = new QPushButton(gridLayoutWidget);
        btn_AC->setObjectName("btn_AC");
        btn_AC->setEnabled(true);

        gridLayout->addWidget(btn_AC, 0, 0, 1, 1);

        btn_7 = new QPushButton(gridLayoutWidget);
        btn_7->setObjectName("btn_7");

        gridLayout->addWidget(btn_7, 1, 0, 1, 1);

        btn_4 = new QPushButton(gridLayoutWidget);
        btn_4->setObjectName("btn_4");

        gridLayout->addWidget(btn_4, 2, 0, 1, 1);

        btn_equals = new QPushButton(gridLayoutWidget);
        btn_equals->setObjectName("btn_equals");

        gridLayout->addWidget(btn_equals, 4, 4, 1, 1);

        btn_9 = new QPushButton(gridLayoutWidget);
        btn_9->setObjectName("btn_9");

        gridLayout->addWidget(btn_9, 1, 2, 1, 1);

        btn_0 = new QPushButton(gridLayoutWidget);
        btn_0->setObjectName("btn_0");

        gridLayout->addWidget(btn_0, 4, 1, 1, 1);

        btn_percent = new QPushButton(gridLayoutWidget);
        btn_percent->setObjectName("btn_percent");

        gridLayout->addWidget(btn_percent, 0, 2, 1, 1);

        btn_2 = new QPushButton(gridLayoutWidget);
        btn_2->setObjectName("btn_2");

        gridLayout->addWidget(btn_2, 3, 1, 1, 1);

        btn_3 = new QPushButton(gridLayoutWidget);
        btn_3->setObjectName("btn_3");

        gridLayout->addWidget(btn_3, 3, 2, 1, 1);

        btn_8 = new QPushButton(gridLayoutWidget);
        btn_8->setObjectName("btn_8");

        gridLayout->addWidget(btn_8, 1, 1, 1, 1);

        display = new QLCDNumber(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(30, 50, 351, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 415, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        btn_comma->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        btn_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_multiply->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        btn_mode->setText(QCoreApplication::translate("MainWindow", "MODE", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_pm->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        btn_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        btn_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btn_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
