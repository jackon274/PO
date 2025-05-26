#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QDialog>
#include "SerialPortManager.h"
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectionWindow;
}
QT_END_NAMESPACE

class ConnectionWindow : public QDialog
{
    Q_OBJECT
    SerialPortManager &serialPortManager;
public:
    explicit ConnectionWindow(SerialPortManager &manager, QWidget *parent = nullptr);
    ~ConnectionWindow();

    signals:
    void signalSerialPortConnected() const;

private slots:
    void on_btn_refresh_clicked();


    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void on_btn_read_clicked();

private:
    Ui::ConnectionWindow *ui;
};
#endif // CONNECTIONWINDOW_H
