#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h>
class Student;//前置声明，扩大作用访问，前置声明位置下面都可以作用
class Person
{
public:
	Person()//无参构造函数初始化对象
	{
		this->age = 0;
		this->name = new char[1];
		this->name[0] = '\0';
	}
	Person(int age, const char *name)//构造有参构造函数
	{
		this->age = age;
		this->name = new char[strlen(name) + 1];
		memset(this->name, 0, strlen(name) + 1);
		strcpy(this->name, name);
	}
	Person(const Person &p1)//写拷贝构造函数
	{
		this->age = p1.age;
		this->name = new char[strlen(p1.name) + 1];//直接将指针变量的值被拷贝成p1.name的值,这种做法会造成二次释放name指向的堆空间，会报错(p1释放了堆空间、之后p2还要再释放一次)，这是浅拷贝。
		memset(this->name, 0, strlen(p1.name) + 1);//清除堆空间数据
		strcpy(this->name, p1.name);//要使用头文件string.h,而且要使用_CRT_SECURE_NO_WARNINGS
	}

	//成员函数重载+号运算符,加号不改变原有的数据，所以返回类型为类名
	Person operator+(Person &p1)
	{
		//将this指向对象和p1的字符串链接
		char *newname = new char[strlen(this->name) + strlen(p1.name) + 1];
		memset(newname, 0, strlen(this->name) + strlen(p1.name) + 1);//清空申请的堆空间内容

		strcpy(newname, this->name);
		strcat(newname, p1.name);//将this指向对象和p1字符串拷贝到newname

		Person temp(this->age + p1.age, newname);//用新数据初始化新对象

		return temp;

	}
	//将减号重载为成员函数
	Person operator-(Person &p1)
	{
		//在this指向的字符串中找到与p1中字符串相同的部分的开始位置,策略是用strstr函数找到位置，之后用strncpy拷贝指定的数据部分
		char *start = strstr(this->name, p1.name);
		if (NULL == start)
		{
			//start==NULL意味不存在相同的部分，此处用p1内的字符串初始化新对象
			Person temp(this->age + p1.age, p1.name);
			return temp;
		}
		//将this指向的字符串删除与p1中字符串相同的部分，已经默认this指向的字符串包含p1中的字符串
		char *newname = new char[strlen(this->name) - strlen(p1.name) + 1];
		memset(newname, 0, strlen(this->name) - strlen(p1.name) + 1);//清空申请的堆空间内容

		strncpy(newname, this->name, start- this->name);
		Person temp(this->age + p1.age, newname);//用新数据初始化新对象

		return temp;
	}
	//重载赋值运算符(系统默认的重载等号运算符是浅拷贝)
	Person& operator=(Person &temp)
	{
		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
		}
		//深拷贝
		this->name = new char[strlen(temp.name) + 1];
		memset(this->name, 0, strlen(temp.name) + 1);

		strcpy(this->name, temp.name);
		this->age = temp.age;

