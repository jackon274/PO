//
// Created by Jacek Konderak on 06/06/2025.
//

#ifndef PLOT_WIDGET_CONTROLLER__
#define PLOT_WIDGET_CONTROLLER__
#include <string>
#include "DataType.h"
#include "DataSeries.h"
#include "qcustomplot.h"


class PlotWidgetController {
std::string title;
std::string xAxisTitle = "t";
std::string yAxisTitle;
QCustomPlot *plot = nullptr;
QLabel *titleLabel = nullptr;
    DataSeries *currentSeries = nullptr;

public:
    PlotWidgetController(QCustomPlot *ptrPlot, DataSeries *ptrSeries, QLabel *ptrLabel);
    void updateDataSeries(DataSeries *series);
    void adjustAxes();

};



#endif
