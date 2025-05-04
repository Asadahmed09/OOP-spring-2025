#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  const string fileName = "data_records.txt";

  {
    ofstream fileOut(fileName);
    fileOut << "Record 1\n";
    fileOut << "Record 2\n";
    fileOut << "Record 3\n";
    fileOut << "Record 4\n";
    fileOut.close();
    cout << "File created with 4 sample records.\n";
  }

  ifstream fileIn(fileName);
  if (!fileIn)
  {
    cerr << "Couldn't open the file for reading.\n";
    return 1;
  }

  const int recordSize = 8;
  const int recordNumber = 3;
  int byteOffset = (recordNumber - 1) * recordSize;

  fileIn.seekg(byteOffset, ios::beg);

  string selectedRecord;
  getline(fileIn, selectedRecord);
  cout << "The 3rd record is: " << selectedRecord << endl;

  fileIn.close();

  return 0;
}
