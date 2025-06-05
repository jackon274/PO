#include "connectionwindow.h"
#include <iostream>
#include "ui_connectionwindow.h"
#include <QSystemTrayIcon>
#include "ErrorNotifier.h"
#include "AppException.h"

ConnectionWindow::ConnectionWindow(ISerialPort *port, QWidget *parent): QDialog(parent)
                                                     , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<SerialPort*>();
    serialPort = port;

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

    serialPort->checkAvailableSerialPorts();
    for(auto port:serialPort->getAvailableSerialPorts()) {
        ui->box_ports->addItem(QString::fromStdString(port->displayName), QVariant::fromValue(port));
    }
}

void ConnectionWindow::on_btn_connect_clicked() {
    int baudRate = ui->box_baudrate->currentText().toInt();
    serialPort->setBaudRate(baudRate);
    SerialPort* selectedPort = ui->box_ports->currentData().value<SerialPort*>();
    if(selectedPort == nullptr) {
        return;
    }
    std::cout << selectedPort->displayName << std::endl; //debug only
    try {
        serialPort->open(selectedPort);
        ui->btn_connect->setEnabled(false);
        ui->btn_disconnect->setEnabled(true);
        emit signalSerialPortConnected();
    }
    catch (AppException e) {
        ErrorNotifier notifier {e.code()};
        notifier.notify();
    }
}


void ConnectionWindow::on_btn_disconnect_clicked() {
    serialPort->close();
    ui->btn_connect->setEnabled(true);
    ui->btn_disconnect->setEnabled(false);
}


void ConnectionWindow::on_btn_read_clicked() {
    std::vector<uint8_t> data = serialPort->receive();

    parser.parseLine(data);
}