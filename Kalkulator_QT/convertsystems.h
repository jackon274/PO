#ifndef CONVERTSYSTEMS_H
#define CONVERTSYSTEMS_H

#include <QDialog>

namespace Ui {
class ConvertSystems;
}

class ConvertSystems : public QDialog
{
    Q_OBJECT

public:
    explicit ConvertSystems(QWidget *parent = nullptr);
    ~ConvertSystems();

private slots:
    void on_btn_convert_clicked();

private:
    Ui::ConvertSystems *ui;
};

#endif // CONVERTSYSTEMS_H
