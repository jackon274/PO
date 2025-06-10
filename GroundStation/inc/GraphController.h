//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H
#include "DataSeries.h"
#include "DataType.h"
#include <map>

#include "PlotWidgetView.h"

class GraphController {
    std::unordered_map <DataType, DataSeries*> dataSeries;
    std::unordered_map <PlotWidgetView*, DataType> viewsTypes;
    std::vector <PlotWidgetView*> plotWidgetViewPointers;
    public:
      GraphController();
    void addPlotWidgetView(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type);
    void updatePlotWidgetView(int index, DataType type);
    void updateDataSeries(DataFrame &frame);
};



#endif //GRAPHMANAGER_H
