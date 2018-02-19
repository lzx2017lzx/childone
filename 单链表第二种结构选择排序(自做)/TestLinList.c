#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"
/*
用户定义数据
*/


//用户使用链表二,必须在数据首地址的位置包含链表节点
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
//指定排序的方式
int CompareFunction(void *First, void *Next)
{
	//因为结构体struct Person的第一个结点的地址正好是这个结构体的地址，因此将这个结点地址进行强制类型转换，就可以访问到数据，这个很关键。
	struct Person *PersonFirst = (struct Person *)First;
	struct Person *PersonNext = (struct Person *)Next;

#if 1
	//按年龄升序排序
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
	//按名子排序，只适用于英文名字
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

	//初始化链表
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

	//对链表选择排序
	SelectRanking(list, CompareFunction);
	printf("-------------------\n");
	//排序后打印
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
