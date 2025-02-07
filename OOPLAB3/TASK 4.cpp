#include<iostream>
using namespace std;
class Laptop
{
  private:
  float ram;
  string brand;
  string model;
  string processor;
  float storage;
  public:
  Laptop()
  {
    ram = 0;
    brand = "NULL";
    model = "NULL";
    processor = "NULL";
    storage = 0;
  }
  void turnon_off()
  {
    cout << "Your laptop is turned on " << endl;
    cout << "Please enter the Specification of your laptop : " << endl;
    cout << "\n1-Enter the Brand of your Laptop : " << endl;
    cin >> brand;
    cout << "\n2-Enter the Model of your Laptop : " << endl;
    cin >> model;
    cout << "\n3-Enter the processor of your Laptop : " << endl;
    cin >> processor;
    cout << "\n4-Enter the ram of your Laptop : " << endl;
    cin >> ram;
    cout << "\n5-Enter the storage of your Laptop : " << endl;
    cin >> storage;
    cout << "Thanks ! Your specifications has been observed " << endl;
  }
  void Run_program()
  {
    cout << "This program is running !" << endl;
  }
  void check_specs()
  {
    cout << "The Brand : " << brand << endl;
    cout << "The Model : " << model << endl;
    cout << "The Processor : " << processor << endl;
    cout << "The Ram : " << ram << endl;
    cout << "The storage of your Model is : " << storage << endl;
  }
};
int main()
{
  cout << "Hey Bilal and Ayesha ! Please enter Run your Laptop One by One " << endl;
  Laptop b,a;
  int select,characterselect,oprselect;
  while(1)
  {
    cout << "Please select your Role " << endl;
    cout << "1: Bilal \n2: Ayesha" << endl;
    cin >> characterselect;
    if(characterselect == 1)
    {
      while(1)
      {
          cout << "Welcome Bilal \nPlease run your Program Accordingly " << endl;
          cout << "1-Turn ON/OFF \n2-RUN a program \n3-Check specs\n4-Exit" << endl;
          cin >> oprselect;
          if(oprselect == 1)
          {
            b.turnon_off();
          }
          else if(oprselect == 2)
          {
            b.Run_program();
          }
          else if(oprselect == 3)
          {
            b.check_specs();
          }
          else if(oprselect == 4)
          {
            break;
          }
      }

      
    }
    else if(characterselect== 2)
    {
      while (1)
      {
        cout << "Welcome Ayesha \nPlease run your Program Accordingly " << endl;
        cout << "1-Turn ON/OFF \n2-RUN a program \n3-Check specs\n4-Exit" << endl;
        cin >> oprselect;
        if (oprselect == 1)
        {
          a.turnon_off();
        }
        else if (oprselect == 2)
        {
          a.Run_program();
        }
        else if (oprselect == 3)
        {
          a.check_specs();
        }
        else if (oprselect == 4)
        {
          break;
        }
      }
    }
  }
  cout << "Now comparing Both Models " << endl;
  b.check_specs();
  a.check_specs();
}
