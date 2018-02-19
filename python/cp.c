#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **args)
{
  char ch;
	if(argc<4)
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
	if(args[3][0]=='0')
	ch--;
	else if(args[3][0]=='1')
	ch++;
	putc(ch,p2);
	}
	}
	fclose(p2);
	fclose(p1);
	}	
	return 0;
}
