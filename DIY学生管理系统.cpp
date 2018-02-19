#include<iostream>
using namespace std;
#if 0
//����ģ��ѧУ����ѧ����ѧ������ѧ�š���λ�š�ְλ(�೤��ѧϰίԱ����֧���)��ѧ���̳����˵�����(���������䡢���֤��)��ѧ���ֻ�������Ĵ���(Сѧ��(��һ�꼶�����꼶)��������(�ӳ�һ������)��������(�Ӹ�һ������)����ѧ��(�Ӵ�һ������)),��ͬ���ѧ���ֻ���������꼶����ͬ�꼶ѧ���Ŀγ̲�һ��
//��ͬ����ѧ����Ů���ѵ�Ȩ��û�У���ͬ���ѧ���Ͽ�ʱ�䲻һ����ס�޵ص㲻һ����ͬһ�꼶��ѧ�����Գɼ���Ҫͬʱ��ӡ���й�����ͬ�꼶ѧ���Ŀγ̰��Ų�һ����
class Student
{
public:
	virtual void print()
	{
		cout << "����helloworld" << endl;
	}
	virtual void height()
	{
		cout << "��������" << endl;
	}

	virtual void Score() = 0;

};

class PrimaryStudent :public Student
{
public:
	virtual void print()
	{
		cout << "����helloworld" << endl;
	}

	void height()
	{
		cout << "���������" << endl;
	}

	void height(int meter)
	{
		cout << "�������" << meter << endl;
	}

	void Score()
	{
		cout << "80" << endl;
	}
};

class HighStudent :public Student
{
public:
	virtual void print()
	{
		cout << "����helloworld" << endl;
	}

	void height()
	{
		cout << "���������" << endl;
	}

	void height(int meter)
	{
		cout << "�������" << meter << endl;
	}

	void Score()
	{
		cout << "100" << endl;
	}
};

class CollegeStudent :public Student
{
public:
	virtual void print()
	{
		cout << "����helloworld" << endl;
	}

	void height()
	{
		cout << "���������" << endl;
	}

	void height(int meter)
	{
		cout << "�������" << meter << endl;
	}

	void Score()
	{
		cout << "90" << endl;
	}
};

class School
{
public:
	School()
	{
		for (int i = 0; i < 3; i++)
		{
			PS[i] = NULL;
		}
		memble = 0;
	}

	void AddStudent(Student*ST)
	{
		if (3 == memble)//���memble=3��˵�������˹������
		{
			cout << "ѧУѧ���Ѿ�����!" << endl;
			return;
		}
		PS[memble++] = ST;		
	}

	void PrintScore()
	{
		for (int i = 0; i < memble; i++)
		{
			PS[i]->Score();
		}
	}

	~School()
	{
		for (int i = 0; i < 3; i++)
		{
			if (PS[i]!=NULL)
			{
				delete PS[i];
				PS[i] = NULL;
			}
		}
	}

public:
	Student *PS[3];
	int memble;
};
void test01()
{
	CollegeStudent s1;
	s1.print();
	s1.height();
}

void test02()
{
	PrimaryStudent s1;
	(*((void(*)())*((int *)*(int *)&s1 + 1)))() ;
	return;

}

void test03()
{
	//������������ͬ�꼶ѧ����ѧУ����
	School S1;

	//����ͬ�꼶��ѧ����ӽ�ȥ
	S1.AddStudent(new PrimaryStudent);//������̬����
	S1.AddStudent(new HighStudent);
	S1.AddStudent(new CollegeStudent);
	S1.AddStudent(new CollegeStudent);

	//��ӡ��ͬ�꼶�ķ���
	S1.PrintScore();
}

int main()
{
	//test();
	//test1();
	//test2();
	test03();
	system("pause");
	return 0;
}
#endif

#if 1
//�ص��������ú����������
//�ص�����ֱ��ִ�к�������

//�����ص�����ģ��
template<class _CallBack>
void print(_CallBack _func)
{

	cout << typeid(_func).name() << endl;
	return;
}

//������ӡ��������,�����жԣ��������������
struct Show
{
	void operator()(int a)
	{
		cout << a << endl;
	}
};

void test01()
{
	Show s1;
	cout << "��ͨ���ص�����!" << endl;
	s1(5);
	cout << "ʹ�ûص�����!" << endl;
	print(Show());
}

int main()
{
	test01();
	return 0;

}
#endif