#include "mainwindow.h"

#include <QWebEngineView>
#include "Map.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"
#include <QPainterPath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPainterPath path;
    path.addRoundedRect(ui->map->rect(), 10, 10);
    ui->map->setMask(QRegion(path.toFillPolygon().toPolygon()));
    Map map(ui->map);
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



