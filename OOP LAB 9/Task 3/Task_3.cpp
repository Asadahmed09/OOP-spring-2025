#include<iostream>
#include "book.h"
using namespace std;
int main()
{
  Book obj1("Man of Dignity","Asad Ahmed Janjua","123");
  cout << obj1.GetAuthor() << endl;
}
