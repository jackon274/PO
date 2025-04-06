#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_AC_clicked()
{
    ui->display->display(0);
}

void MainWindow::on_btn_1_clicked()
{
    ui->display->display(1);
}


void MainWindow::on_btn_2_clicked()
{
    ui->display->display(2);
}

void MainWindow::on_btn_3_clicked()
{
    ui->display->display(3);
}




void MainWindow::on_btn_4_clicked()
{
    ui->display->display(4);
}


void MainWindow::on_btn_5_clicked()
{
    ui->display->display(5);
}


void MainWindow::on_btn_6_clicked()
{
    ui->display->display(6);
}


void MainWindow::on_btn_7_clicked()
{
    ui->display->display(7);
}


void MainWindow::on_btn_8_clicked()
{
    ui->display->display(8);
}


void MainWindow::on_btn_9_clicked()
{
    ui->display->display(9);
}


void MainWindow::on_btn_0_clicked()
{
    ui->display->display(0);
}

