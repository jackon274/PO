#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectionwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked() {
    ConnectionWindow window;
    window.setModal(true);
    window.exec();
}



