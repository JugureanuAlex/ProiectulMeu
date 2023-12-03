#include "Clase.h"
#include <cstring>
#include <cstdlib>
#include <stack>

Expresie::Expresie() : expresie(nullptr) {}

Expresie::Expresie(const char* exp) {
    expresie = new char[strlen(exp) + 1];
    strcpy(expresie, exp);
}

Expresie::Expresie(const Expresie& other) {
    expresie = new char[strlen(other.expresie) + 1];
    strcpy(expresie, other.expresie);
}

Expresie::~Expresie() {
    delete[] expresie;
}

Expresie& Expresie::operator=(const Expresie& other) {
    if (this != &other) {
        delete[] expresie;
        expresie = new char[strlen(other.expresie) + 1];
        strcpy(expresie, other.expresie);
    }
    return *this;
}

char* Expresie::getExpresie() const {
    return expresie;
}

void Expresie::setExpresie(const char* exp) {
    delete[] expresie;
    expresie = new char[strlen(exp) + 1];
    strcpy(expresie, exp);
}

std::ostream& operator<<(std::ostream& os, const Expresie& exp) {
    os << exp.expresie;
    return os;
}

double Calculator::evaluate(const Expresie& exp) {
    try {
        return calculareRezultat(exp.getExpresie());
    }
    catch (const char* mesaj) {
        procesareEroare(mesaj);
        return 0.0;
    }
}

bool Calculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#';
}

void Calculator::procesareEroare(const char* mesaj) {
    std::cout << "Eroare: " << mesaj << std::endl;
}

double Calculator::calculareRezultat(const char* exp) {
    std::stack<double> stiva;
    int lungime = strlen(exp);

    for (int i = 0; i < lungime; ++i) {
        if (isdigit(exp[i])) {
            stiva.push(atof(&exp[i]));
            while (isdigit(exp[i]) || exp[i] == '.') {
                ++i;
            }
            --i;
        }
        else if (isOperator(exp[i])) {
            if (stiva.size() < 2) {
                throw "Expresie invalida";
            }

            double op2 = stiva.top();
            stiva.pop();
            double op1 = stiva.top();
            stiva.pop();

            double rezultat = operatie(op1, exp[i], op2);
            stiva.push(rezultat);
        }
    }

    if (stiva.size() != 1) {
        throw "Expresie invalida";
    }

    return stiva.top();
}

double Calculator::operatie(double op1, char oper, double op2) {
    switch (oper) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0) {
            throw "Impartire la zero";
        }
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    case '#':
        if (op2 == 0) {
            throw "Radical din ordin zero";
        }
        return pow(op1, 1 / op2);
    default:
        throw "Operator necunoscut";
    }
}

Eroare::Eroare(const char* msg) {
    mesaj = new char[strlen(msg) + 1];
    strcpy(mesaj, msg);
}

Eroare::~Eroare() {
    delete[] mesaj;
}

char* Eroare::getMesaj() const {
    return mesaj;
}
