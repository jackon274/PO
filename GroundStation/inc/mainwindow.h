#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>
#include "UIStyler.h"
#include "ISerialPort.h"
#include "connectionwindow.h"
#include "PlotWidgetView.h"
#include "DataDisplayController.h"
#include "Map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QTranslator *ptrTranslator, QApplication *ptrApp, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void SerialPortConnected() const;
    void SerialPortDisconnected() const;

    void on_btn_connect_clicked();

    void on_btn_info_clicked();

    void on_btn_menu_toggled(bool checked);

    void on_btn_map_clicked();

    void on_btn_stats_clicked();

    void on_btn_graph_clicked();

    void on_btn_settings_clicked();

    void on_btn_config_clicked();

    void on_box_languages_currentIndexChanged(int index);

    void on_btn_testmode_clicked();

    void on_btn_configuration_clicked();

    void on_btn_rx_mode_clicked();

    void timerSlot();

    void on_box_graph1_currentIndexChanged(int index);

    void on_box_graph2_activated(int index);

    void on_box_graph3_activated(int index);

    void on_box_graph4_activated(int index);

    void on_btn_tx_mode_clicked();

    void on_btn_buzz_clicked();

    void on_btn_light_on_clicked();

    void on_btn_light_off_clicked();

    void on_box_units_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    UIStyler styler;
    ISerialPort *serialPort;
    ConnectionWindow window;
    QTranslator *translator;
    QApplication *application;
    UARTParser parser;
    DataFrameParser dfParser;
    DataDisplayController controller;
    Map *map = nullptr;
};

#endif // MAINWINDOW_H
