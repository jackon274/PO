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
    public:
    uint32_t get_frame_count() const;
    uint32_t get_elapsed_time() const;
    float get_longitude() const;
    float get_latitude() const;
    float get_height_meters() const;
    float get_temperature_outside_centigrade() const;
    float get_temperature_inside_centigrade() const;
    float get_humidity_percent() const;
    int get_radiation_cpm() const;
    int get_checksum() const;
};



#endif //DATAFRAME_H
