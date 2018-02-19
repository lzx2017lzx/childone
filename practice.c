#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#define SIZE (1024*8)
//制作菜单
#if 0
void menu()
{
	printf("==============\n");
	printf("1、写配置信息\n");
	printf("2、读配置信息\n");
	printf("3、清屏\n");
	printf("4、退出\n");
	printf("==============\n");
}
//向文件写配置信息
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
一、文件练习（需要封装合适函数，无需分文件）

示例程序，参考《demo_file/demo.exe》

struct student
{
char name[20];
int age;
};

1、循环输入结构体信息，当输入age小于0时，则结束输入
2、查询所有用户信息
3、输入要删除的姓名，然后把文件中相应的名字的结构删除
4、不可以使用第二个文件，只用一个文件来完成这个任务
5、需要使用的文件核心操作函数fwrite、fread

void menu()
{
printf("**************************\n");
printf("* 1 输入信息\n");
printf("* 2 查询信息\n");
printf("* 3 删除用户\n");
printf("* 4 清除屏幕\n");
printf("* 5 退出程序\n");
printf("**************************\n");
}*/
void print_stu();
struct student
{
	char name[20];
	int age;
};
//菜单
void menu()
{
	printf("**************************\n");
	printf("* 1 输入信息\n");
	printf("* 2 查询信息\n");
	printf("* 3 删除用户\n");
	printf("* 4 清除屏幕\n");
	printf("* 5 退出程序\n");
	printf("**************************\n");
}
//定义函数，向文件输入学生信息
void write_inf()
{
	struct student s1 = { 0 };
	char *ps1 = (char *)malloc(sizeof(s1));
	memset(ps1, 0, sizeof(s1));
	//char buf[40] = { 0 };//注意向文件中写入信息时，一般都要512的倍数,但是此处是按行写，且是fwrite和fread函数为主，因此选择这种大小
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
		printf("请输入学生名字:");
		scanf("%s", s1.name);
		if (strcmp(s1.name, "exit") == 0)
			break;
		printf("请输入学生年龄:");
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
//打印文件中学生信息
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
//查找人员信息
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
	printf("请输入要查找的姓名:\n");
	scanf("%s", name);
	if (strcmp(name, "exit")==0)
		break;
	fseek(fp, 0, SEEK_SET);
	int flag = 0;//标记姓名是否存在
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
		printf("%s 不在文件中.\n", name);
		//return ;
	}
	}
	fclose(fp);
	free(ps1);
	return;
}
//删除文件中相应姓名的学生信息
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
	long len_file = ftell(fp);//求要在内存中申请的堆空间的大小
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
		printf("请输入你要删除的学生的姓名.\n");
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
				continue;//如果能找到信息，跳过本次循环
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
		printf("请输入cmd: ");
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
二、重写配置文件写功能
1、课堂上的例子，临时数据是放在栈区数组，然后关闭文件，再把临时数据重新写入文件
2、将临时数组放在堆区，堆区大小不是一次性就分配好，而是通过realloc分配，慢慢增加
*/

#endif
#if 0
/*
三、已知 char **p = NULL; int lines 编写读文件函数，从文件中读取内容，为每一行内容按大小分配空间。
void readFile(char ***p,int *line);

文件内容参考《demo.txt》

提示：
首先扫描文件行数，根据行数给指针p分配指针数组空间。
再根据每行内容，动态分配空间，存放每行内容。
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
四、
a) 一个整型（An integer）
int a;
b) 一个指向整型的指针（A pointer to an integer）
int *pa=&a;
c) 一个指向指向整型的指针（A pointer to a pointer to an integer）
int **ppa=&pa;
d) 一个10个存放整型的数组（An array of 10 integers）
int a[10];
e) 一个10个存放指向整型指针的数组
（An array of 10 pointers to integers）
int *a[10];
f) 一个指向存放10个整型数组的指针
（A pointer to an array of 10 integers）
int (*p)[10];
g) 一个指向 需要一个整型参数并且返回值是一个整型函数的指针
（A pointer to a function that takes an integer as an argument and returns an integer）
int (*pf)(int a);
h) 一个存放10个 指向 需要一个整型参数并且返回值是一个整型函数的指针的数组
（An array of ten pointers to functions that take an integer argument and return an integer）
int (*pf[10])(int a)
*/
#endif


