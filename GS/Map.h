//
// Created by Jacek Konderak on 22/05/2025.
//

#ifndef MAP_H
#define MAP_H


#include <QApplication>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>



class Map {
    float longitude;
    float latitude;
    const QString sourceFile = "/Users/jacekk/MapTest/map.html";
    public:
    QWebEngineView* view;
    Map(QWebEngineView* ptrView);
};



#endif //MAP_H
