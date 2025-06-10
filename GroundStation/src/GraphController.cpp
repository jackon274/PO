//
// Created by Jacek Konderak on 07/06/2025.
//

#include "GraphController.h"
#include <iostream>
#include <fmt/ranges.h>
#include "fmt/base.h"

GraphController::GraphController() {
    dataSeries.insert({TEMPERATURE_IN, new DataSeries(TEMPERATURE_IN)});
    dataSeries.insert({TEMPERATURE_OUT, new DataSeries(TEMPERATURE_OUT)});
    dataSeries.insert({ALTITUDE, new DataSeries(ALTITUDE)});
    dataSeries.insert({HUMIDITY, new DataSeries(HUMIDITY)});
    dataSeries.insert({RADIATION, new DataSeries(RADIATION)});
}

void GraphController::addPlotWidgetView(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type) {
    PlotWidgetView* ptrPlotWidgetView = new PlotWidgetView(ptrPlot, dataSeries.at(type), ptrLabel);
    viewsTypes.insert({ptrPlotWidgetView, type});
    plotWidgetViewPointers.push_back(ptrPlotWidgetView);
}

void GraphController::addDataValueLabelView(DataType type, QLabel *labelVal, QLabel *labelUnit) {
    DataValueLabelView *ptrDataValueLabelView = new DataValueLabelView(labelVal, labelUnit, dataSeries.at(type));
    dataValueViewsTypes.insert({ptrDataValueLabelView, type});
    dataValueLabelViewPointers.push_back(ptrDataValueLabelView);
}

void GraphController::updatePlotWidgetView(int index, DataType type) {
    if(index >= static_cast <int> (plotWidgetViewPointers.size())) {
        return;
    }
    plotWidgetViewPointers.at(index)->updateDataSeries(dataSeries.at(type));
    dataValueLabelViewPointers.at(index)->updateDataSeries(dataSeries.at(type));
}

void GraphController::updateDataSeries(DataFrame &frame) {
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

void GraphController::changeUnitSystem(UnitSystem unitSystem) {
    currentUnitSystem = unitSystem;
    for (auto a:dataValueLabelViewPointers) {
        a->changeUnits(unitSystem);
        if(unitSystem == IMPERIAL)
            fmt::println("Switching to hamburgers!");
    }
}
