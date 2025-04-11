#include <iostream>
using namespace std;

class Currency 
{
    double value;

public:
    Currency(double val = 0.0) : value(val) {}

    Currency operator-()
 {
        return Currency(-value);
    }

    Currency operator+(Currency other) 
{
        return Currency(value + other.value);
    }

    Currency operator-(Currency other)
 {
        return Currency(value - other.value);
    }

    Currency& operator+=(Currency other)
 {
        value += other.value;
        return *this;
    }

    Currency& operator-=(Currency other) 
{
        value -= other.value;
        return *this;
    }

    friend ostream& operator<<(ostream& os, Currency curr)
 {
        os << "dollar $  = " << curr.value;
        return os;
    }
};

int main() 
{
    Currency a(50.0), b(30.5);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    Currency c = a + b;
    cout << "a + b: " << c << endl;

    Currency d = a - b;
    cout << "a - b: " << d << endl;

    Currency e = -a;
    cout << "-a: " << e << endl;

    a += b;
    cout << "a after += b: " << a << endl;

    a -= b;
    cout << "a after -= b: " << a << endl;
}