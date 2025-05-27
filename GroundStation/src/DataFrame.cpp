//
// Created by Jacek Konderak on 19/05/2025.
//

#include "DataFrame.h"

uint32_t DataFrame::get_frame_count() const {
    return frame_count;
}

uint32_t DataFrame::get_elapsed_time() const {
    return elapsed_time;
}

float DataFrame::get_longitude() const {
    return static_cast <float> (longitude) / (10e7);
}

float DataFrame::get_latitude() const {
    return static_cast <float> (latitude) / (10e7);
}

float DataFrame::get_height_meters() const {
    return static_cast <float> (height) / 100;
}

float DataFrame::get_temperature_outside_centigrade() const {
    return static_cast <float> (temperature_outside) / 100;
}

float DataFrame::get_temperature_inside_centigrade() const {
    return static_cast <float> (temperature_inside) / 100;
}

float DataFrame::get_humidity_percent() const {
    return static_cast <float> (humidity_percent) / 2;
}

int DataFrame::get_radiation_cpm() const {
    return radiation_cpm;
}

int DataFrame::get_checksum() const {
    return checksum;
}
