#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//���ַ�����ǰ��ո��ַ�ȥ��
char * removeempty1(char *ptr,int n)
{
	char *ptr1=ptr;//����ָ����ҵ�һ���ǿհ��ַ�
	char *ptr2=(char *)malloc(n);
	memset(ptr2,0,n);
	int i=0;
	int j=0;
	int k=n-1;
	for(i=0;i<n;i++)
	{
	if(ptr[i]!=' ')
	{
	break;
	}
	}
	for(;k>0;k--)
	{
	if(ptr[k]!=' ')
	{
	break;
	}
	}
	while(1)
	{
	ptr2[j++]=ptr[i++];
	if(i>k)
	{
	printf("seccess\n");
	break;
	}
	}
	printf("%d\n",strlen(ptr2));
	return ptr2;
}
char *removeempty2(char *str)
{
	int i=0;
	//����ַ����ĳ���,����'\0';
	while(str[i]!='\0')
	{
	i++;
	};
	int j=0;
	int k=0;
	int flag=0;
	char *str1=(char *)malloc(i);
	memset(str1,0,i);
	while(str[i-1]==' ')
	{
	i--;
	}
	for(;j<i;j++)
	{
	if(str[j]!=' '||flag)
	{
	str1[k++]=str[j];
	flag=1;	
	};
	};
	return str1;
}
char *removeempty3(char *ptr)
{
	char *p1=ptr;
	char *p2=NULL;
	int i=0;
	while(ptr[i])
	{
	p2=ptr+i;
	i++;
	}
	//���е���p2ָ���ַ������Ŀ��ַ���ǰһ���ַ�
	for(;p1<p2;)
	{
	if(*p1==' ')
	p1++;
	else if(*p2==' ')
	p2--;
	else
	{
	break;
	}
	}
}
int main()
{
	char *ptr="     hello world!      ";
//	char *ptr1=removeempty(ptr,i);		
	char *ptr1=removeempty2(ptr);
	printf("%s\n",ptr1);
	printf("%d\n",strlen(ptr1));
	return 0;
}