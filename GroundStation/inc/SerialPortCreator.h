//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef SERIALPORTCREATOR_H
#define SERIALPORTCREATOR_H

#include "ISerialPort.h"

#if defined(__APPLE__) || defined(__linux__)
#include "UnixSerialPortManager.h"
#endif




ISerialPort* createSerialPort() {
#if defined(__APPLE__) || defined(__linux__)
    return new UnixSerialPortManager();
#endif
};


#endif //SERIALPORTCREATOR_H
