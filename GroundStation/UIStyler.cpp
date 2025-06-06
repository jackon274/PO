//
// Created by Jacek Konderak on 06/06/2025.
//

#include "UIStyler.h"

void UIStyler::highlightSelectedButtonLabel(int index) {
    for(auto label:sidebarButtonLabels)
        label->setStyleSheet(sidebarTextStyleUnselected);
    sidebarButtonLabels.at(index)->setStyleSheet(sidebarTextStyleSelected);
}

UIStyler::UIStyler(Ui::MainWindow *ptrUi) {
    ui = ptrUi;
    sidebarButtonsGroup = new QButtonGroup;
}

UIStyler::~UIStyler() {
    delete sidebarButtonsGroup;
}

void UIStyler::applyStyle() {
    sidebarButtons.push_back(ui->btn_map);
    sidebarButtons.push_back(ui->btn_stats);
    sidebarButtons.push_back(ui->btn_graph);
    sidebarButtons.push_back(ui->btn_config);
    sidebarButtons.push_back(ui->btn_info);
    sidebarButtons.push_back(ui->btn_settings);

    sidebarButtonLabels.push_back(ui->label_map);
    sidebarButtonLabels.push_back(ui->label_stats);
    sidebarButtonLabels.push_back(ui->label_graph);
    sidebarButtonLabels.push_back(ui->label_config);
    sidebarButtonLabels.push_back(ui->label_info);
    sidebarButtonLabels.push_back(ui->label_settings);

    for (auto button:sidebarButtons) {
        sidebarButtonsGroup->addButton(button);
        button->setCheckable(true);
        button->setStyleSheet(sidebarButtonStyle);
    }
    int startPage = ui->widget_content->currentIndex();
    sidebarButtons.at(startPage)->setChecked(true);
    highlightSelectedButtonLabel(startPage);
    ui->label_connection_status->setText("");

    ui->box_languages->addItem("Polish", "pl");
    ui->box_languages->addItem("English", "en");
    ui->box_languages->setStyle(QStyleFactory::create("Fusion"));

    QPainterPath path;
    path.addRoundedRect(ui->map->rect(), 10, 10);
    ui->map->setMask(QRegion(path.toFillPolygon().toPolygon()));
    ui->widget_sidebar_labels->setVisible(false);
}
