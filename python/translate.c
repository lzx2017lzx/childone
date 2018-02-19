#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct words
{
       char *wordgiven;
       char *wordmeaning;
};
int main(int argc,char **args)
{
          if(argc<2)
          return 0;
	  time_t timer1;
	  time_t timer2;
	  double seconds;
          //打开文件
          //FILE *p=fopen(args[1],"r");
          //将文件扫描到内存，且边扫描边查找
          int i=0;//结构体下标
          struct words *ptr=NULL;
          FILE *p=fopen(args[1],"r");
          //将文件扫描到内存，且边扫描边查找
          //int i=0;//结构体下标
          int j=0;//查找计数
	  int l=0;//打印各字符
          //struct words *ptr=NULL;
          char wordinput[100]={0};
          char buf[100]={0};//缓冲区定义
	  printf("please input the word.\n");
          scanf("%s",wordinput);
	  strcat(wordinput,"\r\n");
	  //strcat(wordinput,"\n");
//	  printf("%s",wordinput);
          char *pr=NULL;
	   while(1)
          {
	  fgets(buf,sizeof(buf),p);
	  if(feof(p))
	  {
	   //printf("---");
	   break;
	  };
	  ptr=realloc(ptr,(i+1)*sizeof(struct words));
	 // printf("%p\n",&ptr);
          if(ptr==NULL)
	  {
 	  printf("error memery!\n");
	  break;
	  };
	 // printf("------1\n");
	  ptr[i].wordgiven=(char *)malloc(strlen(buf)+1);
          memset(ptr[i].wordgiven,0,strlen(buf)+1);
	  strcpy(ptr[i].wordgiven,&buf[1]);
//	  printf("%s",ptr[i].wordgiven);
          fgets(buf,sizeof(buf),p);
          ptr[i].wordmeaning=(char *)malloc(strlen(buf)+1);
	  memset(ptr[i].wordmeaning,0,strlen(buf)+1);
	  pr=strtok(buf,"@");
         // p=strtok(NULL,"@");
	  while((pr=strtok(NULL,"@"))!=NULL)
	  {
	   pr--;
 	   *pr='\n';
	  };
          strcpy(ptr[i].wordmeaning,&buf[6]);
//	  printf("%s\n",ptr[i].wordmeaning);
          i++;  
	 // printf("------2\n");
	  }
	 // printf("-----\n");
	  //单词匹配
	  while(strncmp(wordinput,"exit!",5))
	  {
	  //printf("----------\n");
    	  time(&timer1);
	  for(j=0;j<i;j++)
	  {
	 // printf("%s",ptr[j].wordgiven);
	 // printf("\n--1--\n");
	 // printf("%s",wordinput);
	  if(!strcmp(wordinput,ptr[j].wordgiven))
	  {
	  printf("%d\n",strlen(wordinput));
	  printf("%d\n",strlen(ptr[j].wordgiven));	
	  while((ptr[j].wordgiven)[l])
	  {
	  printf("%d\n",(ptr[j].wordgiven)[l]);
	  l++;
	  }	
	  time(&timer2);
 	  seconds=difftime(timer2,timer1);
	  printf("time used %lf\n",seconds);
	  printf("%s\n",ptr[j].wordmeaning);
		break;
	  }
	  }
	  if(i==j)
	  printf("no found\n");
	  scanf("%s",wordinput);
	 // printf("%s",wordinput);
	  strcat(wordinput,"\r\n");
	  };
	  //释放内存
	for(j=0;j<i;j++)
	{
	free(ptr[j].wordgiven);
	free(ptr[j].wordmeaning);
	};
	free(ptr);
	fclose(p);
	return 0;
}

