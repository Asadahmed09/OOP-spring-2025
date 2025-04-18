#include <iostream>
using namespace std;

class Vehicle
 {
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}

    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle 
{
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate()
{
        return rate;
    }

    void displayDetails()
 {
        cout << "Car Model : " << model << endl;
        cout << "Daily Rate : " << rate << endl;
    }
};

class Bike : public Vehicle 
{
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate()
{
        return rate;
    }

    void displayDetails()
 {
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rate: " << rate << endl;
    }
};

int main()
 {
    Vehicle* v1 = new Car("Toyota Corolla", 55.0);
    Vehicle* v2 = new Bike("Yamaha YBR", 25.0);

    v1->displayDetails();
    cout << "Rate for Car: " << v1->getDailyRate() << endl << endl;

    v2->displayDetails();
    cout << "Rate for Bike: " << v2->getDailyRate() << endl;

    delete v1;
    delete v2;

    return 0;
}
