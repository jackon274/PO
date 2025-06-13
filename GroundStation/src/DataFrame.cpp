//
// Created by Jacek Konderak on 19/05/2025.
//

#include "DataFrame.h"


uint32_t DataFrame::getFrameCount() const {
    return frameCount;
}

uint32_t DataFrame::getElapsedTimeMinutes() const {
    return elapsedTime/60;
}

float DataFrame::getLongitude() const {
    return static_cast <float> (longitude) / (10e6);
}

float DataFrame::getLatitude() const {
    return static_cast <float> (latitude) / (10e6);
}

float DataFrame::getAltitudeMeters() const {
    return static_cast <float> (altitude) / 100;
}

float DataFrame::getTemperatureOutsideCentigrade() const {
    return static_cast <float> (temperatureOutside) / 100;
}

float DataFrame::getTemperatureInsideCentigrade() const {
    return static_cast <float> (temperatureInside) / 100;
}

float DataFrame::getHumidityPercent() const {
    return static_cast <float> (relativeHumidity) / 2;
}

int DataFrame::getRadiationCPM() const {
    return ionizingRadiationCPM;
}

int DataFrame::getChecksum() const {
    return checksum;
}

DataFrame::DataFrame() {
    dataPointers.push_back(&frameCount);
    dataPointers.push_back(&elapsedTime);
    dataPointers.push_back(&longitude);
    dataPointers.push_back(&latitude);
    dataPointers.push_back(&altitude);
    dataPointers.push_back(&temperatureOutside);
    dataPointers.push_back(&temperatureInside);
    dataPointers.push_back(&relativeHumidity);
    dataPointers.push_back(&ionizingRadiationCPM);
    dataPointers.push_back(&flags);
    dataPointers.push_back(&checksum);
}

const std::vector<DataFrame::PointerVariant> &DataFrame::getDataPointers() const {
    return dataPointers;
}
