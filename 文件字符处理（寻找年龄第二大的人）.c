#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct man
{
	char name[20];
	int age;
};
//���ַ����к��ʵ��������뵽�ṹ����
/*
1���ļ���ʽ���£�����δ֪
����=���»�,����=50
����=����,����=30
����=��ѧ��,����=45
����=����ʦ,����=70
���еĽ���Ǵ�ӡ������ļ�������ڶ����˵���Ϣ��
*/
int main01()
{
	int i = 0;
	int j = 0;
	//char buf[1024] = { 0 };
	char *str = NULL;
	FILE *p = fopen("d:\\1.txt", "r");
	while (!feof(p))
	{
		if (fgetc(p) == '\n')
			i++;
	}
	fclose(p);

	//char *buf=(char *)malloc(i*20);
	struct man*ptr =(struct man *)malloc(i*(sizeof(struct man)));
	p = fopen("d:\\1.txt", "r");
//	struct man *ptr = (struct man *)malloc(i*(sizeof(struct man)));
	char buf[1024] = { 0 };
	//char *temp = NULL;
	int max = 0;
	int sec = 0;
	while ((fgets(buf, sizeof(buf), p))!=NULL)
	{	
		char *p1=strtok(buf,",");
		char *p2 = strchr(p1,'=');
		strcpy(ptr[j].name, &p2[1]);
		printf("%s\n",ptr[j].name);
		p1 = strtok(NULL, ",");
		p2 = strchr(p1, '=');
		char *p3 = &p2[1];
		ptr[j].age = atoi(p3);
		printf("%d\n", ptr[j].age);
		j++;
		if (ptr[j].age > ptr[max].age)
		{
			sec = max;
			max = j;
		}
		//printf("%s", temp);
		//printf("%s", buf);		
	}
	printf("the second maxium age is=%s,of age:%d\n", ptr[sec].name,ptr[sec].age);
	fclose(p);
	printf("%d", i);
	printf("__________\n");
	//printf("%s", buf);
	//printf("___________\n");
	//	char *s = strtok(buf, ",\\n");
		//printf("%s", s);	
		//char *s = strtok(buf,",");
		//char *name1 = strchr(s,"=");
		//printf("%s\n", name1);
		//strcpy(ptr[j].name, name1);
		//char *s1 = strtok(NULL, "= ");
		//char *age = s;
		//sscanf(s, "%d", &ptr[j].age);
		//j++;
	//}
	//char buf[1024] = { 0 };
	//while (*(fgets(buf, sizeof(buf), p))= '\n');
	//{
	//	printf("%s", buf);
	
	//}
	//for (j = 0; j < i; j++)
	//	printf("%s,%d\n", ptr[j].name, ptr[j].age);	
	//while ()
	//{
		//ptr[j].name = (char *)malloc(20, 1);
	//	fscanf(p, "����=%s,����=%d", ptr[j].name,&(ptr[j].age));
	//	j++;
	//}
	//for (j = 0; j < i; j++)
		//fscanf(p, "����=%s ,����=%d\n", ptr[j].name, &(ptr[j].age));
	//printf("%s", ptr[0].name);
	//printf("%s", ptr[1].name);
	//printf("%d", ptr[0].age);
	//fclose(p);
	//printf("%d", i);
	system("pause");
	return 0;
}
int main()
{
	FILE *p = fopen("C:\\2.txt", "r");
	int i = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, sizeof(buf), p) != NULL)
		printf("%d\n", ++i);
	system("pause");
	return 0;
}