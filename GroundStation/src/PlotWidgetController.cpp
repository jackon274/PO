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
    plot->graph(0)->setData(currentSeries->getTime(), currentSeries->getData());
    adjustAxes();
    plot->replot();
}

void PlotWidgetController::adjustAxes() {
    double yValueMin, yValueMax, xValueMin, xValueMax;
    auto yValueMaxPtr = std::max_element(currentSeries->getData().begin(), currentSeries->getData().end());
    auto yValueMinPtr = std::min_element(currentSeries->getData().begin(), currentSeries->getData().end());
    if(yValueMaxPtr != nullptr && yValueMinPtr != nullptr) {
        yValueMax = *yValueMaxPtr;
        yValueMin = *yValueMinPtr;
        plot->yAxis->setRange(yValueMin, yValueMax);
    }

    auto xValueMaxPtr = std::max_element(currentSeries->getTime().begin(), currentSeries->getTime().end());
    auto xValueMinPtr = std::min_element(currentSeries->getTime().begin(), currentSeries->getTime().end());
    if(yValueMaxPtr != nullptr && yValueMinPtr != nullptr) {
        xValueMax = *xValueMaxPtr;
        xValueMin = *xValueMinPtr;
        plot->xAxis->setRange(xValueMin, xValueMax);
    }

}
