#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[]="AbCdefGHijLKdfkjf";
	int i=0;//遍历字符串
	int len=strlen(a);
	char temp='0';
	int j=0;//交换遍历
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(isupper(a[j])&&islower(a[j+1]))
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("a=%s",a);
	return 0;
}
