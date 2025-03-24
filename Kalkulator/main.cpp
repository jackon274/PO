#include <iostream>
#include "Kalkulator.h"


void menu(Kalkulator &calc) {
    int fun;
    double number;
    std::cout << "Wybierz co chcesz zrobic: \n";
    std::cout << "  1. Dodawanie\n";
    std::cout << "  2. Odejmowanie\n";
    std::cout << "  3. Mnożenie\n";
    std::cout << "  4. Dzielenie\n";
    std::cout << "  5. Modulo\n";
    std::cout << "  6. Wyczyść\n";
    std::cout << "Wybrana funkcja: ";
    std::cin >> fun;
    std::cout << "Liczba: ";
    std::cin >> number;

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
        break;
    case 6:
            calc.clearResult();
        break;

    default:
        std::cout << "Bledna komenda!\n";
        break;
    }
    std::cout << "Wynik to: " << calc.displayResult() << std::endl;
}



int main()
{
    Kalkulator calculator;
    while(true)
        menu(calculator);
    return 0;
}

