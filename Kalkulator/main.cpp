#include <iostream>
using namespace std;

class Memory {
public:
    Memory();
    double memory;
    void clearMemory();
    double readMemory() const;
};


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


Kalkulator::Kalkulator() {}

Memory::Memory() {
    memory = 0;
}

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

void Memory::clearMemory() {
    memory = 0;
}

double Memory::readMemory() const{
    return memory;
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

