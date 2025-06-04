//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef ERRORNOTIFIER_H
#define ERRORNOTIFIER_H

#include <string>

class ErrorNotifier {
  std::string errorOpenPort = "Failed to open selected serial port!";
  std::string errorTermiosGetAttributes = "Error getting termios attributes";
  std::string errorTermiosSetAttributes = "Error setting termios attributes";
  std::string errorFileOpen = "Error opening file";
  std::string errorUnknown = "Unknown error occurred";
  std::string messageBoxTitle = "Error";
public:
  enum ErrorCode {
    PORT_OPEN_FAILED,
    TERMIOS_GET_ATTRIBUTES_FAILED,
    TERMIOS_SET_ATTRIBUTES_FAILED,
    FILE_OPEN_FAILED
  };
  void notify(ErrorCode code);
};



#endif //ERRORNOTIFIER_H
