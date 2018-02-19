#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

//定义用户数据结构体
struct Person
{
	char name[20];
	int age;
};

void Test()
{
	//初始化数据
	//初始化
	struct SeqQue *PSeqQue = Init_LinkQueue();
	

	//创建数据
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "bbb",20 };
	struct Person p3 = { "ccc",30 };
	struct Person p4 = { "ddd",40 };

	//向队列Push数据
	Push_LinkQueue(PSeqQue, &p1);
	Push_LinkQueue(PSeqQue, &p2);
	Push_LinkQueue(PSeqQue, &p3);
	Push_LinkQueue(PSeqQue, &p4);
	//大小
	printf("before poping queue has Size:%d\n", Size_LinkQueue(PSeqQue));
	//出队
	Pop_LinkQueue(PSeqQue);

	//大小
	printf("after poping queue has Size:%d\n",Size_LinkQueue(PSeqQue));
	//获得队头元素
	struct Person *PPerson= Front_LinkQueue(PSeqQue);
	if (NULL == PPerson)
	{
		printf("Fail for Visit Front Element.\n");
	}
	printf("the first element of queue with name:%s,age:%d\n", PPerson->name, PPerson->age);
	
	//获得队尾元素
	PPerson = Back_LinkQueue(PSeqQue);
	if (NULL == PPerson)
	{
		printf("Fail for Visit Front Element.\n");
	}
	printf("the rear element of queue with name:%s,age:%d\n", PPerson->name, PPerson->age);
	//销毁
	Destroy_LinkQueue(PSeqQue);
	return;

}
int main(void)
{
	Test();
	printf("\n");
	system("pause");
	return 0;
}
