#include "convertsystems.h"
#include "ui_convertsystems.h"
#include "sstream"
#include <iostream>
#include <QSystemTrayIcon>

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

std::string convertToHex (long input, int fromBase) {
        std::stringstream hexStream;
        hexStream << std::hex << std::uppercase<< input;
        return hexStream.str();
}

int convertSystems(long input, int fromBase, int toBase) {

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
    std::cout << numberToConvert << std::endl;
    if(numberToConvert < 0) {
        static QSystemTrayIcon trayIcon;
        if (!trayIcon.isVisible()) {
            trayIcon.setIcon(QIcon(":/Fotki/resources/icon.png"));
            trayIcon.setVisible(true);
        }
        std::cout << "ERROR!!" << std::endl;

        trayIcon.showMessage("Błąd", "Nie można obsłużyć liczb ujemnych", QSystemTrayIcon::Critical, 3000);
        numberToConvert = 0;
        convertStream.clear();
        convertStream.str("");
        return;
    }
    if(baseEnd != 16)
        ui->value_out->setText( QString::number(convertSystems(numberToConvert, baseStart, baseEnd) ) );
    else
        ui->value_out->setText(QString::fromStdString(convertToHex(convertSystems(numberToConvert, baseStart, 10), baseStart) ) ) ;
    convertStream.clear();
    convertStream.str("");
}

