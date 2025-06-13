//
// Created by Jacek Konderak on 07/06/2025.
//

#include "DataSeries.h"

#include "fmt/base.h"


void DataSeries::appendData(DataFrame &frame) {
    switch(dataType) {
        case TEMPERATURE_IN:
            data.push_back(frame.getTemperatureInsideCentigrade());
        break;
        case TEMPERATURE_OUT:
            data.push_back(frame.getTemperatureOutsideCentigrade());
        break;
        case ALTITUDE:
            data.push_back(frame.getAltitudeMeters());
        break;
        case HUMIDITY:
            data.push_back(frame.getHumidityPercent());
        break;
        case RADIATION:
            data.push_back(frame.getRadiationCPM());
        break;
        case ELAPSED_TIME:
            data.push_back(frame.getElapsedTimeMinutes());
    }
    time.push_back(timeTest++);
}

void DataSeries::appendData (const std::map <std::string, int> &params) {
    switch (dataType) {
        case SNR:
            data.push_back(params.at("SNR"));
        break;
        case RSSI:
            data.push_back(params.at("RSSI"));
        break;
    }
}

const QVector<double> &DataSeries::getData() const {
    return data;
}

DataSeries::DataSeries(const DataType &type) : dataType(type) {

}

const DataType &DataSeries::getDataType() const {
    return dataType;
}

const QVector <double> & DataSeries::getTime() const {
    return time;
}
