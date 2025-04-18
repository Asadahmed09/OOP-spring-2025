#include<iostream>
#include "book.h"
using namespace std;
Book::Book(string title ,string author , string ISBN)
{
  this->author = author;
  this->title = title ;
  this->ISBN = ISBN;
  cout << "Constructor Called " << endl;
}
string Book::GetTitle()
{
  return title;
}
string Book::GetAuthor()
{
  return author;
}
string Book::GetISBN()
{
  return ISBN;
}
