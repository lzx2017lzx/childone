#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyLinkQueue.h"

//初始化用户数据
struct Person
{
	char name[20];
	int age;
};
//写print函数
void PrintPerson(void *Data)
{
	if (NULL == Data)
	{
		return;
	}

	struct Person *pPer = (struct Person *)Data;

	printf("name:%s,age:%d\n", pPer->name, pPer->age);
}
void Test()
{
	struct Person p1 = { "abc",21 };
	struct Person p2 = { "deg",22 };
	struct Person p3 = { "paa",10 };
	struct Person p4 = { "bbb",20 };
	struct Person p5 = { "ccc",30 };
	struct Person p6 = { "ddd",40 };

	/*
	//初始化栈
	//初始化链式队列
	LinkQueueList InitLinkQueue();
	//入队
	int PushLinkQueue(LinkQueueList LQueue, void *Data);
	//出队
	int PopLinkQueue(LinkQueueList LQueue);
	//访问队头元素
	void * VisitHeaderQueue(LinkQueueList LQueue);
	//访问队尾元素
	void *VisitRearQueue(LinkQueueList LQueue);
	//获得队内元素个数
	int GetSizeQueue(LinkQueueList LQueue);
	//销毁队
	int DestroyQueue(LinkQueueList LQueue);
	typedef struct LinkNode
{
	void *Data;
	struct LinkNode * Next;
}LNode;

//借用结构体定义链式队列
struct LinkQueue
{
	LNode Header;
	int Size;
	LNode *Rear;
};*/
	//初始化队列
	struct LinkQueue*PLQueue= InitLinkQueue();
	//向队列插入数据
	PushLinkQueue(PLQueue, &p1);
	PushLinkQueue(PLQueue, &p2);
	PushLinkQueue(PLQueue, &p3);
	PushLinkQueue(PLQueue, &p4);
	PushLinkQueue(PLQueue, &p5);
	PushLinkQueue(PLQueue, &p6);
	//访问队头元素
	struct LinkNode *PLNode = NULL;
	PLNode= VisitHeaderQueue(PLQueue);
	PrintPerson(PLNode);


	//访问队尾元素
	PLNode = VisitRearQueue(PLQueue);
	PrintPerson(PLNode);


	//访问尺寸
	//printf("Size=%d\n",GetSizeQueue(PLNode));//此处输入的参数应该是PLQueue
	printf("Before Pop Size=%d\n", GetSizeQueue(PLQueue));


	//弹出元素
	//PopLinkQueue(PLNode);//此处输入的参数应该是PLQueue
	PopLinkQueue(PLQueue);


	//printf("Size=%d\n", GetSizeQueue(PLNode));//此处输入的参数应该是PLQueue
	printf("After Pop Size=%d\n", GetSizeQueue(PLQueue));


	//访问队头元素
	printf("弹出队头元素之后的队头元素，以及队的大小。\n");
	PLNode = VisitHeaderQueue(PLQueue);
	PrintPerson(PLNode);


	//销毁队
	DestroyQueue(PLQueue);
}
int main(void)
{
	Test();
	printf("\n");
	system("pause");
	return 0;
}
