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
    QString filePath = QCoreApplication::applicationDirPath() + "/../Resources/map.html";
    public:
    QWebEngineView* view;
    Map(QWebEngineView* ptrView);
};



#endif //MAP_H
