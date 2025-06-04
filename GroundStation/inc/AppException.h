//
// Created by Jacek Konderak on 04/06/2025.
//

#ifndef APPEXCEPTION_H
#define APPEXCEPTION_H

#include <exception>
#include "ErrorCode.h"

class AppException :public std::exception {
    ErrorCode errorCode;
public:
    explicit AppException(ErrorCode code) :errorCode(code) {};
    ErrorCode code() const noexcept {return errorCode;}
};



#endif //APPEXCEPTION_H
