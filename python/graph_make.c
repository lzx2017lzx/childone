#include<stdio.h>
//打印一定个数空格
int prt_emp(int a)
{
int i=0;
for(i=0;i<a;i++)
{
	printf(" ");
}
return 0;
}
//打印一行图形
int prt_ghy(int a,char *str)//str指定特殊图形字符串
{
	int i=0;
	for(i=0;i<a;i++)
	{
	  printf("%s",str);
	}
	return 0;
}
//打印一个正方形
int prt_sq(int a,int side_length)//其中a表示边距左边的距离，side_length表示边长
{
int i=0;
prt_emp(a);
prt_ghy(side_length,"--");
printf("\n");
for(i=0;i<side_length-2;i++)
{
prt_emp(a);
printf("|");
prt_emp(2*side_length);
printf("|");
printf("\n");
}
prt_emp(a);
prt_ghy(side_length,"--");
printf("\n");
return 0;
}
int main()
{
	
	prt_sq(5,8);
	return 0;
}
