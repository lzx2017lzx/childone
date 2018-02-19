#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>//��.hд��.c
/*
1����ȡ�������������ĸ���
����ԭ�ͣ�int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
�������ܣ���ȡ������arr�������ĸ���
��������:	arr����Ҫ��ɨ�������
p_count��һ��������ָ�����,����ȡ����������������
��������ֵ��
�ɹ�����0��
����д��󷵻�-1
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
			*p_count = *p_count + 1;//*p_count++��ı�p_count�ĵ�ַ
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
	printf("�������е�������:%u��", p_count);
	free(ptr);
	system("pause");
	return 0;
}