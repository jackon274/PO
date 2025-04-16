/********************************************************************************
** Form generated from reading UI file 'convertsystems.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTSYSTEMS_H
#define UI_CONVERTSYSTEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConvertSystems
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *value_in;
    QComboBox *base_in;
    QGroupBox *groupBox_2;
    QLineEdit *value_out;
    QComboBox *base_out;
    QPushButton *btn_convert;

    void setupUi(QDialog *ConvertSystems)
    {
        if (ConvertSystems->objectName().isEmpty())
            ConvertSystems->setObjectName("ConvertSystems");
        ConvertSystems->resize(349, 300);
        buttonBox = new QDialogButtonBox(ConvertSystems);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 251, 311, 31));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Close);
        label = new QLabel(ConvertSystems);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 341, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(ConvertSystems);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 80, 291, 51));
        value_in = new QLineEdit(groupBox);
        value_in->setObjectName("value_in");
        value_in->setGeometry(QRect(10, 20, 201, 21));
        base_in = new QComboBox(groupBox);
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->addItem(QString());
        base_in->setObjectName("base_in");
        base_in->setGeometry(QRect(230, 20, 51, 22));
        groupBox_2 = new QGroupBox(ConvertSystems);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 140, 291, 51));
        value_out = new QLineEdit(groupBox_2);
        value_out->setObjectName("value_out");
        value_out->setGeometry(QRect(10, 20, 201, 21));
        base_out = new QComboBox(groupBox_2);
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->addItem(QString());
        base_out->setObjectName("base_out");
        base_out->setGeometry(QRect(230, 20, 51, 22));
        btn_convert = new QPushButton(ConvertSystems);
        btn_convert->setObjectName("btn_convert");
        btn_convert->setGeometry(QRect(170, 254, 75, 24));

        retranslateUi(ConvertSystems);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConvertSystems, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConvertSystems, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConvertSystems);
    } // setupUi

    void retranslateUi(QDialog *ConvertSystems)
    {
        ConvertSystems->setWindowTitle(QCoreApplication::translate("ConvertSystems", "Konwersja", nullptr));
        label->setText(QCoreApplication::translate("ConvertSystems", "Konwersja system\303\263w liczbowych", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ConvertSystems", "Liczba wej\305\233ciowa", nullptr));
        base_in->setItemText(0, QCoreApplication::translate("ConvertSystems", "2", nullptr));
        base_in->setItemText(1, QCoreApplication::translate("ConvertSystems", "3", nullptr));
        base_in->setItemText(2, QCoreApplication::translate("ConvertSystems", "4", nullptr));
        base_in->setItemText(3, QCoreApplication::translate("ConvertSystems", "5", nullptr));
        base_in->setItemText(4, QCoreApplication::translate("ConvertSystems", "6", nullptr));
        base_in->setItemText(5, QCoreApplication::translate("ConvertSystems", "7", nullptr));
        base_in->setItemText(6, QCoreApplication::translate("ConvertSystems", "8", nullptr));
        base_in->setItemText(7, QCoreApplication::translate("ConvertSystems", "9", nullptr));
        base_in->setItemText(8, QCoreApplication::translate("ConvertSystems", "10", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("ConvertSystems", "Liczba wyj\305\233ciowa", nullptr));
        base_out->setItemText(0, QCoreApplication::translate("ConvertSystems", "2", nullptr));
        base_out->setItemText(1, QCoreApplication::translate("ConvertSystems", "3", nullptr));
        base_out->setItemText(2, QCoreApplication::translate("ConvertSystems", "4", nullptr));
        base_out->setItemText(3, QCoreApplication::translate("ConvertSystems", "5", nullptr));
        base_out->setItemText(4, QCoreApplication::translate("ConvertSystems", "6", nullptr));
        base_out->setItemText(5, QCoreApplication::translate("ConvertSystems", "7", nullptr));
        base_out->setItemText(6, QCoreApplication::translate("ConvertSystems", "8", nullptr));
        base_out->setItemText(7, QCoreApplication::translate("ConvertSystems", "9", nullptr));
        base_out->setItemText(8, QCoreApplication::translate("ConvertSystems", "10", nullptr));
        base_out->setItemText(9, QCoreApplication::translate("ConvertSystems", "16", nullptr));

        btn_convert->setText(QCoreApplication::translate("ConvertSystems", "Konwertuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertSystems: public Ui_ConvertSystems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTSYSTEMS_H
