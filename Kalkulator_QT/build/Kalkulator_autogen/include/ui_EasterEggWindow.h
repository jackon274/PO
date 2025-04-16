/********************************************************************************
** Form generated from reading UI file 'EasterEggWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASTEREGGWINDOW_H
#define UI_EASTEREGGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EasterEggWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_5;
    QPushButton *noclick1;
    QPushButton *noclick2;
    QLabel *label_7;
    QLabel *label_name;
    QLabel *label_author;

    void setupUi(QDialog *EasterEggWindow)
    {
        if (EasterEggWindow->objectName().isEmpty())
            EasterEggWindow->setObjectName("EasterEggWindow");
        EasterEggWindow->resize(398, 309);
        buttonBox = new QDialogButtonBox(EasterEggWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Yes);
        label = new QLabel(EasterEggWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 81, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_5 = new QLabel(EasterEggWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, -10, 231, 161));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Fotki/resources/flag.jpg")));
        label_5->setScaledContents(true);
        noclick1 = new QPushButton(EasterEggWindow);
        noclick1->setObjectName("noclick1");
        noclick1->setGeometry(QRect(290, 270, 81, 25));
        noclick2 = new QPushButton(EasterEggWindow);
        noclick2->setObjectName("noclick2");
        noclick2->setGeometry(QRect(110, 10, 81, 25));
        label_7 = new QLabel(EasterEggWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 150, 101, 131));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/Fotki/resources/POL.svg")));
        label_7->setScaledContents(true);
        label_name = new QLabel(EasterEggWindow);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(10, 100, 181, 41));
        QFont font1;
        font1.setPointSize(12);
        label_name->setFont(font1);
        label_author = new QLabel(EasterEggWindow);
        label_author->setObjectName("label_author");
        label_author->setGeometry(QRect(10, 80, 181, 41));
        label_author->setFont(font1);

        retranslateUi(EasterEggWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EasterEggWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EasterEggWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EasterEggWindow);
    } // setupUi

    void retranslateUi(QDialog *EasterEggWindow)
    {
        EasterEggWindow->setWindowTitle(QCoreApplication::translate("EasterEggWindow", "About", nullptr));
        label->setText(QCoreApplication::translate("EasterEggWindow", "Witaj!", nullptr));
        label_5->setText(QString());
        noclick1->setText(QCoreApplication::translate("EasterEggWindow", "Nie klikaj", nullptr));
        noclick2->setText(QCoreApplication::translate("EasterEggWindow", "Nie klikaj", nullptr));
        label_7->setText(QString());
        label_name->setText(QCoreApplication::translate("EasterEggWindow", "Jacek Konderak", nullptr));
        label_author->setText(QCoreApplication::translate("EasterEggWindow", "Autor:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EasterEggWindow: public Ui_EasterEggWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASTEREGGWINDOW_H
