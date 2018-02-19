#include<iostream>
using namespace std;
template<class T>class Person;
template<class T>ostream& operator<<(ostream &os, Person<T> &p1);
template<class T>void PrintPerson(Person<T> &p1);

template<class T>
class Person
{

public:
	Person(T a, T b)//定义公有成员构造函数，方便定义对象
	{
		this->a = a;
		this->b = b;
	}

	//friend ostream&operator<<(ostream &os, Person & p1)//类内定义友元函数
	//{
	//	os << p1.a << endl;
	//	os << p1.b << endl;
	//	return os;
	//}
	friend ostream& operator<<<>(ostream &os, Person &p1);//在类外定义运算符重载的友元函数
	friend void PrintPerson<>(Person &p1);//在类外定义全局的友元函数

	template<class T, class TT>friend void ShowPerson(Person &p1, TT a);//定义全局的模板函数，且是友元的
private:
	T a;
	T b;
};

template<class T>
ostream& operator<<(ostream &os, Person<T> &p1)
{
	os << p1.a << endl;
	os << p1.b << endl;
	return os;
}

template<class T>
void PrintPerson(Person<T> &p1)
{
	cout << p1.a << endl;
	cout << "PrintPerson works." << endl;
}

template<class T, class TT>
void ShowPerson(Person<T> &p1, TT a)
{
	cout << a << endl;
	printf("ShowPerson works.");
}

void test()
{
	Person<int>p1(2, 3);
	//cout << p1 << endl;
	//PrintPerson(p1);
	ShowPerson<int, int>(p1, 'a');
}

int main()
{
	test();
	system("pause");
	return 0;
}