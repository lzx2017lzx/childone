#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	��ѡ����������Ż������ٽ����Ĵ���
*/
int main01(void)
{

	int a[] = { 2,4,1,3,9,6,7,5,8 };
	int i = 0, j = 0;
	int len = sizeof(a) / sizeof(a[0]);
	//����������洢ÿ����ѭ����������Сֵ���±�
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
		//�����±�MinForIndex��i������,�������ķ�ʽ��ע������������������ͬһ���洢�ռ���
		if(MinForIndex!=i)
		{
		a[MinForIndex] ^= a[i];
		a[i] ^= a[MinForIndex];
		a[MinForIndex] ^= a[i];
		}
	}

	//������ӡ����
	for (i = 0; i < len; i++)
	{
		printf("a[%d]:%d  ", i, a[i]);
	}
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}
