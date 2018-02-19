#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>//将.h写成.c
/*
1、获取到数组中质数的个数
函数原型：int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
函数功能：获取到数组arr中质数的个数
函数参数:	arr是需要被扫描的数组
p_count是一个传出的指针参数,将获取到的质数个数传出
函数返回值：
成功返回0；
如果有错误返回-1
*/
int getCountOfPrimer(int arr[], int len, unsigned int *p_count)
{
	if (len == 0)
		return 0;
	*p_count = 0;
	int i;
	int j;
	for (i = 0; i < len; i++)
	{
		for (j = 2; j <= sqrt(arr[i]); j++)
			if (arr[i] % j == 0)
				break;
		if (j > sqrt(arr[i]))
			*p_count = *p_count + 1;//*p_count++会改变p_count的地址
	}
	return 0;
}
int main01()
{
	int n;
	int i;
	unsigned int p_count = 0;
	printf("please input the number:\n");
	scanf("%d", &n);
	int *ptr = (int *)calloc(n, sizeof(int));
	printf("please input your datas.");
	for (i = 0; i < n; i++)
		scanf("%d", &ptr[i]);
	getCountOfPrimer(ptr, n, &p_count);
	printf("这组数中的质数有:%u个", p_count);
	free(ptr);
	system("pause");
	return 0;
}