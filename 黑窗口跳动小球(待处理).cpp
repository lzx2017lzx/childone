#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;
class A
{
public:
	A(int a, int b) :_b(b), _a(_b)
	{}
	void show()
	{
		cout << "a = " << this->_a << " b = " << this->_b << endl;
	}
private:
	int _a;
	int _b;
};
int main01(void)
{
	A a(3, 4);
	a.show();
	return 0;
}
class Father
{
private:
	void Xinghui()
	{
		cout << "�����������л�" << endl;
	}
public:
	void showSelf()
	{
		cout << "Look Look������ô��Ǯ" << endl;
	}
public:
	void workHard()
	{
		cout << "������Ŭ��������ͨ�������Ŭ�����ӵײ�һ��һ����������̳��Ұֵ��Ų���" << endl;
		mName;
		mAge;
		mMoney;
	}
public:
	string mName;
private:
	int mAge;
protected:
	int mMoney;
};

class Son :public Father
{
	void print()
	{
		mMoney;
		mName;
	}

};

void test1()
{
	Father father;
	Son son;
}


int main0001()
{
	system("pause");
	return 0;
}

#if 0
class MyClass
{
public:
	int getOnlyRead()
	{
		return mOnlyRead;
	}

	void setWrite(int val)
	{
		if (val < 0 || val>100)
		{
			return;
		}
		mOnlyWrite = val;
	}

	void setReadWrite(int val)
	{

	}

	int getReadWrite()
	{
		return mReadWrite;
	}

private:
	int mOnlyRead;
	int mOnlyWrite;
	int mReadWrite;
};
int main(void)
{
	MyClass ms;
	ms.getOnlyRead();
	ms.setWrite(1000);
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
class Person
{
public:
	void init(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	void setName(string name)
	{
		mName = name;
	}

	string getName()
	{
		return mName;
	}

	void setAge(int age)
	{
		if (age < 0 || age>100)
		{
			return;
		}
		mAge = age;
	}
	int getAge()
	{
		return mAge;
	}

	void printPerson()
	{
		cout << "Name:"<<mName<< "Age:" << mAge << endl;
	}
private:
	string mName;
	int mAge;
};

void test()
{
	Person person;
	person.init("trump", 20);

	person.setAge(70);

	person.printPerson();
}

int main(void)
{
	test();
	printf("\n");
	system("pause");
	return 0;
}

#endif

#if 0
class Cube//�������๹��
{
public:
	void init()//��ʼ�������Ϊ0
	{
		mL = 0;
		mW = 0;
		mH = 0;
	}

	//��Ա�����ķ��ʽӿ�
	void setL(int l)//�๫�к��������ö����ʼ���ߴ�
	{
		mL = l;
	}
	void setW(int w)
	{
		mW = w;
	}
	void setH(int h)
	{
		mH = h;
	}
	int getL()//�๫�к���������ö���ĳߴ�
	{
		return mL;
	}
	int getW()
	{
		return mW;
	}
	int getH()
	{
		return mH;
	}

	int getS()//�๫�к���������ö�������
	{
		return (mL*mW + mL*mH + mW*mH) * 2;
	}

	int getV()//�๫�к���������ö�������
	{
		return mL*mH*mW;
	}

	bool CubeEqualCube(Cube &c)//�๫�к��������Ƚϵ��øú����Ķ����Ƿ���������������ͬ����
	{
		if (getH() == c.getH() && getL() == c.getL() && getW() == c.getW())
		{
			return true;
		}

		return false;
	}
private:
	int mL;
	int mW;
	int mH;

};


//�ж������������Ƿ����
bool CubeEqualCube(Cube &c1, Cube &c2)//�����Ա���������ж����������Ƿ����
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}

	return false;
}

void test()
{
	Cube cube1;
	Cube cube2;

	cube1.init();
	cube2.init();

	cube1.setH(10);
	cube1.setL(20);
	cube1.setW(30);

	cube2.setH(20);
	cube2.setL(20);
	cube2.setW(30);

	cout << "cube1: s=" << cube1.getS() << "v=" << cube1.getV() << endl;
	cout << "cube2:s=" << cube2.getS() << "v=" << cube2.getV() << endl;

	CubeEqualCube(cube1, cube2);

	cube1.CubeEqualCube(cube2);
	cube2.CubeEqualCube(cube1);
};

