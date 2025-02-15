// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Book
{
private:
  string title;
  float price;
  int *stock = new int;
  float totalPrice;
public:
  Book(float p,string title,int s)
  {
    this->title = title;
    price = p;
    *stock = s;
    totalPrice+=price*(*stock);
  }
  Book()
  {
    title = "Unknown";
    price = 0.0;
    *stock = 30;
    totalPrice = price;
  }
  float applyDiscount(int purchaseItem)
  {
    float newprice;float discount;
    if(purchaseItem > 5 && purchaseItem <= 10)
    {
      discount = (price*purchaseItem)*0.05;
      return discount;
    }
    else if(purchaseItem > 10)
    {
      discount = (price*purchaseItem)*0.10;
      return discount;
    }
    return 0;
  }
  void UpdateBookDetails()
  {
    cout << "Enter the title of Book : " << endl;
    getline(cin, title);
    cout << "Enter the price of Book : " << endl;
    cin >> price;
    cout << "Enter the Item to be added in stock : " << endl;
    int add;
    cin >> add;
    *stock += add;
    totalPrice+=(price*add);
    cout << "Updated successfull and The total price for Added " << add << " BOOks is : " << totalPrice
    << endl; 
  }
  void simulateBookPurchase()
  {
    cout << "Enter the number of Books you want to Purchase " << endl;
    int no;
    cin >> no;
    float disc = applyDiscount(no);
    if (*stock < no)
    {
      cout << "Sorry ! you do not have Enough inventory\nThe remaining stock is "<< *stock << endl;
    }
    else if (*stock < 5)
    {
      cout << "Low stock warning ! \nPurchase successfull!" << endl;
      *stock -= no;
      float finalPrice = (price * no) - disc;
      totalPrice -= finalPrice;
    }
    else
    {
      float finalPrice = (price * no)- disc;
      cout << "Purchase Successfull !" << endl
           << "At the price of " << price * no << endl
           << "And Discount is " << disc << endl
           << "SO final price is " <<finalPrice << endl
           << "of " << no << " Books " << endl;
      *stock -= no;
      totalPrice -= finalPrice;
    }
  }
  void TrackStock()
  {
    cout << "The stock is " << *stock << endl;
    cout << "The price of stock is " << totalPrice << endl;
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
  b1.simulateBookPurchase();
  b1.TrackStock();
}
