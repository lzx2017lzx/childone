#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h>
class Student;//ǰ���������������÷��ʣ�ǰ������λ�����涼��������
class Person
{
public:
	Person()//�޲ι��캯����ʼ������
	{
		this->age = 0;
		this->name = new char[1];
		this->name[0] = '\0';
	}
	Person(int age, const char *name)//�����вι��캯��
	{
		this->age = age;
		this->name = new char[strlen(name) + 1];
		memset(this->name, 0, strlen(name) + 1);
		strcpy(this->name, name);
	}
	Person(const Person &p1)//д�������캯��
	{
		this->age = p1.age;
		this->name = new char[strlen(p1.name) + 1];//ֱ�ӽ�ָ�������ֵ��������p1.name��ֵ,������������ɶ����ͷ�nameָ��Ķѿռ䣬�ᱨ��(p1�ͷ��˶ѿռ䡢֮��p2��Ҫ���ͷ�һ��)������ǳ������
		memset(this->name, 0, strlen(p1.name) + 1);//����ѿռ�����
		strcpy(this->name, p1.name);//Ҫʹ��ͷ�ļ�string.h,����Ҫʹ��_CRT_SECURE_NO_WARNINGS
	}

	//��Ա��������+�������,�ӺŲ��ı�ԭ�е����ݣ����Է�������Ϊ����
	Person operator+(Person &p1)
	{
		//��thisָ������p1���ַ�������
		char *newname = new char[strlen(this->name) + strlen(p1.name) + 1];
		memset(newname, 0, strlen(this->name) + strlen(p1.name) + 1);//�������Ķѿռ�����

		strcpy(newname, this->name);
		strcat(newname, p1.name);//��thisָ������p1�ַ���������newname

		Person temp(this->age + p1.age, newname);//�������ݳ�ʼ���¶���

		return temp;

	}
	//����������Ϊ��Ա����
	Person operator-(Person &p1)
	{
		//��thisָ����ַ������ҵ���p1���ַ�����ͬ�Ĳ��ֵĿ�ʼλ��,��������strstr�����ҵ�λ�ã�֮����strncpy����ָ�������ݲ���
		char *start = strstr(this->name, p1.name);
		if (NULL == start)
		{
			//start==NULL��ζ��������ͬ�Ĳ��֣��˴���p1�ڵ��ַ�����ʼ���¶���
			Person temp(this->age + p1.age, p1.name);
			return temp;
		}
		//��thisָ����ַ���ɾ����p1���ַ�����ͬ�Ĳ��֣��Ѿ�Ĭ��thisָ����ַ�������p1�е��ַ���
		char *newname = new char[strlen(this->name) - strlen(p1.name) + 1];
		memset(newname, 0, strlen(this->name) - strlen(p1.name) + 1);//�������Ķѿռ�����

		strncpy(newname, this->name, start- this->name);
		Person temp(this->age + p1.age, newname);//�������ݳ�ʼ���¶���

		return temp;
	}
	//���ظ�ֵ�����(ϵͳĬ�ϵ����صȺ��������ǳ����)
	Person& operator=(Person &temp)
	{
		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
		}
		//���
		this->name = new char[strlen(temp.name) + 1];
		memset(this->name, 0, strlen(temp.name) + 1);

		strcpy(this->name, temp.name);
		this->age = temp.age;

