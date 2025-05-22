//
// Created by Jacek Konderak on 19/05/2025.
//

#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <cstdint>


class DataFrame {
    uint32_t frame_count;
    uint32_t elapsed_time;
    int32_t longitude;
    int32_t latitude;
    uint32_t height;
    int16_t temperature_outside;
    int16_t temperature_inside;
    uint8_t humidity_percent;
    uint16_t radiation_cpm;
    uint8_t flags;
    uint32_t checksum;
};



#endif //DATAFRAME_H
