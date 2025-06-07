//
// Created by Jacek Konderak on 07/06/2025.
//

#include "GraphManager.h"

GraphManager::GraphManager() {
    dataSeries.insert({TEMPERATURE_IN, new DataSeries(TEMPERATURE_IN)});
    dataSeries.insert({TEMPERATURE_OUT, new DataSeries(TEMPERATURE_OUT)});
    dataSeries.insert({ALTITUDE, new DataSeries(ALTITUDE)});
    dataSeries.insert({HUMIDITY, new DataSeries(HUMIDITY)});
    dataSeries.insert({RADIATION, new DataSeries(RADIATION)});
}

void GraphManager::addPlotWidgetController(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type) {
    controllersTypes.insert({new PlotWidgetController(ptrPlot, dataSeries.at(type), ptrLabel), type});
}
