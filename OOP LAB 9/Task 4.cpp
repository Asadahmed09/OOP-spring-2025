#include <iostream>
using namespace std;
class PaymentMethods
{
public:
  virtual void ProcessPayment(double amount) = 0;
};
class CreditCard : public PaymentMethods
{
private:
  string CardNumber;

public:
  CreditCard(string CardNumber) : CardNumber(CardNumber)
  {
    cout << "Card Number assigned Sucessfully : " << CardNumber << endl;
  }
  void ProcessPayment(double amount)
  {
    cout << "The Payment of " << amount << " is in queue" << endl;
  }
};
class DigitalWallets : public PaymentMethods
{
private:
  double balance;

public:
  DigitalWallets(double balance) : balance(balance)
  {
    cout << "Digital wallet is created and inital balance is " << balance << endl;
  }
  void ProcessPayment(double amount)
  {
    if (balance >= amount)
    {
      cout << "Payment is Succesfull ! of Amount : " << amount << endl;
      balance -= amount;
      cout << "Remaining Balance is " << balance << endl;
    }
    else
    {
      cout << "Insufficient Balance : " << balance << " for Transaction : " << amount << endl;
    }
  }
};
int main()
{
  CreditCard card1("AX100BDKJ");
  DigitalWallets wallet1(10000);
  card1.ProcessPayment(5000);
  wallet1.ProcessPayment(5000);
}
