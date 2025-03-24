#include <iostream>
#include "Kalkulator.h"
using namespace std;


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

