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
		cout << "向政府机关行贿" << endl;
	}
public:
	void showSelf()
	{
		cout << "Look Look我有这么多钱" << endl;
	}
public:
	void workHard()
	{
		cout << "我自已努力工作，通过自身的努力，从底层一步一步摸爬滚打继承我爸的遗产！" << endl;
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
class Cube//长方体类构建
{
public:
	void init()//初始化长宽高为0
	{
		mL = 0;
		mW = 0;
		mH = 0;
	}

	//成员变量的访问接口
	void setL(int l)//类公有函数用来让对象初始化尺寸
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
	int getL()//类公有函数用来获得对象的尺寸
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

	int getS()//类公有函数用来获得对象的面积
	{
		return (mL*mW + mL*mH + mW*mH) * 2;
	}

	int getV()//类公有函数用来获得对象的体积
	{
		return mL*mH*mW;
	}

	bool CubeEqualCube(Cube &c)//类公有函数用来比较调用该函数的对象是否与其它对象是相同对象
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


//判断两个立方体是否相等
bool CubeEqualCube(Cube &c1, Cube &c2)//非类成员函数用来判断两个对象是否相等
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
		pName = (char *)malloc(100);//为pName字符指针变量设置堆空间
		memset(pName, 0, 100);//清理堆空间的数据为0；
		strcpy(pName, "John");//strcpy会将字符串完全拷贝到pName开始的内存空间，不会自动添加NUL字符，所以如果拷贝的一系列字符没有NUL结尾，就必须自己手动添加，所以上段代码将空间置零是有必要的
		mAge = 0;//构造函数初始化年龄为0

		cout << "Person 构造函数自动调用!" << endl;


	}

	~Person()//析构函数释放申请的堆空间
	{
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}

		cout << "析构函数被自动调用!" << endl;
	}
public:
	char *pName;//peson的姓名属性
	int mAge;//person的年龄属性
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
	Person()//手动添加没有参数的构造函数
	{
		mID = 0;
		mAge = 0;
		cout << "无参构造函数被调用!" << endl;
	}

	Person(int id, int age)//手动添加有参构造函数
	{
		mID = id;
		mAge = age;
		cout << "有参构造函数!" << endl;
	}

	Person(int id)//手动添加有参构造函数
	{
		mID = id;
		mAge = 0;
		cout << "有参构造函数!" << endl;
	}

#if 0
	Person(int id, int age = 0)//有参构造函数使用默认构造函数
	{
		mID = id;
		mAge = age;
	}
#endif

	Person(const Person &person)//拷贝构造函数编写
	{
		mID = person.mID;
		mAge = person.mAge;
		cout << "拷贝构造函数！" << endl;//提示代码编写，显示拷贝函数被调用
	}

	~Person()
	{
		cout << "析构函数!" << endl;
	}

public:
	int mID;
	int mAge;
};

void test01()
{
	Person person;//创建对象，调用无参构造函数

}

void test02()
{
	Person person01(10, 20);//有参构造函数创建对象括号法
	Person person02(person01);//拷贝构造函数创建对象括号法

	Person person03 = Person(20, 30);//显示调用构造函数类似匿名对象法
	Person person04 = Person(person03);//显示调用构造函数利用拷贝构造函数

	Person person05 = 10;//等于号法创建对象
	Person person06 = person05;//等于号法创建对象
}

void test03()
{
	Person();//无参构造函数创建匿名对象
	cout << "匿名对象已经被释放!" << endl;

	Person(10, 20);
	cout << "匿名对象已经被释放!" << endl;

	Person person01;
	//Person(person01);//编译器理解为Person person01;
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
	Person()//手动添加无参构造函数
	{
		cout << "默认构造函数!" << endl;//提示无参构造函数调用
	}

	Person(const Person &person)//拷贝构造函数(注意参数是引用)编写
	{
		cout << "拷贝构造函数!" << endl;//提示拷贝构造函数被调用
	}

	~Person()
	{
		cout << "析构函数!" << endl;//提示析构函数被调用
	}
};


void printPerson(Person p)
{

}

void test01()
{
	Person person;//调用无参构造函数创建对象
	printPerson(person);//打印对象
}

void test02()
{
	Person person01;//调用无参构造函数创建对象
	Person person02(person01);//调用拷贝构造函数创建对象
	Person person03 = person01;//调用拷贝构造函数，不是等号赋值函数。
}


Person CreatePerson()
{
	Person person;//无参构造函数初始化对象
	cout << "person:" << (int)&person << endl;//返回对象的地址
	return person;
}

