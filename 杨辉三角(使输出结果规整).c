#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//给定一个元素，求位数
int Uni_value(int num)
{
	int i=0;
	while(num)
	{
	i++;
	num/=10;
	}
	return i;
}
//要打印的空格数
int prt_emp(int prt_num)
{
	int i=0;
	for(i=0;i<prt_num;i++)
	printf(" ");
	return 0;
}
int main()
{
	//输入要打印的行数
	size_t a=0;//记录行数
	size_t num=0;//记录要输入的数据个数
	size_t i=0;//遍历数组输入数据
	size_t j=0;//记录数组行序
	size_t temp=0;//存放表达式下标的值
	printf("please input the number of rows:\n");
	while(1)
	{
	if(scanf("%u",&a)==1)
	{
//	getchar();
	break;
	}else
	{
	printf("input error,input again!.\n");
	getchar();
	}
	}
	num=(1+a)*a/2;
	size_t *arr=(size_t *)calloc(sizeof(size_t),num);
	for(i=0,j=1;i<num;i++)
	{
	if(((j-1)==0)&&(i<a))
	arr[i]=i+1;
	else if((i<((2*a-j+1)*j/2))&&(i>((2*a-j+2)*(j-1)/2)))
	{
	temp=(2*a-j+2)*(j-1);temp/=2;
	arr[i]=(i-(2*a-j+2)*(j-1)/2)*pow(2,j-1)+arr[temp];
	}else if(i==((2*a-j+1)*j/2))
	{
	j++;
	arr[i]=arr[(2*a-j+3)*(j-2)/2]+arr[(2*a-j+3)*(j-2)/2+1];
	};
//	j++;
	}
	int prt_row=Uni_value(arr[num-1]);//获得最大数的位数
	prt_row+=1;//保证最后几行之间存在分割符
	for(i=0,j=2;i<num;i++)
	{
	if((i==((2*a-j+2)*(j-1)/2)))
	{
	printf("\n");
	j++;
	}
//	if(prt_row<4)
	//prt_row=4;
//	prt_row-=Uni_value(arr[i]);//将最大数的位数减去要打印的元素的位数
	//prt_emp(prt_row);
	printf("%d",arr[i]);
	//prt_row-=Uni_value(arr[i]);
	prt_emp(prt_row-Uni_value(arr[i]));
	}
	printf("\n");
	return 0;
}
