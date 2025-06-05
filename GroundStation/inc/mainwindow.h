#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>

#include "ISerialPort.h"
#include "connectionwindow.h"

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

    void highlightSelectedButtonLabel(int index);

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

private:
    Ui::MainWindow *ui;
    std::vector <QPushButton *> sidebarButtons;
    std::vector <QLabel *> sidebarButtonLabels;
    QButtonGroup *sidebarButtonsGroup;
    ISerialPort *serialPort;
    ConnectionWindow window;
    QTranslator *translator;
    QApplication *application;
};

#endif // MAINWINDOW_H
