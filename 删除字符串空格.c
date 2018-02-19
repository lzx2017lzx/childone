#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
4. 编写一个函数。其参数为一个字符串，函数删除字符串中的空格
*/
void delspace(char *p1)
{
	char *p2;
	while (*p1 != '\0')
	{
		if (*p1 == ' ')
		{
			p2 = p1;
			while (*p2 != '\0')
			{
				*p2 = *(p2 + 1);
				p2++;
			}
			p1--;//抵消下面的p1++
		}
		p1++;
	}
}
int main(void)
{
	char str[] = "abc hello mike ";
	delspace(str);
	printf("str=%s\n", str);


	printf("\n");
	system("pause");
	return 0;
}