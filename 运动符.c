#include<stdio.h>
#include<windows.h>
int main()
{
	while(1)
	{
	printf("/");
	sleep(1);
	printf("\b");//表示会退格

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