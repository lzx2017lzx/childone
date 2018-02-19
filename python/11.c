#include<stdio.h>
struct student
{
char name[20];
char a;
int age;
};
struct teacher
{
char name[21];
int age;
struct student st1;
};
int main1()
{
	struct student st[3]={{"张三",34},{"李四",22},{"王二",55}};
	struct student *p=st;
	struct teacher te;
	printf("%s %d\n",p->name,p->age);
	printf("%d,%d\n",sizeof(st),sizeof(p[0]));
	printf("%d\n",sizeof(te));
	return 0;
}
union A
{
	int a1;
	short a2;
	char a3;
};
int main()
{
	union A a;
	a.a1=1;
	printf("%u",a.a1);
	return 0;
}
