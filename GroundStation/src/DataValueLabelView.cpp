//
// Created by Jacek Konderak on 10/06/2025.
//

#include "DataValueLabelView.h"

#include "fmt/base.h"
#include "fmt/format.h"

void DataValueLabelView::updateDataSeries(DataSeries *series) {
    if (series != nullptr)
        currentSeries = series;
    if(currentSeries->getData().empty())
        return;
    labelValue->setText(QString::number(currentSeries->getData().back()));
}

void DataValueLabelView::changeUnits(UnitSystem unitSystem) {
    if (currentSeries == nullptr)
        return;

    switch (unitSystem) {
        case METRIC:
            labelUnit->setText(UnitsMetric.at(currentSeries->getDataType()));
            break;
        case IMPERIAL:
            labelUnit->setText(UnitsImperial.at(currentSeries->getDataType()));
            break;
    }
    fmt::println("Changing unit to {}", UnitsImperial.at(currentSeries->getDataType()).toStdString());
    updateDataSeries();
}

DataValueLabelView::DataValueLabelView(QLabel *ptrlabelValue, QLabel *ptrlabelUnit, DataSeries *ptrSeries) {
    labelValue = ptrlabelValue;
    labelUnit = ptrlabelUnit;
    updateDataSeries(ptrSeries);
}
