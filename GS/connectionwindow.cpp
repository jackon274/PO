#include "connectionwindow.h"
#include "./ui_connectionwindow.h"
#include "SerialPortManager.h"



ConnectionWindow::ConnectionWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
#ifdef _WIN32
    ui->btn_refresh->setEnabled(false);
    ui->box_ports->addItem("Simulation");
#endif
    ui->btn_refresh->setText(tr("Refresh"));
}

ConnectionWindow::~ConnectionWindow()
{
    delete ui;
}


void ConnectionWindow::on_btn_refresh_clicked()
{
    ui->box_ports->clear();
    ui->box_ports->addItem("Simulation");
    /*serialPort.checkAvailableSerialPorts();
    std::vector <std::string> sp = serialPort.getAvailableSerialPorts();
    for(auto &a:sp) {
        ui->box_ports->addItem(QString::fromStdString(a));
    }*/
    SerialPortManager serialPortManager;
    serialPortManager.checkAvailableSerialPorts();
    for(auto port:serialPortManager.getAvailableSerialPorts()) {
        ui->box_ports->addItem(QString::fromStdString(port->displayName), QString::fromStdString(port->portName));
    }

}

