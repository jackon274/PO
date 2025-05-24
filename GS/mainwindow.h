#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "SerialPortManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void highlightSelectedButtonLabel(int index);

    void on_btn_connect_clicked();

    void on_btn_info_clicked();

    void on_btn_menu_toggled(bool checked);

    void on_btn_map_clicked();

    void on_btn_stats_clicked();

    void on_btn_graph_clicked();

    void on_btn_settings_clicked();

    void on_btn_config_clicked();

private:
    Ui::MainWindow *ui;
    std::vector <QPushButton *> sidebarButtons;
    std::vector <QLabel *> sidebarButtonLabels;
    SerialPortManager serialPortManager;
};

#endif // MAINWINDOW_H
