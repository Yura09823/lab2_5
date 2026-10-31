#include "Pair.h"
#include <sstream>

using namespace std;

Pair::Pair() : first(0), second(0) {}

Pair::Pair(int f, int s) : first(f), second(s) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

void Pair::setFirst(int f) { first = f; }
void Pair::setSecond(int s) { second = s; }
int Pair::getFirst() const { return first; }
int Pair::getSecond() const { return second; }

Pair& Pair::operator=(const Pair& p) {
    if (this != &p) {
        first = p.first;
        second = p.second;
    }
    return *this;
}

Pair::operator string() const {
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
}

Pair& Pair::operator++() {
    ++first;
    ++second;
    return *this;
}

Pair operator++(Pair& p, int) {
    Pair temp(p);
    ++p;
    return temp;
}
Pair Pair::operator++(int) {
    Pair temp(*this);
    first++;
    second++;
    return temp;
}

Pair& Pair::operator--() {
    --first;
    --second;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp(*this);
    first--;
    second--;
    return temp;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << static_cast<string>(p);
    return out;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "¬вед≥ть перше число: ";
    in >> p.first;
    cout << "¬вед≥ть друге число: ";
    in >> p.second;
    return in;
}

bool operator>(const Pair& p1, const Pair& p2) {
    return (p1.first > p2.first) || ((p1.first == p2.first) && (p1.second > p2.second));
}