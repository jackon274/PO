//
// Created by Jacek Konderak on 06/05/2025.
//

#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <vector>



class SerialPort {
    std::vector <std::string> availableSerialPorts;
public:
    void checkAvailableSerialPorts();
    std::vector <std::string> getAvailableSerialPorts();
};



#endif //SERIALPORT_H
