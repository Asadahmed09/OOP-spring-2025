#ifndef BOOK_H
#define BOOK_H
#include"iostream"
using namespace std;
class Book
{
  private:
  string title , author , ISBN ;
  public:
  Book(string title , string auhtor , string ISBN );
  string GetTitle();
  string GetAuthor();
  string GetISBN();
};
#endif
