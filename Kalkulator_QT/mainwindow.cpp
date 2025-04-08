#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "kalkulator.h"
#include <iostream>

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
    //calculator.numberButtonPressed(1);
    //ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 1;
    calculator.operationStream << 1;
}


void MainWindow::on_btn_2_clicked()
{
    //calculator.numberButtonPressed(2);
    //ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 2;
    calculator.operationStream << 2;
}

void MainWindow::on_btn_3_clicked()
{
    // calculator.numberButtonPressed(3);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 3;
    calculator.operationStream << 3;
}




void MainWindow::on_btn_4_clicked()
{
//     calculator.numberButtonPressed(4);
//     ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 4;
    calculator.operationStream << 4;
 }


void MainWindow::on_btn_5_clicked()
{
    // calculator.numberButtonPressed(5);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 5;
    calculator.operationStream << 5;
}


void MainWindow::on_btn_6_clicked()
{
    // calculator.numberButtonPressed(6);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 6;
    calculator.operationStream << 6;
}


void MainWindow::on_btn_7_clicked()
{
    // calculator.numberButtonPressed(7);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 7;
    calculator.operationStream << 7;
}


void MainWindow::on_btn_8_clicked()
{
    // calculator.numberButtonPressed(8);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 8;
    calculator.operationStream << 8;
}


void MainWindow::on_btn_9_clicked()
{
    // calculator.numberButtonPressed(9);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 9;
    calculator.operationStream << 9;
}


void MainWindow::on_btn_0_clicked()
{
    // calculator.numberButtonPressed(0);
    // ui->display->display(calculator.getDisplayVal());
    calculator.displayStream << 0;
    calculator.operationStream << 0;
}


void MainWindow::on_btn_add_clicked()
{
    // ui->display->display("");
    // //dodać do jakiejś tymczasowej pamięci
    calculator.operationStream << "+";
}


void MainWindow::on_btn_subtract_clicked()
{
    // ui->display_sign->setVisible(true);
    // ui->display_sign->display("-");
    calculator.operationStream << "-";
}


void MainWindow::on_btn_equals_clicked()
{
    std::cout << calculator.operationStream.str();
}


void MainWindow::on_btn_multiply_clicked()
{
    calculator.operationStream << "*";
}


void MainWindow::on_btn_comma_clicked()
{
    calculator.displayStream << ",";
    calculator.operationStream << ".";
}

