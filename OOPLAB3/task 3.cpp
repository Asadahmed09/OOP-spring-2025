#include<iostream>
using namespace std;
class Planner
{
  private:
  string Task[30];
  int day;
  public:
  Planner()
  {
    day = 0;
  }
  void addTask()
  {
    cout << "Enter the name of the task : " << endl;
    cin >> Task[day];
    cout << "Tasked added Successfully !" << endl;
    day++;
  } 
  void RemoveTask()
  {
    string dummyName;
    cout << "Enter the name of the task to remove: " << endl;
    cin >> dummyName;
    for(int i = 0 ; i < day ; i++)
    {
      if(Task[i] == dummyName)
      {
        for(int j = i ; j < day - 1 ; j++)
        {
          Task[j] = Task[j+1];
        }
      }
      day--;
      cout << "Tasked removed Successfully ! " << endl;
      break;
    }
  } 
  void DisplayTask()
  {
    for(int i =  0 ; i < day ; i++)
    {
      cout << "TASK " << i+1 << " is : " << Task[i] << endl;
    }
  } 
};
int main()
{
  int select;
  Planner p;
  cout << "Welcome ! Hassan \nPlease select the operation below \n1-Add task\n2-Remove Task\n3-See all the tasks for month" << endl;
  while(1)
  {
    cin >> select;
    if(select>=1 && select <=3)
    {
      if(select ==1)
      {
        p.addTask();
      }
      else if(select == 2)
      {
        p.RemoveTask();
      }
      else if(select == 3)
      {
        p.DisplayTask();
      }
    }
    else
    {
      break;
    }
  }
}
