#include<iostream>
using namespace std;
class TeaMug
{
  private:
  string brand;
  string color;
  float capacity;
  float currentFillLevel;
  public:
  TeaMug(string b , string c, float cap , float cur)
  {
    brand = b;
    color = c;
    capacity = cap;
    currentFillLevel = cur;
  }
  void SipTea()
  {
    currentFillLevel -= 5;
  }
  void refillMug()
  {
    currentFillLevel = capacity;
  }
  void checkMug()
  {
    cout << "The brand of Cup is : " << brand << endl;
    cout << "The Color of Cup is : " << color << endl;
    cout << "The Capacity of Cup is : " << capacity << endl;
    cout << "The Current Tea Level is   : " << currentFillLevel << endl;
  }
};
int main()
{
  int select;
  string name,color;
  float capacity,currentlevel;
  cout << "hello Fatima \n please input all tha data in sequence \n1-Name of brand of Cup\n2-Color of Mug\n3-Capacity of Cup(not more then 100)\n4-Current Tea level" << endl;
  cin >> name >> color >> capacity >> currentlevel;
  TeaMug t = {name,color,capacity,currentlevel};
  while(1)
  {
    cout << "Please select the operation you want to perform " << endl;
    cout << "1-Sip Tea \n2-Refill the Mug\n3-Check the current Mug Tea\n4-Exit" << endl;
    cin >> select;
    if(select == 1)
    {
      t.SipTea();
    }
    else if(select == 2)
    {
      t.refillMug();
    }
    else if(select == 3)
    {
      t.checkMug();
    }
    else
    break;
  }
}
