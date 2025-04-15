#include "convertsystems.h"
#include "ui_convertsystems.h"
#include "sstream"
#include <iostream>

std::stringstream convertStream;

ConvertSystems::ConvertSystems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConvertSystems)
{
    ui->setupUi(this);
    ui->value_in->setValidator(new QIntValidator(ui->value_in));
    ui->value_out->setReadOnly(true);
}

ConvertSystems::~ConvertSystems()
{
    delete ui;
}

int convertToDecimal(long input, int fromBase, int toBase) {
    int result_10 = 0;
    int multiplier = 1;

    while (input > 0) {
        int digit = input % 10;
        result_10 += digit * multiplier;
        multiplier *= fromBase;
        input /= 10;
    }

    if (toBase == 10)
        return result_10;

    multiplier = 1;
    int result = 0;

    while (result_10 > 0) {
        int digit = result_10 % toBase;
        result += digit * multiplier;
        multiplier *= 10;
        result_10 /= toBase;
    }

    return result;

}
void ConvertSystems::on_btn_convert_clicked()
{
    convertStream << ui->value_in->text().toStdString() << " " << ui->base_in->currentText().toStdString() << " " << ui->base_out->currentText().toStdString();
    int baseStart, baseEnd;
    long numberToConvert;
    convertStream >> numberToConvert >> baseStart >> baseEnd;
    ui->value_out->setText( QString::number(convertToDecimal(numberToConvert, baseStart, baseEnd) ) );
    convertStream.clear();
    convertStream.str("");
}

