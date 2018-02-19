#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct man
{
	char name[30];
	int age;
};
int insert()
{
	struct man m={0};
	FILE *p=fopen("a.dat","a");
	if(p==NULL)
            return 0;
	while(1)
	{
	    printf("please input name:");
	    scanf("%s",m.name);
	    if(strcmp(m.name,"exit")==0)
	        break;
	     printf("please input age:");
	     scanf("%d",&m.age);
	     fwrite(&m,1,sizeof(struct man),p);
	}
	fclose(p);
	return 0;	
}
 int myselect()
{
	struct man m={0};
	char name[30]={0};
	unsigned int a=1;
	printf("input name or all:");
	scanf("%s",name);
	FILE *p=fopen("a.dat","r");
	if(p==NULL)
 	  return 0;
	while(1)
	{
	  fread(&m,1,sizeof(struct man),p);
	  if(feof(p))
		break;
	  if(!strcmp(name,"all")||(a=!strcmp(name,m.name)))
	  printf("–’√˚=%s,ƒÍ¡‰=%d\n",m.name,m.age);
	}
	if(a==0)
	printf("no found\n");
	fclose(p);
	return 0;
}

int main(int argc,char **args)
{
	if(argc<2)
	  return 0;
	char c=args[1][0];
	if(c=='0')
	{
	insert();
	}
	else if(c=='1')
	{
	myselect();
	}	
	return 0;
}