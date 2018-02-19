#include<stdio.h>
int main()
{
//	float a=0;
	unsigned long *p2;
	p2=(unsigned long *)0x810000;
	printf("%p",p2+5);
	return 0;

}
