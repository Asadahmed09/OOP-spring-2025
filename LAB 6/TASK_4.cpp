#include<iostream>
using namespace std;
class Account
{
  protected:
  int AccountNumber;
  float balance;
  Account(int accnum,float bal) : AccountNumber(accnum),balance(bal){}
  void displayDetails()
  {
    cout << "Account Number is : " << AccountNumber << endl; 
    cout << "Account Balance is : " << balance << endl; 
  }
};
class SavingsAccount : public Account
{
  public:
  float interestRate;
  SavingsAccount(float interestRate,int accountnumber,float balance) : interestRate(interestRate),Account(accountnumber,balance){}
  void displaydetails()
  {
    displayDetails();
    cout << "Interest Rate is : " << interestRate << endl;
  } 
};
class CheckingAccount : public Account
{
  public:
  float overDarftLimit;
  CheckingAccount(float overdraftlimit, int accountnumber, float balance) : overDarftLimit(overdraftlimit), Account(accountnumber, balance) {}
  void displaydetails()
  {
    displayDetails();
    cout << "Over Darft Limit is : " << overDarftLimit << endl;
  } 
};
int main()
{
  SavingsAccount user1(10,1010,5000);
  user1.displaydetails();
  CheckingAccount user2(20,1010,500);
  user2.displaydetails();
} 
