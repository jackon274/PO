//
// Created by Jacek Konderak on 10/06/2025.
//

#include "DataValueLabelView.h"

#include "fmt/base.h"
#include "fmt/format.h"

void DataValueLabelView::updateDataSeries(DataSeries *series) {
    currentSeries = series;
    if(currentSeries->getData().empty())
        return;
    fmt::println("Not empty!");
    labelValue->setText(QString::number(currentSeries->getData().back()));
}

void DataValueLabelView::changeUnits(UnitSystem unitSystem) const {
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
    labelValue->setText(QString::number(currentSeries->getData().back()));
}

DataValueLabelView::DataValueLabelView(QLabel *ptrlabelValue, QLabel *ptrlabelUnit, DataSeries *ptrSeries) {
    labelValue = ptrlabelValue;
    labelUnit = ptrlabelUnit;
    updateDataSeries(ptrSeries);
}
