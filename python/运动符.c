#include<stdio.h>
//#include<windows.h>
int main()
{
	char buf[2]={0};
	while(1)
	{
	buf[0]='-';
	printf("%s\n",buf);
	sleep(5);
	buf[0]='\b';
	printf("%s",buf);
//	printf("\b");
	buf[0]='\\';
	printf("%s",buf);
	sleep(1);
	buf[0]='\b';
	printf("%s",buf);
	
	buf[0]='-';
	printf("%s",buf);
	sleep(1);
	buf[0]='\b';
	printf("%s",buf);
	
//	printf("/\0");
	sleep(1);
//	printf("\b");
	}
	return 0;
}
