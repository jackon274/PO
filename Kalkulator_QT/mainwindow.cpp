#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "kalkulator.h"
Kalkulator calculator;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->display_sign->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_AC_clicked()
{
    calculator.clearDisplayVal();
    ui->display->display(calculator.getDisplayVal());
}

void MainWindow::on_btn_1_clicked()
{
    calculator.numberButtonPressed(1);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_2_clicked()
{
    calculator.numberButtonPressed(2);
    ui->display->display(calculator.getDisplayVal());
}

void MainWindow::on_btn_3_clicked()
{
    calculator.numberButtonPressed(3);
    ui->display->display(calculator.getDisplayVal());
}




void MainWindow::on_btn_4_clicked()
{
    calculator.numberButtonPressed(4);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_5_clicked()
{
    calculator.numberButtonPressed(5);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_6_clicked()
{
    calculator.numberButtonPressed(6);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_7_clicked()
{
    calculator.numberButtonPressed(7);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_8_clicked()
{
    calculator.numberButtonPressed(8);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_9_clicked()
{
    calculator.numberButtonPressed(9);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_0_clicked()
{
    calculator.numberButtonPressed(0);
    ui->display->display(calculator.getDisplayVal());
}


void MainWindow::on_btn_add_clicked()
{
    ui->display->display("");
    //dodać do jakiejś tymczasowej pamięci
}


void MainWindow::on_btn_subtract_clicked()
{
    ui->display_sign->setVisible(true);
    ui->display_sign->display("-");
}

