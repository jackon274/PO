//
// Created by Jacek Konderak on 06/05/2025.
//

#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <vector>
#include <string>
#include <QMetaType>



class SerialPort {
    int serialPortFd;
    std::string portName;
    std::string displayName;
public:
    explicit SerialPort(const std::string& name);
    SerialPort(const std::string& name, const std::string& dispName);
    std::string &getDisplayName();
    std::string &getPortName();
    int getSerialPortFd();
    void setSerialPortFd(int fd);
};

Q_DECLARE_METATYPE(SerialPort*)

#endif //SERIALPORT_H
