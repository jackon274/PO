//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef DATATYPE_H
#define DATATYPE_H
#include <QString>
#include <unordered_map>

enum DataType {
    TEMPERATURE_IN,
    TEMPERATURE_OUT,
    ALTITUDE,
    HUMIDITY,
    RADIATION,
    ELAPSED_TIME,
    RSSI,
    SNR
    };

enum UnitSystem {
    METRIC,
    IMPERIAL
};

extern std::unordered_map <DataType, QString> UnitsMetric;
extern std::unordered_map <DataType, QString> UnitsImperial;

#endif //DATATYPE_H
