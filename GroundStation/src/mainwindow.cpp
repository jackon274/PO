#include "mainwindow.h"

#include <iostream>
#include <QGraphicsDropShadowEffect>
#include "Map.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"
#include <QPainterPath>
#include <QButtonGroup>
#include <vector>
#include <QStyleFactory>
#include <QTimer>
#include "SerialPortCreator.h"
#include "PlotWidgetController.h"
#include "DataType.h"
#include "DataSeries.h"

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
    DataSeries series1 (TEMPERATURE_IN);
    PlotWidgetController(ui->widget_graph1, &series1, ui->label_title_graph1);
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
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
}

void MainWindow::timerSlot() {
    if (*serialPort == ISerialPort::SERIAL_PORT_OPENED) {
        std::vector<uint8_t> data = serialPort->receive();
        parser.parseLine(data);
    }
}
