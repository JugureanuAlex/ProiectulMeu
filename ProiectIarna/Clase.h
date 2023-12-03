#pragma once


#include <iostream>

class Expresie {
private:
    char* expresie;

public:
    Expresie();
    Expresie(const char* exp);
    Expresie(const Expresie& other);
    ~Expresie();
    Expresie& operator=(const Expresie& other);

    char* getExpresie() const;
    void setExpresie(const char* exp);

    friend std::ostream& operator<<(std::ostream& os, const Expresie& exp);
};

class Calculator {
public:
    static double evaluate(const Expresie& exp);

private:
    static bool isOperator(char c);
    static void procesareEroare(const char* mesaj);
    static double calculareRezultat(const char* exp);
    static double operatie(double op1, char oper, double op2);
    static double operatieRadical(double op, double rad);
};

class Eroare {
private:
    char* mesaj;

public:
    Eroare(const char* msg);
    ~Eroare();

    char* getMesaj() const;
};
