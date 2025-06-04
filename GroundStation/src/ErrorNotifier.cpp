//
// Created by Jacek Konderak on 04/06/2025.
//

#include "ErrorNotifier.h"
#include <QSystemTrayIcon>

void ErrorNotifier::notify(ErrorCode code) {
    QString komunikat;
    static QSystemTrayIcon trayIcon;
    if (!trayIcon.isVisible()) {
        trayIcon.setIcon(QIcon::fromTheme("dialog-information"));
        trayIcon.setVisible(true);
    }


    switch (code) {
        case PORT_OPEN_FAILED:
        komunikat = QString::fromStdString(errorOpenPort);
            break;
        case TERMIOS_GET_ATTRIBUTES_FAILED:
            komunikat = QString::fromStdString(errorTermiosGetAttributes);
        break;
        case TERMIOS_SET_ATTRIBUTES_FAILED:
            komunikat = QString::fromStdString(errorTermiosSetAttributes);
        break;
        case FILE_OPEN_FAILED:
            komunikat = QString::fromStdString(errorFileOpen);
        break;
        default:
            komunikat = QString::fromStdString(errorUnknown);
        break;
    }
    trayIcon.showMessage(QString::fromStdString(messageBoxTitle), komunikat, QSystemTrayIcon::Critical, 3000);
}
