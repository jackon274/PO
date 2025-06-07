//
// Created by Jacek Konderak on 07/06/2025.
//

#include "DataSeries.h"

void DataSeries::appendData(DataFrame &frame) {
    switch(dataType) {
        case TEMPERATURE_IN:
            data.push_back(frame.get_temperature_inside_centigrade());
        break;
        case TEMPERATURE_OUT:
            data.push_back(frame.get_temperature_outside_centigrade());
        break;
        case ALTITUDE:
            data.push_back(frame.get_altitude_meters());
        break;
        case HUMIDITY:
            data.push_back(frame.get_humidity_percent());
        break;
        case RADIATION:
            data.push_back(frame.get_radiation_cpm());
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
