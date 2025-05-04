#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ofstream fout("sensor_log.txt");
  cout <<" position of pointer : " <<  fout.tellp() << endl;
  fout << "Sensor 1 : Graphics card sensor" << endl;
  cout << " position of pointer : " << fout.tellp() << endl;
  fout << "Sensor 2 : Khair bhai ka sensor" << endl;
  cout << " position of pointer : " << fout.tellp() << endl;
}
