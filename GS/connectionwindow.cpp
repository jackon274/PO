#include "connectionwindow.h"

#include <iostream>
#include <ostream>

#include "./ui_connectionwindow.h"
#include "SerialPortManager.h"



ConnectionWindow::ConnectionWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<SerialPort*>();
#ifdef _WIN32
    ui->btn_refresh->setEnabled(false);
    ui->box_ports->addItem("Simulation");
#endif
ui->btn_connect->setEnabled(false);


}
SerialPortManager serialPortManager;

ConnectionWindow::~ConnectionWindow()
{
    delete ui;
}


void ConnectionWindow::on_btn_refresh_clicked()
{
    ui->btn_connect->setEnabled(true);
    ui->box_ports->clear();
    ui->box_ports->addItem("Simulation");
    /*serialPort.checkAvailableSerialPorts();
    std::vector <std::string> sp = serialPort.getAvailableSerialPorts();
    for(auto &a:sp) {
        ui->box_ports->addItem(QString::fromStdString(a));
    }*/
    serialPortManager.checkAvailableSerialPorts();
    for(auto port:serialPortManager.getAvailableSerialPorts()) {
        ui->box_ports->addItem(QString::fromStdString(port->displayName), QVariant::fromValue(port));
    }

}


void ConnectionWindow::on_btn_connect_clicked()
{
    int baudRate = ui->box_baudrate->currentText().toInt();
    serialPortManager.setBaudRate(baudRate);
}

