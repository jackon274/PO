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
    FILE * fileUART;
public:
    std::vector <SerialPort *> getAvailableSerialPorts();
    void checkAvailableSerialPorts();
    void setBaudRate(int newBaudRate);
    int open(SerialPort *port);
    int close();
    int send(const std::string &message);
    std::vector <uint8_t> receive();
    const std::string &getOpenSerialPort() const;
    int getSerialPortState() const;

    SerialPortManager();
    ~SerialPortManager();
};



#endif //SERIALPORTMANAGER_H
