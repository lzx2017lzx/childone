#if 0
//任务创建5个学生，并为每个学生打分，要求每个学生的分数必须为10个50-100之间的整数除去最高分和最低分后的平均值；
//显示学生信息，并按照从小到大的顺序打印出来；要求不能从标准输入输出设备输入数据



//通过string容器的+=函数，加同样是string temp="ABCDE"，每次加一个字符。
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include<ctime>
//#include<algorithm>

//类用来创建学生对象
class Student
{
public:
	bool operator<(const Student &p1)const
	{
		return this->Score < p1.Score;
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

//bool Compare(const Student &p1, const Student &p2)//按升序排列
//{
//	return p1.Score < p2.Score;
//}

//创建容器用来存储学生信息
void GiveScore( vector<Student> &v)
{

	for (int i = 0; i < 5; i++)
	{
		Student s1;
		s1.name = "xiaoli";//但是每次名字都是一样的，可以通过string的特点，实行加,但是自加数据来源一是字符、而是字符串，如何解决，可以通过辅助字符串取字符的方式
		string temp = "ABCDE";
		s1.name += temp[i];
		
		//创建queue容器用来存储10个随机数，并进行排序，按要求除去最大值和最小值，最后求平均值
		deque<int>qq;
		
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 50 + 50;
			qq.push_front(score);
		}

		sort(qq.begin(), qq.end());

		qq.pop_front();
		qq.pop_back();
		int total = 0;
		for (deque<int>::iterator it=qq.begin();it!=qq.end(); it++)
		{
			total += (*it);
		}

		int average = total / qq.size();
		s1.Score = average;
		v.push_back(s1);
	}
}

//按顺序显示学生信息
void ShowInformation( vector<Student>&v)
{
	sort(v.begin(), v.end());//但是v容器内的数据是学生，所以必须通过回调函数或反函数才能运行sort函数。
	//sort()
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).name << " " << (*it).Score << endl;
	}

}
void test()
{
	srand((unsigned int)(time(NULL)));
	vector<Student> v;
	GiveScore(v);
	ShowInformation(v);



}
int main(void)
{
	test();
	system("pause");
	return 0;
}
#endif
//重载<号和>号
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
