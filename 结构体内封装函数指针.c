#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����һ������ָ������
typedef void(*PFUN)(int a);

//�ṹ���׺���ָ�����
typedef struct Test
{
	PFUN func;
}Test;

void setFunc(Test *p, PFUN tmp)
{
	p->func = tmp;
}
void funa(int a)
{
	printf("a=%d\n", a);
}
int main(void)
{
	Test obj;
	setFunc(&obj, NULL);
	obj.func = funa;

	obj.func(10);

	printf("\n");
	system("pause");
	return 0;
}