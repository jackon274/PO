//
// Created by Jacek Konderak on 07/06/2025.
//

#include "DataDisplayController.h"
#include <iostream>
#include <fmt/ranges.h>
#include "fmt/base.h"

DataDisplayController::DataDisplayController() {
    dataSeries.insert({TEMPERATURE_IN, new DataSeries(TEMPERATURE_IN)});
    dataSeries.insert({TEMPERATURE_OUT, new DataSeries(TEMPERATURE_OUT)});
    dataSeries.insert({ALTITUDE, new DataSeries(ALTITUDE)});
    dataSeries.insert({HUMIDITY, new DataSeries(HUMIDITY)});
    dataSeries.insert({RADIATION, new DataSeries(RADIATION)});
    dataSeries.insert({ELAPSED_TIME, new DataSeries(ELAPSED_TIME)});
    dataSeries.insert({SNR, new DataSeries(SNR)});
    dataSeries.insert({RSSI, new DataSeries(RSSI)});
}

void DataDisplayController::addPlotWidgetView(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type) {
    PlotWidgetView* ptrPlotWidgetView = new PlotWidgetView(ptrPlot, dataSeries.at(type), ptrLabel);
    viewsTypes.insert({ptrPlotWidgetView, type});
    plotWidgetViewPointers.push_back(ptrPlotWidgetView);
}

void DataDisplayController::addDataValueLabelView(DataType type, QLabel *labelVal, QLabel *labelUnit) {
    DataValueLabelView *ptrDataValueLabelView = new DataValueLabelView(labelVal, labelUnit, dataSeries.at(type));
    dataValueViewsTypes.insert({ptrDataValueLabelView, type});
    dataValueLabelViewPointers.push_back(ptrDataValueLabelView);
}

void DataDisplayController::updatePlotWidgetView(int index, DataType type) {
    if(index >= static_cast <int> (plotWidgetViewPointers.size())) {
        return;
    }
    plotWidgetViewPointers.at(index)->updateDataSeries(dataSeries.at(type));
    dataValueLabelViewPointers.at(index)->updateDataSeries(dataSeries.at(type));
}

void DataDisplayController::updateDataSeries(DataFrame &frame) {
    for (auto a:dataSeries) {
        a.second->appendData(frame);
    }
    for (auto a:plotWidgetViewPointers) {
        a->updateDataSeries(dataSeries.at(viewsTypes.at(a)));
    }
    for (auto a:dataValueLabelViewPointers) {
        a->updateDataSeries(dataSeries.at(dataValueViewsTypes.at(a)));
    }
}

void DataDisplayController::updateDataSeries(const std::map <std::string, int> &params) {
    for (auto a:dataSeries) {
        a.second->appendData(params);
    }
    for (auto a:dataValueLabelViewPointers) {
        a->updateDataSeries(dataSeries.at(dataValueViewsTypes.at(a)));
    }
}

void DataDisplayController::changeUnitSystem(UnitSystem unitSystem) {
    currentUnitSystem = unitSystem;
    for (auto a:dataValueLabelViewPointers) {
        a->changeUnits(unitSystem);
        if(unitSystem == IMPERIAL)
            fmt::println("Switching to hamburgers!");
    }
}
