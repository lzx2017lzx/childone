#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#define SIZE (1024*8)
//�����˵�
#if 0
void menu()
{
	printf("==============\n");
	printf("1��д������Ϣ\n");
	printf("2����������Ϣ\n");
	printf("3������\n");
	printf("4���˳�\n");
	printf("==============\n");
}
//���ļ�д������Ϣ
void write_cfg()
{

}

void main()
{
	int cmd;
	while (1)
	{
		int cmd;
		while (1)
		{
			menu();

			printf("cmd: ");
			scanf("%d", &cmd);

			switch (cmd)
			{
			case 1:
				write_cfg_file();
				break;
			case 2:
				read_cfg_file();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				exit(0);
			}
		}
	}
	system("pause");
	return 0;
}
#endif
#if 0
/*
һ���ļ���ϰ����Ҫ��װ���ʺ�����������ļ���

ʾ�����򣬲ο���demo_file/demo.exe��

struct student
{
char name[20];
int age;
};

1��ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
2����ѯ�����û���Ϣ
3������Ҫɾ����������Ȼ����ļ�����Ӧ�����ֵĽṹɾ��
4��������ʹ�õڶ����ļ���ֻ��һ���ļ�������������
5����Ҫʹ�õ��ļ����Ĳ�������fwrite��fread

void menu()
{
printf("**************************\n");
printf("* 1 ������Ϣ\n");
printf("* 2 ��ѯ��Ϣ\n");
printf("* 3 ɾ���û�\n");
printf("* 4 �����Ļ\n");
printf("* 5 �˳�����\n");
printf("**************************\n");
}*/
void print_stu();
struct student
{
	char name[20];
	int age;
};
//�˵�
void menu()
{
	printf("**************************\n");
	printf("* 1 ������Ϣ\n");
	printf("* 2 ��ѯ��Ϣ\n");
	printf("* 3 ɾ���û�\n");
	printf("* 4 �����Ļ\n");
	printf("* 5 �˳�����\n");
	printf("**************************\n");
}
//���庯�������ļ�����ѧ����Ϣ
void write_inf()
{
	struct student s1 = { 0 };
	char *ps1 = (char *)malloc(sizeof(s1));
	memset(ps1, 0, sizeof(s1));
	//char buf[40] = { 0 };//ע�����ļ���д����Ϣʱ��һ�㶼Ҫ512�ı���,���Ǵ˴��ǰ���д������fwrite��fread����Ϊ�������ѡ�����ִ�С
	FILE *fp = NULL;
	fp = fopen("./student.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("./student.txt", "wb+");
		if (fp == NULL)
		{
			perror("fopen fails.\n");
			free(ps1);
			return;
		}
	}
	fseek(fp, 0, SEEK_END);
	while (1)
	{
		memset(&s1, 0, sizeof(s1));
		memset(ps1, 0, sizeof(s1));
		printf("������ѧ������:");
		scanf("%s", s1.name);
		if (strcmp(s1.name, "exit") == 0)
			break;
		printf("������ѧ������:");
		scanf("%d", &(s1.age));
		if (s1.age <= 0)
			break;
		//sprintf(buf, "name:%s,age:%d", s1.name, s1.age);
		//buf[38] = '\r';
		//buf[39] = '\n';
		sprintf(ps1, "%s %d", s1.name, s1.age);
		fwrite(ps1, 1, sizeof(s1), fp);
	}
	fclose(fp);
	print_stu();
	free(ps1);
	return;
}
//��ӡ�ļ���ѧ����Ϣ
void print_stu()
{
	FILE *fp = fopen("./student.txt", "r+");
	if (fp == NULL)
	{
		perror("fopen fails.\n");
		return;
	}
	//char buf[39] = { 0 };
	struct student s1 = { 0 };
	char *ps1 = (char *)malloc(sizeof(s1));
	memset(ps1, 0, sizeof(s1));
	int ret = 0;
	while(1)
	{ 
	memset(ps1, 0, sizeof(s1));
	ret=fread(ps1,1, sizeof(s1), fp);
	
	if (ret<=0)
		break;
	sscanf(ps1, "%s %d", s1.name, &(s1.age));
	printf("%s,%d\n",s1.name,s1.age);
	}
	//printf("\n");
	fclose(fp);
	free(ps1);
	return;
}
//������Ա��Ϣ
void find_stu()
{
	struct student s1 = { 0 };
	char name[20] = { 0 };
	char *ps1 = (char *)malloc(sizeof(s1));
	memset(ps1, 0, sizeof(s1));
	FILE *fp = fopen("./student.txt", "r+");
	if (fp == NULL)
	{
		perror("open file fails.\n");
		free(ps1);
		return;
	}
	while(1)
	{ 
	memset(name, 0, sizeof(name));
	//memset(temp, 0, sizeof(temp));
	printf("������Ҫ���ҵ�����:\n");
	scanf("%s", name);
	if (strcmp(name, "exit")==0)
		break;
	fseek(fp, 0, SEEK_SET);
	int flag = 0;//��������Ƿ����
	while (1)
	{
		memset(&s1, 0, sizeof(s1));
		memset(ps1, 0, sizeof(s1));
		fread(ps1,1,sizeof(s1), fp);
		if (feof(fp))
			break;
		sscanf(ps1, "%s %d", s1.name, &(s1.age));
		if (strcmp(s1.name, name)==0)
		{
			printf("%s,%d\n", s1.name,s1.age);
			flag = 1;
			break;
		}
	}
	if (0 == flag)
	{
		printf("%s �����ļ���.\n", name);
		//return ;
	}
	}
	fclose(fp);
	free(ps1);
	return;
}
//ɾ���ļ�����Ӧ������ѧ����Ϣ
void Delete_stu()
{
	
	FILE *fp = fopen("./student.txt", "r+");
	if (fp == NULL)
	{
		perror("fopen fails.\n");
		return;
	}
	struct student s1 = { 0 };
	char *ps1 = (char *)malloc(sizeof(s1));
	memset(ps1, 0, sizeof(s1));
	fseek(fp, 0, SEEK_END);
	long len_file = ftell(fp);//��Ҫ���ڴ�������Ķѿռ�Ĵ�С
	rewind(fp);
	struct student *buf_file = (struct student  *)malloc(100);
	memset(buf_file, 0, len_file);

	//char buf[39] = { 0 };
	int ret = 0;
	char name[25] = { 0 };
	//char temp[35] = { 0 };
	int i = 0;
	while (1)
	{
		//memset(buf_file, 0, sizeof(buf));
		memset(name, 0, sizeof(name));
		//memset(temp, 0, sizeof(temp));
		printf("��������Ҫɾ����ѧ��������.\n");
		scanf("%s", name);
		if (strcmp(name, "exit") == 0)
			break;
		//sprintf(temp, "name:%s,", name);
		fseek(fp, 0, SEEK_SET);
		while (1)
		{
			memset(ps1, 0, sizeof(s1));
			memset(&s1, 0, sizeof(s1));
			fread(ps1, 1, sizeof(s1), fp);
			if (feof(fp))
				break;
			sscanf(ps1, "%s %d", s1.name, &(s1.age));
			if (strcmp(s1.name, name) == 0)
			{
				continue;//������ҵ���Ϣ����������ѭ��
			}
			//buf[38] = '\n';
			//buf[37] = '\r';
			memcpy(buf_file + i, ps1, sizeof(s1));
			i++;
		}
		fclose(fp);
		fp = fopen("./student.txt", "wb+");
		if (fp == NULL)
		{
			perror("fopen fails.\n");
			free(ps1);
			return;
		}
		fwrite(buf_file, 1, i * sizeof(struct student), fp);
		fclose(fp);
		free(buf_file);
		print_stu();
		free(ps1);
		return;

	}
}

