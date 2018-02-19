/*
可变参数练习
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
void func(int n, ...)
{
	int num;
	//int i = 0;

	va_list ap;

	va_start(ap, n);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		num = va_arg(ap, int);
		printf("num=%d\n", num);
	}

	va_end(ap);
}

void func2(char *a, int b, int n, ...)
{
	printf("a=%s\n", a);
	printf("b=%d\n", b);

	int num;
	int i = 0;

	va_list ap;

	va_start(ap, n);

	for (int i = 0; i < n; i++)
	{
		num = va_arg(ap, int);
		printf("num=%d\n", num);
	}

	va_end(ap);
}

void func3(const char *fmt, ...)
{
	const char *arg = fmt;

	va_list ap;

	va_start(ap, fmt);

	while (arg != NULL)
	{
		printf("arg=%s\n", arg);
		arg = va_arg(ap, const char *);
	}
	va_end(ap);
}
int main(void)
{
	//func(3, 1, 2, 4);
	//func2("abcde", 5, 4, 2, 3, 4, 6);
	char *p = "lllll";
	func3("mm", "abcde", p, NULL);
	printf("\n");
	system("pause");
	return 0;
}