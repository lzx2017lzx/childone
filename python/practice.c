#include<stdio.h>
#include<stdlib.h>
//加法追加
int stdigitplus(char *str)
{
	int a;
	int b;
sscanf(str,"%d %d",&a,&b);
sprintf(str[5],"%d",a+b);
return 0;
}
//减法追加
int stdigitminus(char *str)
{
	int a;
	int b;
sscanf(str,"%d %d",&a,&b);
sprintf(str[5],"%d",a-b);
return 0;
}
//乘法追加
int stdigitmultiplex(char *str)
{
	int a;
	int b;
sscanf(str,"%d %d",&a,&b);
sprintf(str[5],"%d",a*b);
return 0;
}
//除法追加
int stdigitdivice(char *str)
{
	int a;
	int b;
sscanf(str,"%d %d",&a,&b);
sprintf(str[5],"%d",a/b);
	return 0;
}
int main(int argc,char **args)
{
	if(argc<2)
	return 0;
	int i=0;
	char *ch[50]=(char *)malloc(200);
//将文件拷贝到内存
	FILE *p=fopen(args[1],"r");
	if(p==NULL)
	return 0;
	ch[0]=(char *)malloc(20);
	while((fgets(ch[i],20,p))!=NULL)
	{
		switch(ch[i][2])
		{
		case '+':
			stdigitplus(ch[i])



		}
		i++;
	}


}
