//
// Created by Jacek Konderak on 06/06/2025.
//

#ifndef PLOT_WIDGET_CONTROLLER__
#define PLOT_WIDGET_CONTROLLER__
#include <string>
#include "DataType.h"
#include "DataSeries.h"
#include "qcustomplot.h"


class PlotWidgetView {
    std::string title;
    std::string xAxisTitle = "t";
    std::string yAxisTitle;
    QCustomPlot *plot = nullptr;
    QLabel *titleLabel = nullptr;
    DataSeries *currentSeries = nullptr;
    UnitSystem currentUnitSystem = METRIC;

public:
    PlotWidgetView(QCustomPlot *ptrPlot, DataSeries *ptrSeries, QLabel *ptrLabel);
    void updateDataSeries(DataSeries *series = nullptr);
    void adjustAxes();
    void changeUnitSystem(UnitSystem unitSystem);
};



#endif
