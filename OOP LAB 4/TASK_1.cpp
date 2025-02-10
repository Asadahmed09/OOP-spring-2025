// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Book
{
    private:
    string title;
    float price;
    int* stock = new int;
    public:
    Book()
    {
        title = "Unknown";
        price = 0.0;
        *stock = 30;
    }
    void UpdateBookDetails()
    {
        cout << "Enter the title of Book : " << endl;
        getline(cin,title);
        cout << "Enter the price of Book : " << endl;
        cin >> price;
        cout << "Enter the Item to be added in stock : " << endl;
        int add;
        cin >> add;
        *stock+=add;
    }
    void simulateBookPurchase()
    {
        cout << "Enter the number of Books you want to Purchase " << endl;
        int no;
        cin >> no;
        if(*stock<1)
        {
            cout << "Sorry ! you do not have Enough inventory" << endl;
        }
        else if(*stock<5 && no > 5)
        {
            cout << "Low stock warning !\nNot enough books " << endl;
        }
        else if(*stock<5)
        {
            cout << "Low stock warning ! \nPurchase successfull!" << endl;
            *stock-=no;
        }
        else 
        {
            cout << "Purchase Successfull !" << endl << "At the price of " << price*no << endl << "of " << no << " Books " << endl;
            *stock-=no;
            
        }
    }
    void TrackStock()
    {
        cout << "The stock is " << *stock << endl;
    }
    ~Book()
    {
        delete stock;
    }
};
int main()
{
    Book b1;
    b1.UpdateBookDetails();
    b1.TrackStock();
    b1.simulateBookPurchase();
}
