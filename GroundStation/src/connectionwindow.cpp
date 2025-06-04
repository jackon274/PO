#include "connectionwindow.h"
#include <iostream>
#include "ui_connectionwindow.h"
#include "SerialPortCreator.h"
#include <QSystemTrayIcon>

ConnectionWindow::ConnectionWindow(QWidget *parent): QDialog(parent)
    , ui(new Ui::ConnectionWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<SerialPort*>();
    serialPort = createSerialPort();
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
    if(serialPort->open(selectedPort) == 0) {
        ui->btn_connect->setEnabled(false);
        ui->btn_disconnect->setEnabled(true);
        emit signalSerialPortConnected();
    }
    else {
        QString komunikat = "Nie udało się otworzyć portu!";
        static QSystemTrayIcon trayIcon;

        if (!trayIcon.isVisible()) {
            trayIcon.setIcon(QIcon::fromTheme("dialog-information"));
            trayIcon.setVisible(true);
        }
        trayIcon.showMessage("Błąd", komunikat, QSystemTrayIcon::Critical, 3000);
    }
}


void ConnectionWindow::on_btn_disconnect_clicked() {
    ui->btn_connect->setEnabled(true);
    ui->btn_disconnect->setEnabled(false);
}


void ConnectionWindow::on_btn_read_clicked() {
    std::vector<uint8_t> data = serialPort->receive();

    parser.parseLine(data);
}