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



void UARTConnectionTest(UnixSerialPortManager &serialPortManager) {
   fmt::println("Wykryto {} portów!", serialPortManager.availableSerialPorts.size());
   if(serialPortManager.openPort != nullptr)
      fmt::println("Wybrano port {} ", serialPortManager.openPort->getDisplayName());
}

void UARTReceiveTest(UnixSerialPortManager &serialPortManager) {
    std::vector<uint8_t> data = serialPortManager.receive();

    if (!data.empty()) {
        std::string text(data.begin(), data.end());
        fmt::println("Received text: {}", text); //
        fmt::print("Received {} bytes: ", data.size());

        for (uint8_t byte : data) {
            std::cout << std::hex << std::uppercase << std::setw(2)
                      << std::setfill('0') << static_cast<int>(byte) << " ";
        }
        std::cout << std::dec << std::endl;  // Reset to decimal
    }
}
