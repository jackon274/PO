#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QFontDatabase>
#include <iostream>

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    ui->noclick2->setVisible(false);

    int fontID = QFontDatabase::addApplicationFont ( ":/Font/resources/SF-Pro-Rounded-Regular.otf" );
    QString family = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont appleFontBig(family);
    appleFontBig.setPointSize(20);
    ui->label->setFont(appleFontBig);
    QFont appleFontSmall(family);
    appleFontSmall.setPointSize(10);
    ui->label_name->setFont(appleFontSmall);
    ui->label_author->setFont(appleFontSmall);
    ui->label_index->setFont(appleFontSmall);


}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_noclick1_clicked()
{
    ui->noclick1->setVisible(false);
    ui->noclick2->setVisible(true);
}

