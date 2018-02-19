#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

#if 0
/*
1.ʹ�õ���ģʽʵ��һ����ӡ����
��ӡ������ַ���
�ۼƴ�ӡ����
*/

//��������ʽ����:�����й��캯��˽�У�������������Ҫ���壬���ͷ�ָ��ָ��Ķ���ռ䣬��������ڴ�й©;�ڡ���̬���еĺ������ؾ�ָ̬��������ۡ��þ�ָ̬�����������������
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

//��������
void test()
{
	//��������
	Printer*Psingleexample = Printer::Generator();
	//��ӡ����
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
2.ʹ�ö�̬ʵ��һ��ͼ�λ��࣬�������ࣺ���κ�Բ��
��������������󷽷����ܳ������
����ֱ���д����������
����дһ��ȫ�ֵļ��㷽��������Ϊ����ָ�룬�����������ʱ�������Ӧ���ܳ������
*/

//���������ֻ࣬��������Ա����
class Graph
{
public:
	virtual void ShowPerimeter() = 0;
	virtual void ShowArea() = 0;
};

//�������,�������ݳ�Ա���͸�
class Rectangle :public Graph
{
public:
	//�вξ��͹��캯��
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

//����Բ�࣬���ݳ�Ա�뾶
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
	//�������
	float a = (float)3.3;
	float b = (float)4.5;
	float radius = (float)2.8;
	Rectangle RT(a, b);

	//����Բ����
	Circle CR(radius);

	//��ӡ�����ܳ������
	Show(&RT);

	//��ӡԲ�ܳ������
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
3.ʵ��һ���ַ����࣬ͷ�ļ����£�

class MyString
{
private:
char* pAddress; //�ַ���ʵ�ʴ洢��ַ
int mSize; //�ַ�����С
public:
MyString(); //�޲ι���
MyString(int n, char c); //�вι��죬ָ����С�ͳ�ʼֵ
MyString(const MyString& str); //��������
MyString& operator=(const MyString& str); //��ֵ���������
MyString& operator=(const char* str); //��ֵ���������
~MyString(); //��������


MyString operator+(const MyString& str); //�Ӻ����������
MyString operator+(const char *s); //�Ӻ����������

MyString& operator+=(const MyString& str); //�ӵ����������
MyString& operator+=(const char *s); //�ӵ����������

char& operator[](int index); //�±����������
int Size(); //�����ַ�������
friend std::ostream& operator<<(std::ostream &out, MyString &str); //������������
friend std::istream& operator >> (std::istream &in, MyString &str); //�������������
};
*/
class MyString
{
private:
	char* pAddress; //�ַ���ʵ�ʴ洢��ַ
	int mSize; //�ַ�����С
public:
	MyString() //�޲ι��� 
	{
		pAddress = new char[1];//Ϊ��ͳһ��delete []���˴���[],ע��new��Ŀռ��ڿ���������ֵ
		*pAddress = 0;
		mSize = 0;
	}
	MyString(int n, char c) //�вι��죬ָ����С�ͳ�ʼֵ
	{
		pAddress = new char[n + 1];
		memset(pAddress, 0, n + 1);
		for (int i = 0; i < n; i++)
		{
			pAddress[i] = c;
		}
		mSize = n;
	}
	MyString(const MyString& str) //��������
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
	MyString& operator=(const MyString& str)//��ֵ���������
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
	MyString& operator=(const char* str) //��ֵ���������
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
	~MyString() //��������
	{
		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		mSize = 0;
	}


	MyString operator+(const MyString& str);//�Ӻ����������

	MyString operator+(const char *s);//�Ӻ����������


	MyString& operator+=(const MyString& str) //�ӵ����������
	{
		//�������ÿռ䱣��thisָ��Ķ������ַ��������ͷ�thisָ��Ķ����е�ָ��ָ��Ŀռ�
		char *Temp = new char[strlen(this->pAddress) + strlen(str.pAddress) + 1];
		strcpy(Temp, this->pAddress);

		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		//��str�е��ַ���׷�ӵ�Temp��
		strcat(Temp, str.pAddress);


		*(this) = Temp;
		return *this;

	}
	MyString& operator+=(const char *s) //�ӵ����������
	{
		//�������ÿռ䱣��thisָ��Ķ������ַ��������ͷ�thisָ��Ķ����е�ָ��ָ��Ŀռ�
		char *Temp = new char[strlen(this->pAddress) + strlen(s) + 1];
		strcpy(Temp, this->pAddress);

		if (pAddress != NULL)
		{
			delete[]pAddress;
			pAddress = NULL;
		}

		//��str�е��ַ���׷�ӵ�Temp��
		strcat(Temp, s);


		*(this) = Temp;
		return *this;
	}

	char& operator[](int index) //�±����������
	{
		//�˴��±�������Ĺ����Ƿ���ָ���±���ַ�
		if (index<0 || index>mSize)
		{

			return this->pAddress[mSize];//˵���±겻�Ϸ�,����'\0';
		}

		return this->pAddress[index];

	}
	int Size() //�����ַ�������
	{
		return mSize;
	}
	friend std::ostream& operator<<(std::ostream &out, MyString &str) //������������
	{
		if (str.pAddress)
			out << "string:" << str.pAddress << endl;
		out << "mSize:" << str.mSize << endl;
		return out;
	}
	friend std::istream& operator >> (std::istream &in, MyString &str)//�������������
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
MyString MyString:: operator+(const MyString& str)//�Ӻ����������
{
	//MyString temp;//������������
	int mSize = strlen(this->pAddress) + strlen(str.pAddress) + 1;
	char *SteForTemp = new char[mSize];
	memset(SteForTemp, 0, mSize);

	strcpy(SteForTemp, this->pAddress);
	strcat(SteForTemp, str.pAddress);

	MyString temp;
	temp = SteForTemp;
	return temp;

}

MyString MyString::operator+(const char *s)//�Ӻ����������
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
	MyString st1;//�޲ι���
	cout << "st1:" << st1 << endl;

	MyString st2(3, 'A');//�вι��죬ָ����С�ͳ�ʼֵ
	cout << "st2" << st2 << endl;

	MyString st3(st2);//�������캯��
	cout << "st3:" << st3 << endl;

	st1 = st3;//��ֵ��������ش�����
	cout << "str1:" << st1 << endl;


	st2 = "abcde";//��ֵ��������ش��ַ���
	cout << "st2:" << st2 << endl;

	MyString st4(st2 + st3);//�Ӻ���������ش�����
	cout << "st4:" << st4 << endl;

	MyString st5(st2 + "mmmm");//�Ӻ���������ش��ַ���
	cout << "st5:" << st5 << endl;

	cout << "st1[" << 3 << "]" << st1[3] << endl;//�±����������

	cout << "st1.Size():" << st1.Size() << endl;//��ö����ַ�����С

	cin >> st1;//>>��������أ��������
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
4. ʹ��ģ��ʵ�ֲ�������(����������)
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

//����Person�ഴ������
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
//�ú������󹩻ص���������
struct FuncObj
{
	//�Ƚ�����
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

	//�Ƚ��ַ�
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

//����<<�����ģ�庯��

ostream &operator<<(ostream &os, Person & data)
{
	os << data.name << endl;
	os << data.age << endl;
	return os;
}
void test()
{
	//������������
	FuncObj ObjFunc;
	//������������
	int integer[] = { 2,1,3,6,4,5,9,8,7 };
	int len = sizeof(integer) / sizeof(integer[0]);
	//printf("%d", len);
	InsertSortFunc<int, FuncObj>(integer, len, ObjFunc);

	for (int i = 0; i < len; i++)
	{
		cout << integer[i] << " ";
	}
	cout << endl;

	//�����ַ�������
	char character[] = { 'b','a','c','f','d','e','i','h','g' };
	len = sizeof(character) / sizeof(char);
	InsertSortFunc<char, FuncObj>(character, len, ObjFunc);

	//��ӡ
	for (int i = 0; i < len; i++)
	{
		cout << character[i] << endl;
	}

	//�����ఴ��������
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