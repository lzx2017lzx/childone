#include<stdio.h>
int recursion(int a)
{
	if((a==1)||(a==2))
	return 1;
	else
	return recursion(a-1)+recursion(a-2);
}
//求feibonaqie前n项和
int cla_sum(int a)
{
	if(a==1)
	return recursion(1);
	else
	return recursion(a)+cla_sum(a-1);
}
int main()
{
	int a=0;
	scanf("%d",&a);
	printf("%d",recursion(a));
	int n=0;
	printf("please input your number:\n");
	scanf("%d",&n);
	printf("前%d项和是：%d",n,cla_sum(n));
	return 0;
}
