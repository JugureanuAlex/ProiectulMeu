#include "Clase.h"
#include <iostream>

using namespace std;

int main() {
    Expresie exp;
    char buffer[100];

    cout << "Introduceti o expresie sau scrieti 'exit' pentru a iesi:" << endl;

    while (true) {
        cin.getline(buffer, 100);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        exp.setExpresie(buffer);
        double rezultat = Calculator::evaluate(exp);
        cout << "Rezultat: " << rezultat << endl;
    }

    return 0;
}
