//
// Created by Jacek Konderak on 22/05/2025.
//

#include "Map.h"

Map::Map(QWebEngineView* ptrView) {
    view = ptrView;
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    view->load(QUrl::fromLocalFile(QFileInfo(filePath).absoluteFilePath()));
    view->show();
}
