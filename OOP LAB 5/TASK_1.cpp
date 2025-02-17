#include<iostream>
using namespace std;
class CAR
{
	private:
		int reg_no;
		string modelName;
		//string *name;
		string name;
	public:
	CAR(int regno , string modelN , string owner)
	{
		reg_no = regno;
		modelName = modelN;
		name = owner;
	}
	void update(string owner)
	{
		name = owner;
	}
	void displayCarDetails()
	{
		cout << "The Name of Model of Car is : " << modelName << endl << "The REGISTRATION No of CAR : " << reg_no << endl << "The Owner of CAR : " << name << endl;
	}
//	CAR(CAR &c)
//	{
//		reg_no = c.reg_no;
//		modelName = c.modelName;
//		name = new string;
//		*name = *(c.name);	
//	}	
		
};
int main()
{
	cout << "------------WELCOME to FAST rent ----------------------" << endl;
	cout << "Making an object " << endl;
	CAR c1(1,"corolla","asad");
	CAR c2 = c1;
	c1.displayCarDetails();
	c2.displayCarDetails();
	c2.update("ahmed");
	c1.displayCarDetails();
	c2.displayCarDetails();
}
