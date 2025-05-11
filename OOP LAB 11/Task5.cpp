#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class InsufficientFundsException : public exception
{
  string message;

public:
  InsufficientFundsException(double deficit)
  {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "InsufficientFundsException - Deficit: " << deficit;
    message = ss.str();
  }
  const char *what() const noexcept
  {
    return message.c_str();
  }
};

template <typename T>
class BankAccount
{
  T balance;

public:
  BankAccount(T initial) : balance(initial) {}

  void withdraw(T amount)
  {
    if (amount > balance)
      throw InsufficientFundsException(static_cast<double>(amount - balance));
    balance -= amount;
  }

  T getBalance() const { return balance; }
};

int main()
{
  BankAccount<double> acc(500.00);
  cout << "Balance: " << fixed << setprecision(2) << acc.getBalance() << endl;

  try
  {
    acc.withdraw(600.00);
  }
  catch (exception &e)
  {
    cout << "\nWithdraw 600: " << e.what() << endl;
  }

}
