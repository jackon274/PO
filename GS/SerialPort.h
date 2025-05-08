//
// Created by Jacek Konderak on 06/05/2025.
//

#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <vector>
#include <string>


class SerialPort {
public:
    std::string portName;
    explicit SerialPort(const std::string& name);
};



#endif //SERIALPORT_H
