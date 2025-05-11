#include <iostream>
#include <exception>
using namespace std;

class StackOverflowException : public exception
{
public:
  const char *what() const noexcept override
  {
    return "StackOverflowException - Stack is full!";
  }
};

class StackUnderflowException : public exception
{
public:
  const char *what() const noexcept override
  {
    return "StackUnderflowException - Stack is empty!";
  }
};


template <typename T>
class Stack
{
private:
  T *arr;
  int top;
  int capacity;

public:
  Stack(int size)
  {
    capacity = size;
    arr = new T[capacity];
    top = -1;
  }

  ~Stack()
  {
    delete[] arr;
  }

  void push(const T &item)
  {
    if (top >= capacity - 1)
      throw StackOverflowException();
    arr[++top] = item;
  }

  T pop()
  {
    if (top < 0)
      throw StackUnderflowException();
    return arr[top--];
  }

  bool isEmpty() const
  {
    return top == -1;
  }

  bool isFull() const
  {
    return top == capacity - 1;
  }
};

int main()
{
  Stack<int> stack(2);

  try
  {
    
    stack.push(10);
    stack.push(20);

    stack.push(30);
  }
  catch (const exception &e)
  {
    cerr << "Pushing to a full stack: " << e.what() << endl;
  }

  try
  {
    stack.pop();
    stack.pop();
    stack.pop();
  }
  catch (const exception &e)
  {
    cerr << "Popping from an empty stack: " << e.what() << endl;
  }

}