		return *this;
	}
	//����+=�����,���ǵ�+=����������ʣ��˴���������Ҫ������,������������ָ����Ϊ�����ĸ����ռ䣬�ٽ���������ռ����ݸ���thisָ��Ķ���
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
		//���
		this->name = pperson;//ֱ�ӽ�pperson����Ķ�̬����ռ䣬��this->nameָ��
		this->age += temp.age;

		return *this;
	}
	Person& operator+=(int age)
	{
		this->age += age;
		return *this;
	}
	//����-=������
	Person& operator-=(Person &temp)
	{
		char *pperson = new char[strlen(this->name)-strlen(temp.name) + 1];
		memset(pperson, 0, strlen(this->name) - strlen(temp.name) + 1);

		char *start = strstr(this->name, temp.name);
		if (NULL == start)//���ı�thisָ��ָ��Ķ����name������,ֻ�ı�data��
		{
			this->age -= temp.age;
			return *this;
		}
		strncpy(pperson, this->name,start-this->name);
		if (this->name != NULL)//�ͷ�ԭ��this->nameָ��Ķ�̬����ռ�
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
	//����*=�����
	Person& operator*=(int factor)
	{
		this->age *= factor;
		return *this;
	}
	//����/=�����
	Person & operator/=(int factor)
	{
		this->age /= factor;
		return *this;
	}
	//����++�����(ǰ��)
	Person & operator++()
	{
		this->age++;
		return *this;
	}
	//����++�����(����)
	Person operator++(int)
	{
		Person temp(this->age, this->name);
		this->age++;
		return temp;
	}
	//����--�����(ǰ��)
	Person & operator--()
	{
		this->age--;
		return *this;
	}
	//����--�����(����)
	Person operator--(int)
	{
		Person temp(*this);
		this->age--;
		return temp;
	}
	//���������±������
	int operator[](int pos)
	{
		if (pos < 0 || pos >= 20)
		{
			return -1;
		}
		return this->data[pos];
	}
	//���������±������
	Person operator[](Person &temp)
	{
		return temp;
	}
	//����()_�����,ʵ����һ�����������һ������
	void operator()(Person &temp)
	{
		cout << "name:" << temp.name << endl;
		cout << "age:" << temp.age << endl;
		return;
	}
	//����int����ʵ����ʽ����ת������int�ͱ���ת����Person�����
	operator int()
	{
		return this->age;
	}
	//ʵ�ֶ���һ�������ʽ����ת��
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
	char *name;//һ������ĳ�Ա��ָ�룬�����ֶ���д�޲ι��캯�����������캯����������������ֵ����(c++Ĭ�ϻ�����=��)��
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
//����<<�����,��������ostream����ΪҪ��ӡPerson�����Ĺ��г�Ա�������г�Ա������������ʣ����Բ���Ҫ�õ���Ԫ����
ostream &operator<<(ostream &os, Person &ps)
{
	os << "name:" << ps.name << endl;
	os << "age:" << ps.age << endl;
	return os;//���ǵ�����cout,�˴����ص���cout����
}
//����<<�����,��������ostream����ΪҪ��ӡPerson�����Ĺ��г�Ա�������г�Ա������������ʣ����Բ���Ҫ�õ���Ԫ����
ostream &operator<<(ostream &os, const Person &ps)//������������constҲ�����غ�����������
{
	os << "name:" << ps.name << endl;
	os << "age:" << ps.age << endl;
	return os;//���ǵ�����cout,�˴����ص���cout����
}
//����>>�����,����>>������ķ������ͱ�����istream����ΪҪʵ��cin����Ĵ��룬���Ա���ָ����һ������Ϊistream����
istream &operator>>(istream &is, Person &ps)
{
	//�������������ַ����Ļ�����buf
	char buf[1024];
	int age;
	cout << "����������:";
	is.getline(buf, sizeof(buf));
	cout << "����������:";
	is  >> age;
	//��ps��name��ֵbuf
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

//�Ӻ�����(ȫ�ֺ�����ʽ)
Person operator+(Person &p1, int age)//ʹ�����õķ�ʽ��ʡ�ռ�
{
	Person temp(p1.age + age, p1.name);//�������ݳ�ʼ���¶���
	return temp;
}

//�������������
Person operator-(Person &p1, int age)
{
	Person temp(p1.age - age, p1.name);//�������ݳ�ʼ���¶���
	return temp;
}

//�˺����������
Person operator*(Person &p1, int factor)
{
	Person temp(p1.age*factor, p1.name);
	return temp;
}

//�������������
Person operator/(Person &p1, int factor)
{
	Person temp(p1.age / factor, p1.name);
	return temp;
}

void test01()
{
	//�����޲ι��캯��
	Person p1;
	cout << "name:" << p1.name << " age:" << p1.age << endl;

	//���Կ������캯��
	Person p2(p1);
	cout << "name:" << p2.name << " age:" << p2.age << endl;

	//�����вι��캯��
	Person p3(20, "����");
	cout << "name:" << p3.name << " age:" << p3.age << endl;

	//���Գ�Ա������+��������ĺ���,Ϊ��ʵ��cout<<����������ʽ��������<<�����
	Person p4(10, "lixiao");
	cout << p4 + 3 << endl;//p4+3�������������ܹ�ֱ�ӱ����ص�cout��������

	cout << "p3+p4:" << p3 + p4 << endl;

	Person p4plus3 = p4 + 3;
	cout << "p4plus3:" << p4plus3 << endl;

	Person p4plusp3 = p4 + p3;
	cout << "p4plusp3:" << p4plusp3 << endl;
	//���Լ�������������غ���
	cout << "p4" << p4 << endl;
	cout << "p4plus3minus3:" << p4plus3 - 3 << endl;

	cout << "p4plusp3minusp3:" << p4plusp3 - p3 << endl;

	//���Գ˺�����������غ���
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
	//���Ը�ֵ�����
	Person p1(23, "������");

	Person p2(35, "�°���");

	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;

	p1 = p2;
	cout << "p1:" << p1 << endl;
	

}
//����+=��-=��*=��/=
void test03()
{
	Person p1(20, "����");
	
	p1 += 3;
	cout << p1 << endl;

	p1 -= 3;
	cout << p1 << endl;

	Person p2(32, "����");
	p1 += p2;
	cout << p1 << endl;

	p1 -= p2;
	cout << p1 << endl;

	Person p3(3, "ռ��");
	p1 -= p3;
	cout << p1 << endl;

	p3 *= 34;
	cout << p3 << endl;

	p3 /= 34;
	cout << p3 << endl;
}
//����>>�����
void test04()
{
	Person p1;
	cin >> p1;
	cout << p1 << endl;
}
//����ǰ�üӼӡ����üӼӡ�ǰ�ü��������ü���
void test05()
{
	Person p1(20, "����ΰ");
	cout<<p1++<<endl;
	cout << p1 << endl;

	++p1;
	cout << p1 << endl;

	cout<<p1--<<endl;
	cout << p1 << endl;

	--p1;
	cout << p1 << endl;
}
//������������
void test06()
{
	const Person &p1 = Person();
	cout << p1 << endl;	
}
//���������±����������
void test07()
{
	Person p1 = Person();
	cout << p1[3] << endl;

	Person p2(20, "�����");
	cout << p1[p2] << endl;
}
//�����������������
void test08()
{
	Person p1(20, "xzl");
	Person p2(30, "�����");
	p1(p2);
	return;
}
//��������int�ͺ��������ض����age
void test09()
{
	Person p1(23, "����Ϥ");
	int age = p1;
	cout << age << endl;

	Student s1 = p1;
	cout << s1.number << endl;
}
#if 0
//����vs������Ա���߲鿴�̳��˲������ʵĸ���˽�г�Ա;���鿴protected��ԱȨ�ޣ���֪protected��Ա�ܱ�������ʣ����������������
class Base
{
public:
	int BApublic;
protected://��ζ����public��protected��ʽʱ���Ա�����̳�Ϊprotected(��protectedȨ�޵ķ�ʽ��Ϊ����ĳ�Ա)
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
		cout << "BBprotected:" << &BBprotected << endl;//������Է�����public��ʽ�̳еĸ����е�protected��Ա��
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