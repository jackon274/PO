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

QString sidebarTextStyleSelected = R"(color: #5C2D91;)";
QString sidebarTextStyleUnselected = R"(color: rgb(0,0,0);)";

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
    sidebarButtons.push_back(ui->btn_stats);
    sidebarButtons.push_back(ui->btn_graph);
    sidebarButtons.push_back(ui->btn_info);
    sidebarButtons.push_back(ui->btn_settings);

    sidebarButtonLabels.push_back(ui->label_map);
    sidebarButtonLabels.push_back(ui->label_stats);
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

void MainWindow::highlightSelectedButtonLabel(int index) {
    for(auto label:sidebarButtonLabels)
        label->setStyleSheet(sidebarTextStyleUnselected);
    sidebarButtonLabels.at(index)->setStyleSheet(sidebarTextStyleSelected);
}

void MainWindow::on_btn_connect_clicked() {
    ConnectionWindow window(serialPortManager);
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

void MainWindow::on_btn_info_clicked() {
    ui->widget_content->setCurrentIndex(3);
    highlightSelectedButtonLabel(3);

}

void MainWindow::on_btn_settings_clicked() {
    ui->widget_content->setCurrentIndex(4);
    highlightSelectedButtonLabel(4);
}