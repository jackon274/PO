//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef DATASERIES_H__
#define DATASERIES_H__
#include <QVector>
#include <vector>
#include "DataFrame.h"
#include "DataType.h"
#include <map>

class DataSeries {
    QVector <double> data;
    QVector <double> time;
    const DataType dataType;
    int timeTest = 0;
    public:
    void appendData(DataFrame &frame);
    void appendData (const std::map <std::string, int> &params);
    const QVector <double> &getData() const;
    const QVector <double> &getDataImperial() const;
    explicit DataSeries(const DataType &type);
    const DataType &getDataType() const;
    const QVector <double> &getTime() const;
};



#endif //DATASERIES_H

