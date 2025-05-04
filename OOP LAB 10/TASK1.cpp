#include<iostream>
#include<fstream>
using namespace std;
class FileManagement
{
  private:
  ifstream fetch;
  string line;
  public:
  FileManagement(string fileName):fetch(fileName,ios::app)
  {
    if(fetch.is_open())
    {
      cout << "File with the name " << fileName << " opened successfull" << endl;
    }
    else
    {
      try
      {
        throw runtime_error("File not opened !");
      }
      catch(exception& e)
      {
        cout << e.what() << '\n';
      }
      
    }
  }

    void ReadFile()
    {
      while (getline(fetch,line))
      {
        cout << line << endl;
      }
      
    }
  
  };
int main()
{
  FileManagement f1("vehicle.txt");
  f1.ReadFile();
}
