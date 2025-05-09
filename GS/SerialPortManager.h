//
// Created by Jacek Konderak on 08/05/2025.
//

#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H
#include <vector>
#include "SerialPort.h"


class SerialPortManager {
    std::vector <SerialPort *> availableSerialPorts;
    int baudRate;
    SerialPort *openPort;
public:
    void checkAvailableSerialPorts();
    std::vector <SerialPort *> getAvailableSerialPorts();
    int open(SerialPort *port);
    int close(SerialPort *port);
    SerialPortManager();
    ~SerialPortManager();
};



#endif //SERIALPORTMANAGER_H
