//
// Created by Jacek Konderak on 30/05/2025.
//

#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <fmt/std.h>
#include "DataDisplayController.h"
#include "DataFrameParser.h"


class UARTParser {
    std::vector <std::string> linesTest;
    std::vector <std::string> linesLog;
    std::vector <std::string> linesInfo;
    std::map <std::string, int> parameters { {"LEN", 0}, {"RSSI", 0}, {"SNR", 0} };
    std::string rxFrameString;
    public:
    void parseLine(std::vector<uint8_t> &receivedData);
    const std::map <std::string, int> &getParameters() const;
    const std::string &getRxFrameString() const;
};

#endif //PARSER_H
