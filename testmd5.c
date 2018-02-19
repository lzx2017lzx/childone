#include"opensslmd5API.h"

int main()
{
	const char* temp=MYMD5("333");
	printf("temp:%s\n",temp);
	return 0;
}
