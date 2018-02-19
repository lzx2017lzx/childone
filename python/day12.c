#include<stdio.h>
#include<stdlib.h>
struct man
{
char *name;
int age;
};
int main(int argc,char **args)
{
	if(argc<2)
	return 0;
	int i=0;
	int j=0;
	FILE *p=fopen(args[1],"r");
	while(!feof(p))
	{
	
	if(fgetc(p)=='\n')
		i++;
	}
	fclose(p);
	p=fopen(args[1],"r");
	struct man * ptr=(struct man *)malloc(i*(sizeof(struct man)));
	while(!feof(p))
	{
	ptr[j].name=(char *)calloc(20,1);
	fscanf(p,"姓名=%s,年龄=%d",ptr[j].name,&ptr[j].age);
//	printf("%s,%d\n",ptr[j].name,ptr[j].age);
	j++;
	}
	printf("%s,%d\n",ptr[0].name,ptr[0].age);
	printf("%d",i);
	fclose(p);
	return 0;
}
