#pragma once
#include "Pair.h"
#include <string>
#include <iostream>

using namespace std;

class Rational {
private:
    Pair value;
    void normalizeSign();

public:
    Rational();
    Rational(int num, int den);
    Rational(const Rational& r); 

    void setPair(const Pair& p);
    Pair getPair() const;
    void setNumerator(int num);
    bool setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;

    Rational& operator=(const Rational& r);

    operator string() const;

    Rational& operator++();    
    Rational operator++(int);  
    Rational& operator--();    
    Rational operator--(int);  

    friend ostream& operator<<(ostream& out, const Rational& r);
    friend istream& operator>>(istream& in, Rational& r);

    friend bool operator==(const Rational& r1, const Rational& r2);
    friend bool operator!=(const Rational& r1, const Rational& r2);
    friend bool operator>(const Rational& r1, const Rational& r2);
    friend bool operator<(const Rational& r1, const Rational& r2);
    friend bool operator>=(const Rational& r1, const Rational& r2);
    friend bool operator<=(const Rational& r1, const Rational& r2);
};