#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "Memory.h"



class Kalkulator {
private:

public:
    Memory mem;
    void add(double n, Memory *memory = nullptr);
    void subtract(double n, Memory *memory = nullptr);
    void multiply(double n, Memory *memory = nullptr);
    void divide(double n, Memory *memory = nullptr);
    void modulo(double n, Memory *memory = nullptr);
    Kalkulator();
};





#endif //KALKULATOR_H
