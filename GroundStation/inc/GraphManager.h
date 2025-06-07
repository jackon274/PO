//
// Created by Jacek Konderak on 07/06/2025.
//

#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H
#include "DataSeries.h"
#include "DataType.h"
#include <map>

#include "PlotWidgetController.h"

class GraphManager {
    std::map <DataType, DataSeries*> dataSeries;
    /*std::vector <PlotWidgetController> plotWidgetControllers;
    std::vector <QCustomPlot*> plots;*/
    std::unordered_map <PlotWidgetController*, DataType> controllersTypes;
    public:
      GraphManager();
    void addPlotWidgetController(QCustomPlot *ptrPlot, QLabel *ptrLabel, DataType type);
};



#endif //GRAPHMANAGER_H
