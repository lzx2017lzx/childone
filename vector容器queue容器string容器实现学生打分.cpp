#if 0
//���񴴽�5��ѧ������Ϊÿ��ѧ����֣�Ҫ��ÿ��ѧ���ķ�������Ϊ10��50-100֮���������ȥ��߷ֺ���ͷֺ��ƽ��ֵ��
//��ʾѧ����Ϣ�������մ�С�����˳���ӡ������Ҫ���ܴӱ�׼��������豸��������



//ͨ��string������+=��������ͬ����string temp="ABCDE"��ÿ�μ�һ���ַ���
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include<ctime>
//#include<algorithm>

//����������ѧ������
class Student
{
public:
	bool operator<(const Student &p1)const
	{
		return this->Score < p1.Score;
	}
	Student(string mname, int mage)//������ʼ������
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

//bool Compare(const Student &p1, const Student &p2)//����������
//{
//	return p1.Score < p2.Score;
//}

//�������������洢ѧ����Ϣ
void GiveScore( vector<Student> &v)
{

	for (int i = 0; i < 5; i++)
	{
		Student s1;
		s1.name = "xiaoli";//����ÿ�����ֶ���һ���ģ�����ͨ��string���ص㣬ʵ�м�,�����Լ�������Դһ���ַ��������ַ�������ν��������ͨ�������ַ���ȡ�ַ��ķ�ʽ
		string temp = "ABCDE";
		s1.name += temp[i];
		
		//����queue���������洢10������������������򣬰�Ҫ���ȥ���ֵ����Сֵ�������ƽ��ֵ
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

//��˳����ʾѧ����Ϣ
void ShowInformation( vector<Student>&v)
{
	sort(v.begin(), v.end());//����v�����ڵ�������ѧ�������Ա���ͨ���ص������򷴺�����������sort������
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
//����<�ź�>��
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
	Student(string mname, int mage)//������ʼ������
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
