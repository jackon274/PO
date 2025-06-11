//
// Created by Jacek Konderak on 10/06/2025.
//

#ifndef DATAVALUELABELVIEW_H
#define DATAVALUELABELVIEW_H
#include <QLabel>
#include "DataSeries.h"


class DataValueLabelView {
    QLabel *labelValue = nullptr;
    QLabel *labelUnit = nullptr;
    DataSeries *currentSeries = nullptr;
    UnitSystem currentUnitSystem = METRIC;
public:
    void updateDataSeries(DataSeries *series = nullptr);
    void changeUnits(UnitSystem unitSystem);
    DataValueLabelView(QLabel *ptrlabelValue, QLabel *ptrlabelUnit, DataSeries *ptrSeries);
};



#endif //DATAVALUELABELVIEW_H
