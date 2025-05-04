#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class FileManagement
{
private:
  ifstream fetch;
  string line;

public:
  FileManagement(string fileName) : fetch(fileName)
  {
    if (fetch.is_open())
    {
      cout << "File with the name " << fileName << " opened successfull" << endl;
    }
    else
    {
      try
      {
        throw runtime_error("File not opened !");
      }
      catch (exception &e)
      {
        cout << e.what() << '\n';
      }
    }
  }

  void ReadFile()
  {
    while (getline(fetch, line))
    {
      if (line.empty() || line[0] == '/')
      {
        continue;
      }
      istringstream ss(line);
      string type, id, name, year, extra, certification;
      getline(ss, type, ',');
      getline(ss, id, ',');
      getline(ss, name, ',');
      getline(ss, year, ',');
      getline(ss, extra, ',');
      getline(ss, certification, ',');

      int YEAR = stoi(year);
      cout << "Year in INT : " << YEAR << endl;
      

      cout << "Type: " << type << "\n";
      cout << "ID: " << id << "\n";
      cout << "Name: " << name << "\n";
      cout << "Year: " << year << "\n";
      cout << "ExtraData: " << extra << "\n";
      cout << "Certification: " << certification << "\n";

      
      size_t colonPos = extra.find(':');
      if (colonPos != string::npos)
      {
        string numericStr = extra.substr(colonPos + 1);

        if (type == "AutonomousCar")
        {
          float softwareVersion = stof(numericStr); 
          cout << "Vehicle ID: " << id << " | Software Version: " << softwareVersion << "\n";
        }
        else if (type == "ElectricVehicle")
        {
          int batteryCapacity = stoi(numericStr);
          cout << "Vehicle ID: " << id << " | Battery Capacity: " << batteryCapacity << "\n";
        }
      }
      else
      {
        cout << "No colon found in ExtraData for vehicle ID: " << id << "\n";
      }
    }
  }
  ~FileManagement()
  {
    fetch.close();
  }
};
int main()
{
  FileManagement f1("vehicle.txt");
  f1.ReadFile();
}
