//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef ISERIALPORT_H
#define ISERIALPORT_H

#include <vector>
#include "SerialPort.h"

class ISerialPort {
protected:
    std::vector <SerialPort *> availableSerialPorts;
    int baudRate;
    SerialPort *openPort;
    FILE * fileUART = nullptr;
    virtual bool getSerialPortState() const = 0;

public:
    virtual void checkAvailableSerialPorts() = 0;
    virtual std::vector <SerialPort *> getAvailableSerialPorts() = 0;
    virtual void setBaudRate(int newBaudRate) = 0;
    virtual int open(SerialPort *port) = 0;
    virtual int close() = 0;
    virtual int send(const std::string &message) = 0;
    virtual std::vector <uint8_t> receive() = 0;
    virtual const std::string &getOpenSerialPort() const = 0;


    enum SerialPortState {
        SERIAL_PORT_OPENED,
        SERIAL_PORT_CLOSED
    };
    virtual bool operator== (SerialPortState state) const = 0;
};



#endif //ISERIALPORT_H
