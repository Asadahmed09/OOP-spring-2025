#include <iostream>
#include <cmath>
#include <typeinfo>
#include <type_traits>
using namespace std;

class NegativeNumberException : public exception
{
public:
  const char *what() const noexcept override
  {
    return "NegativeNumberException - Input must be non-negative!";
  }
};

class InvalidTypeException : public exception
{
public:
  const char *what() const noexcept override
  {
    return "InvalidTypeException - Non-numeric type detected!";
  }
};

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, double>::type
sqrt_custom(T num)
{
  if (num < 0)
    throw NegativeNumberException();
  return sqrt(num);
}

template <typename T>
typename std::enable_if<!std::is_arithmetic<T>::value, double>::type
sqrt_custom(T)
{
  throw InvalidTypeException();
}

int main()
{
  try
  {
    cout << "sqrt(-4): ";
    cout << sqrt_custom(-4) << endl;
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    cout << "sqrt(\"hello\"): ";
    cout << sqrt_custom(string("hello")) << endl;
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }

  try
  {
    cout << "sqrt(16): ";
    cout << sqrt_custom(16) << endl;
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }

}
