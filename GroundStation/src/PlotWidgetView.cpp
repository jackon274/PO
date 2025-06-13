//
// Created by Jacek Konderak on 06/06/2025.
//

#include "PlotWidgetView.h"



PlotWidgetView::PlotWidgetView(QCustomPlot *ptrPlot, DataSeries *ptrSeries, QLabel *ptrLabel) {
    plot = ptrPlot;
    titleLabel = ptrLabel;
    updateDataSeries(ptrSeries);
}


void PlotWidgetView::updateDataSeries(DataSeries *series) {
    if(series != nullptr)
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
    if (currentUnitSystem == METRIC)
        plot->graph(0)->setData(currentSeries->getTime(), currentSeries->getData());
    else if (currentUnitSystem == IMPERIAL) {
        QVector <double> dataImperial(currentSeries->getData().size());
        if(currentSeries->getDataType() == TEMPERATURE_IN || currentSeries->getDataType() == TEMPERATURE_OUT) {
            std::transform(currentSeries->getData().begin(), currentSeries->getData().end(), dataImperial.begin(), [](double temp) {return 1.8*temp + 32;});
            plot->graph(0)->setData(currentSeries->getTime(), dataImperial);
        }
        else if (currentSeries->getDataType() == ALTITUDE) {
            std::transform(currentSeries->getData().begin(), currentSeries->getData().end(), dataImperial.begin(), [](double alt) {return 3.2808399*alt;});
            plot->graph(0)->setData(currentSeries->getTime(), dataImperial);
        }
        else
            plot->graph(0)->setData(currentSeries->getTime(), currentSeries->getData());
        }
    adjustAxes();
    plot->replot();
}

void PlotWidgetView::adjustAxes() {
    double yValueMin = 0, yValueMax = 0, xValueMin = 0, xValueMax = 0;

    auto yValueMaxPtr = std::max_element(currentSeries->getData().begin(), currentSeries->getData().end());
    auto yValueMinPtr = std::min_element(currentSeries->getData().begin(), currentSeries->getData().end());
    if (yValueMaxPtr != nullptr && yValueMinPtr != nullptr) {
        yValueMax = *yValueMaxPtr;
        yValueMin = *yValueMinPtr;
    }

    auto xValueMaxPtr = std::max_element(currentSeries->getTime().begin(), currentSeries->getTime().end());
    auto xValueMinPtr = std::min_element(currentSeries->getTime().begin(), currentSeries->getTime().end());
    if (xValueMaxPtr != nullptr && xValueMinPtr != nullptr) {
        xValueMax = *xValueMaxPtr;
        xValueMin = *xValueMinPtr;
    }
    if( (yValueMin - yValueMax) < 0.1) {
        yValueMax = 1.1 * yValueMax;
        yValueMin = 0.9 * yValueMin;
    }
    plot->xAxis->setRange(xValueMin, xValueMax);
    plot->yAxis->setRange(yValueMin, yValueMax);
}

void PlotWidgetView::changeUnitSystem(UnitSystem unitSystem) {
    currentUnitSystem = unitSystem;
    updateDataSeries();
}
