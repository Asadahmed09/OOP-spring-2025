#include<iostream>
using namespace std;
class Currency
{
  public:
  double amount;
  string CurrencyCode,CurrencySymbol;
  double ExchangeRate;
  Currency(double amount,string cc,string cs,double er):amount(amount),CurrencyCode(cc),
  CurrencySymbol(cs),ExchangeRate(er){}
  Currency(){amount = 3;}
  virtual void convertToBase(){cout << "Converting to Base" << endl;}
  virtual void convertToTargetCurrency() { cout << "Converting to Target currency" << endl; }
  virtual void displayCurrent()
  {
    cout << "Amount of Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "CurrencySymbol  : " << CurrencySymbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
class Dollar : public Currency
{
  private:
  double amount,ExchangeRate;
  string CurrencySymbol,CurrencyCode;
  public:
    void convertToBase() 
    { cout << "Converting to Base" << endl; 
      cout << "One "<< CurrencySymbol << " equals to " << ExchangeRate << "Base Currency" << endl; 
      cout << "now , " << amount << " " << CurrencySymbol << " are " << ExchangeRate*amount << " Base Currency" << endl;  
    }
    void displayCurrent()
     { cout << "Amount of Currency : " << amount << endl;
       cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
       cout << "CurrencySymbol  : " << CurrencySymbol << endl;
       cout << "Code of Currency : " << CurrencyCode << endl; }
};
class Euro : public Currency
{
private:
  double amount, ExchangeRate;
  string CurrencySymbol, CurrencyCode;

public:
  void convertToBase()
  {
    cout << "Converting to Base" << endl;
    cout << "One " << CurrencySymbol << " equals to " << ExchangeRate << "Base Currency" << endl;
    cout << "now , " << amount << " " << CurrencySymbol << " are " << ExchangeRate * amount << " Base Currency" << endl;
  }
  void displayCurrent()
  {
    cout << "Amount of Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "CurrencySymbol  : " << CurrencySymbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
class Rupee : public Currency
{
private:
  double amount, ExchangeRate;
  string CurrencySymbol, CurrencyCode;

public:
  Rupee(double amount, string cc, string cs, double er) : amount(amount),CurrencyCode(cc),CurrencySymbol(cs), ExchangeRate(er),
  Currency(amount,cc,cs,er){}
  Rupee(){cout << amount << endl;}
  void convertToBase()
  {
    cout << "Converting to Base" << endl;
    cout << "One " << CurrencySymbol << " equals to " << ExchangeRate << " Base Currency" << endl;
    cout << "now , " << amount << " " << CurrencySymbol << " are " << ExchangeRate * amount << " Base Currency" << endl;
  }
  void displayCurrent()
  {
    cout << "Amount of Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "CurrencySymbol  : " << CurrencySymbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
int main()
{
  cout << "Running " << endl;
  Currency c(10,"Dollar","$",100);
  c.displayCurrent();
  Rupee r(100, "RUpee", "pkr", 200);
  r.displayCurrent();
  r.convertToBase();
}
