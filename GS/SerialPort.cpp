//
// Created by Jacek Konderak on 06/05/2025.
//

#include "SerialPort.h"
#include <iostream>
#include <vector>
#include <string>

#ifdef __APPLE__
    #include <fcntl.h>
    #include <termios.h>
    #include <unistd.h>
#endif


SerialPort::SerialPort(const std::string& name) {
    portName = name;
    displayName = name;
}

SerialPort::SerialPort(const std::string& name, const std::string& dispName) {
    portName = name;
    displayName = dispName;
}


#ifdef __APPLE__
int SerialPort::open(int baudRate) {
    int serialPortFd = ::open(portName.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

    if(serialPortFd < 0)
        std::cerr << "Error opening serial port";

    struct termios options;
    memset(&options, 0, sizeof options);

    if (tcgetattr(serialPortFd, &options) != 0) {
        std::cerr << "Error getting termios attributes: " << strerror(errno) << std::endl;
        close(serialPortFd);
        return -1;
    }

    // Configure baud rate
    cfsetospeed(&options, baudRate);
    cfsetispeed(&options, baudRate);

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
        close(serialPortFd);
        return -1;
    }

    return serialPortFd;
}

#endif