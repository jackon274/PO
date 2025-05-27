#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>

#include "SerialPortManager.h"
#include "connectionwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTranslator *translator;

public:
    explicit MainWindow(QTranslator *ptrTranslator, QWidget *parent = nullptr);
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

private:
    Ui::MainWindow *ui;
    std::vector <QPushButton *> sidebarButtons;
    std::vector <QLabel *> sidebarButtonLabels;
    QButtonGroup *sidebarButtonsGroup;
    SerialPortManager serialPortManager;
    ConnectionWindow window;
};

#endif // MAINWINDOW_H
