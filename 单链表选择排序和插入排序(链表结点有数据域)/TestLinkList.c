#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"

struct Person
{
	char name[64];
	int age;
};

void myPrint(void* data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name, person->age);
}
//写插入排序比较函数，用来回调
int pfun(void *Data1, void *Data2)
{
	struct Person *person1 = (struct Person *)Data1;
	struct Person *person2 = (struct Person *)Data2;

	//按年龄排序
	if (person1->age > person2->age)
	{
		return 1;
	}
	else if(person1->age < person2->age)
	{
		return -1;
	}
	else
	{
		return 0;
	}

	return 0;
}
//写选择排序回调函数
int pfun1(void *data1, void *data2)
{
	struct Person *person1 = (struct Person *)data1;
	struct Person *person2 = (struct Person *)data2;

	//按年龄排序
	if (person1->age > person2->age)
	{
		return 1;
	}
	return 0;
}
void test()
{

	//测试数据
	struct Person p1 = { "aaa", 21 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 21 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 11 };
	struct Person p6 = { "fff", 10 };

	//创建链表
	LinkList list = Init_LinkList();

	//插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);

	//Foreach_LinkList(list, myPrint);

	//删除数据
	//Remove_LinkList(list, 0);
	printf("-------------\n");
	Foreach_LinkList(list, myPrint);
	//Remove_LinkList(list, Size_LinkList(list) - 1 );
	//printf("-------------\n");
	//Foreach_LinkList(list, myPrint);
	//SelectSort(list, pfun1);
	//printf("\n选择排序结果-------------\n");
	InsertSort(list, pfun);
	printf("\n插入排序结果-------------\n");
	Foreach_LinkList(list, myPrint);




	//销毁链表
	Destroy_LinkList(list);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}