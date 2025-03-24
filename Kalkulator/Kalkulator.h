#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "Memory.h"


class Kalkulator {
    Memory mem;
public:
    void add(double n, Memory *memory = nullptr);
    void subtract(double n, Memory *memory = nullptr);
    void multiply(double n, Memory *memory = nullptr);
    void divide(double n, Memory *memory = nullptr);
    void modulo(double n, Memory *memory = nullptr);
    void convertSystems (const int n, const int base_start, const int base_end = 10) const;
    void clearResult();
    double displayResult();
    Kalkulator();
};





#endif //KALKULATOR_H
