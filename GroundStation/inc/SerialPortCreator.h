//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef SERIALPORTCREATOR_H
#define SERIALPORTCREATOR_H

#include "ISerialPort.h"

#ifdef __APPLE__
#include "UnixSerialPortManager.h"
#endif




ISerialPort* createSerialPort() {
#ifdef __APPLE__
    return new UnixSerialPortManager();
#endif
};


#endif //SERIALPORTCREATOR_H