void test03()
{
	Person p = CreatePerson();//使用函数返回值创建对象，vs中debug模式不会优化，地址相同。release 模式会优化，创建的对象是同一个对象
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
	Person1()//定义无参构造函数
	{

	}
#if 1
	Person1(const Person1 &)//定义拷贝构造函数
	{
		cout << "拷贝构造函数" << endl;
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
	MyClass(int p1, int p2)//带参数的类
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
	MyClass m1(10, 20);//带参数构造函数初始化对象
	MyClass m2(30, 40);
	MyClass m3(m1);//拷贝构造函数初始化对象

	m1.printMyClass();
	m2.printMyClass();
	m3.printMyClass();
}

class Person
{
public:
	Person(const char *name, int age)//带参数的构造函数
	{
		pName = (char *)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	Person(const Person &person)//拷贝构造函数
	{
		cout << "调用手动添加的拷贝构造函数" << endl;
		pName = (char *)malloc(strlen(person.pName) + 1);
		strcpy(pName, person.pName);
		mAge = person.mAge;
	}

	~Person()//自定义析构函数
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
	Person person01("Edward", 20);//带参数初始化对象
	Person person02(person01);//构造函数初始化对象
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
class Car//定义轿车类
{
public:
#if 0
	Car()
	{
		cout << "Car 构造函数!" << endl;
}

	Car(int a)
	{
		cout << "Car有参构造函数!" << endl;
	}

#endif

	

	~Car()
	{
		cout << "Car 析构函数" << endl;
	}
};
class Bus//定义bus类
{
public:
#if 0
	Bus(int a)
	{
		cout << "Bus 构造函数!" << endl;
	}
	Bus()
	{
		cout << "Bus无参构造函数!" << endl;
	}
#endif

	

	~Bus()
	{
		cout << "Bus析构函数!" << endl;
	}
};

class RichPerson//定义富人类
{
public:
#if 0
	RichPerson(int a, int b) :mCar(a), mBus()
	{
		cout << "RichPerson构造函数" << endl;
	}

	RichPerson() :mCar(0), mBus(0)
	{
		cout << "RichPerson 构造函数" << endl;
	}
#endif

	

	~RichPerson()
	{
		cout << "RichPerson析构函数" << endl;
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
红包代码
*/
int main(void)
{
	double a[10];//用来保存10个红包金额
	double total = 100;//红包总金额
	int num = 10;//分成10份
	double min = 0.01;//最小红包金额
	int i = 0;//循环变量
	double t;//平均值
	double safe_total = 0;//跳跃值
	double sum = 0;//累计每次领取的红包金额
	srand((unsigned int)time(0));//随机种子
	for (i = 0; i < num - 1; i++)//循环领取红包，先求平均值，接着跳跃值，再随机
	{
		t = total / (10 -i+1);//平均值10-i+1是用来表示领取红包后的份数
		safe_total = t * 2;//第一次领取红包是在20以内的==跳跃值
		a[i] = (rand() % (int)(safe_total * 100) + (int)min * 100) / 100.0 + min;//rand是随机函数
		total = total - a[i];//每次领取多少红包
		sum += a[i];//累计每次领取的红包金额
		printf("第%d个红包有%0.2lf\n", i+1, a[i]);

	}
	a[i] = total;
	printf("第%d个红包有%0.2lf\n总金额有%0.2lf", i+1, a[i], sum + a[i]);
	printf("\n");
	system("pause");
	return 0;
}


#endif
#define R 50
#if 0
/*
黑窗口设置跳动白色小球

*/
int main(void)
{
	HWND hwnd;//窗口的句柄
	HDC hdc;//设备环境句柄
	HBRUSH hbru_W, hbru_B;//画刷句柄
	RECT rect;//短型结构
	POINT pt;//点结构

	int disX = 10;//水平方向移动的距离，以像素为单位
	int disY = 15;//垂直方向移动的距离
	char name[100];
	GetConsoleTitle(name, 100);//获取窗口的标题，保存在name数组中

	hwnd = FindWindow(NULL, name);
	hdc = GetDC(hwnd);//获取参数所指定窗口的设备环境句柄

	GetClientRect(hwnd, &rect);//获取窗口的矩型大小，保存到rect变量中

	printf("窗口宽度:%d 像素\n", rect.right - rect.left);
	printf("窗口高度:%d 像素\n", rect.bottom - rect.top);
	pt.x = (rect.right - rect.left) / 2;
	pt.y = (rect.bottom - rect.top) / 2;

	//创建两个画刷
	hbru_W = CreateSolidBrush(RGB(255, 255, 255));//白色画刷
	hbru_B = CreateSolidBrush(RGB(0, 0, 0));//黑色画刷

	while (1)
	{
		SelectObject(hdc, hbru_W);//放入白色画刷
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);
		Sleep(50);
		SelectObject(hdc, hbru_B);//放入黑色画刷
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
黑窗口设置其它颜色跳动小球
*/
int main(void)
{
	HWND hwnd;//窗口的句柄
	HDC hdc;//设备环境句柄
	HBRUSH hbru_W, hbru_B, hbru_T;//画刷句柄
	RECT rect;//短型结构
	POINT pt;//点结构

	int disX = 10;//水平方向移动的距离，以像素为单位
	int disY = 15;//垂直方向移动的距离
	char name[100];
	GetConsoleTitle(name, 100);//获取窗口的标题，保存在name数组中

	hwnd = FindWindow(NULL, name);
	hdc = GetDC(hwnd);//获取参数所指定窗口的设备环境句柄

	GetClientRect(hwnd, &rect);//获取窗口的矩型大小，保存到rect变量中

	printf("窗口宽度:%d 像素\n", rect.right - rect.left);
	printf("窗口高度:%d 像素\n", rect.bottom - rect.top);
	pt.x = (rect.right - rect.left) / 2;
	pt.y = (rect.bottom - rect.top) / 2;

	//创建两个画刷
	hbru_W = CreateSolidBrush(RGB(255, 255, 255));//白色画刷
	hbru_B = CreateSolidBrush(RGB(0, 0, 0));//黑色画刷
	hbru_T= CreateSolidBrush(RGB(0, 0, 139));//创建任意画刷
	while (1)
	{
		SelectObject(hdc, hbru_T);//放入白色画刷
		Ellipse(hdc, pt.x - R, pt.y - R, pt.x + R, pt.y + R);//为下次画刷的位置作设置
		Sleep(50);
		SelectObject(hdc, hbru_B);//放入黑色画刷
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



