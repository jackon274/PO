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

QString sidebarButtonStyle = R"(
    QPushButton {

    }
    QPushButton:checked {
        color: #5C2D91;
    }
    QPushButton:hover {
        color:#7D57A7;
    }
)";

QString sidebarTextStyleSelected = R"(color: #5C2D91; font-weight: bold;)";
QString sidebarTextStyleUnselected = R"(color: rgb(0,0,0); font-weight: normal;)";

MainWindow::MainWindow(QTranslator *ptrTranslator, QApplication *ptrApp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    window (serialPort = createSerialPort()),
    translator(ptrTranslator),
    application(ptrApp)
{
    ui->setupUi(this);
    QPainterPath path;
    path.addRoundedRect(ui->map->rect(), 10, 10);
    ui->map->setMask(QRegion(path.toFillPolygon().toPolygon()));
    Map map(ui->map);

    connect (&window, &ConnectionWindow::signalSerialPortConnected, this, &MainWindow::SerialPortConnected);

    ui->widget_sidebar_labels->setVisible(false);
    sidebarButtonsGroup = new QButtonGroup;

    sidebarButtons.push_back(ui->btn_map);
    sidebarButtons.push_back(ui->btn_stats);
    sidebarButtons.push_back(ui->btn_graph);
    sidebarButtons.push_back(ui->btn_config);
    sidebarButtons.push_back(ui->btn_info);
    sidebarButtons.push_back(ui->btn_settings);

    sidebarButtonLabels.push_back(ui->label_map);
    sidebarButtonLabels.push_back(ui->label_stats);
    sidebarButtonLabels.push_back(ui->label_graph);
    sidebarButtonLabels.push_back(ui->label_config);
    sidebarButtonLabels.push_back(ui->label_info);
    sidebarButtonLabels.push_back(ui->label_settings);


    for (auto button:sidebarButtons) {
        sidebarButtonsGroup->addButton(button);
        button->setCheckable(true);
        button->setStyleSheet(sidebarButtonStyle);
    }
    int startPage = ui->widget_content->currentIndex();
    sidebarButtons.at(startPage)->setChecked(true);
    highlightSelectedButtonLabel(startPage);
    ui->label_connection_status->setText("");

    ui->box_languages->addItem(tr("Polish"), "pl");
    ui->box_languages->addItem(tr("English"), "en");
    ui->box_languages->setStyle(QStyleFactory::create("Fusion"));

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete sidebarButtonsGroup;
    delete ui;
}

void MainWindow::SerialPortConnected() const {
    ui->label_serial_port_name->setText(QString::fromStdString(serialPort->getOpenSerialPort()));
    ui->label_connection_status->setText("");
}

void MainWindow::highlightSelectedButtonLabel(int index) {
    for(auto label:sidebarButtonLabels)
        label->setStyleSheet(sidebarTextStyleUnselected);
    sidebarButtonLabels.at(index)->setStyleSheet(sidebarTextStyleSelected);
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
    highlightSelectedButtonLabel(0);
}

void MainWindow::on_btn_stats_clicked() {
    ui->widget_content->setCurrentIndex(1);
    highlightSelectedButtonLabel(1);
}

void MainWindow::on_btn_graph_clicked() {
    ui->widget_content->setCurrentIndex(2);
    highlightSelectedButtonLabel(2);
}

void MainWindow::on_btn_config_clicked() {
    ui->widget_content->setCurrentIndex(3);
    highlightSelectedButtonLabel(3);
}

void MainWindow::on_btn_info_clicked() {
    ui->widget_content->setCurrentIndex(4);
    highlightSelectedButtonLabel(4);

}

void MainWindow::on_btn_settings_clicked() {
    ui->widget_content->setCurrentIndex(5);
    highlightSelectedButtonLabel(5);
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
