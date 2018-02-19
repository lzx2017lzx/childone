//重载<号和>号;并用对象调用
#include<iostream>
using namespace std;

class Student
{
public:
	bool operator<(const Student &p1)const
	{
		return this->Score < p1.Score;
	}

	bool operator>(const Student &p1)
	{
		return this->Score > p1.Score;
	}
	Student(string mname, int mage)//用来初始化对象
	{
		name = mname;
		Score = mage;
	}
	Student()
	{
		name = '\0';
		Score = 0;
	}


public:
	int Score;
	string name;


};

void test()
{
	Student s1("mm", 20);
	Student s2("nn", 21);
	Student s3("kk", 19);
	bool a = s1 < s2;
	cout << a << endl;

	bool b = s2 > s3;
	cout << b << endl;
}
int main(void)
{
	test();
	system("pause");
	return 0;
}
