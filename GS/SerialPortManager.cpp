//
// Created by Jacek Konderak on 08/05/2025.
//

#include "SerialPortManager.h"
#include "SerialPort.h"

#ifdef __APPLE__

#include <dirent.h>
#include <sys/stat.h>

void SerialPortManager::checkAvailableSerialPorts() {
    const std::string devPath = "/dev/";
    std::vector<SerialPort *> serialPorts;

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
                serialPorts.push_back(new SerialPort(fullPath));
            }
        }
    }

    closedir(dir);
    availableSerialPorts = serialPorts;
}


#endif

#ifdef _WIN32
#include <windows.h>
std::vector<SerialPort *> serialPorts;
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

void SerialPortManager::checkAvailableSerialPorts() {
    for (int i = 1; i <= 256; ++i) {
        std::string portName = "\\\\.\\COM" + std::to_string(i);
        if (isPortAvailable(portName)) {
            serialPorts.push_back(new SerialPort(portName));
        }
    }
    availableSerialPorts = serialPorts;
}
#endif
std::vector <SerialPort *> SerialPortManager::getAvailableSerialPorts() {
    return availableSerialPorts;
}

SerialPortManager::SerialPortManager() {
    checkAvailableSerialPorts();
}

SerialPortManager::~SerialPortManager() {
    for (auto port:availableSerialPorts)
        delete port;
}