		return *this;
	}
	//重载+=运算符,考虑到+=运算符的性质，此处返回类型要用引用,策略是先设置指针作为操作的辅助空间，再将这个辅助空间数据赋给this指向的对象
	Person& operator+=(Person &temp)
	{
		char *pperson = new char[strlen(this->name) + strlen(temp.name) + 1];
		memset(pperson, 0, strlen(this->name) + strlen(temp.name) + 1);

		strcpy(pperson, this->name);
		strcat(pperson, temp.name);

		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
		}
		//深拷贝
		this->name = pperson;//直接将pperson申请的动态对象空间，用this->name指向
		this->age += temp.age;

		return *this;
	}
	Person& operator+=(int age)
	{
		this->age += age;
		return *this;
	}
	//重载-=操作符
	Person& operator-=(Person &temp)
	{
		char *pperson = new char[strlen(this->name)-strlen(temp.name) + 1];
		memset(pperson, 0, strlen(this->name) - strlen(temp.name) + 1);

		char *start = strstr(this->name, temp.name);
		if (NULL == start)//不改变this指针指向的对象的name数据域,只改变data域
		{
			this->age -= temp.age;
			return *this;
		}
		strncpy(pperson, this->name,start-this->name);
		if (this->name != NULL)//释放原来this->name指向的动态对象空间
		{
			delete[]this->name;
			this->name = NULL;
		}
		this->name = pperson;
		this->age-=temp.age;
		return *this;
	}
	Person& operator-=(int age)
	{
		this->age -= age;
		return *this;
	}
	//重载*=运算符
	Person& operator*=(int factor)
	{
		this->age *= factor;
		return *this;
	}
	//重载/=运算符
	Person & operator/=(int factor)
	{
		this->age /= factor;
		return *this;
	}
	//重载++运算符(前置)
	Person & operator++()
	{
		this->age++;
		return *this;
	}
	//重载++运算符(后置)
	Person operator++(int)
	{
		Person temp(this->age, this->name);
		this->age++;
		return temp;
	}
	//重载--运算符(前置)
	Person & operator--()
	{
		this->age--;
		return *this;
	}
	//重载--运算符(后置)
	Person operator--(int)
	{
		Person temp(*this);
		this->age--;
		return temp;
	}
	//重载数组下标运算符
	int operator[](int pos)
	{
		if (pos < 0 || pos >= 20)
		{
			return -1;
		}
		return this->data[pos];
	}
	//重载数组下标运算符
	Person operator[](Person &temp)
	{
		return temp;
	}
	//重载()_运算符,实现用一个对象访问另一个对象
	void operator()(Person &temp)
	{
		cout << "name:" << temp.name << endl;
		cout << "age:" << temp.age << endl;
		return;
	}
	//重载int类型实现隐式类型转换，将int型变量转换成Person类对象
	operator int()
	{
		return this->age;
	}
	//实现对另一个类的隐式类型转换
	operator Student();
	
	~Person()
	{
		if (this->name != NULL)
		{
			delete[] this->name;
			this->name = NULL;
		}
	}
public:
	int age;
	char *name;//一旦对象的成员有指针，必须手动书写无参构造函数、拷贝构造函数、析构函数、赋值函数(c++默认会重载=号)；
	int data[20];
};
class Student
{
public:
	int number;
};
Person::operator Student()
{
	Student temp;
	temp.number = this->age;
	return temp;
}
//重载<<运算符,返回类型ostream，因为要打印Person类对象的公有成员，而公有成员可以在类外访问，所以不需要用到友元函数
ostream &operator<<(ostream &os, Person &ps)
{
	os << "name:" << ps.name << endl;
	os << "age:" << ps.age << endl;
	return os;//考虑到传入cout,此处返回的是cout对象
}
//重载<<运算符,返回类型ostream，因为要打印Person类对象的公有成员，而公有成员可以在类外访问，所以不需要用到友元函数
ostream &operator<<(ostream &os, const Person &ps)//函数参数有无const也是重载函数的条件。
{
	os << "name:" << ps.name << endl;
	os << "age:" << ps.age << endl;
	return os;//考虑到传入cout,此处返回的是cout对象
}
//重载>>运算符,重载>>运算符的返回类型必须是istream，因为要实现cin对象的传入，所以必须指定第一个参数为istream类型
istream &operator>>(istream &is, Person &ps)
{
	//创建用来接收字符串的缓冲区buf
	char buf[1024];
	int age;
	cout << "请输入名字:";
	is.getline(buf, sizeof(buf));
	cout << "请输入年龄:";
	is  >> age;
	//将ps的name赋值buf
	if (ps.name != NULL)
	{
		delete[]ps.name;
		ps.name = NULL;
	}
	ps.name = new char[strlen(buf) + 1];
	memset(ps.name, 0, strlen(buf) + 1);

	strcpy(ps.name, buf);
	ps.age = age;
	return is;

}

//加号重载(全局函数形式)
Person operator+(Person &p1, int age)//使用引用的方式节省空间
{
	Person temp(p1.age + age, p1.name);//用新数据初始化新对象
	return temp;
}

//减号运算符重载
Person operator-(Person &p1, int age)
{
	Person temp(p1.age - age, p1.name);//用新数据初始化新对象
	return temp;
}

//乘号运算符重载
Person operator*(Person &p1, int factor)
{
	Person temp(p1.age*factor, p1.name);
	return temp;
}

//除号运算符重载
Person operator/(Person &p1, int factor)
{
	Person temp(p1.age / factor, p1.name);
	return temp;
}

