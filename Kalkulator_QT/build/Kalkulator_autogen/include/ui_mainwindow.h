/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_about;
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
    QPushButton *btn_sqrt;
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
    QLabel *label_sign;
    QMenuBar *menubar;
    QMenu *menuOpcje;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(320, 490);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(320, 490));
        MainWindow->setMaximumSize(QSize(320, 490));
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Fotki/resources/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-color:rgb(0, 0, 0);\n"
"color:rgb(0,0,0);\n"
"}\n"
""));
        action_about = new QAction(MainWindow);
        action_about->setObjectName("action_about");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 100, 291, 342));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_add = new QPushButton(gridLayoutWidget);
        btn_add->setObjectName("btn_add");
        btn_add->setMinimumSize(QSize(60, 60));
        btn_add->setMaximumSize(QSize(60, 60));
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(251, 141, 14);\n"
"color: rgb(255, 255, 255);\n"
"font:25pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(244, 183, 119);\n"
"}"));

        gridLayout->addWidget(btn_add, 3, 4, 1, 1);

        btn_6 = new QPushButton(gridLayoutWidget);
        btn_6->setObjectName("btn_6");
        btn_6->setMinimumSize(QSize(60, 60));
        btn_6->setMaximumSize(QSize(60, 60));
        btn_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_6, 2, 2, 1, 1);

        btn_subtract = new QPushButton(gridLayoutWidget);
        btn_subtract->setObjectName("btn_subtract");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_subtract->sizePolicy().hasHeightForWidth());
        btn_subtract->setSizePolicy(sizePolicy1);
        btn_subtract->setMinimumSize(QSize(60, 60));
        btn_subtract->setMaximumSize(QSize(60, 60));
        btn_subtract->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(251, 141, 14);\n"
"color: rgb(255, 255, 255);\n"
"font:25pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(244, 183, 119);\n"
"}"));

        gridLayout->addWidget(btn_subtract, 2, 4, 1, 1);

        btn_div = new QPushButton(gridLayoutWidget);
        btn_div->setObjectName("btn_div");
        btn_div->setMinimumSize(QSize(60, 60));
        btn_div->setMaximumSize(QSize(60, 60));
        btn_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(251, 141, 14);\n"
"color: rgb(255, 255, 255);\n"
"font:25pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(244, 183, 119);\n"
"}"));

        gridLayout->addWidget(btn_div, 0, 4, 1, 1);

        btn_comma = new QPushButton(gridLayoutWidget);
        btn_comma->setObjectName("btn_comma");
        btn_comma->setMinimumSize(QSize(60, 60));
        btn_comma->setMaximumSize(QSize(60, 60));
        btn_comma->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_comma, 4, 2, 1, 1);

        btn_5 = new QPushButton(gridLayoutWidget);
        btn_5->setObjectName("btn_5");
        btn_5->setMinimumSize(QSize(60, 60));
        btn_5->setMaximumSize(QSize(60, 60));
        btn_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_5, 2, 1, 1, 1);

        btn_multiply = new QPushButton(gridLayoutWidget);
        btn_multiply->setObjectName("btn_multiply");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_multiply->sizePolicy().hasHeightForWidth());
        btn_multiply->setSizePolicy(sizePolicy2);
        btn_multiply->setMinimumSize(QSize(60, 60));
        btn_multiply->setMaximumSize(QSize(60, 60));
        btn_multiply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(251, 141, 14);\n"
"color: rgb(255, 255, 255);\n"
"font:25pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(244, 183, 119);\n"
"}"));

        gridLayout->addWidget(btn_multiply, 1, 4, 1, 1);

        btn_mode = new QPushButton(gridLayoutWidget);
        btn_mode->setObjectName("btn_mode");
        btn_mode->setMinimumSize(QSize(60, 60));
        btn_mode->setMaximumSize(QSize(60, 60));
        btn_mode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_mode, 4, 0, 1, 1);

        btn_1 = new QPushButton(gridLayoutWidget);
        btn_1->setObjectName("btn_1");
        sizePolicy1.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy1);
        btn_1->setMinimumSize(QSize(60, 60));
        btn_1->setMaximumSize(QSize(60, 60));
        btn_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_1, 3, 0, 1, 1);

        btn_sqrt = new QPushButton(gridLayoutWidget);
        btn_sqrt->setObjectName("btn_sqrt");
        btn_sqrt->setMinimumSize(QSize(60, 60));
        btn_sqrt->setMaximumSize(QSize(60, 60));
        btn_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(74, 73, 77);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(121, 121, 121);\n"
