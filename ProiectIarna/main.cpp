#include <iostream>
#include "Clase.h"

int main() {
    Expresie exp;
    char buffer[100];

    std::cout << "Introduceti o expresie sau scrieti 'exit' pentru a iesi:" << std::endl;

    while (true) {
        std::cin.getline(buffer, 100);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        exp.setExpresie(buffer);
        double rezultat = Calculator::evaluate(exp);
        std::cout << "Rezultat: " << rezultat << std::endl;
    }

    return 0;
}
