#include<iostream>
using namespace std;
class device
{
  protected:
  int id;
  bool status;
  device(int id,bool s):id(id),status(s){}
  void displayDetails()
  {
    cout << "Device ID is : " << id << endl;
    cout << "Device Status is : " << status << endl;
  }
};
class SmartPhone : public device 
{
  protected:
  float screensize;
  SmartPhone(float screensize,int id , bool status):screensize(screensize),device(id,status){}
  void displaydetails()
  {
    displayDetails();
    cout << "Screen Size is : " << screensize << endl;
  }
};
class SmartWatch : public device 
{
  protected:
  bool HeartRateMonitor;
  SmartWatch(bool HeartRateMonitor,int id , bool status):HeartRateMonitor(HeartRateMonitor),device(id,status){}
  void displaydetails1()
  {
    // displayDetails();
    cout << "Heart Rate Monitor is : " << HeartRateMonitor << endl;
  }
};
class SmartWearable : public SmartPhone,public SmartWatch
{
  public:
  int stepCounter;
  SmartWearable(int stepcounter,float screensize,bool HeartRateMonitor, int id, bool status):
  stepCounter(stepcounter),SmartPhone(screensize,id,status),SmartWatch(HeartRateMonitor,id,status){}
  void displayalldetails()
  {
    displaydetails();
    displaydetails1();
    cout << "Step counter is  : " << stepCounter << endl;
  }
};
int main()
{
  SmartWearable one(5,4,1,1,1);
  one.displayalldetails();
}
