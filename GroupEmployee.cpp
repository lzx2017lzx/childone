//����ٲ���10��Ա����ÿλԱ������������нˮ�������ݣ�������������ͬ�ڡ������ĸ����ţ�DEVELOPMENTDEPARTMENT��RESEARCHDEPARTMENT��SALEDEPARTMENT��FINACIALDEPARTMENT��Ҫ�����ĸ�������ֵ��ĸ����У�ÿλֻ����һ�����Ź���������������һ���˶�û��
//����ʾ��Ϣ


//˼·:����list��������10��Ա��������Ϊÿ��Ա�����������нˮ����Ϣ��Ȼ����飬ͨ��multimap������Ա���Ͳ����γɼ�ֵ�ԣ����в����Ǽ�����������������Ϣ
#include<iostream>
using namespace std;
#include<list>
#include<map>
#include<string>
#include<ctime>

//����Ա����Ϣ��
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
		em.name = "Ա��";
		em.name += temp[i];
		em.salary = rand() % 2000 + 2000;

		Emp.push_back(em);//��list������������Ϣ
	}
}

//����
void DivideGroup(list<Employee> &Emp,multimap<int,Employee>&EmpMul)
{
	srand((unsigned int)time(NULL));

	for (list<Employee>::iterator it = Emp.begin(); it !=Emp.end(); it++)
	{
		int Department = rand() % 4 + 1;
		//EmpMul.insert(pair<int, Employee>(Department, (*it)));����һ��������
		//EmpMul.insert(make_pair(Department, (*it)));��������������
		EmpMul.insert(map<int, Employee>::value_type(Department, (*it)));//��������������

	}
	//for (int i = 0; i < 10; i++)
	//{

	//	int Department = rand() % 4 + 1;
	//	
	//	EmpMul.insert(pair<int, Employee>(Department, Emp.front()));//��multimap�в������ݣ�ע��map�в��������ظ��ļ�ֵ)
	//	Emp.pop_front();//��������ʼԪ��
	//}

	return;
}

//�����Ŵ�ӡ����
void PrintEmployee(multimap<int, Employee>&MulEmp)
{
	for(int i=1;i<5;i++)
	{
		//���ȸ��ݲ��ź�����ͬ���ŵ���Ա��Ϣ�����õ������ӷ���ֵע��multimap���͵ı�������ֵ�ǵ�����
		//multimap<int, Employee>::iterator *it = MulEmp.find(i);//�ҵ����м�ֵΪ1�����ݳ�Ա
		//auto pos = MulEmp.find(i);
		multimap<int, Employee>::iterator pos = MulEmp.find(i);
		int cnt = MulEmp.count(i);//�ҵ���ֵΪ1�����ݳ�Ա�ĸ���
		switch (i)
		{
		case 1:
			cout << "DEVELOPMENTDEPARTMENTEԱ����Ϣ:"<<endl;
			break;
		case 2:
			cout << "RESEARCHDEPARTMENTԱ����Ϣ:" << endl;
			break;
		case 3:
			cout << "SALEDEPARTMENTԱ����Ϣ:" << endl;
			break;
		case 4:
			cout << "FINACIALDEPARTMENTԱ����Ϣ:" << endl;
		default:
			break;

		}
		for (int j = 0; j < cnt; j++)
		{
			cout << "Name:" << pos->second.name <<" "<< "Salary:" << pos->second.salary << endl;
			pos++;
			//cout << " pos������" << typeid(pos).name() << endl;
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
