#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
struct student
{
	char name[100];
	int age;
};
int main01()
{
	struct student st;
	st.age=20;
	strcpy(st.name,"刘德华");
	printf("name=%s,age=%d\n",st.name,st.age);
	return 0;
}
int main()
{
	struct student st={.age=30,.name="张学友"};
	printf("name=%s,age=%d\n",st.name,st.age);
	return 0;
}
