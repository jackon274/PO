#ifndef EASTEREGGWINDOW_H
#define EASTEREGGWINDOW_H

#include <QDialog>

namespace Ui {
class EasterEggWindow;
}

class EasterEggWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EasterEggWindow(QWidget *parent = nullptr);
    ~EasterEggWindow();

private slots:
    void on_noclick1_clicked();

    void on_noclick2_clicked();

private:
    Ui::EasterEggWindow *ui;
};

#endif // EASTEREGGWINDOW_H
