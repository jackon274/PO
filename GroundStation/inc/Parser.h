//
// Created by Jacek Konderak on 30/05/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>
#include <map>
#include <sstream>

class Parser {
    std::vector <std::string> linesTest;
    std::vector <std::string> linesLog;
    std::vector <std::string> linesInfo;
    std::map <std::string, int> parameters { {"LEN", 0}, {"RSSI", 0}, {"SNR", 0}, {"RX", 0} };
    //std::stringstream valueStream;
public:
    void parseLine(std::vector<uint8_t> &receivedData);
};


#endif //PARSER_H
