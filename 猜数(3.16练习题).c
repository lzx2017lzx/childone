/*#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int num[4] = { 0,0,0,0 };
int input[4] = { 0,0,0,0 };

//计算机随机产生4个 不相同 的随机数
void generateNumber()
{
	srand((unsigned int)time(NULL));
	//0-9
	int i,j;
	for (i = 0; i < 4; ++i) ///3  3 
	{
		num[i] = rand() % 10;
		for (j = 0; j < i; ++j)
			if (num[i] == num[j])
				i--;
	}
}

int myisdigit(int ch)
{
	if (ch <= '9' && ch >= '0')
		return 1;
	else
		return 0;
}

//获取用户输入的4个不相同的随机数   判断是否合法  如果合法返回0  否则返回非0

int getInput() //a123 0123123\n
{
	char ch;
	int flag = 0;   //为0 表示正常  非0表示错误
	int count = 0;
	int j = 0;
	while ((ch = getchar()) != '\n') 
	{

		
		if (flag || count >= 4  || myisdigit(ch)==0)//如果是数字字符  返回非0
		{
			flag = 1;
			continue;
		}
		//判断当前字符跟前面的是否重复
		for (j = 0; j < count; ++j)
			if (ch == input[j] + '0')
			{
				flag = 1;
				break;
			}
		if (flag)
			continue;
		input[count] = ch - '0';
		count++;
	}
	return (flag || count<4) ? 1:0;
}

//比对用户输入和计算机的数据  产生结果 将结果传输到main中a和b中
void check(int *pa, int *pb)
{
	*pa = *pb = 0; //(*pa)++;
	int i, j;
	for(i=0;i<4;++i)
		for (j = 0; j < 4; ++j)
		{
			if (num[i] == input[j] && i == j)
			{
				(*pa)++;
			}
			else if (num[i] == input[j]) // i != j
			{
				(*pb)++;
			}
		}
}

//根据a和b的个数  打印AB
void printAB(int a, int b)
{
	int i;
	for (i = 0; i < a; ++i)
		putchar('A');
	for (i = 0; i < b; ++i)
		putchar('B');

	if (a == 0 && b == 0)
		printf("你太菜了");
	putchar('\n');
}



int main()
{
	int a = 0;    //存储A
	int b = 0;    //   B的个数
	generateNumber();

	while (1)
	{
		printf("please input 4numbers(0-9):");
		if( 0 != getInput())
		{
			printf("input error!");
			continue;
		}
		check(&a,&b);
		printAB(a, b);
		if (a == 4)
		{
			printf("GOOD!\n");
			break;
		}
	}

	return 0;
}*/