void test01()
{
	//测试无参构造函数
	Person p1;
	cout << "name:" << p1.name << " age:" << p1.age << endl;

	//测试拷贝构造函数
	Person p2(p1);
	cout << "name:" << p2.name << " age:" << p2.age << endl;

	//测试有参构造函数
	Person p3(20, "李晓");
	cout << "name:" << p3.name << " age:" << p3.age << endl;

	//测试成员的重载+号运算符的函数,为了实现cout<<对象名的形式，需重载<<运算符
	Person p4(10, "lixiao");
	cout << p4 + 3 << endl;//p4+3生成匿名对象，能够直接被重载的cout函数调用

	cout << "p3+p4:" << p3 + p4 << endl;

	Person p4plus3 = p4 + 3;
	cout << "p4plus3:" << p4plus3 << endl;

	Person p4plusp3 = p4 + p3;
	cout << "p4plusp3:" << p4plusp3 << endl;
	//测试减号运算符的重载函数
	cout << "p4" << p4 << endl;
	cout << "p4plus3minus3:" << p4plus3 - 3 << endl;

	cout << "p4plusp3minusp3:" << p4plusp3 - p3 << endl;

	//测试乘号运算符的重载函数
	cout << "p4*3:" << p4 * 3 << endl;
	Person p4multi3(p4 * 3);

	cout << "p4multi3:" << p4multi3 << endl;
	cout << "p4multi3/3:" << p4multi3 / 3 << endl;

	Person p4multi3dive3(p4multi3 / 3);
	cout << "p4multi3dive3:" << p4multi3dive3 << endl;

	//
}

void test02()
{
	//测试赋值运算符
	Person p1(23, "金正恩");

	Person p2(35, "奥巴马");

	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;

	p1 = p2;
	cout << "p1:" << p1 << endl;
	

}
//测试+=、-=、*=、/=
void test03()
{
	Person p1(20, "李天");
	
	p1 += 3;
	cout << p1 << endl;

	p1 -= 3;
	cout << p1 << endl;

	Person p2(32, "张天");
	p1 += p2;
	cout << p1 << endl;

	p1 -= p2;
	cout << p1 << endl;

	Person p3(3, "占天");
	p1 -= p3;
	cout << p1 << endl;

	p3 *= 34;
	cout << p3 << endl;

	p3 /= 34;
	cout << p3 << endl;
}
//测试>>运算符
void test04()
{
	Person p1;
	cin >> p1;
	cout << p1 << endl;
}
//测试前置加加、后置加加、前置减减、后置减减
void test05()
{
	Person p1(20, "恶李伟");
	cout<<p1++<<endl;
	cout << p1 << endl;

	++p1;
	cout << p1 << endl;

	cout<<p1--<<endl;
	cout << p1 << endl;

	--p1;
	cout << p1 << endl;
}
//测试匿名对象
void test06()
{
	const Person &p1 = Person();
	cout << p1 << endl;	
}
//测试数组下标运算符重载
void test07()
{
	Person p1 = Person();
	cout << p1[3] << endl;

	Person p2(20, "恶社会");
	cout << p1[p2] << endl;
}
//测试括号运算符重载
void test08()
{
	Person p1(20, "xzl");
	Person p2(30, "故意的");
	p1(p2);
	return;
}
//测试重载int型函数，返回对象的age
void test09()
{
	Person p1(23, "不熟悉");
	int age = p1;
	cout << age << endl;

	Student s1 = p1;
	cout << s1.number << endl;
}
#if 0
//利用vs开发人员工具查看继承了不被访问的父类私有成员;并查看protected成员权限，已知protected成员能被子类访问，但不能在类外访问
class Base
{
public:
	int BApublic;
protected://意味当以public和protected方式时可以被子类继承为protected(以protected权限的方式成为子类的成员)
	int BBprotected;
private:
	int BCprivate;
};

class Derived :public Base
{
public:
	int DApublic;
protected:
	int DBprotected;
private:
	int DCprivate;
public:
	void print()
	{
		cout << "BBprotected:" << &BBprotected << endl;//子类可以访问以public方式继承的父类中的protected成员。
	}

};

void testclass()
{
	Derived Dobj;
	Dobj.print();

}
#endif



int main()
{
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test09();
	system("pause");
	return 0;
}