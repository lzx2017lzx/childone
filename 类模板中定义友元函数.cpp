#include<iostream>
using namespace std;
template<class T>class Person;
template<class T>ostream& operator<<(ostream &os, Person<T> &p1);
template<class T>void PrintPerson(Person<T> &p1);

template<class T>
class Person
{

public:
	Person(T a, T b)//���幫�г�Ա���캯�������㶨�����
	{
		this->a = a;
		this->b = b;
	}

	//friend ostream&operator<<(ostream &os, Person & p1)//���ڶ�����Ԫ����
	//{
	//	os << p1.a << endl;
	//	os << p1.b << endl;
	//	return os;
	//}
	friend ostream& operator<<<>(ostream &os, Person &p1);//�����ⶨ����������ص���Ԫ����
	friend void PrintPerson<>(Person &p1);//�����ⶨ��ȫ�ֵ���Ԫ����

	template<class T, class TT>friend void ShowPerson(Person &p1, TT a);//����ȫ�ֵ�ģ�庯����������Ԫ��
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