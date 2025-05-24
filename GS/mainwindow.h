#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_connect_clicked();

    void on_btn_info_clicked();

    void on_btn_menu_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    std::vector <QPushButton *> sidebarButtons;
    std::vector <QLabel *> sidebarButtonLabels;
};

#endif // MAINWINDOW_H
