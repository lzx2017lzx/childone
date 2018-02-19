#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

#if 0
/*
1.使用单例模式实现一个打印机类
打印传入的字符串
累计打印次数
*/

//创建懒汉式单例:①所有构造函数私有，析构函数必须要定义，并释放指针指向的对象空间，否则造成内存泄漏;②、静态公有的函数返回静态指针变量；③、用静态指针变量创建单例对象
class Printer
{
public:
	static Printer *Generator(const char *str = NULL)
	{
		if (str != NULL)
		{
			cout << str << endl;
			PPrinter->Times++;
		}

		return PPrinter;
	}


private:
	Printer()
	{
		Times = 0;
	}

public:
	static Printer *PPrinter;
	int Times;

};
Printer*Printer::PPrinter = new Printer;

//创建输入
void test()
{
	//创建单例
	Printer*Psingleexample = Printer::Generator();
	//打印计数
	Psingleexample->Generator("abcde");

	Psingleexample->Generator("efgdeg");

	Psingleexample->Generator("mnopq");


	cout << "the printing times:" << Psingleexample->Times << endl;

	char str[1024] = { 0 };
	cout << "please input your string:" << endl;
	cin >> str;
	Psingleexample->Generator(str);

	cout << "the printing times:" << Psingleexample->Times << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif


#if 0
/*
2.使用多态实现一个图形基类，两个子类：矩形和圆形
基类包含两个抽象方法：周长和面积
子类分别重写这两个方法
另外写一个全局的计算方法，参数为基类指针，传入子类对象时，输出对应的周长和面积
*/

//定义抽象基类，只有两个成员函数
class Graph
{
public:
	virtual void ShowPerimeter() = 0;
	virtual void ShowArea() = 0;
};

//定义矩型,存在数据成员长和高
class Rectangle :public Graph
{
public:
	//有参矩型构造函数
	Rectangle(float a, float b)
	{
		length = a;
		width = b;
	}
	virtual void ShowPerimeter()
	{
		float Perimeter = (length + width) * 2;
		cout << "Perimeter is:" << Perimeter << endl;
	}
	virtual void ShowArea()
	{
		float Area = length*width;
		cout << "Area is:" << Area << endl;
	}
public:
	float length;
	float width;

};

//定义圆类，数据成员半径
class Circle :public Graph
{
public:
	Circle(float r)
	{
		radius = r;
	}
	virtual void ShowPerimeter()
	{
		float Perimeter = (float)3.14*radius * 2;
		cout << "Perimeter is:" << Perimeter << endl;
	}

	virtual void ShowArea()
	{
		float Area = (float)3.14*radius*radius;
		cout << "Area is:" << Area << endl;
	}
public:
	float radius;
};

void Show(Graph *PGraph)
{
	PGraph->ShowPerimeter();
	PGraph->ShowArea();
}

void test()
{
	//定义矩型
	float a = (float)3.3;
	float b = (float)4.5;
	float radius = (float)2.8;
	Rectangle RT(a, b);

	//定义圆对象
	Circle CR(radius);

	//打印矩型周长和面积
	Show(&RT);

	//打印圆周长和面积
	Show(&CR);

}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif

#if 0
/*
3.实现一个字符串类，头文件如下：

class MyString
{
private:
char* pAddress; //字符串实际存储地址
int mSize; //字符串大小
public:
MyString(); //无参构造
MyString(int n, char c); //有参构造，指定大小和初始值
MyString(const MyString& str); //拷贝构造
MyString& operator=(const MyString& str); //赋值运算符重载
MyString& operator=(const char* str); //赋值运算符重载
~MyString(); //析构函数


MyString operator+(const MyString& str); //加号运算符重载
MyString operator+(const char *s); //加号运算符重载

MyString& operator+=(const MyString& str); //加等运算符重载
MyString& operator+=(const char *s); //加等运算符重载

char& operator[](int index); //下标运算符重载
int Size(); //返回字符串长度
friend std::ostream& operator<<(std::ostream &out, MyString &str); //输出运算符重载
friend std::istream& operator >> (std::istream &in, MyString &str); //输入运算符重载
};
*/
class MyString
{
private:
	char* pAddress; //字符串实际存储地址
	int mSize; //字符串大小
public:
	MyString() //无参构造 
	{
		pAddress = new char[1];//为了统一用delete []，此处用[],注意new后的空间内可能有垃圾值
		*pAddress = 0;
		mSize = 0;
	}
	MyString(int n, char c) //有参构造，指定大小和初始值
	{
		pAddress = new char[n + 1];
		memset(pAddress, 0, n + 1);
		for (int i = 0; i < n; i++)
		{
			pAddress[i] = c;
		}
		mSize = n;
	}
	MyString(const MyString& str) //拷贝构造
	{
		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}
		pAddress = new char[strlen(str.pAddress) + 1];
		strcpy(pAddress, str.pAddress);
		mSize = str.mSize;
	}
	MyString& operator=(const MyString& str)//赋值运算符重载
	{
		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		pAddress = new char[str.mSize + 1];
		memset(pAddress, 0, str.mSize + 1);

		strcpy(pAddress, str.pAddress);
		mSize = str.mSize;

		return *this;
	}
	MyString& operator=(const char* str) //赋值运算符重载
	{
		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		pAddress = new char[strlen(str) + 1];
		memset(pAddress, 0, strlen(str) + 1);

		strcpy(pAddress, str);
		mSize = strlen(str);

		return *this;
	}
	~MyString() //析构函数
	{
		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		mSize = 0;
	}


	MyString operator+(const MyString& str);//加号运算符重载

	MyString operator+(const char *s);//加号运算符重载


	MyString& operator+=(const MyString& str) //加等运算符重载
	{
		//首先设置空间保留this指向的对象中字符串，再释放this指向的对象中的指针指向的空间
		char *Temp = new char[strlen(this->pAddress) + strlen(str.pAddress) + 1];
		strcpy(Temp, this->pAddress);

		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		//将str中的字符串追加到Temp中
		strcat(Temp, str.pAddress);


		*(this) = Temp;
		return *this;

	}
	MyString& operator+=(const char *s) //加等运算符重载
	{
		//首先设置空间保留this指向的对象中字符串，再释放this指向的对象中的指针指向的空间
		char *Temp = new char[strlen(this->pAddress) + strlen(s) + 1];
		strcpy(Temp, this->pAddress);

		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		//将str中的字符串追加到Temp中
		strcat(Temp, s);


		*(this) = Temp;
		return *this;
	}

	char& operator[](int index) //下标运算符重载
	{
		//此处下标运算符的功能是返回指定下标的字符
		if (index<0 || index>mSize)
		{

			return this->pAddress[mSize];//说明下标不合法,返回'\0';
		}

		return this->pAddress[index];

	}
	int Size() //返回字符串长度
	{
		return mSize;
	}
	friend std::ostream& operator<<(std::ostream &out, MyString &str) //输出运算符重载
	{
		if (str.pAddress)
			out << "string:" << str.pAddress << endl;
		out << "mSize:" << str.mSize << endl;
		return out;
	}
	friend std::istream& operator >> (std::istream &in, MyString &str)//输入运算符重载
	{
		char buf[1024] = { 0 };
		printf("please input your string:\n");
		cin >> buf;

		str = buf;
		return in;
		//if (str.pAddress != NULL)
		//{
		//	delete[]pAddress;
		//	pAddress = NULL;
		//}

		//str.pAddress
	}
};
MyString MyString:: operator+(const MyString& str)//加号运算符重载
{
	//MyString temp;//创建辅助对象
	int mSize = strlen(this->pAddress) + strlen(str.pAddress) + 1;
	char *SteForTemp = new char[mSize];
	memset(SteForTemp, 0, mSize);

	strcpy(SteForTemp, this->pAddress);
	strcat(SteForTemp, str.pAddress);

	MyString temp;
	temp = SteForTemp;
	return temp;

}

