#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
4. 有一个字符串符合以下特征 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) 以逗号,隔开字串，字串数量不会超过10个，每个字串长度不会超过30
b) 以逗号分隔字符串，并把结果传出
c)参考库函数：strchr(), strncpy(), strcpy(), strlen()
*/
char **getMem(int n)
{
	char **p = malloc(n * sizeof(char *));
	if (p == NULL)
	{
		return NULL;
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		p[i] = malloc(30 * sizeof(char));
		if (p[i] == NULL)
		{
			return NULL;
		}
	}
	return p;
}
void getMemFree(char ***buf, int n)
{
	if (buf == NULL)
	{
		return;
	}
	char **tmp = *buf;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}
	free(tmp);
	*buf = NULL;
}
/*
功能：把"abcdef,acccd,eeee,aaaaa,e3eeeee,ssss,",以","分隔出字符串，分配放在二维数组buf中
参数：
str:原字符串，"abcdef,accccd,eeeee,aaaaa,e3eeeee,ssssss,"
c：分隔标志：','
buf：指针数组首元素地址，其空间在主调函数分配
count：保存buf字符串的个数
返回值：
成功：0
失败：非零

*/
int spitString(const char *str, char c, char **buf, int *count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}

	const char *start = str;
	char *p = NULL;
	int i = 0;

	do
	{
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			if (len > 0)
			{
				strncpy(buf[i], start, len);
				*(*(buf + i) + len) = '\0';
				i++;
			}
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);
			i++;
			break;
		}
	} while (*start != 0);
	*count = i;
	return 0;
}
int main(void)
{
	char *p = "abcdef,acccd,eeeee,aaaa,e3eeeee,ssss,";
	char **buf = getMem(10);
	int n = 0;
	int ret = 0;

	ret = spitString(p, ',', buf, &n);
	if (ret != 0)
	{
		return ret;
	}

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}
	getMemFree(&buf, n);
	printf("\n");
	system("pause");
	return 0;
}