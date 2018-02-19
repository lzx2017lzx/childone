#include<stdio.h>
int main()
{
	char ch=255;
	printf("%d\n",ch);//结果是-1，说明字符存储类型是有符号的，是以补码方式存放
	printf("%c\n",ch);
	ch=200;
	printf("%c\n",ch);
	ch=150;
	printf("%c\n",ch);//有些ASCII值打印不了，现有字符集没有将1个字节填满
	printf("-----\n");
	return 0;
}
