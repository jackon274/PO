#include "Kalkulator.h"
#include <cmath>
#include <iostream>
using std::cerr;

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

void Kalkulator::clearResult() {
    mem.clearMemory();
}

double Kalkulator::displayResult() {
    return mem.readMemory();
}



void Kalkulator::convertSystems (const int n, const int base_start, const int base_end) const {
    if (base_start <= 0 || base_end <= 0) {
        std::cerr << "Invalid input!";
        return;
    }
    if(base_start != 10) {
        int helper = n;
        int buf = 0;
        int digitCount = 0;
        while(n > 0) {
            buf += pow(10, digitCount++);
            helper /= 10;
        }
    }

}
