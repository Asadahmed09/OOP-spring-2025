#include <iostream>
using namespace std;
class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    Account(int accNum, double bal, string name)
    {
        accountNumber = accNum;
        balance = bal;
        accountHolderName = name;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        }
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation depends on account type" << endl;
    }

    virtual void printStatement()
    {
        cout << "Account Statement for " << accountHolderName << " (Account " << accountNumber << ")\n";
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo()
    {
        cout << "Account Holder: " << accountHolderName << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string name, double rate, double minBal)
        : Account(accNum, bal, name), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest()
    {
        double interest = balance * (interestRate / 100);
        cout << "Interest earned: " << interest << endl;
    }

    void withdraw(double amount)
    {
        if (balance - amount < minimumBalance)
        {
            cout << "Withdrawal denied! Minimum balance requirement not met.\n";
        }
        else
        {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int accNum, double bal, string name)
        : Account(accNum, bal, name) {}

    void withdraw(double amount)
    {
        cout << "Checking Account withdrawal: ";
        Account::withdraw(amount);
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    int maturityDate; 

public:
    FixedDepositAccount(int accNum, double bal, string name, double rate, int maturity)
        : Account(accNum, bal, name), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest()
    {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed deposit interest earned: " << interest << endl;
    }

    void withdraw(double amount)
    {
        cout << "Withdrawal not allowed before maturity period (" << maturityDate << " months).\n";
    }
};

int main()
{
    SavingsAccount sa(101, 5000, "Asad Ahmed", 2.5, 1000);

    cout << "\n=== Savings Account ===\n";
    sa.deposit(1000);
    sa.withdraw(4500);
    sa.calculateInterest();
    sa.printStatement();

    return 0;
}
