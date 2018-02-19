#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **args)
{
char ch;
	if(argc<2)
	return 0;
	else
	{
	FILE *p=fopen(args[1],"r");
	if(p)
	{
	while((ch=getc(p))!=EOF)
	{
//	printf("%c",ch);
	putchar(ch);
	}
	}
	fclose(p);
	}
	return 0;
}
