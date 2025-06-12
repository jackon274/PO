//
// Created by Jacek Konderak on 08/05/2025.
//

#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include "ISerialPort.h"


class UnixSerialPortManager :public ISerialPort {
    #ifdef __APPLE__
        std::string serialPortPath = "cu.";
        std::string serialPortPathVirtual = "ttys";
    #endif
    #ifdef __linux__
    std::string serialPortPath = "tty";
    std::string serialPortPathVirtual = "pts";
    #endif
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
    friend void UARTConnectionTest(UnixSerialPortManager &serialPortManager);

    UnixSerialPortManager();
    ~UnixSerialPortManager();
};



#endif //SERIALPORTMANAGER_H
