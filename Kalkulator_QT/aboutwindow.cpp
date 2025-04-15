#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QFontDatabase>

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    int fontID = QFontDatabase::addApplicationFont ( ":/Font/resources/SF-Pro-Rounded-Regular.otf" );
    QString family = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont appleFont(family);
    ui->label_title->setFont(appleFont);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
