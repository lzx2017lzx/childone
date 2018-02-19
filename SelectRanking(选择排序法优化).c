#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	对选择排序进行优化，减少交换的次数
*/
int main01(void)
{

	int a[] = { 2,4,1,3,9,6,7,5,8 };
	int i = 0, j = 0;
	int len = sizeof(a) / sizeof(a[0]);
	//定义变量，存储每次内循环遍历的最小值的下标
	int MinForIndex = 0;
	//int temp = 0;

	for (i = 0; i < len; i++)
	{
		MinForIndex = i;
		for (j = i; j < len; j++)
		{
			if (a[MinForIndex] > a[j])
			{
				MinForIndex = j;
			}
		}
		//交换下标MinForIndex和i的数据,采用异或的方式，注意异或的两个数不能在同一个存储空间中
		if(MinForIndex!=i)
		{
		a[MinForIndex] ^= a[i];
		a[i] ^= a[MinForIndex];
		a[MinForIndex] ^= a[i];
		}
	}

	//遍历打印数据
	for (i = 0; i < len; i++)
	{
		printf("a[%d]:%d  ", i, a[i]);
	}
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}
