#include<iostream>
using namespace std;
class Person
{
  public:
  int age;
  string name;
  Person(string name , int age) : age(age),name(name){}
  void DisplayDetails()
  {
    cout << "Name of Person is : " << name << endl;
    cout << "Age of Person is : " << age << endl;
  }
};
class Teacher : public Person
{
  public:
  string subject ;
  Teacher(string subject , string name , int age) : subject(subject),Person(name,age){}
   void displayDetails()
  {
    DisplayDetails();
    cout  << "Subject is  : " << subject << endl;
  }
};
class Researcher : public Teacher 
{
  public:
  string researcharea;
  Researcher(string researcharea,string subject,string name, int age) : researcharea(researcharea),Teacher(subject,name,age){}
  void displaydetails()
  {
    displayDetails();
    cout << "Reseacrh area is : " << researcharea << endl;
  }
};
class Professor : public Researcher
{
  public:
  int publications;
  Professor(int publications,string researcharea,string subject ,string name,int age) : publications(publications),Researcher(researcharea,subject,name,age){}
  void displayDETAILS()
  {
    displaydetails();
    cout << "Number of Publications : " << publications << endl;
  }
};
int main()
{
  Professor p1(5,"Machine learning","computer science","Asad Ahmed",18);
  p1.displayDETAILS();
}
