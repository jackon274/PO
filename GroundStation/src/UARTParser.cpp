//
// Created by Jacek Konderak on 30/05/2025.
//

#include "UARTParser.h"

void UARTParser::parseLine(std::vector <uint8_t> &receivedData) {
    std::vector <std::string> lines;
    std::vector <uint8_t>::iterator lineBegin = receivedData.end();
    std::vector <uint8_t>::iterator lineEnd = receivedData.end();

#ifdef __APPLE__
    char lineEndChar = '\r';
#endif
#ifdef __linux__
    char lineEndChar = '\n';
#endif //Linux używa innych znaków zakończenia linii

    for (auto a = receivedData.begin(); a != receivedData.end(); a++) {
        if(*a == '+') {
            lineBegin = a;
        }
        else if(*a == lineEndChar) {
            lineEnd = a;
            if (lineBegin != receivedData.end()) {
                std::string line(lineBegin, lineEnd);
                lines.push_back(line);
            }
        }
    }

    for (auto &a:lines) {
        if(a.substr(0, 5) == "+TEST") {
            linesTest.push_back(a.substr(7));
            fmt::println("Linia TEST: {}", linesTest);
        }
        else if(a.substr(0, 5) == "+LOG:") {
            linesLog.push_back(a.substr(6));
            fmt::println("Linia LOG: {}", linesLog);
        }
        else if(a.substr(0, 5) == "+INFO") {
            linesInfo.push_back(a.substr(7));
            fmt::println("Linia INFO: {}", linesInfo);
        }
    }

    for (auto &a:linesTest) {
        while(a.size() > 0) {
            auto separator1 = a.find(':');
            auto separator2 = a.find(',');
            std::string key, value;

            if(a.substr(0, a.find('"')) == "RX ") {
                size_t dataFrameBegin = a.find('"') + 1;
                size_t dataFrameEnd = a.rfind('"');
                rxFrameString = a.substr(dataFrameBegin, dataFrameEnd - dataFrameBegin);
                a = a.substr(separator2 + 2);
                fmt::println("RX Found!");
                continue;
            }
            else {
                key = a.substr(0, separator1);
                value = a.substr(separator1 + 1, separator2 - separator1 - 1);
            }

            if (key == "RXLRPKT")
                break;
            if (key.size() > 6)
                break;

            try {
                parameters.at(key) = stoi(value);
            } catch (std::out_of_range e) {
                fmt::println("RXLRPKT: invalid key '{}'", key);
            }


            for(auto [key, val] : parameters) {
                //fmt::println("KEY: {},  VALUE: {}", key, val);
            }

            if(separator2 == std::string::npos) {
                break;
            }
            a = a.substr(separator2 + 2);
        }
    }
    linesTest.clear();
    linesLog.clear();
    linesInfo.clear();
}

const std::map<std::string, int> &UARTParser::getParameters() const {
    return parameters;
}

const std::string & UARTParser::getRxFrameString() const {
    return rxFrameString;
}
