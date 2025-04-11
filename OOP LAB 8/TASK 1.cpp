#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}

    friend class Librarian;
};

class Librarian {
public:
    void displayBookDetails(Book& book) {
        cout << "Title: " << book.title << ", Price: $" << book.price << endl;
    }

    void applyDiscount(Book& book, double discountPercent) {
        book.price *= (1 - discountPercent / 100);
    }
};

int main() {
    Book book("The C++ Programming Language", 45.99);
    Librarian lib;
    
    lib.displayBookDetails(book);
    lib.applyDiscount(book, 10);
    lib.displayBookDetails(book);
    
    return 0;
}