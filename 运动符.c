#include<stdio.h>
#include<windows.h>
int main()
{
	while(1)
	{
	printf("/");
	sleep(1);
	printf("\b");//��ʾ���˸�

	printf("-");
	sleep(1);
	printf("\b");
	;

	printf("\a");
	sleep(1);

	printf("\\");
	sleep(1);
	printf("\b");;
	;};
	return 0;
;}