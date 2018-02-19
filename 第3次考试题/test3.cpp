#if 0
#include<iostream>
using namespace std;
#include<string>
//1.ʹ��ģ��ʵ��ð������



//ģ�����ð������(������)
template<typename T>
int BubbleSort(T arr[], int len)
{
	if (0 == len)
	{
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		T temp;
		for (int j = 1; j < len - i; j++)
		{
			if (arr[j - 1] > arr[j])//����Ƕ���Ҫ�ڶ���������������>��
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}

	}
	return 0;

}


void test01()//��������
{
	int arr[] = { 2,1,3,6,4,5,9,8,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort<int>(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}

}

void test02()//�����ַ�����
{
	char arr[] = "cbdemnadgf";
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	BubbleSort<char>(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}

}

struct Person
{
	Person()
	{
		name = '0';
		age = 0;
	}
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
	bool operator>(const Person &p)const//ָ����������������
	{
		if (this->age > p.age)
		{
			return true;
		}
		return false;
	};
};
void test03()//������
{

	Person arr[] = { Person("����ǿ",34),Person("��˼��",31),Person("����",35),Person("Baby",18) };
	int len = sizeof(arr) / sizeof(arr[0]);

	BubbleSort<Person>(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << "name:" << arr[i].name << " " << "age:" << arr[i].age << endl;
	}
}
int main(void)
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<cstring>

//�����ṹ��
struct Person
{
	Person()
	{
		mName[0] = 0;
		mAge = 0;

	}
	Person(char *name, int age)
	{
		strcpy(mName, name);
		mAge = age;
	}
	char mName[64];
	int mAge;

};

//personѡ������

int SelectSort(Person arr[], int len)
{
	if (0 == len)
	{
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		Person temp;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i].mAge > arr[j].mAge)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

	}

	return 0;
}

int main(void)
{
	//����vector�������������洢�ļ��е�����
	vector<Person>v;
	
	char *fileName = "a.txt";

	ifstream inputmemory(fileName, ios::in);

	if (!inputmemory)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	while (!inputmemory.eof())
	{
		char buf[1024] = { 0 };
		inputmemory.getline(buf, 1024);
		cout << buf << endl;
		//����person
		if (*buf == '\0')
		{
			break;
		}
		char *temp = strtok(buf, "#");//��#�ÿգ�tempָ����buf��Ԫ�ص�ַ
		temp = strtok(NULL, "#");//tempָ��ԭ#λ�ú��Ԫ�ص�ַ

		int a = atoi(temp);
		Person ptemp(buf, a);
		v.push_back(ptemp);


		//cout << ptemp.mName << ptemp.mAge << endl;
		//cout << buf << endl;
	}

	inputmemory.close();
	//��ӡvector�е�����(������)�����뵽����
	int len = v.size();
	Person *arr = (Person *)malloc(len * sizeof(Person));;
	memset(arr, 0, sizeof(Person)*len);
	int i = 0;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).mName << " " << (*it).mAge << endl;
		arr[i++] = (*it);
	}

	//��������
	

	//ѡ������
	//int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);

	//��ӡ����
	cout << "��ӡ��������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i].mName << "  " << arr[i].mAge << endl;
	}


	//д�����ļ�
	ofstream outdisc("./newa.txt", ios::out);

	if (!outdisc)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	i = 0;
	while (i < len)
	{
		char buf[1024] = { 0 };
		//strcpy(buf, arr[i].mName);
		sprintf(buf, "%s %d", arr[i].mName, arr[i].mAge);
		outdisc << buf << endl;//��endl��Ϊ�����ļ�ĩβд�ϻ��з�
		i++;
	}
	outdisc.close();
	system("pause");


	return 0;
}
#endif



#if 0
/*3.STL��������ջʵ��һ������

class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//���
	void Push(const int& val);
	//����
	void Pop();
	//���ض���Ԫ��
	int& Front();
	//���ض�βԪ��
	int& Back();
	//�ж϶����Ƿ�Ϊ��
	bool Empty();
	//���ض��д�С
	int Size();
};*/

#include<iostream>
using namespace std;
#include<stack>
class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//���
	void Push(const int& val);
	//����
	void Pop();
	//���ض���Ԫ��
	int& Front();
	//���ض�βԪ��
	int& Back();
	//�ж϶����Ƿ�Ϊ��
	bool Empty();
	//���ض��д�С
	int Size();
};


int main(void)
{
	system("pause");
	return 0;
}

#endif






























#if 0
//ð������(�ų�����)
#include<iostream>
using namespace std;

int BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int temp = 0;
		for (int j = 1; j < len - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}

int main(void)
{
	int arr[] = { 2,1,3,6,4,5,9,8,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}
#endif