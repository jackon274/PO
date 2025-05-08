//
// Created by Jacek Konderak on 06/05/2025.
//

#include "SerialPort.h"
#include <iostream>
#include <vector>
#include <string>

SerialPort::SerialPort(const std::string& name) {
    portName = name;
    displayName = name;
}

SerialPort::SerialPort(const std::string& name, const std::string& dispName) {
    portName = name;
    displayName = dispName;
}
