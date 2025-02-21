#include <iostream>
using namespace std;
class TourGuide
{
public:
  string name;
  int Year_of_exp;
  string specialization;
  TourGuide(string name , string specialization , int yox)
  {
    this->name = name;
    this->specialization = specialization;
    Year_of_exp = yox;
  }
  TourGuide()
  {
    name = "";
    Year_of_exp = 0;
    specialization = "";
  }
};
class TravelAgency
{
  public:
  TourGuide **guide;
  int count;
  int number;
  TravelAgency() : count(0)
  {
    guide = new TourGuide*[10];
  }
  void add_guide(TourGuide &g)
  {
    guide[count] = &g;
    count++;
  }
    void display_details()
    {
      cout << "Displaying the details of members in Descending order :  " << endl;
      for(int i =0 ; i < count ; i++)
      {
        cout << "Name of Guide : " << guide[i]->name << endl;
        cout << "Years of Experience : " << guide[i]->Year_of_exp << endl;
        cout << "Specialization : " << guide[i]->specialization << endl;
      }
    }
  ~TravelAgency()
  {
    delete[] guide;
  }
};
int main()
{
  TourGuide guide("asad","it",1);
  TravelAgency t;
  t.add_guide(guide);
  t.display_details();
}
