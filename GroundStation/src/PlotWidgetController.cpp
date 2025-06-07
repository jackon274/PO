//
// Created by Jacek Konderak on 06/06/2025.
//

#include "PlotWidgetController.h"


PlotWidgetController::PlotWidgetController(QCustomPlot *ptrPlot, DataSeries *ptrSeries, QLabel *ptrLabel) {
    plot = ptrPlot;
    titleLabel = ptrLabel;
    updateDataSeries(ptrSeries);
}

void PlotWidgetController::updateDataSeries(DataSeries *series) {
    currentSeries = series;

    switch (currentSeries->getDataType()) {
        case TEMPERATURE_IN:
            title = "Temperature Inside the Container";
        break;
        case TEMPERATURE_OUT:
            title = "Temperature Outside the Container";
        break;
        case ALTITUDE:
            title = "Altitude";
        break;
        case HUMIDITY:
            title = "Humidity";
        break;
        case RADIATION:
            title = "Radiation";
        break;
    }

    plot->addGraph();
    titleLabel->setText(QString::fromStdString(title));
    plot->graph(0)->setData(currentSeries->getData(), currentSeries->getTime());
    plot->replot();
}
