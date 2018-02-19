#include<stdio.h>
struct A
{
	unsigned char a:2;
	char b:4;
};
int main1()
{
	struct A a1={0b11,0b1000};
	printf("%x,%x",a1.a,a1.b);
	return 0;
}
struct C
{
	char a1:4;
	int a2:10;
	char a3:1;
};
int main()
{
	printf("%u\n",sizeof(struct C));
	return 0;
}
