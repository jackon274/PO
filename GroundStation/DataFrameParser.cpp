//
// Created by Jacek Konderak on 07/06/2025.
//

#include "DataFrameParser.h"
#include "fmt/xchar.h"

void DataFrameParser::parseString(std::string &dataString, GraphManager &manager) {
    fmt::println("Parsing data string received: {}", dataString);
    for(auto a = dataString.begin(); a != dataString.end(); a+=2) {
        std::string singleCharacter = dataString.substr(a - dataString.begin(), 2);
        char c = static_cast<char> (std::stoi(singleCharacter, nullptr, 16));
        ss << c;
    }

    fmt::println("Parsed: {}", ss.str());
    dataPointers = frame.getDataPointers();
    char separator;

    for(size_t i = 0; i < dataPointers.size(); i++) {
        std::visit([&](auto* ptr) {
            int temp;
            ss >> temp;
            ss >> separator;
            *ptr = temp;
            fmt::println("{}, appended value {}", sizeof(*ptr), *ptr);
        }, dataPointers.at(i) );
        fmt::println("Exited for!");
    }
    ss.str("");
    ss.clear();
    fmt::println("Exited for!");
    manager.updateDataSeries(frame);
}
