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
    QFont appleFontBig(family);
    appleFontBig.setPixelSize(25);
    ui->label_title->setFont(appleFontBig);
    ui->label_title->setAlignment(Qt::AlignCenter);

    QFont appleFontMedium(family);
    appleFontMedium.setPixelSize(18);
    ui->label_name->setFont(appleFontMedium);
    ui->label_index->setFont(appleFontMedium);

    QFont appleFontSmall(family);
    appleFontMedium.setPixelSize(11);
    ui->label_copyright->setFont(appleFontSmall);
    ui->label_compilation->setFont(appleFontSmall);


}

AboutWindow::~AboutWindow()
{
    delete ui;
}
