#include <iostream>
using namespace std;

struct Memory {
public:
    Memory();
    double memory;
    void clearMemory();
    double readMemory();
};


struct Kalkulator {
public:
    void add(double n);
    void subtract(double n);
    void multiply(double n);
    void divide(double n);
    void modulo(double n);
    Kalkulator();
//private:
    Memory mem;
};


Kalkulator::Kalkulator() {}

Memory::Memory() {
    memory = 0;
}

void Kalkulator::add(double n) {
    mem.memory += n;
}


void Kalkulator::subtract(double n) {
    mem.memory -= n;
}

void Kalkulator::multiply(double n) {
    mem.memory *= n;
}

void Kalkulator::divide(double n) {
    mem.memory /= n;
}

void Memory::clearMemory() {
    memory = 0;
}

double Memory::readMemory() {
    return memory;
}

void Kalkulator::modulo(double n) {
    mem.memory - static_cast <int> (n / mem.memory) * mem.memory;
}


void menu(Kalkulator &calc) {
    int fun;
    double number;
    cout << "Wybierz co chcesz zrobic: \n";
    cout << "  1. Dodawanie\n";
    cout << "  2. Odejmowanie\n";
    cout << "  3. Mnożenie\n";
    cout << "  4. Dzielenie\n";
    cout << "  5. Modulo\n";
    cout << "Wybrana funkcja: ";
    cin >> fun;
    cout << "Liczba: ";
    cin >> number;

    switch (fun) {
    case 1:
        calc.add(number);
        break;
    case 2:
        calc.subtract(number);
        break;
    case 3:
        calc.multiply(number);
        break;
    case 4:
        calc.divide(number);
        break;
    case 5:
        calc.modulo(number);
    default:
        cout << "Bledna komenda!\n";
        break;
    }
    cout << calc.mem.readMemory();
}



int main()
{
    Kalkulator calculator;
    menu(calculator);
    return 0;
}

