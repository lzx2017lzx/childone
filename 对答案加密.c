//清除文件中在答：之后的所有大写字符
#include<stdio.h>
//去掉每行开头的所有空格
int format(char *buf)
{
	
}
int main(int argv,char **args)
{
	if(argv<2)
	return 0;
	FILE *p=fopen(args[1],"a+")
	if(p==NULL)
	{
	fprintf(stderr,"File has not been found.");
	return 0;
	}
	char buf[1024]={0};//定义缓冲区读取文件数据
	char temp[3]={0};
	int i=0;//遍历文件查找要删除的字符
	while(fgets(buf,p)!=NULL)//行读写
	{
	while(buf[i]!=0)
	{
	

	}

	}



	return 0;
}