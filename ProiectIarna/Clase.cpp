#include "Clase.h"
#include <cstring>

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
    // Implementarea evaluării expresiei
    // Folosește stiva pentru a manipula expresia
    // ... implementarea ...
    return 0.0;
}

double Calculator::operatie(double op1, char oper, double op2) {
    // Implementarea operațiilor de bază
    // ... implementarea ...
    return 0.0;
}

double Calculator::operatieRadical(double op, double rad) {
    // Implementarea operației de radical
    // ... implementarea ...
    return 0.0;
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
