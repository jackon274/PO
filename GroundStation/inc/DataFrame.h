//
// Created by Jacek Konderak on 19/05/2025.
//

#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <cstdint>
#include <variant>
#include <vector>


class DataFrame {
    uint32_t frameCount;
    uint32_t elapsedTime;
    int32_t longitude;
    int32_t latitude;
    uint32_t altitude;
    int16_t temperatureOutside;
    int16_t temperatureInside;
    uint8_t relativeHumidity;
    uint16_t ionizingRadiationCPM;
    uint8_t flags;
    uint32_t checksum;
    using PointerVariant = std::variant<uint8_t*, int16_t*, uint16_t*, int32_t*, uint32_t*>;
    std::vector <PointerVariant> dataPointers;
    public:
    uint32_t getFrameCount() const;
    uint32_t getElapsedTime() const;
    float getLongitude() const;
    float getLatitude() const;
    float getAltitudeMeters() const;
    float getTemperatureOutsideCentigrade() const;
    float getTemperatureInsideCentigrade() const;
    float getHumidityPercent() const;
    int getRadiationCPM() const;
    int getChecksum() const;
    DataFrame();
    const std::vector <PointerVariant> &getDataPointers() const;
};



#endif //DATAFRAME_H
