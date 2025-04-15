#include "Kalkulator.h"
#include <cmath>
#include <iostream>
#include "EasterEggWindow.h"
#include <cmath>
#include <QSystemTrayIcon>
#include <QString>
#include <cmath>

Kalkulator::Kalkulator() {
    operationStream << 0;
}

void openEasterEggWindow() {
    EasterEggWindow easterEgg;
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

void Kalkulator::square_root (double m, Memory *memory) {
    if (memory == nullptr)
        memory = &mem;

    if(m != 0 && mem.memory != 0)
        std::cerr << "Error both first digit and memory non zero!";
        mem.memory = sqrt(m);
}

void Kalkulator::divide(double m, double n, Memory *memory) {
    if(n == 0) {
        handleException(1);
        return;
    }

    if (memory == nullptr)
        memory = &mem;

    if (m != 0)
        mem.memory = m / n;
    else
    mem.memory /= n;
}

void Kalkulator::modulo(double m, double n, Memory *memory) {
    if(n == 0) {
        handleException(2);
        return;
    }
    if (memory == nullptr)
        memory = &mem;

    if(m != 0 && mem.memory != 0)
        std::cerr << "Error both first digit and memory non zero!";
    else if (m != 0)
        mem.memory = fmod(m, n);
    else
        mem.memory = fmod(mem.memory, n);

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
        break;
    case '$':
        square_root(tmp1);
        break;
    case '%':
        modulo(tmp1, tmp2);
        break;
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

void Kalkulator::handleException(char event) {
    QString komunikat;
    static QSystemTrayIcon trayIcon;

    if (!trayIcon.isVisible()) {
        trayIcon.setIcon(QIcon::fromTheme("dialog-information"));
        trayIcon.setVisible(true);
    }
    switch (event) {
    case 1:
        komunikat = "Dzielenie przez zero nie jest dozwolone!";
        break;
    case 2:
        komunikat = "Operacja modulo nie może przyjmować zera!";
        break;
    case 3:
        komunikat = "Pierwiastek z liczby ujemnej nie jest dozwolony!";
    }
    trayIcon.showMessage("Błąd", komunikat, QSystemTrayIcon::Critical, 3000);
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

double Kalkulator::updateDisplayHelper() {
    double tmp = 0;
    displayStream >> tmp;
    std::cout << std::endl << "tmp = " << tmp << std::endl;
    displayStream.clear();
    displayStream.str("");
    displayStream << tmp;
    return tmp;
}
