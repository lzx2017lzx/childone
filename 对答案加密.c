//����ļ����ڴ�֮������д�д�ַ�
#include<stdio.h>
//ȥ��ÿ�п�ͷ�����пո�
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
	char buf[1024]={0};//���建������ȡ�ļ�����
	char temp[3]={0};
	int i=0;//�����ļ�����Ҫɾ�����ַ�
	while(fgets(buf,p)!=NULL)//�ж�д
	{
	while(buf[i]!=0)
	{
	

	}

	}



	return 0;
}