MyString MyString::operator+(const char *s)//加号运算符重载
{
	int mSize = strlen(this->pAddress) + strlen(s) + 1;
	char *SteForTemp = new char[mSize];
	memset(SteForTemp, 0, mSize);

	strcpy(SteForTemp, this->pAddress);
	strcat(SteForTemp, s);

	MyString temp;
	temp = SteForTemp;
	return temp;
}
void test()
{
	MyString st1;//无参构造
	cout << "st1:" << st1 << endl;

	MyString st2(3, 'A');//有参构造，指定大小和初始值
	cout << "st2" << st2 << endl;

	MyString st3(st2);//拷贝构造函数
	cout << "st3:" << st3 << endl;

	st1 = st3;//赋值运算符重载传对象
	cout << "str1:" << st1 << endl;


	st2 = "abcde";//赋值运算符重载传字符串
	cout << "st2:" << st2 << endl;

	MyString st4(st2 + st3);//加号运算符重载传对象
	cout << "st4:" << st4 << endl;

	MyString st5(st2 + "mmmm");//加号运算符重载传字符串
	cout << "st5:" << st5 << endl;

	cout << "st1[" << 3 << "]" << st1[3] << endl;//下标运算符重载

	cout << "st1.Size():" << st1.Size() << endl;//获得对象字符串大小

	cin >> st1;//>>运算符重载，输入参数
	cout << "st1:" << st1 << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif

#if 1
/*
4. 使用模板实现插入排序(按升序排序)
*/

template<class T, class _cback>
int InsertSortFunc(T arr[], int len, _cback _fun)
{
	if (0 == len)
	{
		return -1;
	}

	for (int i = 1; i < len; i++)
	{
		T temp = arr[i];
		int j = 0;
		if (_fun(arr[i - 1], arr[i]) > 0)
		{
			for (j = i; j > 0 && (_fun(arr[j - 1], temp) > 0); j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}

	}

	return 0;

}

//定义Person类创建数据
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};
//用函数对象供回调函数调用
struct FuncObj
{
	//比较整数
	int operator()(const int &a, const int &b)
	{
		if (a > b)
		{
			return 1;
		}
		else if (a == b)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	//比较字符
	int operator()(const char &a, const char &b)
	{
		if (a > b)
		{
			return 1;
		}
		else if (a == b)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	int operator()(const Person &a, const Person &b)
	{
		if (a.age > b.age)
		{
			return 1;
		}
		else if (a.age == b.age)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
};

//重载<<运算符模板函数

ostream &operator<<(ostream &os, Person & data)
{
	os << data.name << endl;
	os << data.age << endl;
	return os;
}
void test()
{
	//创建函数对象
	FuncObj ObjFunc;
	//测试整型数据
	int integer[] = { 2,1,3,6,4,5,9,8,7 };
	int len = sizeof(integer) / sizeof(integer[0]);
	//printf("%d", len);
	InsertSortFunc<int, FuncObj>(integer, len, ObjFunc);

	for (int i = 0; i < len; i++)
	{
		cout << integer[i] << " ";
	}
	cout << endl;

	//测试字符型数据
	char character[] = { 'b','a','c','f','d','e','i','h','g' };
	len = sizeof(character) / sizeof(char);
	InsertSortFunc<char, FuncObj>(character, len, ObjFunc);

	//打印
	for (int i = 0; i < len; i++)
	{
		cout << character[i] << endl;
	}

	//测试类按年龄排序
	/*Person p1("lihua", 22);
	Person p2("liming", 21);
	Person p3("zhanghua", 20);
	Person p4("lizhang", 23);*/
	Person personarr[] = { Person("lihua", 22),Person("liming", 21), Person("zhanghua", 20),Person("lizhang", 23) };
	len = sizeof(personarr) / sizeof(personarr[0]);
	InsertSortFunc<Person, FuncObj>(personarr, len, ObjFunc);

	for (int i = 0; i < len; i++)
	{
		cout << personarr[i] << " ";
	}


}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif

#if 0
//void insertsort(int *arr, int len)
//{
//	for (int i = 1; i < len; i++)
//	{	
//		if (arr[i - 1] > arr[i])
//		{
//			int temp = arr[i];
//			int j = 0;
//			for (j = i;j > 0 && arr[j - 1] >=arr[j];j--)
//			{
//				arr[j] = arr[j - 1];
//			}
//			arr[j] = temp;
//		}
//		
//	}
//}

void insertsort(int *arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i];
			int j = 0;
			for (j = i; j > 0 && arr[j - 1] > temp; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[j] = temp;
		}

	}
}
void test()
{
	int arr[] = { 2,1,3,6,4,5,9,8,7 };
	//int arr[] = { 2,1,5,3,8,9};
	int len = sizeof(arr) / sizeof(arr[0]);

	insertsort(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif