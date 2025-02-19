#include<iostream>
using namespace std;
class professor
{
public:
  string department;
  string name;
  void set_data(string name , string dep)
  {
    this-> name = name;
    this-> department = dep; 
  }
  professor(string name, string dep) : name(name), department(dep) {}
};
class University
{
  public:
  int count = 0;
  professor **p;
  string Uniname;
  University(string name,int size): Uniname(name){
    p = new professor*[size];
  }
  void addProfessors(professor* pro)
  {
    p[count++] = pro;
  }


  void display()
  {
    for(int i = 0 ; i < count ; i++)
    cout << "The name of professor is : " << p[i]->name << endl << "The name of department is : " << p[i]->department << endl;
  }
  ~University()
  {
    for (int i = 0; i < count; i++)
    {
      delete p[i];
    }
    delete[] p;
  }
};
int main()
{
  int select;
  string uniname;
  int size;
  cout << "Enter the name of University: ";
  cin >> uniname;
  cout << "Enter the size of Professor Array: ";
  cin >> size;
  University u(uniname, size);
  while (true)
  {
    cout << "1- Add Professors\n2- Display University\n3- Exit" << endl;
    cin >> select;

    if (select == 1)
    {
      string name, dep;
      cout << "Enter the name of Professor: ";
      cin >> name;
      cout << "Enter the name of Department: ";
      cin >> dep;

      professor *newProf = new professor(name, dep);
      u.addProfessors(newProf);
    }
    else if (select == 2)
    {
      u.display();
    }
    else
    {
      break;
    }
  }
}
