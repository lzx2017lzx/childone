#include<stdio.h>
int main()
{
	char* str="abc";
	FILE *fp=fopen("a.bat","wb");
	fseek(fp,1024,SEEK_SET);
	fwrite(str,1,1,fp);
	fclose(fp);
	return 0;
}
