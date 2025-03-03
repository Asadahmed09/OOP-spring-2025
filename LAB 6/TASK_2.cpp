#include<iostream>
using namespace std;
class Vehicle

{
    protected :
    string brand;
    int speed;
    public:
    Vehicle(string name , int speed) :brand(name) , speed(speed) {}
    void display()
    {
        cout << "_________________________" << endl;
        cout << "name : " << brand << endl;
        cout << "speed of car : " << speed << endl;
    }
};
class car : public Vehicle
{
    public:
    int seats;
    car(string name,int speed,int seats) : Vehicle(name,speed) ,seats(seats){}
    void displaydetails()
    {
        display();
        cout << "seats are : " << seats<< endl;
    }
};
class electriccar : public car
{
    public:
    int battery;
    electriccar(string name,int speed,int seats,int battery) : car(name,speed,seats) ,battery(battery{}
    void displaydet()
    {
        displaydetails();
        cout << "battery : " << battery<< endl;
    }
};
int main()
{
    electriccar c1("tesla",200,2,600);
    c1.displaydetails();
}
