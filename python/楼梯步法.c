#include<stdio.h>
int any_sort(int a)
{
	if(a<0)
	return 0;
	if(a==1)
	{
	return 1;
	}
	else if(a==2)
	{
	return 2;
	}else if(a>2)
	{
	return (any_sort(a-1)+any_sort(a-2));
	}
}
int main()
{
	int n=0;//楼梯的梯级数
	printf("please input your number!\n");
	scanf("%d\n",&n);
	
	int j=any_sort(n);
	printf("走法种类是:%d\n",j);
	return 0;
}
