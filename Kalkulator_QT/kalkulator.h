#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "Memory.h"
#include <stdint.h>
#include <sstream>
#include "mainwindow.h"
#define SECRET_STRING "021+37"

class Kalkulator {
    Memory mem;
    Memory lastOperationMemory;
public:
    void add(double m, double n = 0, Memory *memory = nullptr);
    void subtract(double m, double n = 0, Memory *memory = nullptr);
    void multiply(double m, double n = 0, Memory *memory = nullptr);
    void divide(double m, double n, Memory *memory = nullptr);
    void modulo(double n, Memory *memory = nullptr);
    void square_root (double m, Memory *memory = nullptr);
    void convertSystems (const int n, const int base_start, const int base_end = 10) const;
    void clearResult();
    double displayResult();
    double getMemoryVal(Memory *memory = nullptr);
    std::stringstream displayStream;
    std::stringstream operationStream;
    void handleStream();
    void handleException(char event);
    void handleButtonClick(char buttonPressed);
    double updateDisplayHelper();
    Kalkulator();
};

#endif // KALKULATOR_H
