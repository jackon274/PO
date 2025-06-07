//
// Created by Jacek Konderak on 06/06/2025.
//

#include "PlotWidgetController.h"


PlotWidgetController::PlotWidgetController(QCustomPlot *ptrPlot, DataSeries *ptrSeries, QLabel *ptrLabel) {
    plot = ptrPlot;
    currentSeries = ptrSeries;
    titleLabel = ptrLabel;

    /*QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = x[i]*x[i]; // let's plot a quadratic function
    }*/

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
