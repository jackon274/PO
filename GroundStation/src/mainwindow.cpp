#include "mainwindow.h"
#include <iostream>
#include "Map.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"
#include <vector>
#include <QTimer>
#include "SerialPortCreator.h"
#include "PlotWidgetController.h"
#include "DataType.h"


MainWindow::MainWindow(QTranslator *ptrTranslator, QApplication *ptrApp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    styler(ui),
    window (serialPort = createSerialPort()),
    translator(ptrTranslator),
    application(ptrApp)
{
    ui->setupUi(this);
    styler.applyStyle();
    Map map(ui->map);

    connect (&window, &ConnectionWindow::signalSerialPortConnected, this, &MainWindow::SerialPortConnected);
    manager.addPlotWidgetController(ui->widget_graph1, ui->label_title_graph1, ui->box_graph1->currentData().value<DataType>());
    manager.addPlotWidgetController(ui->widget_graph2, ui->label_title_graph2, ui->box_graph2->currentData().value<DataType>());
    manager.addPlotWidgetController(ui->widget_graph3, ui->label_title_graph3, ui->box_graph3->currentData().value<DataType>());
    manager.addPlotWidgetController(ui->widget_graph4, ui->label_title_graph4, ui->box_graph4->currentData().value<DataType>());

    QTimer *timer = new QTimer(this);
    timer->setInterval(5000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    timer->start();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SerialPortConnected() const {
    ui->label_serial_port_name->setText(QString::fromStdString(serialPort->getOpenSerialPort()));
    ui->label_connection_status->setText("");
}


void MainWindow::on_btn_connect_clicked() {
    window.setModal(true);
    window.exec();
}

void MainWindow::on_btn_menu_toggled(bool checked) {
    ui->widget_sidebar_labels->setVisible(checked);
}

void MainWindow::on_btn_map_clicked() {
    ui->widget_content->setCurrentIndex(0);
    styler.highlightSelectedButtonLabel(0);
}

void MainWindow::on_btn_stats_clicked() {
    ui->widget_content->setCurrentIndex(1);
    styler.highlightSelectedButtonLabel(1);
}

void MainWindow::on_btn_graph_clicked() {
    ui->widget_content->setCurrentIndex(2);
    styler.highlightSelectedButtonLabel(2);
}

void MainWindow::on_btn_config_clicked() {
    ui->widget_content->setCurrentIndex(3);
    styler.highlightSelectedButtonLabel(3);
}

void MainWindow::on_btn_info_clicked() {
    ui->widget_content->setCurrentIndex(4);
    styler.highlightSelectedButtonLabel(4);

}

void MainWindow::on_btn_settings_clicked() {
    ui->widget_content->setCurrentIndex(5);
    styler.highlightSelectedButtonLabel(5);
}

void MainWindow::on_box_languages_currentIndexChanged(int index) {
    QString langCode = ui->box_languages->itemData(index).toString();
    if (langCode == "en") {
        application->removeTranslator(translator);
        ui->retranslateUi(this);
    }
    if (langCode == "pl") {
        translator->load(":/Translations/GroundStation_pl_PL.qm");
        application->installTranslator(translator);
        ui->retranslateUi(this);
    }
}



void MainWindow::on_btn_testmode_clicked() {
    serialPort->send("AT+MODE=TEST");
}


void MainWindow::on_btn_configuration_clicked() {
    serialPort->send("AT+TEST=RFCFG,868,SF12,125,12,15,14,ON,OFF,OFF\r\n");
}


void MainWindow::on_btn_rx_mode_clicked() {
    serialPort->send("AT+TEST=RXLRPKT");
    styler.enableReceive();
}

void MainWindow::timerSlot() {
    if (*serialPort == ISerialPort::SERIAL_PORT_OPENED) {
        std::vector <uint8_t> data = serialPort->receive();
        if (data.size() > 0) {
            std::vector <char> dataChar;
            for (auto a : data) {
                dataChar.push_back(static_cast <char> (a));
            }
            fmt::println("{}", dataChar);
            parser.parseLine(data, manager);
        }
    }
}

void MainWindow::on_box_graph1_currentIndexChanged(int index) {
    manager.updatePlotWidgetController(0, ui->box_graph1->currentData().value<DataType>());
}

void MainWindow::on_box_graph2_activated(int index) {
    manager.updatePlotWidgetController(1, ui->box_graph2->currentData().value<DataType>());
}

void MainWindow::on_box_graph3_activated(int index) {
    manager.updatePlotWidgetController(2, ui->box_graph3->currentData().value<DataType>());
}

void MainWindow::on_box_graph4_activated(int index) {
    manager.updatePlotWidgetController(3, ui->box_graph4->currentData().value<DataType>());
}


void MainWindow::on_btn_tx_mode_clicked() {
    styler.enableTransmit();
}


void MainWindow::on_btn_buzz_clicked() {

}


void MainWindow::on_btn_light_on_clicked() {

}


void MainWindow::on_btn_light_off_clicked() {

}

