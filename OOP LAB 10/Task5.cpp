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
      cout << "File with the name " << fileName << " opened successfully.\n";
    }
    else
    {
      try
      {
        throw runtime_error("File not opened!");
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
      if (line[0] == '/' || line.empty())
        continue;

      istringstream ss(line);
      string type, id, name, yearStr, extra, certification;

      getline(ss, type, ',');
      getline(ss, id, ',');
      getline(ss, name, ',');
      getline(ss, yearStr, ',');
      getline(ss, extra, ',');
      getline(ss, certification, ',');

      cout << "\n---- Vehicle Details ----\n";
      cout << "Type: " << type << "\n";
      cout << "ID: " << id << "\n";
      cout << "Name: " << name << "\n";
      cout << "Year: " << yearStr << "\n";
      cout << "ExtraData: " << extra << "\n";
      cout << "Certification: " << certification << "\n";

      int year = stoi(yearStr);
      cout << "Converted Year (int): " << year << "\n";

      if (type == "AutonomousCar")
      {
        size_t colonPos = extra.find(':');
        if (colonPos != string::npos)
        {
          string softwareStr = extra.substr(colonPos + 1);
          float softwareVersion = stof(softwareStr);
          cout << "Software Version: " << softwareVersion << "\n";
        }
      }
      else if (type == "ElectricVehicle")
      {
        size_t colonPos = extra.find(':');
        if (colonPos != string::npos)
        {
          string batteryStr = extra.substr(colonPos + 1);
          int batteryCapacity = stoi(batteryStr);
          cout << "Battery Capacity: " << batteryCapacity << "\n";
        }
      }
      else if (type == "HybridTruck")
      {
        size_t cargoColon = extra.find(':');
        size_t pipe = extra.find('|');
        size_t batteryColon = extra.find(':', pipe);

        if (cargoColon != string::npos && pipe != string::npos && batteryColon != string::npos)
        {
          string cargoStr = extra.substr(cargoColon + 1, pipe - cargoColon - 1);
          string batteryStr = extra.substr(batteryColon + 1);

          int cargo = stoi(cargoStr);
          int battery = stoi(batteryStr);

          cout << "Cargo Capacity: " << cargo << "\n";
          cout << "Battery Capacity: " << battery << "\n";
        }
        else
        {
          cout << "Invalid format in ExtraData for HybridTruck.\n";
        }
      }
      else
      {
        cout << "Unknown vehicle type: " << type << "\n";
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
