#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pair {
private:
    int first;
    int second;

public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& p); 

    void setFirst(int f);
    void setSecond(int s);
    int getFirst() const;
    int getSecond() const;

    Pair& operator=(const Pair& p);

    operator string() const;

    Pair& operator++(); 
    Pair operator++(int);  
    Pair& operator--();    
    Pair operator--(int);  

    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
    friend bool operator>(const Pair& p1, const Pair& p2);
};