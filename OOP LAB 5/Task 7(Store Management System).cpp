#include <iostream>
using namespace std;
class electronics
{
public:
  int Product_id;
  string name;
  double price;

public:
  electronics()
  {
    Product_id = 0;
    name = "";
    price = 0;
  }
  electronics(string name, int id, double price) : name(name), Product_id(id), price(price) {}
};
class clothing
{
public:
  int Product_id;
  string name;
  double price;

public:
  clothing()
  {
    Product_id = 0;
    name = "";
    price = 0;
  }
 clothing(string name, int id, double price) : name(name), Product_id(id), price(price) {}
  void Add_details(string name, int id, double price)
  {
    this->name = name;
    Product_id = id;
    this->price = price;
  }
};
class groceries
{
public:
  int Product_id;
  string name;
  double price;

public:
  groceries()
  {
    Product_id = 0;
    name = "";
    price = 0;
  }
  groceries(string name, int id, double price) : name(name), Product_id(id), price(price) {}
  void Add_details(string name, int id, double price)
  {
    this->name = name;
    Product_id = id;
    this->price = price;
  }
};
class store
{
public:
  int count_electronics, count_clothing, count_groceries;
  store() : count_electronics(0), count_clothing(0), count_groceries(0) {}
  electronics *E[5] = {nullptr};
  clothing *C[5] = {nullptr};
  groceries *G[5] = {nullptr};
  void Add_electronics()
  {
    cout << "Welcome to store : " << endl;
    cout << "Add the electronics Item in the given Sequence " << endl;
    cout << "1-Name of Product || 2-Id of product || 3-Price of product" << endl;
    string name;
    int id;
    double price;
    getline(cin >> ws, name);
    cin >> id;
    cin >> price;
    E[count_electronics] = new electronics(name, id, price);
    count_electronics++;
  }
  void Add_grocery()
  {
    cout << "Welcome to store : " << endl;
    cout << "Add the grocery Item in the given Sequence " << endl;
    cout << "1-Name of Product || 2-Id of product || 3-Price of product" << endl;
    string name;
    int id;
    double price;
    getline(cin >> ws, name);
    cin >> id;
    cin >> price;
    G[count_groceries] = new groceries(name , id , price);
    count_groceries++;
  }
  void Add_clothing()
  {
    cout << "Welcome to store : " << endl;
    cout << "Add the clothing Item in the given Sequence " << endl;
    cout << "1-Name of Product || 2-Id of product || 3-Price of product" << endl;
    string name;
    int id;
    double price;
    getline(cin >> ws, name);
    cin >> id;
    cin >> price;
    C[count_clothing] = new clothing(name, id, price);
    count_clothing++;
  }
  void Find_Electronics()
  {
    cout << "Enter the product name to found : " << endl;
    string name;
    getline(cin >> ws, name);
    for (int i = 0; i < count_electronics; i++)
    {
      if (name == E[i]->name)
      {
        cout << "Product Found " << endl;
        cout << "Name Of product is :  " << E[i]->name << endl;
        cout << "Price Of product is :  " << E[i]->price << endl;
        cout << "ID  Of product is :  " << E[i]->Product_id << endl;
        return;
      }
    }
  }
  void Find_grocery()
  {
    cout << "Enter the product name to found : " << endl;
    string name;
    getline(cin >> ws, name);
    for (int i = 0; i < count_groceries; i++)
    {
      if (name == G[i]->name)
      {
        cout << "Product Found " << endl;
        cout << "Name Of product is :  " << G[i]->name << endl;
        cout << "Price Of product is :  " << G[i]->price << endl;
        cout << "ID  Of product is :  " << G[i]->Product_id << endl;
        return;
      }
    }
  }
  void Find_clothing()
  {
    cout << "Enter the product name to found : " << endl;
    string name;
    getline(cin >> ws, name);
    for (int i = 0; i < count_clothing; i++)
    {
      if (name == C[i]->name)
      {
        cout << "Product Found " << endl;
        cout << "Name Of product is :  " << C[i]->name << endl;
        cout << "Price Of product is :  " << C[i]->price << endl;
        cout << "ID  Of product is :  " << C[i]->Product_id << endl;
        return;
      }
    }
  }
  void Sort_electronics()
  {
    for (int i = 0; i < count_electronics-1; i++)
    {
      for (int j = i+1; j < count_electronics; j++)
      {
        if (E[i]->price > E[j]->price)
        {
        swap(E[i],E[j]);
        }
      }
    }
    for (int i = 0; i < count_electronics; i++)
    {
      cout << "Name of Product is : " << E[i]->name << " and price is : " << E[i]->price << endl;
    }
  }
  void Sort_clothing()
  {
    for (int i = 0; i < count_clothing-1; i++)
    {
      for (int j = i+1; j < count_clothing; j++)
      {
        if (C[i]->price > C[j]->price)
        {
          swap(C[i],C[j]);
        }
      }
    }
    for (int i = 0; i < count_clothing; i++)
    {
      cout << "Name of Product is : " << C[i]->name << " and price is : " << C[i]->price << endl;
    }
  }
  void Sort_grocery()
  {
    for (int i = 0; i < count_groceries; i++)
    {
      for (int j = i+1; j < count_groceries; j++)
      {
        if (G[i]->price > G[j]->price)
        {
          groceries *temp = G[i];
          G[i] = G[j];
          G[j] = temp;
        }
      }
    }
    for (int i = 0; i < count_groceries; i++)
    {
      cout << "Name of Product is : " << G[i]->name << " and price is : " << G[i]->price << endl;
    }
  }
  ~store()
  {
    for (int i = 0; i < count_electronics; i++)
      delete E[i];

    for (int i = 0; i < count_clothing; i++)
      delete C[i];

    for (int i = 0; i < count_groceries; i++)
      delete G[i];
  }
};
int main()
{
  store s1;
  int choice;

  while (true)
  {
    cout << "\n----------------- Store Menu ---------------------" << endl;
    cout << "1. Add Electronics\n";
    cout << "2. Add Clothing\n";
    cout << "3. Add Grocery\n";
    cout << "4. Find Electronics\n";
    cout << "5. Find Clothing\n";
    cout << "6. Find Grocery\n";
    cout << "7. Sort Electronics by Price\n";
    cout << "8. Sort Clothing by Price\n";
    cout << "9. Sort Grocery by Price\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 0)
      break;
    switch (choice)
    {
    case 1:
    {
      s1.Add_electronics();
      break;
    }
    case 2:
    {
      s1.Add_clothing();
      break;
    }
    case 3:
    {
      s1.Add_grocery();
      break;
    }
    case 4:
      s1.Find_Electronics();
      break;
    case 5:
      s1.Find_clothing();
      break;
    case 6:
      s1.Find_grocery();
      break;
    case 7:
      s1.Sort_electronics();
      break;
    case 8:
      s1.Sort_clothing();
      break;
    case 9:
      s1.Sort_grocery();
      break;
    default:
      cout << "Invalid choice! Try again.\n";
    }
  }
  cout << "Exiting program...\n";
  return 0;
}
