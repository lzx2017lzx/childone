#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **args)
{
  char ch[1024]={0};
  int i;
	if(argc<4)
	return 0;
	else
	{
	FILE *p1=fopen(args[1],"r");
	if(p1==NULL)
	return 0;
	FILE *p2=fopen(args[2],"w");
	if(p2==NULL)
	return 0;
	
	while(!feof(p1))
	{
//	printf("%c",ch);
	if(args[3][0]=='0')
	{
		fgets(ch,sizeof(ch),p1);
		for(i=0;(i<1024)&&(ch[i]);i++)
		ch[i]=ch[i]-1;	
		fputs(ch,p2);
	}
	else if(args[3][0]=='1')
	{
		fgets(ch,sizeof(ch),p1);
		for(i=0;(i<1024)&&(ch[i]);i++)
		ch[i]=ch[i]+1;
		fputs(ch,p2);
//	putc(ch,p2);
	}
	}
	fclose(p2);
	fclose(p1);
	}	
	return 0;
}
