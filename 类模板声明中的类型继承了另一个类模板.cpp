#include<iostream>
using namespace std;

template<class a>
struct Person
{
	typedef a aa;
	Person(a ax) :m(ax)
	{

	}
	a m;
	void printm()
	{
		cout << "Person m:" << m << endl;
	}
};

template<class b>
struct Student
{
	typedef typename b::aa A;
	Student(b bPerson, A APreson) :b1(bPerson), a1(APreson)
	{

	}
	//A AStudent;
	void printA()
	{
		cout << "AStudent:" << a1 << endl;
	}
public:
	b b1;
	A a1;
};

void test()
{
	Person<int>p1(23);
	Student<Person<int>>s1(p1, 6);
	//s1.AStudent=34;
	s1.printA();

}
int main(void)
{
	test();

	system("pause");
	return 0;
}