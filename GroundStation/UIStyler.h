//
// Created by Jacek Konderak on 06/06/2025.
//

#ifndef UISTYLER_H
#define UISTYLER_H
#include <ui_mainwindow.h>
#include <QFontDatabase>
#include <vector>


class UIStyler {
    Ui::MainWindow *ui;
    int materialIconsRoundFontID = QFontDatabase::addApplicationFont(":/Fonts/MaterialIconsRound.otf");
    QButtonGroup *sidebarButtonsGroup;
    std::vector <QPushButton *> sidebarButtons;
    std::vector <QLabel *> sidebarButtonLabels;
    QFont materialIconsRoundFont;

    QString sidebarButtonStyle = R"(
    QPushButton { }
    QPushButton:checked {
        color: #5C2D91;
    }
    QPushButton:hover {
        color:#7D57A7;
    } )";
    QString sidebarTextStyleSelected = R"(color: #5C2D91; font-weight: bold;)";
    QString sidebarTextStyleUnselected = R"(color: rgb(0,0,0); font-weight: normal;)";


public:
    explicit UIStyler(Ui::MainWindow* ptrUi);
    ~UIStyler();
    void applyStyle();
    void highlightSelectedButtonLabel(const int index) const;
};



#endif //UISTYLER_H
