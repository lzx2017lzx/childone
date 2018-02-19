#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sort(char **array1, int num1, char(*array2)[30], int num2, char ***myp3, int *num3)
{
	if (array1 == NULL || array2 == NULL || myp3 == NULL || num3 == NULL)
	{
		return -1;
	}
	//char *buf[]
	int n = num1 + num2;
	//printf("n=%d\n", n);
	char **p = malloc(n * sizeof(char *));
	if (p == NULL)
	{
		return -1;
	}

	int i = 0;
	for (i = 0; i < num1; i++)
	{
		p[i] = (char *)malloc(strlen(array1[i]) + 1);//�����ַ����������ַ�'\0'
		if (p[i] != NULL)
		{
			strcpy(p[i], array1[i]);
		}
	}
	int j = 0;
	for (i = num1, j = 0; i < n; i++, j++)
	{
		p[i] = malloc(strlen(array2[j]) + 1);
		if (p[i] != NULL)
		{
			strcpy(p[i], array2[j]);
		}
	}

	//ѡ�����򣬽�������ָ�������ֵ�����������ǵ�ַ
	char *tmp = NULL;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	//��Ӹ�ֵ
	*myp3 = p;
	*num3 = n;
	return 0;
}
void printBuf(char **p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
}
void freeBuf(char ***p, int n)
{
	if (p == NULL)
	{
		return;
	}
	char **tmp = *p;//��ԭ����ָ��
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}
	if (tmp != NULL)
	{
		free(tmp);
		*p = NULL;
	}
}
int main(void)
{
	int ret = 0;
	char *p1[] = { "aa","cccc","bbbbbb" };
	char buf2[10][30] = { "11111","3333333","2222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;
	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;
	//ͨ���βθı�ʵ�ε�ֵ
	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("sort err:%d\n", ret);
		return ret;
	}
	printBuf(p3, len3);
	freeBuf(&p3, len3);
	printf("\n");
	system("pause");
	return 0;
}
