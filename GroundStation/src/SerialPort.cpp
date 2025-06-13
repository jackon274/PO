//
// Created by Jacek Konderak on 06/05/2025.
//

#include "SerialPort.h"
#include <iostream>
#include <vector>
#include <string>

#ifdef __APPLE__
    #include <fcntl.h>
    #include <termios.h>
    #include <unistd.h>
#endif


SerialPort::SerialPort(const std::string& name) {
    portName = name;
    displayName = name;
}

SerialPort::SerialPort(const std::string& name, const std::string& dispName) {
    portName = name;
    displayName = dispName;
}

std::string &SerialPort::getDisplayName() {
    return displayName;
}

std::string &SerialPort::getPortName() {
    return portName;
}

int SerialPort::getSerialPortFd() {
    return serialPortFd;
}

void SerialPort::setSerialPortFd(int fd) {
    serialPortFd = fd;
}
