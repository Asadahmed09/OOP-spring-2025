#include <iostream>
using namespace std;
class Movie
{
public:
  string title;
  string director;
  string duration;
  void add_details(string name, string direct, string dur)
  {
    title = name;
    director = direct;
    duration = dur;
  }
  ~Movie()
  {
    cout << "Movie class is beind destoyed " << endl;
  }
};
class CinemaHall
{
public:
  Movie m[10];
  int count, num;
  CinemaHall()
  {
    cout << "enter the number of movies currently being screened : " << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
      cout << "Enter " << i + 1 << " Movie details : " << endl;
      string n, k, dur;
      getline(cin >> ws, n);
      getline(cin >> ws, k);
      getline(cin >> ws, dur);
      m[i].add_details(n, k, dur);
    }
  }
  void display_details()
  {
    cout << "This is Cinema Hall and We will provide all the movies being screening or is available for you " << endl;
    cout << "The movie currently screening is " << m[num - 1].title << endl;
    cout << " Other movies are " << endl;
    for (int i = 0; i < num; i++)
    {
      cout << "Title of movie is : " << m[i].title << endl;
      cout << "Director of movie is : " << m[i].director << endl;
      cout << "duration of movie is : " << m[i].duration << endl;
    }
  }
};
int main()
{
  CinemaHall hall1;
  hall1.display_details();
}
