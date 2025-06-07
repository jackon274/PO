//
// Created by Jacek Konderak on 07/06/2025.
//

#include "GraphManager.h"
#include <iostream>
GraphManager::GraphManager() {
    dataSeries.insert({TEMPERATURE_IN, new DataSeries(TEMPERATURE_IN)});
    dataSeries.insert({TEMPERATURE_OUT, new DataSeries(TEMPERATURE_OUT)});
    dataSeries.insert({ALTITUDE, new DataSeries(ALTITUDE)});
    dataSeries.insert({HUMIDITY, new DataSeries(HUMIDITY)});
    dataSeries.insert({RADIATION, new DataSeries(RADIATION)});
}

void GraphManager::addPlotWidgetController(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type) {
    PlotWidgetController* ptrPlotWidgetController = new PlotWidgetController(ptrPlot, dataSeries.at(type), ptrLabel);
    controllersTypes.insert({ptrPlotWidgetController, type});
    plotWidgetControllerPointers.push_back(ptrPlotWidgetController);
}

void GraphManager::updatePlotWidgetController(int index, DataType type) {
    if(index >= plotWidgetControllerPointers.size()) {
        std::cout << "RETURN!";
        return;
    }
    plotWidgetControllerPointers.at(index)->updateDataSeries(dataSeries.at(type));
}
