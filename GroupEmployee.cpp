//问题①产生10个员工，每位员工存在姓名和薪水两类数据；而且姓名都不同②、现有四个部门，DEVELOPMENTDEPARTMENT、RESEARCHDEPARTMENT、SALEDEPARTMENT、FINACIALDEPARTMENT；要将这四个人随机分到四个组中，每位只能在一个部门工作，但不允许部门一个人都没有
//③显示信息


//思路:先用list容器创建10个员工，并且为每个员工填好姓名及薪水等信息；然后分组，通过multimap容器将员工和部门形成键值对，其中部门是键。最后输出各部门信息
#include<iostream>
using namespace std;
#include<list>
#include<map>
#include<string>
#include<ctime>

//创建员工信息类
class Employee
{
public:
	string name;
	int salary;
};

#define DEVELOPMENTDEPARTMENTE 1
#define RESEARCHDEPARTMENT 2
#define SALEDEPARTMENT 3
#define FINACIALDEPARTMENT 4

void CreateEmployee(list<Employee>&Emp)
{
	char *temp = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		Employee em;
		em.name = "员工";
		em.name += temp[i];
		em.salary = rand() % 2000 + 2000;

		Emp.push_back(em);//向list容器中填入信息
	}
}

//分组
void DivideGroup(list<Employee> &Emp,multimap<int,Employee>&EmpMul)
{
	srand((unsigned int)time(NULL));

	for (list<Employee>::iterator it = Emp.begin(); it !=Emp.end(); it++)
	{
		int Department = rand() % 4 + 1;
		//EmpMul.insert(pair<int, Employee>(Department, (*it)));方法一插入数据
		//EmpMul.insert(make_pair(Department, (*it)));方法二插入数据
		EmpMul.insert(map<int, Employee>::value_type(Department, (*it)));//方法三插入数据

	}
	//for (int i = 0; i < 10; i++)
	//{

	//	int Department = rand() % 4 + 1;
	//	
	//	EmpMul.insert(pair<int, Employee>(Department, Emp.front()));//向multimap中插入数据（注意map中不允许有重复的键值)
	//	Emp.pop_front();//弹出链表始元素
	//}

	return;
}

//按部门打印数据
void PrintEmployee(multimap<int, Employee>&MulEmp)
{
	for(int i=1;i<5;i++)
	{
		//首先根据部门号找相同部门的人员信息；设置迭代器接返回值注意multimap类型的变量返回值是迭代器
		//multimap<int, Employee>::iterator *it = MulEmp.find(i);//找到所有键值为1的数据成员
		//auto pos = MulEmp.find(i);
		multimap<int, Employee>::iterator pos = MulEmp.find(i);
		int cnt = MulEmp.count(i);//找到键值为1的数据成员的个数
		switch (i)
		{
		case 1:
			cout << "DEVELOPMENTDEPARTMENTE员工信息:"<<endl;
			break;
		case 2:
			cout << "RESEARCHDEPARTMENT员工信息:" << endl;
			break;
		case 3:
			cout << "SALEDEPARTMENT员工信息:" << endl;
			break;
		case 4:
			cout << "FINACIALDEPARTMENT员工信息:" << endl;
		default:
			break;

		}
		for (int j = 0; j < cnt; j++)
		{
			cout << "Name:" << pos->second.name <<" "<< "Salary:" << pos->second.salary << endl;
			pos++;
			//cout << " pos的类型" << typeid(pos).name() << endl;
		}
	}
}
int main(void)
{
	list<Employee>m1;
	multimap<int, Employee>mulemp;
	CreateEmployee(m1);

	DivideGroup(m1,mulemp);

	PrintEmployee(mulemp);

	system("pause");
	return 0;
}
