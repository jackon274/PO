#ifndef EASTEREGGWINDOW_H
#define EASTEREGGWINDOW_H

#include <QDialog>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private slots:
    void on_noclick1_clicked();

    void on_noclick2_clicked();

private:
    Ui::AboutWindow *ui;
};

#endif // EASTEREGGWINDOW_H