"}"));

        gridLayout->addWidget(btn_sqrt, 0, 1, 1, 1);

        btn_AC = new QPushButton(gridLayoutWidget);
        btn_AC->setObjectName("btn_AC");
        btn_AC->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_AC->sizePolicy().hasHeightForWidth());
        btn_AC->setSizePolicy(sizePolicy);
        btn_AC->setMinimumSize(QSize(50, 60));
        btn_AC->setMaximumSize(QSize(60, 60));
        btn_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"border-radius:40px;\n"
"background-color: rgb(74, 73, 77);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(121, 121, 121);\n"
"}"));

        gridLayout->addWidget(btn_AC, 0, 0, 1, 1);

        btn_7 = new QPushButton(gridLayoutWidget);
        btn_7->setObjectName("btn_7");
        btn_7->setMinimumSize(QSize(60, 60));
        btn_7->setMaximumSize(QSize(60, 60));
        btn_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_7, 1, 0, 1, 1);

        btn_4 = new QPushButton(gridLayoutWidget);
        btn_4->setObjectName("btn_4");
        btn_4->setMinimumSize(QSize(60, 60));
        btn_4->setMaximumSize(QSize(60, 60));
        btn_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_4, 2, 0, 1, 1);

        btn_equals = new QPushButton(gridLayoutWidget);
        btn_equals->setObjectName("btn_equals");
        btn_equals->setMinimumSize(QSize(60, 60));
        btn_equals->setMaximumSize(QSize(60, 60));
        QFont font;
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        btn_equals->setFont(font);
        btn_equals->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(251, 141, 14);\n"
"color: rgb(255, 255, 255);\n"
"font:25pt;\n"
"border-radius: 30px;\n"
"padding-top: -5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(244, 183, 119);\n"
"}"));

        gridLayout->addWidget(btn_equals, 4, 4, 1, 1);

        btn_9 = new QPushButton(gridLayoutWidget);
        btn_9->setObjectName("btn_9");
        btn_9->setMinimumSize(QSize(60, 60));
        btn_9->setMaximumSize(QSize(60, 60));
        btn_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_9, 1, 2, 1, 1);

        btn_0 = new QPushButton(gridLayoutWidget);
        btn_0->setObjectName("btn_0");
        btn_0->setMinimumSize(QSize(60, 60));
        btn_0->setMaximumSize(QSize(60, 60));
        btn_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_0, 4, 1, 1, 1);

        btn_percent = new QPushButton(gridLayoutWidget);
        btn_percent->setObjectName("btn_percent");
        btn_percent->setMinimumSize(QSize(60, 60));
        btn_percent->setMaximumSize(QSize(60, 60));
        btn_percent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(74, 73, 77);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(121, 121, 121);\n"
"}"));

        gridLayout->addWidget(btn_percent, 0, 2, 1, 1);

        btn_2 = new QPushButton(gridLayoutWidget);
        btn_2->setObjectName("btn_2");
        btn_2->setMinimumSize(QSize(60, 60));
        btn_2->setMaximumSize(QSize(60, 60));
        btn_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_2, 3, 1, 1, 1);

        btn_3 = new QPushButton(gridLayoutWidget);
        btn_3->setObjectName("btn_3");
        btn_3->setMinimumSize(QSize(60, 60));
        btn_3->setMaximumSize(QSize(60, 60));
        btn_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_3, 3, 2, 1, 1);

        btn_8 = new QPushButton(gridLayoutWidget);
        btn_8->setObjectName("btn_8");
        btn_8->setMinimumSize(QSize(60, 60));
        btn_8->setMaximumSize(QSize(60, 60));
        btn_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border:none;\n"
"background-color: rgb(31, 31, 32);\n"
"color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgb(95, 95, 95);\n"
"}"));

        gridLayout->addWidget(btn_8, 1, 1, 1, 1);

        display = new QLCDNumber(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(0, 20, 331, 61));
        display->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        display->setDigitCount(7);
        label_sign = new QLabel(centralwidget);
        label_sign->setObjectName("label_sign");
        label_sign->setGeometry(QRect(280, 30, 31, 31));
        QFont font1;
        font1.setPointSize(24);
        label_sign->setFont(font1);
        label_sign->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 320, 22));
        menuOpcje = new QMenu(menubar);
        menuOpcje->setObjectName("menuOpcje");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpcje->menuAction());
        menuOpcje->addAction(action_about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Kalkulator", nullptr));
        action_about->setText(QCoreApplication::translate("MainWindow", "O &Autorze", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        btn_comma->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        btn_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_multiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        btn_mode->setText(QCoreApplication::translate("MainWindow", "CONV", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
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
        label_sign->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        menuOpcje->setTitle(QCoreApplication::translate("MainWindow", "Opcje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
