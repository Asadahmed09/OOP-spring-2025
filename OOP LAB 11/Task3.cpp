#include <iostream>
#include <string>
using namespace std;

class FileException : public exception
{
public:
  virtual const char *what() const noexcept
  {
    return "FileException";
  }
};

class FileNotFoundException : public FileException
{
public:
  const char *what() const noexcept
  {
    return "FileNotFoundException - File not found!";
  }
};

class PermissionDeniedException : public FileException
{
public:
  const char *what() const noexcept
  {
    return "PermissionDeniedException - Access denied!";
  }
};

void readFile(const string &filename)
{
  if (filename == "missing.txt")
    throw FileNotFoundException();
  else if (filename == "secret.txt")
    throw PermissionDeniedException();
  else
    cout << "Reading '" << filename << "': Success!" << endl;
}

int main()
{
  string files[] = {"data.txt", "missing.txt", "secret.txt"};
  for (auto &file : files)
  {
    try
    {
      readFile(file);
    }
    catch (FileNotFoundException &e)
    {
      cout << "Reading '" << file << "': " << e.what() << endl;
    }
    catch (PermissionDeniedException &e)
    {
      cout << "Reading '" << file << "': " << e.what() << endl;
    }
    catch (FileException &e)
    {
      cout << "Reading '" << file << "': " << e.what() << endl;
    }
  }
  
}
