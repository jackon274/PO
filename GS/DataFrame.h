//
// Created by Jacek Konderak on 19/05/2025.
//

#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <cstdint>


class DataFrame {
    int16_t temperature_outside;
    int16_t temperature_inside;
    int32_t longitude;
    int32_t latitude;
    uint32_t height;
    uint16_t radiation_cpm;
    uint8_t humidity_percent;
    uint32_t checksum;
    uint8_t flags;
    uint8_t elapsed_time;

};



#endif //DATAFRAME_H
