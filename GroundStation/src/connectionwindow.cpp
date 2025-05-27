#include "connectionwindow.h"
#include <iostream>
#include "ui_connectionwindow.h"
#include "SerialPortManager.h"
#include <iomanip>


ConnectionWindow::ConnectionWindow(SerialPortManager &manager, QWidget *parent): QDialog(parent), serialPortManager(manager)
    , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<SerialPort*>();
#ifdef _WIN32
    ui->btn_refresh->setEnabled(false);
    ui->box_ports->addItem("Simulation");
#endif
    ui->btn_connect->setEnabled(false);
    ui->btn_disconnect->setEnabled(false);


}


ConnectionWindow::~ConnectionWindow() {
    delete ui;
}


void ConnectionWindow::on_btn_refresh_clicked() {
    ui->btn_connect->setEnabled(true);
    ui->box_ports->clear();
    ui->box_ports->addItem("Simulation", QVariant::fromValue(nullptr));

    serialPortManager.checkAvailableSerialPorts();
    for(auto port:serialPortManager.getAvailableSerialPorts()) {
        ui->box_ports->addItem(QString::fromStdString(port->displayName), QVariant::fromValue(port));
    }
}

void ConnectionWindow::on_btn_connect_clicked() {
    int baudRate = ui->box_baudrate->currentText().toInt();
    serialPortManager.setBaudRate(baudRate);
    SerialPort* selectedPort = ui->box_ports->currentData().value<SerialPort*>();
    if(selectedPort == nullptr) {
        return;
    }
    std::cout << selectedPort->displayName << std::endl; //debug only
    serialPortManager.open(selectedPort);
    ui->btn_connect->setEnabled(false);
    ui->btn_disconnect->setEnabled(true);
    emit signalSerialPortConnected();
}


void ConnectionWindow::on_btn_disconnect_clicked() {
    ui->btn_connect->setEnabled(true);
    ui->btn_disconnect->setEnabled(false);
}


void ConnectionWindow::on_btn_read_clicked() {
    std::vector<uint8_t> data = serialPortManager.uartReceive();

    if (!data.empty()) {
        // Output to stdout
        std::string text(data.begin(), data.end());
        std::cout << "Received text: "; //
        std::cout << text << std::endl;

        std::cout << "Received " << data.size() << " bytes: ";

        for (uint8_t byte : data) {
            std::cout << std::hex << std::uppercase << std::setw(2)
                      << std::setfill('0') << static_cast<int>(byte) << " ";
        }
        std::cout << std::dec << std::endl;  // Reset to decimal
    }
}