int main(void)
{
	int cmd = 0;
	while (1)
	{
		menu();
		printf("������cmd: ");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			write_inf();
			break;
		case 2:
			find_stu();
			break;
		case 3:
			Delete_stu();
			break;
		case 4:
			system("cls");
			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}



#endif

#if 0
/*
������д�����ļ�д����
1�������ϵ����ӣ���ʱ�����Ƿ���ջ�����飬Ȼ��ر��ļ����ٰ���ʱ��������д���ļ�
2������ʱ������ڶ�����������С����һ���Ծͷ���ã�����ͨ��realloc���䣬��������
*/

#endif
#if 0
/*
������֪ char **p = NULL; int lines ��д���ļ����������ļ��ж�ȡ���ݣ�Ϊÿһ�����ݰ���С����ռ䡣
void readFile(char ***p,int *line);

�ļ����ݲο���demo.txt��

��ʾ��
����ɨ���ļ�����������������ָ��p����ָ������ռ䡣
�ٸ���ÿ�����ݣ���̬����ռ䣬���ÿ�����ݡ�
*/
void readFile(char ***p, int *line)
{
	int i = 0;
	*p = (char **)malloc((*line) * sizeof(char *));
	FILE *fp = fopen("./student.txt", "r+");
	if (fp == NULL)
	{
		perror("file open fail.");
		free(*p);
		*p = NULL;
		return;
	}
//	int i = 0;
	char buf[100] = { 0 };
	int len = 0;
	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))
			break;
		len++;
	}
	*line = len;
	rewind(fp);
	for(i=0;i<len;i++)
	{	memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))
			break;
		(*p)[i] = (char *)malloc(strlen(buf));
		memset((*p)[i], 0, strlen(buf));
		strcpy((*p)[i], buf);
	}
	fclose(fp);
	return;
}
void print_file(char ***p, int *line)
{
	int i = 0;
	for (i = 0; i < *line; i++)
	{
		printf("%s\n", (*p)[i]);
	}
	return;
}
void free_heap(char **p, int *line)
{
	int i = 0;
	for (i = 0; i < *line; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
}
int main(void)
{
	char **p = NULL;
	int line = 0;
	readFile(&p, &line);

	print_file(&p, &line);

	free_heap(p, &line);
	p = NULL;
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0

int main(void)
{
	char **p = (char **)malloc(20);
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		p[i] = (char *)malloc(10);
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s\n", p[i]);
	}
	for (i = 19; i >=0; i--)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0

int main(void)
{
	char *p = (char *)malloc(20);
	printf("%s", p);
	free(p);
	//free(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
/*
�ġ�
a) һ�����ͣ�An integer��
int a;
b) һ��ָ�����͵�ָ�루A pointer to an integer��
int *pa=&a;
c) һ��ָ��ָ�����͵�ָ�루A pointer to a pointer to an integer��
int **ppa=&pa;
d) һ��10��������͵����飨An array of 10 integers��
int a[10];
e) һ��10�����ָ������ָ�������
��An array of 10 pointers to integers��
int *a[10];
f) һ��ָ����10�����������ָ��
��A pointer to an array of 10 integers��
int (*p)[10];
g) һ��ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ��
��A pointer to a function that takes an integer as an argument and returns an integer��
int (*pf)(int a);
h) һ�����10�� ָ�� ��Ҫһ�����Ͳ������ҷ���ֵ��һ�����ͺ�����ָ�������
��An array of ten pointers to functions that take an integer argument and return an integer��
int (*pf[10])(int a)
*/
#endif


