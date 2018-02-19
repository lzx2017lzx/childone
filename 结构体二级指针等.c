#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#if 0


void ball()
{
	printf("\t\t●\t");
}
int main(void)
{
	int h = 20;
	int i, j;
	int dir = 1;
	while (h > 0)
	{
		if (dir == 1)
		{
			for (i = 20 - h; i < 20; i++)
			{
				system("cls");
				for (j = 0; j <= i; j++)
				{
					printf("\n");
				}
				ball();
				Sleep(200);
			}
			dir = 0;
		}
		else
		{
			h = h * 8 / 9;
			for (i = 20; i >= 20 - h; i--)
			{
				system("cls");
				for (j = 0; j <= i; j++)
				{
					printf("\n");
				}
				ball();
				Sleep(50);
			}
			dir = 1;
		}
		
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
/*
将特殊字符的ASCII值打印到文件中保存
格式如下
-95 -15 ●
*/
int main(void)
{
	int i = 0;
	FILE *p = fopen("f:\\specialcharacter.txt", "w");
	while(1)
	{ 
	char buf[12] = { 0 };
	//●●sprintf(buf, "%s", "●");
	scanf("%s", buf);
	if (strcmp(buf, "exit") == 0)
		break;
	fprintf(p, "%d %d %d %???",buf[0],buf[1],buf[2],buf);
	//printf("%s", buf1);
	//●printf("\n");
	}
	fclose(p);
	system("pause");
	return 0;
}

#endif
#if 0
/*
1. 堆区二维数组练习（无需封装函数）
a) 在堆区申请空间，int a[3][4]
b) 通过循环给每一个元素赋值，以及打印每个元素的值
c) 使用完，需要释放堆区空间
*/

int main(void)
{
	int(**p)[4] = (int(**)[4])malloc(3 * sizeof(int(*)[4]));
	memset(p, 0, 3 * sizeof(int(*)[4]));
	//int(*p)[4] = (int(*)[4])malloc(3 * sizeof(int[4]));
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		p[i] = (int(*)[4])malloc(4 * sizeof(int));
		memset(p[i], 0, 4 * sizeof(int));
		for (j = 0; j < 4; j++)
		{
			(*p[i])[j] = i*j;	
		}
	}
	for (i = 0; i < 3; i++)
	{
		//p[i] = (int(*)[4])malloc(4 * sizeof(int));
		//memset(p[i], 0, 4 * sizeof(int));
		for (j = 0; j < 4; j++)
		{
			printf("%d\n", (*p[i])[j]);
		}
	}
	//释放空间
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
	

	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
/*2. 结构体嵌套一级指针和二级指针练习

//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//在createTeacher中分配空间
int createTeacher(Teacher **p/out/, int n1, int n2);

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2);

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2);


//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n);


//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2);

int main(void)
{
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

							//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);


	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	return 0;
}
*/
typedef struct Teacher
{
	char *tName; //导师名字，需要动态分配空间
	char **stu;  //三个学生，需要动态分配空间，堆区数组
	int age;
}Teacher;

//在createTeacher中分配空间
int createTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL || n1 == 0 || n2 == 0)
		return -1;
	*p = (Teacher *)malloc(n1 * sizeof(Teacher));
	memset(*p, 0, sizeof(Teacher)*n1);
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++)
	{
		
		char **pstu =(char **)malloc(n2*sizeof(char *));
		memset(pstu, 0, sizeof(char *) * n2);
		(*p)[i].stu = pstu;
		(*p)[i].tName = (char *)malloc(50);
		memset((*p)[i].tName, 0, 50);
		for (j = 0; j < n2; j++)
		{
			pstu[j] = (char *)malloc(50);
			memset(pstu[j], 0, 50);
		}
	}
	return 0;
}

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 == 0 || n2 == 0)
		return;
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++)
	{
		printf("please input the %d teacher's name.\n",i+1);
		scanf("%s", p[i].tName);
		for (j = 0; j < n2; j++)
		{
			printf("please input the %d student's name.\n",j+1);
			scanf("%s", (p[i].stu)[j]);
		}
		printf("please input the %d teacher's age.\n",i+1);
		scanf("%d", &(p[i].age));
	}
}

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL || n1 == 0 || n2 == 0)
		return;
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++)
	{
		printf("the %d teacher's name:%s\n", i + 1, p[i].tName);
		for (j = 0; j < n2; j++)
		{
			printf("   the %d student's name:%s.\n", j + 1, (p[i].stu)[j]);
		}
		printf("the %d teacher's age:%d\n", i+1, p[i].age);
	}
}


//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n)
{
	int i = 0;
	Teacher temp;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i].tName, p[j].tName) > 0)
			{
				memcpy(&temp, p + i, sizeof(Teacher));
				memcpy(p + i, p + j, sizeof(Teacher));
				memcpy(p + j, &temp, sizeof(Teacher));
			}
		}
	}
}


//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++)
	{
		free((*p)[i].tName);
		(*p)[i].tName = NULL;
		for (j = 0; j < n2; j++)
		{
			free((*p)[i].stu[j]);
			(*p)[i].stu[j] = NULL;
		}
		free((*p)[i].stu);
		(*p)[i].stu = NULL;
	}
	free(*p);
	*p = NULL;
}
	;


int main(void)
{
	int ret = 0;
	int n1 = 6; //导师个数
	int n2 = 6; //学生
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

							//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);


	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);
	system("pause");
	return 0;
}
#endif
#if 1
int delet_empty(char *pstr)
{
	int i=0, j=0;
	int len=0;
	while (pstr[len])
	{
		len++;
	}
	while (pstr[j] == ' ')
	{
		pstr[j] = '\0';
		j++;
	}
	for (i = 0; i < len; i++)
	{
		pstr[i] = pstr[j];
		pstr[j] = '\0';
		j++;
		while (pstr[j] == ' ')
		{
			pstr[j] = '\0';
			j++;		
		}
	}
	return 0;
}
int main(void)
{
	char buf[100] ="   abcde  dddk    ";
	//while (1)
	//{
		//printf("please input your string.\n");
		//scanf("%s", buf);
		//if (strcmp(buf, "exit") == 0)
		//	break;
	delet_empty(buf);
	//}
	printf("%s", buf);
	printf("\n");
	system("pause");
	return 0;
}



#endif




