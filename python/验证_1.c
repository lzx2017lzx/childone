#include<stdio.h>
int main()
{
	int a[10]={0};
	printf("%p,%p,%p,%p",a,&a,a+1,&a+1);
	printf("\nsizeof(a):%d",sizeof(a));
	char *p[3]={"0"};
	printf("sizeof(*p)=%d\n",sizeof(*p));
	return 0;

}
