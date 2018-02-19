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
		//this->Print("abcde");�������и����ͬ�������������е�����ͬ�������������أ�������ĺ����в��ܷ���
		this->Person::Print("abcde");//����ͨ����������ʸ�������غ���
	}
public:
	int id;
	int grade;

};


int main(void)
{
	Student s1("����",30);

	s1.Print(2, 3);
	//s1.Print();���������ֱ�ӷ������صĺ���
	s1.Person::Print();//����ͨ����������ʸ�������غ���
	s1.Person::Print("abcd");//����ͨ����������ʸ�������غ���
	system("pause");
	return 0;
}
