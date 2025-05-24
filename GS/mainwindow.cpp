#include "mainwindow.h"

#include <QWebEngineView>
#include "Map.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"
#include <QPainterPath>
#include <QButtonGroup>
#include <vector>

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPainterPath path;
    path.addRoundedRect(ui->map->rect(), 10, 10);
    ui->map->setMask(QRegion(path.toFillPolygon().toPolygon()));
    Map map(ui->map);

    ui->widget_sidebar_labels->setVisible(false);
    QButtonGroup *group = new QButtonGroup;

    sidebarButtons.push_back(ui->btn_map);
    sidebarButtons.push_back(ui->btn_graph);
    sidebarButtons.push_back(ui->btn_info);
    sidebarButtons.push_back(ui->btn_settings);

    sidebarButtonLabels.push_back(ui->label_menu);
    sidebarButtonLabels.push_back(ui->label_3);
    sidebarButtonLabels.push_back(ui->label_map);
    sidebarButtonLabels.push_back(ui->label_graph);
    sidebarButtonLabels.push_back(ui->label_info);
    sidebarButtonLabels.push_back(ui->label_settings);


    for (auto button:sidebarButtons) {
        group->addButton(button);
        button->setCheckable(true);
        button->setStyleSheet(sidebarButtonStyle);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
SerialPortManager serialPortManager;

void MainWindow::on_btn_connect_clicked() {
    ConnectionWindow window(serialPortManager);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_btn_info_clicked() {

}

void MainWindow::on_btn_menu_toggled(bool checked)
{
    for (auto label:sidebarButtonLabels) {
        ui->widget_sidebar_labels->setVisible(checked);
    }
}

