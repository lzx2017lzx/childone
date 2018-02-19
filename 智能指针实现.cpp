#include<iostream>
using namespace std;

class Person//����һ���࣬ʵ��������ʱ����Ϊ����ָ��ָ��ı�־
{
public:
	Person(int m, int n)
	{
		a = m;
		b = n;
	}

	//����һ������
	void print()
	{
		cout << a << endl;
		cout << b << endl;
	}
public:
	int a;
	int b;
};


class SmartPointer//��������ָ�룬����ʱָ��Person����,����ָ�����������Ϊ���Զ��ͷŶ���Ķ�̬�ռ䣬������Ҫ�Լ��ֶ���delete�ͷ�
{
public:
	SmartPointer(Person *p1)
	{
		PPerson = p1;
	}

	//����*������������������ָ��ָ���һ������
	Person operator*()
	{
		return *PPerson;
	}

	//����->�����������������ָ��ָ��Ķ���ĵ�ַ

	Person *operator->()
	{
		return PPerson;
	}

	//��д�������������ͷ�����ָ��ָ��Ķ���
	~SmartPointer()
	{
		if (PPerson != NULL)
		{
			delete PPerson;
			PPerson = NULL;
			cout << "delete ����" << endl;
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

	(*Smartp).print();//Smartp��Ȼ������Person��ָ�룬����������������Person��ָ��

	Smartp->print();//Smartp��Ȼ������Person��ָ�룬����������������Person��ָ��
}

int main()
{
	test();
	system("pause");
	return 0;
}