int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 0
class Person
{
public:
	Person()
	{
		pName = (char *)malloc(100);//ΪpName�ַ�ָ��������öѿռ�
		memset(pName, 0, 100);//����ѿռ������Ϊ0��
		strcpy(pName, "John");//strcpy�Ὣ�ַ�����ȫ������pName��ʼ���ڴ�ռ䣬�����Զ����NUL�ַ����������������һϵ���ַ�û��NUL��β���ͱ����Լ��ֶ���ӣ������϶δ��뽫�ռ��������б�Ҫ��
		mAge = 0;//���캯����ʼ������Ϊ0

		cout << "Person ���캯���Զ�����!" << endl;


	}

	~Person()//���������ͷ�����Ķѿռ�
	{
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}

		cout << "�����������Զ�����!" << endl;
	}
public:
	char *pName;//peson����������
	int mAge;//person����������
};

void test()
{
	Person person;
	Person person1;
}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 0
class Person
{
public:
	Person()//�ֶ����û�в����Ĺ��캯��
	{
		mID = 0;
		mAge = 0;
		cout << "�޲ι��캯��������!" << endl;
	}

	Person(int id, int age)//�ֶ�����вι��캯��
	{
		mID = id;
		mAge = age;
		cout << "�вι��캯��!" << endl;
	}

	Person(int id)//�ֶ�����вι��캯��
	{
		mID = id;
		mAge = 0;
		cout << "�вι��캯��!" << endl;
	}

#if 0
	Person(int id, int age = 0)//�вι��캯��ʹ��Ĭ�Ϲ��캯��
	{
		mID = id;
		mAge = age;
	}
#endif

	Person(const Person &person)//�������캯����д
	{
		mID = person.mID;
		mAge = person.mAge;
		cout << "�������캯����" << endl;//��ʾ�����д����ʾ��������������
	}

	~Person()
	{
		cout << "��������!" << endl;
	}

public:
	int mID;
	int mAge;
};

void test01()
{
	Person person;//�������󣬵����޲ι��캯��

}

void test02()
{
	Person person01(10, 20);//�вι��캯�������������ŷ�
	Person person02(person01);//�������캯�������������ŷ�

	Person person03 = Person(20, 30);//��ʾ���ù��캯��������������
	Person person04 = Person(person03);//��ʾ���ù��캯�����ÿ������캯��

	Person person05 = 10;//���ںŷ���������
	Person person06 = person05;//���ںŷ���������
}

void test03()
{
	Person();//�޲ι��캯��������������
	cout << "���������Ѿ����ͷ�!" << endl;

	Person(10, 20);
	cout << "���������Ѿ����ͷ�!" << endl;

	Person person01;
	//Person(person01);//���������ΪPerson person01;
}

int main()
{
	test02();
	system("pause");
	return 0;
}
#endif
#if 0
class Person
{
public:
	Person()//�ֶ�����޲ι��캯��
	{
		cout << "Ĭ�Ϲ��캯��!" << endl;//��ʾ�޲ι��캯������
	}

	Person(const Person &person)//�������캯��(ע�����������)��д
	{
		cout << "�������캯��!" << endl;//��ʾ�������캯��������
	}

	~Person()
	{
		cout << "��������!" << endl;//��ʾ��������������
	}
};


void printPerson(Person p)
{

}

void test01()
{
	Person person;//�����޲ι��캯����������
	printPerson(person);//��ӡ����
}

void test02()
{
	Person person01;//�����޲ι��캯����������
	Person person02(person01);//���ÿ������캯����������
	Person person03 = person01;//���ÿ������캯�������ǵȺŸ�ֵ������
}


Person CreatePerson()
{
	Person person;//�޲ι��캯����ʼ������
	cout << "person:" << (int)&person << endl;//���ض���ĵ�ַ
	return person;
}

void test03()
{
	Person p = CreatePerson();//ʹ�ú�������ֵ��������vs��debugģʽ�����Ż�����ַ��ͬ��release ģʽ���Ż��������Ķ�����ͬһ������
	cout << "person:" << (int)&p << endl;
}

