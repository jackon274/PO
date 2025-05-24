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
        color: blue;
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
    QButtonGroup *group = new QButtonGroup;
    std::vector <QPushButton *> sidebarButtons;
    sidebarButtons.push_back(ui->btn_map);
    sidebarButtons.push_back(ui->btn_map);
    sidebarButtons.push_back(ui->btn_graph);
    sidebarButtons.push_back(ui->btn_info);
    sidebarButtons.push_back(ui->btn_settings);

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
