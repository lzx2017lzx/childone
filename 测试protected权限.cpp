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
		Print();//˵������protected���Ա�����ĺ������ʣ�
	}


};
int main(void)
{

	Student s1;
	s1.Person::a = 3;//˵������protected�����Ա�����Ķ�����ʡ�
	s1.Person::Print();//˵������protected�����Ա�����Ķ�����ʡ�

	system("pause");
	return 0;
}