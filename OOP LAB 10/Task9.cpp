#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  string FILENAME = "large.txt";
  fstream file(FILENAME,ios::in | ios::out | ios::app);
  file << "My name is Asad " << endl;
  file << "random text for checking " << endl;
  cout << "Pointer position : " << file.tellp() << endl;
  file << "Visual studio coding" << endl;
  cout << " Current pointer : " << file.tellg() << endl;
  file.seekp(0,ios::beg);
  cout << "New position after seek p : " << file.tellp() << endl;
  file.close();
  file.open(FILENAME);
  file << "I am studying in FAST nuces " << endl;
  char line[10];
  file.read(line,10);
  file.close();
}
