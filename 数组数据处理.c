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
	//异常处理
	if (pos<0 || pos>*size)
	{
		pos = *size;
	}

	int i = 0;
	for (i = *size; i > pos; i--)
	{//移动元素，在指定的pos留出空位
	//从pos到*size-1，前一个元素给后一个
		a[i] = a[i - 1];

	}
	//在pos的位置插入新元素data
	a[pos] = data;
	(*size)++;//数组长度+1
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
		(*size)--;//数组长度-1
		return;
	}

	int i = 0;
	for(i=pos;i<*size;i++)
	{//从pos位置开始，后一个元素给前一个
		a[i] = a[i + 1];
	}
	(*size)--;//数组长度-1
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

	print_array(a, size); //打印
	insert_array(a, 0, -1, &size); //在0的位置插入-1
	print_array(a, size); //打印

	insert_array(a, 2, 8, &size); //在2的位置插入8
	print_array(a, size); //打印

	insert_array(a, size, 250, &size); //在末尾的位置插入250
	print_array(a, size); //打印

	return 0;
}
#endif



