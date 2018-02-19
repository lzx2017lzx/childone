#include<stdio.h>
extern int n;
void test(int n)
{
	printf("%p,n=%d\n",&n,n);
	if(n<10)
	test(n+1);
	printf("%p,n=%d\n",&n,n);
}
int main()
{
	test(n);
	return 0;
}
