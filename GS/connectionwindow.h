#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectionWindow;
}
QT_END_NAMESPACE

class ConnectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    ConnectionWindow(QWidget *parent = nullptr);
    ~ConnectionWindow();

private:
    Ui::ConnectionWindow *ui;
};
#endif // CONNECTIONWINDOW_H