int main(void)
{
	//test01();
	//test03();
	test02();
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0

class Person1
{
public:
	Person1()//�����޲ι��캯��
	{

	}
#if 1
	Person1(const Person1 &)//���忽�����캯��
	{
		cout << "�������캯��" << endl;
	}
#endif
	int id;
	int age;
};


void test01()
{
	Person1 person;
	Person1 person02(person);

	person02 = person;
}

class MyClass
{
public:
	MyClass(int p1, int p2)//����������
	{
		mParam1 = p1;
		mParam2 = p2;

	}

	void printMyClass()
	{
		cout << "param1:" << mParam1 << endl;
	}
public:
	int mParam1;
	int mParam2;
};


void test02()
{
	MyClass m1(10, 20);//���������캯����ʼ������
	MyClass m2(30, 40);
	MyClass m3(m1);//�������캯����ʼ������

	m1.printMyClass();
	m2.printMyClass();
	m3.printMyClass();
}

class Person
{
public:
	Person(const char *name, int age)//�������Ĺ��캯��
	{
		pName = (char *)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	Person(const Person &person)//�������캯��
	{
		cout << "�����ֶ���ӵĿ������캯��" << endl;
		pName = (char *)malloc(strlen(person.pName) + 1);
		strcpy(pName, person.pName);
		mAge = person.mAge;
	}

	~Person()//�Զ�����������
	{
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
public:
	char *pName;
	int mAge;
};

void test03()
{
	Person person01("Edward", 20);//��������ʼ������
	Person person02(person01);//���캯����ʼ������
	cout << person02.mAge << endl;
	cout << person02.pName << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}
#endif
#if 0
class Car//����γ���
{
public:
#if 0
	Car()
	{
		cout << "Car ���캯��!" << endl;
}

	Car(int a)
	{
		cout << "Car�вι��캯��!" << endl;
	}

#endif

	

	~Car()
	{
		cout << "Car ��������" << endl;
	}
};
class Bus//����bus��
{
public:
#if 0
	Bus(int a)
	{
		cout << "Bus ���캯��!" << endl;
	}
	Bus()
	{
		cout << "Bus�޲ι��캯��!" << endl;
	}
#endif

	

	~Bus()
	{
		cout << "Bus��������!" << endl;
	}
};

class RichPerson//���帻����
{
public:
#if 0
	RichPerson(int a, int b) :mCar(a), mBus()
	{
		cout << "RichPerson���캯��" << endl;
	}

	RichPerson() :mCar(0), mBus(0)
	{
		cout << "RichPerson ���캯��" << endl;
	}
#endif

	

	~RichPerson()
	{
		cout << "RichPerson��������" << endl;
	}
public:
	Bus mBus;
	Car mCar;
};

void test01()
{
	RichPerson person;


}

class MClass
{
public:
	MClass(int a, int b, int c) :mA(a), mB(b), mC(c)
	{

	}

public:
	int mA;
	int mB;
	int mC;
};

int main()
{
	//test01();
	MClass class12(1, 2, 3);
	cout << class12.mA << endl;
	system("pause");
	return 0;
}
#endif
#if 0
/*
�������
*/
int main(void)
{
	double a[10];//��������10��������
	double total = 100;//����ܽ��
	int num = 10;//�ֳ�10��
	double min = 0.01;//��С������
	int i = 0;//ѭ������
	double t;//ƽ��ֵ
	double safe_total = 0;//��Ծֵ
	double sum = 0;//�ۼ�ÿ����ȡ�ĺ�����
	srand((unsigned int)time(0));//�������
	for (i = 0; i < num - 1; i++)//ѭ����ȡ���������ƽ��ֵ��������Ծֵ�������
	{
		t = total / (10 -i+1);//ƽ��ֵ10-i+1��������ʾ��ȡ�����ķ���
		safe_total = t * 2;//��һ����ȡ�������20���ڵ�==��Ծֵ
		a[i] = (rand() % (int)(safe_total * 100) + (int)min * 100) / 100.0 + min;//rand���������
		total = total - a[i];//ÿ����ȡ���ٺ��
		sum += a[i];//�ۼ�ÿ����ȡ�ĺ�����
		printf("��%d�������%0.2lf\n", i+1, a[i]);

	}
	a[i] = total;
	printf("��%d�������%0.2lf\n�ܽ����%0.2lf", i+1, a[i], sum + a[i]);
	printf("\n");
	system("pause");
	return 0;
}


#endif
#define R 50
#if 0
/*
�ڴ�������������ɫС��

*/
int main(void)
{
	HWND hwnd;//���ڵľ��
	HDC hdc;//�豸�������
	HBRUSH hbru_W, hbru_B;//��ˢ���
	RECT rect;//���ͽṹ
	POINT pt;//��ṹ

	int disX = 10;//ˮƽ�����ƶ��ľ��룬������Ϊ��λ
	int disY = 15;//��ֱ�����ƶ��ľ���
	char name[100];
	GetConsoleTitle(name, 100);//��ȡ���ڵı��⣬������name������

	hwnd = FindWindow(NULL, name);
	hdc = GetDC(hwnd);//��ȡ������ָ�����ڵ��豸�������

	GetClientRect(hwnd, &rect);//��ȡ���ڵľ��ʹ�С�����浽rect������

	printf("���ڿ��:%d ����\n", rect.right - rect.left);
	printf("���ڸ߶�:%d ����\n", rect.bottom - rect.top);
	pt.x = (rect.right - rect.left) / 2;
	pt.y = (rect.bottom - rect.top) / 2;

	//����������ˢ
	hbru_W = CreateSolidBrush(RGB(255, 255, 255));//��ɫ��ˢ
	hbru_B = CreateSolidBrush(RGB(0, 0, 0));//��ɫ��ˢ

	while (1)
	{
		SelectObject(hdc, hbru_W);//�����ɫ��ˢ
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);
		Sleep(50);
		SelectObject(hdc, hbru_B);//�����ɫ��ˢ
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);

		if (pt.x - R <= 0 || pt.x + R >= rect.right)
			disX = -disX;
		if (pt.y - R <= 0 || pt.y + R >= rect.bottom)
			disY = -disY;

		pt.x += disX;
		pt.y += disY;

	}
	printf("\n");
	system("pause");
	return 0;
}




#endif
#if 0
/*
�ڴ�������������ɫ����С��
*/
int main(void)
{
	HWND hwnd;//���ڵľ��
	HDC hdc;//�豸�������
	HBRUSH hbru_W, hbru_B, hbru_T;//��ˢ���
	RECT rect;//���ͽṹ
	POINT pt;//��ṹ

	int disX = 10;//ˮƽ�����ƶ��ľ��룬������Ϊ��λ
	int disY = 15;//��ֱ�����ƶ��ľ���
	char name[100];
	GetConsoleTitle(name, 100);//��ȡ���ڵı��⣬������name������

	hwnd = FindWindow(NULL, name);
	hdc = GetDC(hwnd);//��ȡ������ָ�����ڵ��豸�������

	GetClientRect(hwnd, &rect);//��ȡ���ڵľ��ʹ�С�����浽rect������

	printf("���ڿ��:%d ����\n", rect.right - rect.left);
	printf("���ڸ߶�:%d ����\n", rect.bottom - rect.top);
	pt.x = (rect.right - rect.left) / 2;
	pt.y = (rect.bottom - rect.top) / 2;

	//����������ˢ
	hbru_W = CreateSolidBrush(RGB(255, 255, 255));//��ɫ��ˢ
	hbru_B = CreateSolidBrush(RGB(0, 0, 0));//��ɫ��ˢ
	hbru_T= CreateSolidBrush(RGB(0, 0, 139));//�������⻭ˢ
	while (1)
	{
		SelectObject(hdc, hbru_T);//�����ɫ��ˢ
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);//Ϊ�´λ�ˢ��λ��������
		Sleep(50);
		SelectObject(hdc, hbru_B);//�����ɫ��ˢ
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);

		if (pt.x - R <= 0 || pt.x + R >= rect.right)
			disX = -disX;
		if (pt.y - R <= 0 || pt.y + R >= rect.bottom)
			disY = -disY;

		pt.x += disX;
		pt.y += disY;

	}
	printf("\n");
	system("pause");
	return 0;
}
#endif



