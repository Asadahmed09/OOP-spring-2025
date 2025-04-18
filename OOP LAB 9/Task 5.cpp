#include<iostream>
using namespace std;
class Activity
{
  public:
  virtual double calculateCaloriesBurned() = 0;
};
class Running : public Activity
{
  private:
  double distance , time ;
  public :
  Running(double distance , double time ):distance(distance),time(time)
  {
    cout << "Distance : " << distance << endl << "Time : " << time << endl << " For Running " << endl;
  }
  double calculateCaloriesBurned()
  {
    return (distance*60);
  }
};
class Cycling : public Activity
{
  private:
  double speed , time ;
  public:
  Cycling(double speed , double time ):speed(speed),time(time)
  {
    cout << "Speed : " << speed << endl << "Time : " << time << endl << "For Cycling " << endl;
  }
  double calculateCaloriesBurned()
  {
    return (speed*time*8);
  }
};
int main()
{
  Running person1(1,10);
  Cycling person2(2,30);
  cout << "Calories Burned for Person one in running " << person1.calculateCaloriesBurned() << endl;
  cout << "Calories Burned for Person one in running " << person2.calculateCaloriesBurned() << endl;
}
