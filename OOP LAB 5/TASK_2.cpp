#include<iostream>
using namespace std;
int count = 0;
class Patient
{
	private:
		int id;
		string name;
		float* test_result = new float(10);
	public:
		Patient (int id , string name , float res)
		{
			this->id = id;
			this->name = name;
			test_result[count] = res;
			count++;
		}
		Patient(Patient &p)
		{
			id = (p.id);
			name = p.name;
			test_result = new float;
			*test_result = *(p.test_result);
		}
		void display()
		{
			cout << "The name of Patient : " << name << endl << "The id of Patient : " << id << endl ;
			cout << "Displaying previous history : " << endl;
			for(int i = 0 ; i < count ; i++)
			{
				cout << "History " << count << " : " << *test_result << endl;
			}
		}
};
int main()
{
	Patient p1(1,"asad",10.0);
	Patient p2 = p1;
	p1.display();
	p2.display();
	
	
}
