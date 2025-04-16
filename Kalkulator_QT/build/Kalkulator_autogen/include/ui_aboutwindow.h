/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_logo;
    QLabel *label_title;
    QLabel *label_name;
    QLabel *label_index;
    QLabel *label_copyright;
    QLabel *label_compilation;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName("AboutWindow");
        AboutWindow->resize(360, 380);
        AboutWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 171, 211)\n"
""));
        buttonBox = new QDialogButtonBox(AboutWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 340, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(false);
        label_logo = new QLabel(AboutWindow);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(120, 20, 110, 110));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/Fotki/resources/icon.png")));
        label_logo->setScaledContents(true);
        label_title = new QLabel(AboutWindow);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(120, 140, 121, 31));
        QFont font;
        font.setPointSize(18);
        label_title->setFont(font);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(69, 33, 111)"));
        label_name = new QLabel(AboutWindow);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(0, 200, 361, 20));
        QFont font1;
        font1.setPointSize(12);
        label_name->setFont(font1);
        label_name->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 0.8)"));
        label_name->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_index = new QLabel(AboutWindow);
        label_index->setObjectName("label_index");
        label_index->setGeometry(QRect(0, 220, 361, 20));
        label_index->setFont(font1);
        label_index->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 0.8)"));
        label_index->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_copyright = new QLabel(AboutWindow);
        label_copyright->setObjectName("label_copyright");
        label_copyright->setGeometry(QRect(0, 300, 361, 20));
        QFont font2;
        font2.setPointSize(9);
        label_copyright->setFont(font2);
        label_copyright->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 0.56)"));
        label_copyright->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_compilation = new QLabel(AboutWindow);
        label_compilation->setObjectName("label_compilation");
        label_compilation->setGeometry(QRect(0, 280, 361, 20));
        QFont font3;
        font3.setPointSize(8);
        label_compilation->setFont(font3);
        label_compilation->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 0.56)"));
        label_compilation->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(AboutWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AboutWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AboutWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QCoreApplication::translate("AboutWindow", "O Autorze", nullptr));
        label_logo->setText(QString());
        label_title->setText(QCoreApplication::translate("AboutWindow", "Kalkulator", nullptr));
        label_name->setText(QCoreApplication::translate("AboutWindow", "Jacek Konderak", nullptr));
        label_index->setText(QCoreApplication::translate("AboutWindow", "287075", nullptr));
        label_copyright->setText(QCoreApplication::translate("AboutWindow", "Copyright (c) JK", nullptr));
        label_compilation->setText(QCoreApplication::translate("AboutWindow", "Kompilacja: 15.04.2025", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
