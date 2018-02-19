#if 0
#include<iostream>
using namespace std;
#include<string>
//1.使用模板实现冒泡排序



//模板进行冒泡排序(按升序)
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
			if (arr[j - 1] > arr[j])//如果是对象，要在对象所属类中重载>号
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}

	}
	return 0;

}


void test01()//测试整型
{
	int arr[] = { 2,1,3,6,4,5,9,8,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort<int>(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}

}

void test02()//测试字符数组
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
	bool operator>(const Person &p)const//指定按年龄升序排序
	{
		if (this->age > p.age)
		{
			return true;
		}
		return false;
	};
};
void test03()//测试类
{

	Person arr[] = { Person("王宝强",34),Person("王思村",31),Person("王飞",35),Person("Baby",18) };
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

//创建结构体
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

//person选择排序

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
	//定义vector容器对象，用来存储文件中的数据
	vector<Person>v;
	
	char *fileName = "a.txt";

	ifstream inputmemory(fileName, ios::in);

	if (!inputmemory)
	{
		cout << "文件打开失败!" << endl;
	}

	while (!inputmemory.eof())
	{
		char buf[1024] = { 0 };
		inputmemory.getline(buf, 1024);
		cout << buf << endl;
		//创建person
		if (*buf == '\0')
		{
			break;
		}
		char *temp = strtok(buf, "#");//将#置空，temp指针是buf首元素地址
		temp = strtok(NULL, "#");//temp指向原#位置后的元素地址

		int a = atoi(temp);
		Person ptemp(buf, a);
		v.push_back(ptemp);


		//cout << ptemp.mName << ptemp.mAge << endl;
		//cout << buf << endl;
	}

	inputmemory.close();
	//打印vector中的数据(读数据)并输入到数组
	int len = v.size();
	Person *arr = (Person *)malloc(len * sizeof(Person));;
	memset(arr, 0, sizeof(Person)*len);
	int i = 0;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).mName << " " << (*it).mAge << endl;
		arr[i++] = (*it);
	}

	//创建数组
	

	//选择排序
	//int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);

	//打印测试
	cout << "打印测试数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i].mName << "  " << arr[i].mAge << endl;
	}


	//写入新文件
	ofstream outdisc("./newa.txt", ios::out);

	if (!outdisc)
	{
		cout << "文件打开失败!" << endl;
	}

	i = 0;
	while (i < len)
	{
		char buf[1024] = { 0 };
		//strcpy(buf, arr[i].mName);
		sprintf(buf, "%s %d", arr[i].mName, arr[i].mAge);
		outdisc << buf << endl;//加endl是为了在文件末尾写上换行符
		i++;
	}
	outdisc.close();
	system("pause");


	return 0;
}
#endif



#if 0
/*3.STL：用两个栈实现一个队列

class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//入队
	void Push(const int& val);
	//出队
	void Pop();
	//返回队首元素
	int& Front();
	//返回队尾元素
	int& Back();
	//判断队列是否为空
	bool Empty();
	//返回队列大小
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
	//入队
	void Push(const int& val);
	//出队
	void Pop();
	//返回队首元素
	int& Front();
	//返回队尾元素
	int& Back();
	//判断队列是否为空
	bool Empty();
	//返回队列大小
	int Size();
};


int main(void)
{
	system("pause");
	return 0;
}

#endif






























#if 0
//冒泡排序(排成升序)
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