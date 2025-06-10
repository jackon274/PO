//
// Created by Jacek Konderak on 10/06/2025.
//
#include "DataType.h"

std::unordered_map <DataType, QString> UnitsMetric = {{TEMPERATURE_IN, "°C"}, {TEMPERATURE_OUT, "°C"}, {ALTITUDE, "m"}, {HUMIDITY, "%"}, {RADIATION, "CPM"}, {ELAPSED_TIME, "min"}, {RSSI, "dB"}, {SNR, "dB"}};
std::unordered_map <DataType, QString> UnitsImperial = {{TEMPERATURE_IN, "°F"}, {TEMPERATURE_OUT, "°F"}, {ALTITUDE, "ft"}, {HUMIDITY, "%"}, {RADIATION, "CPM"}, {ELAPSED_TIME, "min"}, {RSSI, "dB"}, {SNR, "dB"}};
