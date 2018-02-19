#include<iostream>
using namespace std;
#if 0
//任务模仿学校管理学生，学生都有学号、座位号、职位(班长、学习委员、团支书等)，学生继承了人的属性(姓名、年龄、身份证号)，学生又会继续分四大类(小学生(从一年级到六年级)、初中生(从初一到初三)、高中生(从高一到高三)、大学生(从大一到大四)),不同类的学生又会继续划分年级，不同年级学生的课程不一样
//不同类大的学生交女朋友的权利没有，不同类的学生上课时间不一样，住宿地点不一样，同一年级的学生考试成绩需要同时打印进行管理，不同年级学生的课程安排不一样。
class Student
{
public:
	virtual void print()
	{
		cout << "父类helloworld" << endl;
	}
	virtual void height()
	{
		cout << "基类的身高" << endl;
	}

	virtual void Score() = 0;

};

class PrimaryStudent :public Student
{
public:
	virtual void print()
	{
		cout << "子类helloworld" << endl;
	}

	void height()
	{
		cout << "派生类身高" << endl;
	}

	void height(int meter)
	{
		cout << "子类身高" << meter << endl;
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
		cout << "子类helloworld" << endl;
	}

	void height()
	{
		cout << "派生类身高" << endl;
	}

	void height(int meter)
	{
		cout << "子类身高" << meter << endl;
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
		cout << "子类helloworld" << endl;
	}

	void height()
	{
		cout << "派生类身高" << endl;
	}

	void height(int meter)
	{
		cout << "子类身高" << meter << endl;
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
		if (3 == memble)//如果memble=3，说明超过了管理个数
		{
			cout << "学校学生已经满了!" << endl;
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
	//创建用来管理不同年级学生的学校对象
	School S1;

	//将不同年级的学生添加进去
	S1.AddStudent(new PrimaryStudent);//创建动态对象
	S1.AddStudent(new HighStudent);
	S1.AddStudent(new CollegeStudent);
	S1.AddStudent(new CollegeStudent);

	//打印不同年级的分数
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
//回调函数调用函数对象测试
//回调函数直接执行函数对象

//创建回调函数模板
template<class _CallBack>
void print(_CallBack _func)
{

	cout << typeid(_func).name() << endl;
	return;
}

//创建打印函数对象,必须有对（）运算符的重载
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
	cout << "不通过回调函数!" << endl;
	s1(5);
	cout << "使用回调函数!" << endl;
	print(Show());
}

int main()
{
	test01();
	return 0;

}
#endif