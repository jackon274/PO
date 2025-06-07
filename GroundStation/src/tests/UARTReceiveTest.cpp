//
// Created by Jacek Konderak on 07/06/2025.
//
#include <iomanip>
#include <vector>
#include <iostream>
//#include <ISerialPort.h>

#include "fmt/base.h"
#include "UARTReceiveTest.h"
#include "UnixSerialPortManager.h"



void UARTReceiveTest(UnixSerialPortManager &serialPortManager) {
   fmt::println("Wykryto {} portów!", serialPortManager.availableSerialPorts.size());
   if(serialPortManager.openPort != nullptr)
      fmt::println("Wybrano port {} ", serialPortManager.openPort->displayName);
}

