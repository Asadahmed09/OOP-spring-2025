#include"iostream"
using namespace std;
class GroceryStore
{
  private:
  string item[100];
  double price[100];
  int no;
  public:
  GroceryStore()
  {
    no = 0 ;
  }
  void add_newitems()
  {
    cout << "Enter the Name and price of new item :" << endl;
    cin >> item[no] >> price[no];
    cout << "\nitem added successfully" << endl;
    no++;
  }
  void Update_prices()
  {
    int found;
    cout << "Enter the name of item to update its price : " << endl;
    string dummyname; cin >> dummyname;
    for(int i =  0 ; i <= no ; i++)
    {
      if(dummyname == item[i])
      {
        cout << "item found "<< item[i] <<"! Enter the new price of this item : " << endl;
        double dummyprice; 
        cin >> dummyprice;
        price[i] = dummyprice;
        cout << "Price updated successfully" << endl;
        found++;
        break;
      }
    }
    if(found <= 0)
    {
      cout << "The particular item is not in inventory " << endl;
    }

  }
  void view_inventory()
  {
    for(int i = 0 ; i < no ; i++)
    {
      cout << "Item Name is : " << item[i] << "\nItem Price is : " << price[i] << endl;
    }
  }
  void Generate_receipt()
  {
    double total;
    for (int i = 0; i < no; i++)
    {
      cout << "Item Name is : " << item[i] << "\nItem Price is : " << price[i] << endl;
      total +=price[i];
    }
    cout << "The net Price of all the items is : " << total << endl;
  }

};
int main()
{
  cout << "Hello Zainab !" << endl;
  int select;GroceryStore g;
  cout << "Please select the following operation below " << endl;
  while(1)
  {
    cout << "1-Add Items \n2-Update Price of Existing Item\n3-View Inventory\n4-Generate Receipt" << endl;
    cin >> select;
    if(select == 1)
    {
      g.add_newitems();
    }
    else if(select == 2)
    {
      g.Update_prices();
    }
    else if(select == 3)
    {
      g.view_inventory();
    }
    else if(select == 4)
    {
      g.Generate_receipt();
    }
    else 
    {
      break;
    }
  }
}
