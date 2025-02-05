#include"iostream"
using namespace std;
class MarkerPen
{
  private:
  string brand;
  string color;
  float inkLevel;
  string refillability;
  public:
  MarkerPen(string brand , string c ,float inklvl , string rfl)
  {
    this->brand = brand;
    color = c;
    inkLevel = inklvl;
    refillability = rfl;
  }
  void write()
  {
    inkLevel--;
  }
  void refill()
  {
    if(refillability == "yes")
    {
      inkLevel = 10;
    }
    
  }
  void checkMarker()
  {
    cout << "The brand of Marker is : " << brand << endl;
    cout << "The Color of Marker is : " << color << endl;
    cout << "The Ink Level of Marker is : " << inkLevel << endl;
    cout << "Refillability feature of Marker  : " << refillability << endl;
  }

};
int main()
{
  int select;
  string name,color,refill;
  float level;
  cout << "hello Ahmed \n please input all tha data in sequence \n1-Name of brand of Maker\n2-Color of marker\n3-Inklevel of Marker(not more then 10)\n4-is is refillable(Yes or NO)" << endl;
  cin >> name >> color >> level >> refill;
  MarkerPen m = {name,color,level,refill};
  while(1)
  {
    cout << "Select the operation you want to perform : " << endl;
    cout << "1-Write with Marker\n2-Refill the Marker if it is refillable\n3-Check the status of Marker \n4-Exit (press any key except first three)" << endl;
    cin >> select;
    if (select ==1 )
    {
      m.write();
    }
    else if(select == 2)
    {
      m.refill();
    }
    else if(select == 3)
    {
      m.checkMarker();
    }
    else 
    break;
  }
}
