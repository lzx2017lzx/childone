#include<stdio.h>
int main(int argc,char **args)
{
	if(argc<3)
	return 0;
	FILE *p1=fopen(args[1],"rb");
	if(p1==NULL)
	{
	printf("open fail.\n");
	return 0;
	}
	FILE *p2=fopen(args[2],"wb");
	if(p2==NULL)
	{
	printf("open fail.\n");
	return 0;
	}
	char ch[1024]={0};
	while(1)
	{
	fread(ch,1 ,sizeof(ch),p1);
	if(!feof(p1))
	break;
	fwrite(ch,1,sizeof(ch),p2);
	}
	return 0;
}