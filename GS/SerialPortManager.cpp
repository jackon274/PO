//
// Created by Jacek Konderak on 08/05/2025.
//

#include "SerialPortManager.h"
#include "SerialPort.h"
#include <iostream>

#ifdef __APPLE__

#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


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
        if (name.find("cu.") == 0 || name.find("ttys") == 0) {
            std::string fullPath = devPath + name;
            struct stat st;
            if (stat(fullPath.c_str(), &st) == 0 && S_ISCHR(st.st_mode)) {
                serialPorts.push_back(new SerialPort(fullPath));
            }
        }
    }

    closedir(dir);
    for(auto  port:availableSerialPorts)
        delete port;
    availableSerialPorts = serialPorts;
}



int SerialPortManager::open(SerialPort *port) {
    int serialPortFd = ::open(port->portName.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

    if(serialPortFd < 0)
        std::cerr << "Error opening serial port";

    struct termios options;
    memset(&options, 0, sizeof options);

    if (tcgetattr(serialPortFd, &options) != 0) {
        std::cerr << "Error getting termios attributes: " << strerror(errno) << std::endl;
        ::close(serialPortFd);
        return -1;
    }

    // Configure baud rate
    switch(baudRate) {
        case 9600:
            cfsetospeed(&options, B9600);
            cfsetispeed(&options, B9600);
        break;
        case 19200:
            cfsetospeed(&options, B19200);
            cfsetispeed(&options, B19200);
        break;
        case 38400:
            cfsetospeed(&options, B38400);
            cfsetispeed(&options, B38400);
        break;
        case 57600:
            cfsetospeed(&options, B57600);
            cfsetispeed(&options, B57600);
        break;
        case 115200:
            cfsetospeed(&options, B115200);
            cfsetispeed(&options, B115200);
        break;
    }


    // 8N1 Mode (8 data bits, no parity, 1 stop bit)
    options.c_cflag &= ~PARENB;            // Clear parity bit, disabling parity (no parity)
    options.c_cflag &= ~CSTOPB;            // Clear stop field (only one stop bit)
    options.c_cflag &= ~CSIZE;             // Clear all bits that set the data size
    options.c_cflag |= CS8;                // 8 bits per byte
    options.c_cflag &= ~CRTSCTS;           // Disable RTS/CTS hardware flow control
    options.c_cflag |= CREAD | CLOCAL;     // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    // Make raw
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    options.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)

    // Set in non-blocking read
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 10; // 1 second read timeout

    // Save tty settings, checking for error
    if (tcsetattr(serialPortFd, TCSANOW, &options) != 0) {
        std::cerr << "Error setting termios attributes: " << strerror(errno) << std::endl;
        ::close(serialPortFd);
        return -1;
    }
    openPort = port;
    port->serialPortFd = serialPortFd;
    return serialPortFd;
}


int SerialPortManager::close() {
    //do sth;
    return 0;
}

const std::string &SerialPortManager::getOpenSerialPort() const{
    return openPort->displayName;
}

int SerialPortManager::getSerialPortState() const{
    if(openPort == nullptr)
        return 0;
    return 1;
}

std::vector<uint8_t> SerialPortManager::uartReceive() {
    if (!openPort) {
        std::cerr << "Error: openPort is null in uartReceive().\n";
        return {};
    }
    int maxBytes = 256;
    std::vector<uint8_t> buffer(maxBytes);

    ssize_t bytesRead = read(openPort->serialPortFd, buffer.data(), maxBytes);
    if (bytesRead < 0) {
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            perror("UART read error");
        }
        return {}; // return empty vector on error
    }

    buffer.resize(bytesRead); // shrink to actual size
    return buffer;
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
            serialPorts.push_back(new SerialPort(portName, ("COM" + std::to_string(i) ) ) );
        }
    }
    for(auto  port:availableSerialPorts)
        delete port;
    availableSerialPorts = serialPorts;
}
#endif
std::vector <SerialPort *> SerialPortManager::getAvailableSerialPorts() {
    return availableSerialPorts;
}

void SerialPortManager::setBaudRate(int newBaudRate) {
    baudRate = newBaudRate;
}

SerialPortManager::SerialPortManager() {
    checkAvailableSerialPorts();
}

SerialPortManager::~SerialPortManager() {
    for (auto port:availableSerialPorts)
        delete port;
    close();
    openPort = nullptr;
}
