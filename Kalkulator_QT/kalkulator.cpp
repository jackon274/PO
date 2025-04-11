#include "Kalkulator.h"
#include <cmath>
#include <iostream>
#include "aboutwindow.h"
#include "dialog.h"
using std::cerr;

Kalkulator::Kalkulator() {
    operationStream << 0;
}

void openEasterEggWindow() {
    AboutWindow easterEgg;
    easterEgg.setModal(true);
    easterEgg.exec();
}

void Kalkulator::add(double m, double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;
    memory->memory += (n + m);
}


void Kalkulator::subtract(double m, double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;

    if(m != 0 && mem.memory != 0)
        std::cerr << "Error both first digit and memory non zero!";
    else if (m != 0)
        mem.memory = m - n;
    else
        mem.memory -= n;
}

void Kalkulator::multiply(double m, double n, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;

    if(m != 0 && mem.memory != 0)
        std::cerr << "Error both first digit and memory non zero!";
    else if (m != 0)
        mem.memory = m * n;
    else
        mem.memory *= n;
}

void Kalkulator::divide(double m, double n, Memory *memory) {
    if(n == 0) {
        handleException();
        return;
    }

    if (memory == nullptr)
        memory = &mem;

    if(m != 0 && mem.memory != 0)
        std::cerr << "Error both first digit and memory non zero!";
    else if (m != 0)
        mem.memory = m / n;
    else
    mem.memory /= n;
}

void Kalkulator::modulo(double n, Memory *memory) {
    if(n == 0) {
        handleException();
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
    displayStream.clear();
    displayStream.clear();
    displayStream.str("");
    operationStream.str("");
    operationStream << 0; //bez tego po użyciu przycisku AC pojawi się wartość 0, potem po wciśnięciu + i innej cyfry, po = pojawi się nadal 0 zamiast wyniku dodawania
}

double Kalkulator::displayResult() {
    return mem.readMemory();
}

 double Kalkulator::getMemoryVal(Memory *memory) {
     if (memory == nullptr)
         memory = &mem;
     return memory->memory;
 }


void Kalkulator::handleStream() {
    double tmp1, tmp2;
    char oper;
    operationStream >> tmp1 >> oper >> tmp2;
    if(operationStream.str() == SECRET_STRING)
        openEasterEggWindow();

    switch (oper) {
    case '+':
        add(tmp1, tmp2);
        break;
    case '-':
        subtract(tmp1, tmp2);
        break;
    case '*':
        multiply(tmp1, tmp2);
        break;
    case '/':
        divide(tmp1, tmp2);
    default:
        std::cerr << "Error";
        break;
    }

    operationStream.clear();
    displayStream.clear();
    operationStream.str("");
    displayStream.str("");
    operationStream << 0;


}

void Kalkulator::handleException() {
    cerr << "Division by zero!";
    Dialog divisionByZeroDialog;
    divisionByZeroDialog.setModal(true);
    divisionByZeroDialog.exec();
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

void Kalkulator::handleButtonClick(char buttonPressed) {
    if ( (buttonPressed >= '0' && buttonPressed <= '9') || buttonPressed == '.' ) {
        displayStream << buttonPressed;
        operationStream << buttonPressed;
        std::cout << "Pressed " << buttonPressed << std::endl;
    }
    else {
        operationStream << buttonPressed;
        displayStream.str("");
    }

}
