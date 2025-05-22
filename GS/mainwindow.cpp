#include "mainwindow.h"

#include <QWebEngineView>
#include "Map.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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



