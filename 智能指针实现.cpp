#include<iostream>
using namespace std;

class Person//定义一个类，实例化对象时，作为智能指针指向的标志
{
public:
	Person(int m, int n)
	{
		a = m;
		b = n;
	}

	//定义一个方法
	void print()
	{
		cout << a << endl;
		cout << b << endl;
	}
public:
	int a;
	int b;
};


class SmartPointer//定义智能指针，测试时指向Person对象,智能指针的作用是是为了自动释放对象的动态空间，而不需要自己手动用delete释放
{
public:
	SmartPointer(Person *p1)
	{
		PPerson = p1;
	}

	//重载*操作符用来返回智能指针指向的一个对象
	Person operator*()
	{
		return *PPerson;
	}

	//重载->运算符用来返回智能指针指向的对象的地址

	Person *operator->()
	{
		return PPerson;
	}

	//重写析构函数用来释放智能指针指向的对象
	~SmartPointer()
	{
		if (PPerson != NULL)
		{
			delete PPerson;
			PPerson = NULL;
			cout << "delete 调用" << endl;
			free(PPerson);
		}
	}
public:
	Person *PPerson;

};

void test()
{
	Person p1(4,2);

	Person *pp1 = new Person(2, 3);
	pp1->print();
	(*pp1).print();
	delete pp1;
	printf("--------------------------------\n");
	SmartPointer Smartp(new Person(2, 3));

	(*Smartp).print();//Smartp虽然不是类Person的指针，但是用起来就像类Person的指针

	Smartp->print();//Smartp虽然不是类Person的指针，但是用起来就像类Person的指针
}

int main()
{
	test();
	system("pause");
	return 0;
}