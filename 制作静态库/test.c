#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mylib.h"

#pragma comment(lib,"./mylib.lib")
int main(void)
{

	printf("a=%d\n", myadd(1, 1));
	printf("\n");
	system("pause");
	return 0;
}
