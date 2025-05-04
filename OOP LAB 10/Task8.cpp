#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  int BLOCK_SIZE = 5;
  string FILENAME = "config.txt";

  {
    ofstream outFile(FILENAME, ios::binary);
    outFile << "AAAAA" << "BBBBB" << "CCCCC";
    outFile.close();
    cout << "Initial file created with content: AAAAABBBBBCCCCC\n";
  }

  fstream file(FILENAME, ios::in | ios::out | ios::binary);
  if (!file)
  {
    cerr << "Error opening file for update!" << endl;
    return 1;
  }

  file.seekp(BLOCK_SIZE, ios::beg);

  file << "XXXXX";


  file.close();
  {
    ifstream inFile(FILENAME);
    string content;
    getline(inFile, content);
    inFile.close();

    cout << "Updated file content: " << content << endl;
  }

  return 0;
}
