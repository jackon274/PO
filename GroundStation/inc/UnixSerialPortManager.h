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
    void setBaudRate(int newBaudRate) override;
    int open(SerialPort *port) override;
    int close() override;
    int send(const std::string &message) override;
    std::vector <uint8_t> receive() override;
    const std::string &getOpenSerialPort() const override;
    bool getSerialPortState() const override;

    bool operator== (SerialPortState state) const override;

    UnixSerialPortManager();
    ~UnixSerialPortManager();
};



#endif //SERIALPORTMANAGER_H
