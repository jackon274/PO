#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "kalkulator.h"
#include <iostream>
#include <QFontDatabase>
#include "aboutwindow.h"
#include "convertsystems.h"

Kalkulator calculator;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_sign->setVisible(false);

    int fontID = QFontDatabase::addApplicationFont ( ":/Font/resources/SF-Pro-Rounded-Regular.otf" );
    QString family = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont appleFontButtons(family);
    ui->btn_add->setFont(appleFontButtons);
    ui->btn_multiply->setFont(appleFontButtons);
    ui->btn_equals->setFont(appleFontButtons);
    ui->btn_subtract->setFont(appleFontButtons);
    ui->btn_div->setFont(appleFontButtons);
    ui->btn_percent->setFont(appleFontButtons);
    ui->btn_0->setFont(appleFontButtons);
    ui->btn_1->setFont(appleFontButtons);
    ui->btn_2->setFont(appleFontButtons);
    ui->btn_3->setFont(appleFontButtons);
    ui->btn_4->setFont(appleFontButtons);
    ui->btn_5->setFont(appleFontButtons);
    ui->btn_6->setFont(appleFontButtons);
    ui->btn_7->setFont(appleFontButtons);
    ui->btn_8->setFont(appleFontButtons);
    ui->btn_9->setFont(appleFontButtons);
    ui->btn_comma->setFont(appleFontButtons);
    ui->btn_AC->setFont(appleFontButtons);
    ui->btn_sqrt->setFont(appleFontButtons);
    ui->menubar->setStyleSheet ("QMenu { background-color: #444; color: white; } QMenu::item:selected { background-color:  rgb(74, 73, 77);}QMenuBar { background-color: #000000; color: white;} QMenuBar::item:selected { background-color:  rgb(74, 73, 77);}");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateDisplay() {
    ui->display->display(calculator.updateDisplayHelper());
}

void MainWindow::on_btn_AC_clicked()
{
    calculator.clearResult();
    updateDisplay();
}

void MainWindow::on_btn_1_clicked()
{
    calculator.handleButtonClick('1');
    updateDisplay();
}


void MainWindow::on_btn_2_clicked()
{
    calculator.handleButtonClick('2');
    updateDisplay();
}

void MainWindow::on_btn_3_clicked()
{
    calculator.handleButtonClick('3');
    updateDisplay();
}


void MainWindow::on_btn_4_clicked()
{
    calculator.handleButtonClick('4');
    updateDisplay();
 }


void MainWindow::on_btn_5_clicked()
{
    calculator.handleButtonClick('5');
    updateDisplay();
}


void MainWindow::on_btn_6_clicked()
{
    calculator.handleButtonClick('6');
    updateDisplay();
}


void MainWindow::on_btn_7_clicked()
{
    calculator.handleButtonClick('7');
    updateDisplay();
}


void MainWindow::on_btn_8_clicked()
{
    calculator.handleButtonClick('8');
    updateDisplay();
}


void MainWindow::on_btn_9_clicked()
{
    calculator.handleButtonClick('9');
    updateDisplay();
}


void MainWindow::on_btn_0_clicked()
{
    calculator.handleButtonClick('0');
    updateDisplay();

}


void MainWindow::on_btn_add_clicked()
{
    ui->label_sign->setVisible(true);
    ui->label_sign->setText("+");
    calculator.handleButtonClick('+');
}


void MainWindow::on_btn_subtract_clicked()
{
    ui->label_sign->setVisible(true);
    ui->label_sign->setText("-");
    calculator.handleButtonClick('-');
}


void MainWindow::on_btn_equals_clicked()
{
    ui->label_sign->setVisible(false);
    calculator.handleStream();
    ui->display->display(calculator.getMemoryVal());


}


void MainWindow::on_btn_multiply_clicked()
{
    ui->label_sign->setVisible(true);
    ui->label_sign->setText("x");
    calculator.handleButtonClick('*');
}


void MainWindow::on_btn_comma_clicked()
{
    calculator.handleButtonClick('.');
}


void MainWindow::on_btn_div_clicked()
{
    ui->label_sign->setVisible(true);
    ui->label_sign->setText("÷");
    calculator.handleButtonClick('/');
}


void MainWindow::on_btn_sqrt_clicked()
{
    calculator.handleButtonClick('$');
    calculator.handleStream();
    ui->display->display(calculator.getMemoryVal());
}

void MainWindow::on_action_about_triggered() {
    AboutWindow about;
    about.setModal(true);
    about.exec();
}



void MainWindow::on_btn_mode_clicked()
{
    ConvertSystems convertWindow;
    convertWindow.setModal(true);
    convertWindow.exec();
}


void MainWindow::on_btn_percent_clicked()
{
    ui->label_sign->setVisible(true);
    ui->label_sign->setText("%");
    calculator.handleButtonClick('%');
}

