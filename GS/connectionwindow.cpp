#include "connectionwindow.h"
#include "./ui_connectionwindow.h"
#include "SerialPort.h"

SerialPort serialPort;

ConnectionWindow::ConnectionWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
}

ConnectionWindow::~ConnectionWindow()
{
    delete ui;
}


void ConnectionWindow::on_btn_refresh_clicked()
{
    ui->box_ports->clear();
    serialPort.checkAvailableSerialPorts();
    std::vector <std::string> sp = serialPort.getAvailableSerialPorts();
    for(auto &a:sp) {
        ui->box_ports->addItem(QString::fromStdString(a));
    }
    //ui->box_ports->addItem("Port1");
    //ui->box_ports->addItem("Port2");
}

