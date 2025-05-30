#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_1_clicked();

    void on_btn_AC_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_add_clicked();

    void on_btn_subtract_clicked();

    void on_btn_equals_clicked();

    void on_btn_multiply_clicked();

    void on_btn_comma_clicked();

    void updateDisplay();

    void on_btn_div_clicked();

    void on_btn_sqrt_clicked();

    void on_action_about_triggered();

    void on_btn_mode_clicked();

    void on_btn_percent_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
