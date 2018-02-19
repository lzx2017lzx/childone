#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
4. ��һ���ַ��������������� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) �Զ���,�����ִ����ִ��������ᳬ��10����ÿ���ִ����Ȳ��ᳬ��30
b) �Զ��ŷָ��ַ��������ѽ������
c)�ο��⺯����strchr(), strncpy(), strcpy(), strlen()
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
���ܣ���"abcdef,acccd,eeee,aaaaa,e3eeeee,ssss,",��","�ָ����ַ�����������ڶ�ά����buf��
������
str:ԭ�ַ�����"abcdef,accccd,eeeee,aaaaa,e3eeeee,ssssss,"
c���ָ���־��','
buf��ָ��������Ԫ�ص�ַ����ռ���������������
count������buf�ַ����ĸ���
����ֵ��
�ɹ���0
ʧ�ܣ�����

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