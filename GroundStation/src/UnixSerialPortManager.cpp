//
// Created by Jacek Konderak on 08/05/2025.
//

#include "UnixSerialPortManager.h"
#include "SerialPort.h"
#include <iostream>
#include "AppException.h"

#if defined (__APPLE__) || defined(__linux__)

#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void UnixSerialPortManager::checkAvailableSerialPorts() {
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

        if (name.find(serialPortPath) == 0 || name.find(serialPortPathVirtual) == 0) {
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



int UnixSerialPortManager::open(SerialPort *port) {
    int serialPortFd = ::open(port->getPortName().c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

    if(serialPortFd < 0)
        throw AppException(PORT_OPEN_FAILED);
        //std::cerr << "Error opening serial port";

    struct termios options;
    memset(&options, 0, sizeof options);

    if (tcgetattr(serialPortFd, &options) != 0) {
        //std::cerr << "Error getting termios attributes: " << strerror(errno) << std::endl;
        ::close(serialPortFd);
        throw AppException(TERMIOS_GET_ATTRIBUTES_FAILED);
    }

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
        throw AppException(TERMIOS_SET_ATTRIBUTES_FAILED);
    }

    // Convert to FILE stream
    fileUART = fdopen(serialPortFd, "r+");
    if (!fileUART) {
        perror("Failed to open FILE stream");
        ::close(serialPortFd);
        throw AppException(FILE_OPEN_FAILED);
    }

    // Disable buffering
    setvbuf(fileUART, NULL, _IONBF, 0);
    openPort = port;
    port->setSerialPortFd(serialPortFd);
    return 0;
}


int UnixSerialPortManager::close() {
    openPort = nullptr;
    return 0;
}

int UnixSerialPortManager::send(const std::string &message) {
    int len = message.length();
    if(len > 250)
        return -1;
    if(fileUART == nullptr)
        return -1;
    const char* messageCString = message.c_str();
    int elementsWritten = fwrite(messageCString, sizeof(char), len, fileUART);
    if (elementsWritten != len) {
        fflush(fileUART);
        int ch;
        while ((ch = fgetc(fileUART)) != EOF);
        clearerr(fileUART);
    }
    return 0;
}

const std::string &UnixSerialPortManager::getOpenSerialPort() const{
    return openPort->getDisplayName();
}

bool UnixSerialPortManager::getSerialPortState() const{
    if(openPort == nullptr)
        return false;
    return true;
}

std::vector <uint8_t> UnixSerialPortManager::receive() {
    if (!openPort || !fileUART) {
        std::cerr << "Error" << std::endl;
        return {};
    }
    std::vector <uint8_t> buffer(20024);
    size_t bytesRead = fread(buffer.data(), 1, 1024, fileUART);

    if (bytesRead == 0) {
        if (feof(fileUART)) {
            clearerr(fileUART);
        } else if (ferror(fileUART)) {
            perror("UART fread error");
            clearerr(fileUART);
        }
        return {};
    }
    buffer.resize(bytesRead);
    return buffer;
}


bool UnixSerialPortManager::operator==(SerialPortState state) const {
    switch(state) {
        case SERIAL_PORT_OPENED:
            return getSerialPortState();
        break;
        case SERIAL_PORT_CLOSED:
            return !getSerialPortState();
        break;
    }
}

std::vector <SerialPort *> UnixSerialPortManager::getAvailableSerialPorts() {
    return availableSerialPorts;
}

void UnixSerialPortManager::setBaudRate(int newBaudRate) {
    baudRate = newBaudRate;
}

UnixSerialPortManager::UnixSerialPortManager() {
    UnixSerialPortManager::checkAvailableSerialPorts();
}

UnixSerialPortManager::~UnixSerialPortManager() {
    for (auto port:availableSerialPorts)
        delete port;
    UnixSerialPortManager::close();
    openPort = nullptr;
}
#endif