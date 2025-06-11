//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H
#include "DataSeries.h"
#include "DataType.h"
#include <map>

#include "DataValueLabelView.h"
#include "PlotWidgetView.h"

class DataDisplayController {
    std::unordered_map <DataType, DataSeries*> dataSeries;
    std::unordered_map <PlotWidgetView*, DataType> viewsTypes;
    std::unordered_map <DataValueLabelView*, DataType> dataValueViewsTypes;
    std::vector <PlotWidgetView*> plotWidgetViewPointers;
    std::vector <DataValueLabelView*> dataValueLabelViewPointers;

    UnitSystem currentUnitSystem = METRIC;
    public:
      DataDisplayController();
    void addPlotWidgetView(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type);
    void addDataValueLabelView(DataType type, QLabel *labelVal, QLabel *labelUnit);
    void updatePlotWidgetView(int index, DataType type);
    void updateDataSeries(DataFrame &frame);
    void updateDataSeries(const std::map<std::string, int> &params);
    void changeUnitSystem(UnitSystem unitSystem);
};



#endif //GRAPHMANAGER_H
