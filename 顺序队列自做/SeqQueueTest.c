#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

//�����û����ݽṹ��
struct Person
{
	char name[20];
	int age;
};

void Test()
{
	//��ʼ������
	//��ʼ��
	struct SeqQue *PSeqQue = Init_LinkQueue();
	

	//��������
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "bbb",20 };
	struct Person p3 = { "ccc",30 };
	struct Person p4 = { "ddd",40 };

	//�����Push����
	Push_LinkQueue(PSeqQue, &p1);
	Push_LinkQueue(PSeqQue, &p2);
	Push_LinkQueue(PSeqQue, &p3);
	Push_LinkQueue(PSeqQue, &p4);
	//��С
	printf("before poping queue has Size:%d\n", Size_LinkQueue(PSeqQue));
	//����
	Pop_LinkQueue(PSeqQue);

	//��С
	printf("after poping queue has Size:%d\n",Size_LinkQueue(PSeqQue));
	//��ö�ͷԪ��
	struct Person *PPerson= Front_LinkQueue(PSeqQue);
	if (NULL == PPerson)
	{
		printf("Fail for Visit Front Element.\n");
	}
	printf("the first element of queue with name:%s,age:%d\n", PPerson->name, PPerson->age);
	
	//��ö�βԪ��
	PPerson = Back_LinkQueue(PSeqQue);
	if (NULL == PPerson)
	{
		printf("Fail for Visit Front Element.\n");
	}
	printf("the rear element of queue with name:%s,age:%d\n", PPerson->name, PPerson->age);
	//����
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
