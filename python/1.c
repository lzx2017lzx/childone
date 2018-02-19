#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[20]="abcdefghij";
	char str1[]="4.66";
	char *p=(char *)calloc(100,sizeof(char));
	for(int i=0;i<100;i++)
	printf("%d\n",p[i]);
//	memset(str1,'a',strlen(str1));
//	memcpy(str1,str,sizeof(str1));
//	memset(str1,'j',sizeof(str1));
//	memmove(str1,str,3);
//	printf("%s",str1);
//	long a=atol(str1);
//	printf("%lf",a);
//	char *ptr=strtok(str1," ");
//	printf("%s\n",ptr);
//	ptr=strtok(NULL,"o");
//	printf("%s\n",ptr);
//	ptr=strtok(NULL,"ol");
//	printf("%s\n",ptr);
//	ptr=strtok(NULL,"ol");
//	printf("%s\n",ptr);
//	char *p=str+9;
//	int a=20;
	//strcpy(str1,str);
//	strncpy(str1,"d234567",6);
//	strcpy(str1,"1234");
//	printf("%s",str1);
	
//	sscanf(str1,"%d",a);
//	int a=strncmp(str1,str,4);
//	char *ptr=strstr(str,"cde");
//	printf("%s\n",ptr);
//	printf("%s\n",str1);
//	sprintf(str,"%d%s \n",a,str1);
//	printf("%s\n",str);
	return 0;
//	*(p+1)='b';
	//gets(str);
//	fgets(str,10,stdin);//fgets函数会在某位字节补零，所以实际有效字符是5-1；
	fputs(str1,stdout);
//	unsigned int a=strlen(str1);
//	printf("%d\n",a);
	printf("---------\n");
//	p=str+9;
	puts(str1);
	printf("%s\n",str1);
	printf("---------\n"); 
	printf("%d\n",sizeof(str));//因为str是指针变量，存储的是地址，所以输出是4个字节；
	printf("%s\n",str);//为什么即使输入10个非零字符，输出时没有烫烫烫？	
//	printf("%d\n",*p);
	return 0;
}
