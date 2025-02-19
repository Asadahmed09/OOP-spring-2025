#include<iostream>
using namespace std;
class battery
{
  public:
  int mah;
  battery()
  {
    mah = 0;
  }
};
class smartphone
{
  public:
  string name;
  battery b;
  smartphone(string name, int capacity) : name(name) {
    b.mah = capacity;
  }
  void show_details()
  {
    cout << "The name of smartphone is : " << name << endl << "The battery of smartphone is : " << b.mah << endl;
  }
};
int main()
{
 smartphone sp("Samsung deluxy banger",5000);
 sp.show_details(); 
}
