#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"
/*
�û���������
*/


//�û�ʹ�������,�����������׵�ַ��λ�ð�������ڵ�
struct Person
{
	struct LinkNode node;
	char name[64];
	int age;
};

void myPrint(void *data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n",person->name,person->age);
}
//ָ������ķ�ʽ
int CompareFunction(void *First, void *Next)
{
	//��Ϊ�ṹ��struct Person�ĵ�һ�����ĵ�ַ����������ṹ��ĵ�ַ����˽��������ַ����ǿ������ת�����Ϳ��Է��ʵ����ݣ�����ܹؼ���
	struct Person *PersonFirst = (struct Person *)First;
	struct Person *PersonNext = (struct Person *)Next;

#if 1
	//��������������
	if (PersonFirst->age > PersonNext->age)
	{
		return 1;
	}
	else
	{
		return 0;
	}
#endif
	
#if 0
	//����������ֻ������Ӣ������
	if (strcmp(PersonFirst->name, PersonNext->name) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

#endif

}
void test()
{

	//��ʼ������
	struct LinkList *list = Init_LinkList();

	struct Person p1 = { NULL, "faa", 10 };
	struct Person p2 = { NULL, "ebb", 20 };
	struct Person p3 = { NULL, "dcc", 30 };
	struct Person p4 = { NULL, "bdd", 40 };
	struct Person p5 = { NULL, "cee", 50 };
	struct Person p6 = { NULL, "gff", 60 };

	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);

	Foreach_LinkList(list, myPrint);

	//������ѡ������
	SelectRanking(list, CompareFunction);
	printf("-------------------\n");
	//������ӡ
	Foreach_LinkList(list, myPrint);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}
int main001(void)
{
	int a = 3;
	a = a;
	printf("\n");
	system("pause");
	return 0;
}
