#include<stdio.h>
int main()
{
	FILE *p=fopen("abc.dat","rb");
	int i=0;
	int j=0;
	char ch;
	if(p==NULL)
	{
	printf("file open fail.\n");
	return 0;
	}
	while((i=fread(&ch,1,sizeof(ch),p)!=0))
	{
	j+=i;
	}
	printf("%d\n",j);
	fclose(p);
	return 0;
}
