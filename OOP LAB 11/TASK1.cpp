#include<iostream>
#include<exception>
using namespace std;
class InvalidValueException : public std::exception
{
  public:
    const char *what() const noexcept override
    {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }

};

void ValidateAge(int age)
{
  if(age <= 0 || age >=120)
  {
      throw InvalidValueException();
  }
}
int main()
{

  int age;
  cout << "Enter your age : " << endl;
  cin >> age;
  try
  {
    ValidateAge(age);
  }
  catch (exception &e)
  {
    cout << e.what() << endl;
  }
}
