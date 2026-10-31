#include "Rational.h"
#include <sstream>

using namespace std;

void Rational::normalizeSign() {
    if (value.getSecond() < 0) {
        value.setFirst(-value.getFirst());
        value.setSecond(-value.getSecond());
    }
}

bool Rational::setDenominator(int den) {
    if (den == 0) {
        cerr << "помилка: «наменник не може дор≥внювати нулю!" << endl;
        return false;
    }
    value.setSecond(den);
    normalizeSign();
    return true;
}

void Rational::setNumerator(int num) { value.setFirst(num); }

Rational::Rational() {
    setNumerator(0);
    setDenominator(1);
}

Rational::Rational(int num, int den) {
    setNumerator(num);
    if (!setDenominator(den)) {
        setDenominator(1);
    }
}

Rational::Rational(const Rational& r) : value(r.value) {}

void Rational::setPair(const Pair& p) {
    setNumerator(p.getFirst());
    if (!setDenominator(p.getSecond())) {
        setDenominator(1);
    }
}

Pair Rational::getPair() const { return value; }
int Rational::getNumerator() const { return value.getFirst(); }
int Rational::getDenominator() const { return value.getSecond(); }

Rational& Rational::operator=(const Rational& r) {
    if (this != &r) {
        value = r.value;
    }
    return *this;
}

Rational::operator string() const {
    stringstream ss;
    ss << getNumerator() << "/" << getDenominator();
    return ss.str();
}

Rational& Rational::operator++() {
    setNumerator(getNumerator() + getDenominator());
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    ++(*this);
    return temp;
}

Rational& Rational::operator--() {
    setNumerator(getNumerator() - getDenominator());
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    --(*this);
    return temp;
}

ostream& operator<<(ostream& out, const Rational& r) {
    out << static_cast<string>(r);
    return out;
}

istream& operator>>(istream& in, Rational& r) {
    int num, den;
    cout << "¬вед≥ть чисельник: ";
    in >> num;
    r.setNumerator(num);
    do {
        cout << "¬вед≥ть знаменник (не 0): ";
        in >> den;
    } while (!r.setDenominator(den));
    return in;
}

bool operator==(const Rational& r1, const Rational& r2) {
    return (r1.getNumerator() * r2.getDenominator()) == (r2.getNumerator() * r1.getDenominator());
}
bool operator!=(const Rational& r1, const Rational& r2) {
    return !(r1 == r2);
}
bool operator>(const Rational& r1, const Rational& r2) {
    return (r1.getNumerator() * r2.getDenominator()) > (r2.getNumerator() * r1.getDenominator());
}
bool operator<(const Rational& r1, const Rational& r2) {
    return r2 > r1;
}
bool operator>=(const Rational& r1, const Rational& r2) {
    return (r1 > r2) || (r1 == r2);
}
bool operator<=(const Rational& r1, const Rational& r2) {
    return (r1 < r2) || (r1 == r2);
}