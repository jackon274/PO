//
// Created by Jacek Konderak on 30/05/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>

class Parser {
    std::vector<std::string> linesTest;
    std::vector<std::string> linesLog;
    std::vector<std::string> linesInfo;
public:
    void parseLine(std::vector<uint8_t> &receivedData);
};


#endif //PARSER_H
