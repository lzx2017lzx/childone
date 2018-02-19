#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **args)
{
char ch;
	if(argc<3)
	return 0;
	else
	{
	FILE *p1=fopen(args[1],"r");
	FILE *p2=fopen(args[2],"w");
	if(p1)
	{
	while((ch=getc(p1))!=EOF)
	{
//	printf("%c",ch);
	putc(ch,p2);
	}
	}

	}
	
	return 0;
}
