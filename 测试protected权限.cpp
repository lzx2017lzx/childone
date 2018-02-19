#include<iostream>
using namespace std;
#include<string>
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	Person()
	{
		this->name = 0;
		this->age = 0;
	}
protected:
	//private:
	void Print()
	{
		cout << name << " " << age << endl;
	}

	void Print(char *a)
	{
		name += *a;
		cout << name << " " << age << endl;
	}

	void Print(int man)
	{
		cout << man << endl;
	}
public:
	int age;
	string name;
protected:
	int a;

};

class Student :public Person
{
public:
	void printStduent()
	{
		a = 3;
		Print();//说明父类protected可以被子类的函数访问；
	}


};
int main(void)
{

	Student s1;
	s1.Person::a = 3;//说明父类protected不可以被子类的对象访问。
	s1.Person::Print();//说明父类protected不可以被子类的对象访问。

	system("pause");
	return 0;
}