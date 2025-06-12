//
// Created by Jacek Konderak on 22/05/2025.
//

#ifndef MAP_H
#define MAP_H


#include <QApplication>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QFileInfo>



class Map {
    float longitude;
    float latitude;
#ifdef __APPLE__
    QString filePath = QCoreApplication::applicationDirPath() + "/../Resources/map.html";
#endif
#ifdef __linux__
    QString filePath = QCoreApplication::applicationDirPath() + "/Resources/map.html";
#endif
    public:
    QWebEngineView* view;
    Map(QWebEngineView* ptrView);
    void updateLocation(double latitude, double longitude);
};



#endif //MAP_H
