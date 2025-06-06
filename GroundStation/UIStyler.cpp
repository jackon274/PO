//
// Created by Jacek Konderak on 06/06/2025.
//

#include "UIStyler.h"

void UIStyler::highlightSelectedButtonLabel(const int index) const {
    for(auto label:sidebarButtonLabels)
        label->setStyleSheet(sidebarTextStyleUnselected);
    sidebarButtonLabels.at(index)->setStyleSheet(sidebarTextStyleSelected);
}

UIStyler::UIStyler(Ui::MainWindow *ptrUi) {
    ui = ptrUi;
    sidebarButtonsGroup = new QButtonGroup;
    materialIconsRoundFont = QFont(QFontDatabase::applicationFontFamilies(materialIconsRoundFontID).at(0));
    proximusRegularFont = QFont(QFontDatabase::applicationFontFamilies(proximusRegularFontID).at(0));
    materialIconsRoundFont.setPixelSize(30);
    proximusRegularFont.setPixelSize(20);
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

    statsLabelsText.push_back(ui->label_temperature_in_text);
    statsLabelsText.push_back(ui->label_temperature_out_text);
    statsLabelsText.push_back(ui->label_humidity_text);
    statsLabelsText.push_back(ui->label_time_text);
    statsLabelsText.push_back(ui->label_altitude_text);
    statsLabelsText.push_back(ui->label_radiation_text);
    statsLabelsText.push_back(ui->label_RSSI_text);
    statsLabelsText.push_back(ui->label_SNR_text);

    statsLabelsValue.push_back(ui->label_temperature_in_value);
    statsLabelsValue.push_back(ui->label_temperature_out_value);
    statsLabelsValue.push_back(ui->label_humidity_value);
    statsLabelsValue.push_back(ui->label_time_value);
    statsLabelsValue.push_back(ui->label_altitude_value);
    statsLabelsValue.push_back(ui->label_radiation_value);
    statsLabelsValue.push_back(ui->label_RSSI_value);
    statsLabelsValue.push_back(ui->label_SNR_value);

    statsLabelsIcon.push_back(ui->label_temperature_in_icon);
    statsLabelsIcon.push_back(ui->label_temperature_out_icon);
    statsLabelsIcon.push_back(ui->label_humidity_icon);
    statsLabelsIcon.push_back(ui->label_time_icon);
    statsLabelsIcon.push_back(ui->label_altitude_icon);
    statsLabelsIcon.push_back(ui->label_radiation_icon);
    statsLabelsIcon.push_back(ui->label_SNR_icon);
    statsLabelsIcon.push_back(ui->label_RSSI_icon);

    statsLabelsUnits.push_back(ui->label_temperature_in_unit);
    statsLabelsUnits.push_back(ui->label_temperature_out_unit);
    statsLabelsUnits.push_back(ui->label_humidity_unit);
    statsLabelsUnits.push_back(ui->label_time_unit);
    statsLabelsUnits.push_back(ui->label_altitude_unit);
    statsLabelsUnits.push_back(ui->label_radiation_unit);
    statsLabelsUnits.push_back(ui->label_RSSI_unit);
    statsLabelsUnits.push_back(ui->label_SNR_unit);

    settingsLabelsText.push_back(ui->label_languages_text);
    settingsLabelsText.push_back(ui->label_theme_text);
    settingsLabelsText.push_back(ui->label_units_text);
    settingsLabelsText.push_back(ui->label_graph1_text);
    settingsLabelsText.push_back(ui->label_graph2_text);
    settingsLabelsText.push_back(ui->label_graph3_text);
    settingsLabelsText.push_back(ui->label_graph4_text);

    settingsLabelsIcon.push_back(ui->label_languages_icon);
    settingsLabelsIcon.push_back(ui->label_theme_icon);
    settingsLabelsIcon.push_back(ui->label_units_icon);
    settingsLabelsIcon.push_back(ui->label_graph1_icon);
    settingsLabelsIcon.push_back(ui->label_graph2_icon);
    settingsLabelsIcon.push_back(ui->label_graph3_icon);
    settingsLabelsIcon.push_back(ui->label_graph4_icon);



    for (auto const &button:sidebarButtons) {
        sidebarButtonsGroup->addButton(button);
        button->setCheckable(true);
        button->setStyleSheet(sidebarButtonStyle);
        button->setFont(materialIconsRoundFont);
    }

    for (auto const &label:sidebarButtonLabels) {
        label->setFont(proximusRegularFont);
    }

    for (auto const &label:statsLabelsText) {
        label->setFont(proximusRegularFont);
    }

    for (auto const &label:statsLabelsValue) {
        label->setFont(proximusRegularFont);
    }

    for (auto const &label:statsLabelsIcon) {
        label->setFont(materialIconsRoundFont);
    }

    for (auto const &label:statsLabelsUnits) {
        label->setFont(proximusRegularFont);
    }

    for (auto const &label:settingsLabelsText) {
        label->setFont(proximusRegularFont);
    }

    for (auto const &label:settingsLabelsIcon) {
        label->setFont(materialIconsRoundFont);
    }

    ui->label_connection_status->setFont(materialIconsRoundFont);
    ui->label_serial_port_name->setFont(proximusRegularFont);

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
