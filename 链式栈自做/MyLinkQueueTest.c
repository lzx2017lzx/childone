#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MyLinkQueue.h"

//��ʼ���û�����
struct Person
{
	char name[20];
	int age;
};
//дprint����
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
	//��ʼ��ջ
	//��ʼ����ʽ����
	LinkQueueList InitLinkQueue();
	//���
	int PushLinkQueue(LinkQueueList LQueue, void *Data);
	//����
	int PopLinkQueue(LinkQueueList LQueue);
	//���ʶ�ͷԪ��
	void * VisitHeaderQueue(LinkQueueList LQueue);
	//���ʶ�βԪ��
	void *VisitRearQueue(LinkQueueList LQueue);
	//��ö���Ԫ�ظ���
	int GetSizeQueue(LinkQueueList LQueue);
	//���ٶ�
	int DestroyQueue(LinkQueueList LQueue);
	typedef struct LinkNode
{
	void *Data;
	struct LinkNode * Next;
}LNode;

//���ýṹ�嶨����ʽ����
struct LinkQueue
{
	LNode Header;
	int Size;
	LNode *Rear;
};*/
	//��ʼ������
	struct LinkQueue*PLQueue= InitLinkQueue();
	//����в�������
	PushLinkQueue(PLQueue, &p1);
	PushLinkQueue(PLQueue, &p2);
	PushLinkQueue(PLQueue, &p3);
	PushLinkQueue(PLQueue, &p4);
	PushLinkQueue(PLQueue, &p5);
	PushLinkQueue(PLQueue, &p6);
	//���ʶ�ͷԪ��
	struct LinkNode *PLNode = NULL;
	PLNode= VisitHeaderQueue(PLQueue);
	PrintPerson(PLNode);


	//���ʶ�βԪ��
	PLNode = VisitRearQueue(PLQueue);
	PrintPerson(PLNode);


	//���ʳߴ�
	//printf("Size=%d\n",GetSizeQueue(PLNode));//�˴�����Ĳ���Ӧ����PLQueue
	printf("Before Pop Size=%d\n", GetSizeQueue(PLQueue));


	//����Ԫ��
	//PopLinkQueue(PLNode);//�˴�����Ĳ���Ӧ����PLQueue
	PopLinkQueue(PLQueue);


	//printf("Size=%d\n", GetSizeQueue(PLNode));//�˴�����Ĳ���Ӧ����PLQueue
	printf("After Pop Size=%d\n", GetSizeQueue(PLQueue));


	//���ʶ�ͷԪ��
	printf("������ͷԪ��֮��Ķ�ͷԪ�أ��Լ��ӵĴ�С��\n");
	PLNode = VisitHeaderQueue(PLQueue);
	PrintPerson(PLNode);


	//���ٶ�
	DestroyQueue(PLQueue);
}
int main(void)
{
	Test();
	printf("\n");
	system("pause");
	return 0;
}
