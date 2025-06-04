//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef ERRORNOTIFIER_H
#define ERRORNOTIFIER_H

#include <string>
#include "ErrorCode.h"

class ErrorNotifier {
  ErrorCode errorCode;
  std::string errorOpenPort = "Failed to open selected serial port!";
  std::string errorTermiosGetAttributes = "Error getting termios attributes";
  std::string errorTermiosSetAttributes = "Error setting termios attributes";
  std::string errorFileOpen = "Error opening file";
  std::string errorUnknown = "Unknown error occurred";
  std::string messageBoxTitle = "Error";
public:
  void notify();
  explicit ErrorNotifier(ErrorCode code): errorCode(code) {};
};



#endif //ERRORNOTIFIER_H
