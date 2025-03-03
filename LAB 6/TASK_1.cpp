#include<iostream>
using namespace std;
class Employee

{
    protected :
    string name;
    float salary;
    public:
    Employee(string name , float salary) : name(name) , salary(salary) {}
    void display()
    {
        cout << "_________________________" << endl;
        cout << "name : " << name << endl;
        cout << "salary of employee : " << salary << endl;
    }
};
class Manager : public Employee
{
    public:
    float bonus;
    Manager(string name,float salary,float bonus) : Employee(name,salary) , bonus(bonus) {}
    void displaydetails()
    {
        display();
        cout << "Bonus is : " << bonus << endl;
    }
};
int main()
{
    Manager m1("asad",10000,10000);
    m1.displaydetails();
}
