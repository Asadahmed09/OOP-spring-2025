#include<iostream>
using namespace std;
class Humidity;
class Temperature
{
  private:
  int temperature;
  public:
  void set_temp(int temp)
  {
    temperature = temp;
  }
  friend void calculateHeatIndex(Temperature temp,Humidity humi );
};
class Humidity
{
  private:
  float humidity;
  public:
  void set_Humidity(float humi)
  {
    humidity  = humi;
  }
    friend void calculateHeatIndex(Temperature temp, Humidity humi);
};
void calculateHeatIndex(Temperature temp, Humidity humi)
{
  float T = (temp.temperature*(9/5)+32);
  float R = humi.humidity;
  float HI = -42.379 +
             2.04901523 * T +
             10.14333127 * R -
             0.22475541 * T * R -
             6.83783e-3 * T * T -
             5.481717e-2 * R * R +
             1.22874e-3 * T * T * R +
             8.5282e-4 * T * R * R -
             1.99e-6 * T * T * R * R;
             float HeatIndex = (HI-32)*5/9;
             cout << "The Heat Index in C : " << HeatIndex << endl;
             return ;
}
int main()
{

     Temperature tempObj;
  Humidity humiObj;
  tempObj.set_temp(32);
  humiObj.set_Humidity(70.0);
  calculateHeatIndex(tempObj, humiObj);
}
