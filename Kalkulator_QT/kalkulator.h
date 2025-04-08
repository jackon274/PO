#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "Memory.h"
#include <stdint.h>
#include <sstream>

class Kalkulator {
    Memory mem;
    Memory globalMemory;
    Memory lastOperationMemory;
    long displayVal; //temporary
public:
    void add(double m, double n = 0, Memory *memory = nullptr);
    void subtract(double m, double n = 0, Memory *memory = nullptr);
    void multiply(double n, Memory *memory = nullptr);
    void divide(double n, Memory *memory = nullptr);
    void modulo(double n, Memory *memory = nullptr);
    void convertSystems (const int n, const int base_start, const int base_end = 10) const;
    void clearResult();
    double displayResult();
    double getMemoryVal(Memory *memory = nullptr);
    std::stringstream displayStream;
    std::stringstream operationStream;
    void handleStream();
    Kalkulator();
};

#endif // KALKULATOR_H
