#include "EasterEggWindow.h"
#include "ui_EasterEggWindow.h"
#include <QFontDatabase>
#include <QDesktopServices>
#include <iostream>

EasterEggWindow::EasterEggWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EasterEggWindow)
{
    ui->setupUi(this);
    ui->noclick2->setVisible(false);

    int fontID = QFontDatabase::addApplicationFont ( ":/Font/resources/SF-Pro-Rounded-Regular.otf" );
    QString family = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont appleFontBig(family);
    appleFontBig.setPointSize(20);
    ui->label->setFont(appleFontBig);
    QFont appleFontSmall(family);
    appleFontSmall.setPointSize(12);
    ui->label_name->setFont(appleFontSmall);
    ui->label_author->setFont(appleFontSmall);
}

EasterEggWindow::~EasterEggWindow()
{
    delete ui;
}

void EasterEggWindow::on_noclick1_clicked()
{
    ui->noclick1->setVisible(false);
    ui->noclick2->setVisible(true);
}


void EasterEggWindow::on_noclick2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://youtu.be/oavMtUWDBTM", QUrl::TolerantMode));
}

