#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
#include"mydll.h"
#pragma comment(lib,"./mydll.lib")
int main(void)
{
	printf("%d\n", myadd(1, 2));
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
void insert_array(int *a, int pos, int data, int *size)
{
	//�쳣����
	if (pos<0 || pos>*size)
	{
		pos = *size;
	}

	int i = 0;
	for (i = *size; i > pos; i--)
	{//�ƶ�Ԫ�أ���ָ����pos������λ
	//��pos��*size-1��ǰһ��Ԫ�ظ���һ��
		a[i] = a[i - 1];

	}
	//��pos��λ�ò�����Ԫ��data
	a[pos] = data;
	(*size)++;//���鳤��+1
}

void print_array(int *a, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
}

void remove_array(int *a, int pos, int *size)
{
	if (pos == *size - 1)
	{
		(*size)--;//���鳤��-1
		return;
	}

	int i = 0;
	for(i=pos;i<*size;i++)
	{//��posλ�ÿ�ʼ����һ��Ԫ�ظ�ǰһ��
		a[i] = a[i + 1];
	}
	(*size)--;//���鳤��-1
}

int main()
{
	int a[15] = { 1,3,5,7,9,11,13 };
	int size = 7;

	print_array(a, size);
	remove_array(a, 0, &size);
	print_array(a, size);

	system("pause");
	return 0;
}
int main01()
{
	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7;

	print_array(a, size); //��ӡ
	insert_array(a, 0, -1, &size); //��0��λ�ò���-1
	print_array(a, size); //��ӡ

	insert_array(a, 2, 8, &size); //��2��λ�ò���8
	print_array(a, size); //��ӡ

	insert_array(a, size, 250, &size); //��ĩβ��λ�ò���250
	print_array(a, size); //��ӡ

	return 0;
}
#endif



