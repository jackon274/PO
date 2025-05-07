//
// Created by Jacek Konderak on 06/05/2025.
//

#include "SerialPort.h"
#include <iostream>
#include <vector>
#include <string>

#ifdef __APPLE__

#include <dirent.h>
#include <sys/stat.h>

void SerialPort::checkAvailableSerialPorts() {
    const std::string devPath = "/dev/";
    std::vector<std::string> serialPorts;

    DIR* dir = opendir(devPath.c_str());
    if (!dir) {
        perror("opendir");
        availableSerialPorts = serialPorts;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;

        // Check for typical macOS serial device prefixes
        if (name.find("cu.") == 0) {
            std::string fullPath = devPath + name;
            struct stat st;
            if (stat(fullPath.c_str(), &st) == 0 && S_ISCHR(st.st_mode)) {
                serialPorts.push_back(fullPath);
            }
        }
    }

    closedir(dir);
    availableSerialPorts = serialPorts;
}


#endif

#ifdef _WIN32
#include <windows.h>

bool isPortAvailable(const std::string& portName) {
    HANDLE hComm = CreateFileA(portName.c_str(),
                               GENERIC_READ | GENERIC_WRITE,
                               0,
                               NULL,
                               OPEN_EXISTING,
                               0,
                               NULL);
    if (hComm != INVALID_HANDLE_VALUE) {
        CloseHandle(hComm);
        return true;
    } else {
        return false;
    }
}

void SerialPort::checkAvailableSerialPorts() {
    for (int i = 1; i <= 256; ++i) {
        std::string portName = "\\\\.\\COM" + std::to_string(i);
        if (isPortAvailable(portName)) {
            serialPorts.push_back(portName);
        }
    }
}
#endif
std::vector <std::string> SerialPort::getAvailableSerialPorts() {
    return availableSerialPorts;
}

SerialPort::SerialPort() {
    checkAvailableSerialPorts();
}
