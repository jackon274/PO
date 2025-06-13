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
    if (currentUnitSystem == METRIC)
        labelValue->setText(QString::number(currentSeries->getData().back()));
    else if (currentUnitSystem == IMPERIAL) {
        QVector <double> dataImperial(currentSeries->getData().size());
        if(currentSeries->getDataType() == TEMPERATURE_IN || currentSeries->getDataType() == TEMPERATURE_OUT) {
            std::transform(currentSeries->getData().begin(), currentSeries->getData().end(), dataImperial.begin(), [](double temp) {return 1.8*temp + 32;});
            labelValue->setText(QString::number(dataImperial.back()));
        }
        else if (currentSeries->getDataType() == ALTITUDE) {
            std::transform(currentSeries->getData().begin(), currentSeries->getData().end(), dataImperial.begin(), [](double alt) {return 3.2808399*alt;});
            labelValue->setText(QString::number(dataImperial.back()));
        }
        else
            labelValue->setText(QString::number(currentSeries->getData().back()));


    }

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
    currentUnitSystem = unitSystem;
    fmt::println("Changing unit to {}", UnitsImperial.at(currentSeries->getDataType()).toStdString());
    updateDataSeries();
}

DataValueLabelView::DataValueLabelView(QLabel *ptrlabelValue, QLabel *ptrlabelUnit, DataSeries *ptrSeries) {
    labelValue = ptrlabelValue;
    labelUnit = ptrlabelUnit;
    updateDataSeries(ptrSeries);
}
