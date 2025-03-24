#include "Kalkulator.h"

Kalkulator::Kalkulator() {}

void Kalkulator::add(double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;
    memory->memory += n;
}


void Kalkulator::subtract(double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;
    mem.memory -= n;
}

void Kalkulator::multiply(double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;
    mem.memory *= n;
}

void Kalkulator::divide(double n, Memory *memory) {
    if(n == 0) {
        cerr << "Division by zero!";
        return;
    }

    if (memory == nullptr)
        memory = &mem;
    mem.memory /= n;
}

void Kalkulator::modulo(double n, Memory *memory) {
    if(n == 0) {
        cerr << "Division by zero!";
        return;
    }
    if (memory == nullptr)
        memory = &mem;
    double a = memory->memory;
    a = a - static_cast <int> (n / a) * a;
    memory->memory = a;
}