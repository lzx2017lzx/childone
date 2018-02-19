#if 1
/*
02 已知char **p = NULL; int lines 编写读文件函数，从文件中读取内容，为每一行内容按大小分配空间。
void readFile(char ***p,int *line);

提示：
首先扫描文件行数，根据行数给指针p分配指针数组空间。
再根据每行内容，动态分配空间，存放每行内容。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void readFile(char ***p, int *line)
{
	char *fileName = "./demo.txt";

	int totalLines = 0;
	char buf[1024] = { 0 };

	//创建文件指针，只读方式打开
	FILE *fp = fopen(fileName, "r");
	if (NULL == fp)
	{
		printf("文件打开失败!\n");
		return;
	}

	//先获得文件行数
	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))//如果到文件结尾，退出循环
		{
			break;
		}

		totalLines++;//行数累加
	}
	printf("totalLines=%d\n", totalLines);
	//设置文件指针到文件开始位置
	fseek(fp, 0, SEEK_SET);

	//给分配行数内存
	//char *tmp[totalLines]
	char **tmp = (char **)malloc(sizeof(char *)*totalLines);

	int j = 0;
	for (j = 0; j < totalLines; j++)
	{
		memset(buf, 0, 1024);

		fgets(buf, sizeof(buf), fp);//读取内容

		tmp[j] = (char *)malloc(strlen(buf) + 1);
		memset(tmp[j], 0, strlen(buf) + 1);

		strcpy(tmp[j], buf);
	}

	//指针间接赋值
	*p = tmp;
	*line = totalLines;

	//关闭文件
	fclose(fp);
}
int main(void)
{
	char **p = NULL;
	int lines = 0;

	readFile(&p, &lines);

	int i = 0;
	//显示文件内容
	for (i = 0; i < lines; i++)
	{
		printf("%s", p[i]);
		//释放当前行内存
		free(p[i]);
		p[i] = NULL;
	}
	
	//释放
	free(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif
