#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}

	Person()
	{
		this->name = 0;
		this->age = 0;
	}

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


};


class Student:public Person
{
public:
	Student(string name, int age):Person(name,age)
	{
		id = 0;
		grade = 0;
	}

	void Print(int id,int grade)
	{
		this->id = id;
		this->grade = grade;
		cout << id << " " << grade << endl;
	}

	void ShowPersonPrint()
	{
		//this->Print("abcde");子类中有父类的同名函数，父类中的所有同名函数都被隐藏，在子类的函数中不能访问
		this->Person::Print("abcde");//可以通过作用域访问父类的隐藏函数
	}
public:
	int id;
	int grade;

};


int main(void)
{
	Student s1("黎明",30);

	s1.Print(2, 3);
	//s1.Print();子类对象不能直接访问隐藏的函数
	s1.Person::Print();//可以通过作用域访问父类的隐藏函数
	s1.Person::Print("abcd");//可以通过作用域访问父类的隐藏函数
	system("pause");
	return 0;
}
