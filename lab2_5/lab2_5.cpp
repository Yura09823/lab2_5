#include <iostream>
#include <Windows.h>
#include "Rational.h"

#pragma pack(push, 1)
struct PairPacked {
    int first;
    int second;
};
struct RationalPacked {
    PairPacked value;
};
#pragma pack(pop)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Розмір класу Pair без pack(1): " << sizeof(Pair) << " байт" << endl;
    cout << "Розмір класу Pair з pack(1): " << sizeof(PairPacked) << " байт" << endl;
    cout << "Розмір класу Rational без pack(1): " << sizeof(Rational) << " байт" << endl;
    cout << "Розмір класу Rational з pack(1): " << sizeof(RationalPacked) << " байт" << endl;

    cout << "\n--- Демонстрація класу Pair ---" << endl;
    Pair p1(5, 10);
    Pair p2;       
    cout << "Введіть дані для Pair p2:" << endl;
    cin >> p2;      
    Pair p3 = p1; 

    cout << "Пара 1: " << string(p1) << endl;
    cout << "Пара 2: " << p2 << endl;        
    cout << "Пара 3 (копія 1): " << p3 << endl;

    p3++;
    cout << "Пара 3 після p3++: " << p3 << endl;

    cout << "p1 більша за p2?: " << (p1 > p2 ? "Так" : "Ні") << endl;

    Rational r1(1, 2);
    Rational r2;

    cout << "\nСтворення r2 через введення з клавіатури:" << endl;
    cin >> r2;

    cout << "\nОб'єкти Rational:" << endl;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << string(r2) << endl;

    Rational r3 = r1;
    cout << "r3 (копія r1) = " << r3 << endl;
    ++r3;
    cout << "++r3 = " << r3 << endl;
    r3--;
    cout << "r3-- = " << r3 << endl;

    cout << "\nРезультати порівняння r1 та r2:" << endl;
    cout << "r1 == r2 : " << (r1 == r2 ? "Так" : "Ні") << endl;
    cout << "r1 != r2 : " << (r1 != r2 ? "Так" : "Ні") << endl;
    cout << "r1 > r2  : " << (r1 > r2 ? "Так" : "Ні") << endl;
    cout << "r1 < r2  : " << (r1 < r2 ? "Так" : "Ні") << endl;

    Rational fractions[3];
    fractions[0] = Rational(3, 4);
    fractions[1] = Rational(1, -4);
    fractions[2] = Rational(5, 1);

    for (int i = 0; i < 3; i++) {
        cout << "Дріб [" << i << "]: " << fractions[i] << endl;
    }

    return 0;
}