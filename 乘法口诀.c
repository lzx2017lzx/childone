#include<stdio.h>
int main()
{
	int i=0;
	int j=0;
	for(i=0;i<9;i++)
	{
	for(j=i;j<9;j++)
	{
	printf("%-4d",(i+1)*(j+1));
	};
	printf("\n");
	};
	return 0;
}