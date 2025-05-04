#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InventoryItem
{
  int itemID;
  char itemName[20];
};

int main()
{

  InventoryItem item1;
  item1.itemID = 101;
  strcpy(item1.itemName, "Graphics Card");

  ofstream outFile("inventory.dat", ios::binary);
  if (!outFile)
  {
    cerr << "Error opening file for writing!" << endl;
    return 1;
  }

  outFile.write(reinterpret_cast<char *>(&item1), sizeof(InventoryItem));
  outFile.close();
  cout << "Item written to file.\n";

  InventoryItem item2;

  ifstream inFile("inventory.dat", ios::binary);
  if (!inFile)
  {
    cerr << "Error opening file for reading!" << endl;
    return 1;
  }

  inFile.read(reinterpret_cast<char *>(&item2), sizeof(InventoryItem));
  inFile.close();

  cout << "\nLoaded from file:\n";
  cout << "Item ID: " << item2.itemID << endl;
  cout << "Item Name: " << item2.itemName << endl;

}
