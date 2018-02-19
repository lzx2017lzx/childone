#include<stdio.h>
//打印*
int prt_emp(int prt_num)
{
        int i=0;
        for(i=0;i<prt_num;i++)
        printf("*");
        return 0;
}
//打印p
int prt_p(int prt_num)
{
	int i=0;
	for(i=0;i<prt_num;i++)
	printf("p");
}
//打印一行多级指针
int prt_mup(int num)//num表示打印的级数
{
	if(num<1)
	{
	printf("int a = 0\n");
	return 0;
	}
	else if(num==1)
	{
	printf("int *p = &a\n");
	return 0;
	}else
	{
	printf("int ");
	int i=0;
	for(i=0;i<num;i++)
	printf("*");
	for(i=0;i<num;i++)
	printf("p");
	printf(" = &");
	for(i=0;i<num-1;i++)
	printf("p");
	printf("\n");
	}
	return 0;
}
int main()
{
	int i=0;
	for(i=18;i>=0;i--)
	prt_mup(i);

	return 0;
}
