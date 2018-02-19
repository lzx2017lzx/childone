#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare_character(int a, int b, int c, int d, int a1, int b1, int c1, int d1,int sum)
{
	int i = 0;
	int j = 0;
	//检查重复数
	if ((a1 != b1) && (a1 != c1) && (a1 != d1) && (b1 != c1) && (b1 != d1) && (c1 != d1))
	{
		if (a1 == a)
			i++;
		else if((a1 == b) || (a1 == c) || (a1 == d))
			j++;

		if (b1 == b)
			i++;
		else if((b1 == a) || (b1 == c) || (b1 == d))
			j++;

		if (c1 == c)
			i++;
		else if((c1 == a) || (c1 == b) || (c1 == d))
			j++;

		if (d1 == d)
			i++;
		else if((d1 == a) || (d1 == b) || (d1 == c))
			j++;

		switch (i)
		{
		case 0:
		{
			switch (j)
			{
			case 0:printf("SO BAD!\n"); break;
			case 1:printf("B\n"); break;
			case 2:printf("BB\n"); break;
			case 3:printf("BBB\n"); break;
			case 4:printf("BBBB\n"); break;
			default:break;
			}
			return 0;
		}
		case 1:
				{
			switch (j)
			{
			case 0:printf("A\n"); break;
			case 1:printf("AB\n"); break;
			case 2:printf("ABB\n"); break;
			case 3:printf("ABBB\n"); break;
			default:break;
			}
			return 0;
		}
		case 2:
		{
			switch (j)
			{
			case 0:printf("AA\n"); break;
			case 1:printf("AAB\n"); break;
			case 2:printf("AABB\n"); break;
			default:break;
			}
			return 0;
		}
		case 3:
		{
			switch (j)
			{
			case 0:printf("AAA\n"); break;
			case 1:printf("AAAB\n"); break;
			default:break;
			}
			return 0;
		}
		case 4:printf("SO GOOD!number is %d", sum); return 1;
		default:
			break;
		}
		return 0;//与随机数比较
	}
	else
	{
		printf("input error!");
		return 0;
	}
}
int judgment(const char *str,int *integ)
{
	int i = 0;
	int j = 0;
	//char *ptr = str;
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			integ[j++] = str[i] - '0';
		else
		{
			printf("input error!");
			return 0;
		}
		i++;
	}
	if (i <4)
	{
		printf("input error!");
		return 0;
	}
	return 1;
}
//判断是否有数字；
int hasnumber(const char *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] <'0') || (str[i]>'9'))
		{
			i++;
		}
		else
			return 1;//说明有整数
	}
	return 0;//说明没有整数
}
//判断是否都是空格
int isempty(const char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return 0;
	}
	return 1;
}
int main()
{
	char *str =(char *)calloc(20,1);
	int sum1[4] = { 0 };
	int sum;
	int a, b, c, d;
	int i;
	srand((unsigned)(time(NULL)));
	int a1, b1, c1, d1;
	a = rand() % 10;
	//b = rand() % 10;
	while (1)
	{
		b = rand() % 10;
		if (b == a)
			b =rand() % 10;
		else
			break;
	}
	while (1)
	{
		c = rand() % 10;
		if ((c == a) || (c == b))
			c = rand() % 10;
		else
			break;
	}
	while (1)
	{
		d = rand() % 10;
		if ((d == a) || (d == b) || (d == c))
			d = rand() % 10;
		else
			break;
	}
	//a = 6; b = 5; c = 9; d = 7;
	
	while (1)
	{
		printf("please input 4 numbers(0-9):");
		gets(str,"%s",stdin);
		if (isempty(str))
		{
			printf("input error!");
			continue;
		}
		if (hasnumber(str) == 0)
			continue;
		else if (judgment(str, sum1) == 0)
			continue;//判断是否合格，
		else
		{
			d1 = sum1[0];
			c1 = sum1[1];
			b1 = sum1[2];
			a1 = sum1[3];
		}
		sum = sum1[0] * 1000 + sum1[1] * 100 + sum1[2] * 10 + sum1[3];
		if ((a1 >= 0) && (a1 <= 9) && (b1 >= 0) && (b1 <= 9) && (c1 >= 0) && (c1 <= 9) && (d1 >= 0) && (d1 <= 9))
		{
			i=compare_character(a, b, c, d, a1, b1, c1, d1, sum);//调用比较函数
			if (i == 1)
				break;
		}
		else
		{
			printf("input error!please input 4 numbers(0-9):");//如何分类
			printf("please input 4 numbers(0-9):");//
		}
	}
	system("pause");
	return 1;
}
int numberofcharcter(int i, int j)
{
	int count = 0;
	int a = i % 10;
	while (i)
	{
		a = i % 10;
		if (a == j)
			count++;
		i /= 10;
	}
	return count;
}
int main09()
{
	int number;
	int i, j;
	scanf("%d", &number);
	int count = 0;
	for (j = 0; j < 10; j++)
	{
		for (i = 1; i <= number; i++)
		{
			count += numberofcharcter(i, j);
		}
		printf("%d出现%d次\n", j, count);
		count = 0;
	}
	system("pause");
	return 0;
}