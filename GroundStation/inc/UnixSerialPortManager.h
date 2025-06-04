//
// Created by Jacek Konderak on 08/05/2025.
//

#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include "ISerialPort.h"


class UnixSerialPortManager :public ISerialPort {
public:
    std::vector <SerialPort *> getAvailableSerialPorts() override;
    void checkAvailableSerialPorts() override;
    void setBaudRate(int newBaudRate);
    int open(SerialPort *port);
    int close();
    int send(const std::string &message);
    std::vector <uint8_t> receive();
    const std::string &getOpenSerialPort() const;
    bool getSerialPortState() const;

    bool operator== (SerialPortState state) const override;

    UnixSerialPortManager();
    ~UnixSerialPortManager();
};



#endif //SERIALPORTMANAGER_H
