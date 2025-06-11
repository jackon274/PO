//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef DATAFRAMEPARSER_H
#define DATAFRAMEPARSER_H
#include <sstream>
#include <string>

#include "DataFrame.h"
#include "DataDisplayController.h"


class DataFrameParser {
    std::string receivedDataString;
    DataFrame frame;
    std::stringstream ss;
    using PointerVariant = std::variant<uint8_t*, int16_t*, uint16_t*, int32_t*, uint32_t*>;
    std::vector <PointerVariant> dataPointers;
    public:
    void parseString(const std::string &dataString);
    DataFrame &getDataFrame();
};



#endif //DATAFRAMEPARSER_H
