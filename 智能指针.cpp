#include<iostream>
using namespace std;
//实现智能指针
class Person
{
public:
	Person(int param)
	{
		this->mParam = param;
	}

	void PrintPerson()
	{
		cout << "Param:" << mParam << endl;
	}
private:
	int mParam;
};

class SmartPointer
{
public:
	SmartPointer(Person *person)
	{
		this->pPerson = person;
	}

	Person*operator->()
	{
		return pPerson;
	}

	Person &operator*()
	{
		return *pPerson;
	}

	~SmartPointer()
	{
		if (pPerson != NULL)
		{
			delete pPerson;
		}
	}
public:
	Person *pPerson;
};

void test01()
{
	SmartPointer pointer(new Person(100));
	pointer->PrintPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}