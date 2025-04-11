#include <iostream>
using namespace std;

class Fraction 
{
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    Fraction operator+(Fraction other)
 {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(Fraction other)
 {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(Fraction other)
 {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(Fraction other)
 {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, Fraction frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

int main() 
{
    Fraction f1(1, 2), f2(3, 4);
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f1 + f2: " << f1 + f2 << endl;
    cout << "f1 - f2: " << f1 - f2 << endl;
    cout << "f1 * f2: " << f1 * f2 << endl;
    cout << "f1 / f2: " << f1 / f2 << endl;
}