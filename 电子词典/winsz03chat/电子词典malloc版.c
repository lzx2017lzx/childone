#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct words
{
	char *name;
	char *meanings;
};
//int main(int argc,char **args)
int main()
{
	//if (argc < 2)
	//		return 0;
	//���ļ�
	FILE *p = fopen("d:\\dict.txt", "r");
		//�����ļ�����
		int n = 0;
	char buf[2000] = { 0 };
	//���ļ�ÿ����Ϣ�����ڴ�
//	int num = n / 2;//��Ҫ����Ľṹ����Ŀ
	struct words *ptr = NULL;
	int i = 0;//realloc�����ڴ����������Ϊ�ṹ���±�
	int j = 0;//�ļ���ȡ���м�������������ɨ����ʵ��е��ṹ���name��meanings�С�
	while ((fgets(buf, sizeof(buf), p)) != NULL)
	{
		ptr = realloc(ptr, (i + 1)*sizeof(struct words));
		if (j % 2 == 0)
		{
			ptr[i].name = (char *)malloc(strlen(buf) + 1);
			memset(ptr[i].name, 0, strlen(buf) + 1);
			strcpy(ptr[i].name, &buf[1]);
			//	printf("%s\n", ptr[i].name);
			j++;
		}
		else
		{
			ptr[i].meanings = (char *)malloc(strlen(buf) + 1);//Ӧ�û��ɽ�һ����С�ڴ����
			memset(ptr[i].meanings, 0, strlen(buf) + 1);
			strcpy(ptr[i].meanings, &buf[6]);
			char *p = NULL;
			p = strtok(ptr[i].meanings, "@");
			//printf("%s", p);
			//p = strtok(NULL, "@");
			while ((p = strtok(NULL, "@")) != NULL)
			{

				--p;
				*p = '\n';
			}
			//printf("%s\n", ptr[i].meanings);
			i++;
			j++;
		}
	}
	//printf("%d\n", i);
	//����Ҫ���ҵĵ���
	char inputname[200] = { 0 };
	int l = 0;
	while (strcmp(inputname, "exit!\n"))
	{
		printf("please input your words:");
		scanf("%s", inputname);
		strcat(inputname, "\n");
		//printf("%s\n", inputname);
		//���в��ң���������ҽ��
		for (l = 0; l < i; l++)
		{
			if ((!strcmp(ptr[l].name, inputname)))
			{
				printf("%s\n", ptr[l].meanings);
				break;
			}
			else if (!strcmp(inputname, "exit!\n"))
				break;
		}
		if (l >= i)
			printf("no found\n");
	}
	//�ͷ��ڴ�
	for (l = 0; l < i; l++)
	{
		free(ptr[l].meanings);
		free(ptr[l].name);
	}
	free(ptr);
	fclose(p);
	system("pause");
	return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WORD_COUNT 111102
int isspace(char c)
{
	if (c == ' ')
		return 1;
	else
		return 0;
}
int formart(char *str)//ȥ���ַ������߶���Ŀհ��ַ�
{
	if (str == NULL)
		return 1;
	char *r = str;
	char *p = r;
	char *q = str + strlen(str) - 1;

	while (isspace(*p)) //isspace�ǿհ��ַ����ط�0
	{
		p++;
	}
	while (isspace(*q))
	{
		q--;
	}
	while (p <= q)
		*r++ = *p++;
	*r = '\0';
	return 0;
}
//int main()
//{
//    char buf[] = "\t     hello world  \n ";
//    formart(buf);
//    printf(buf);
//    return 0;
//}
typedef struct word_t
{
	char *key; //?�Դ洢�����ַ�����?��ַ
	char *content; //?�Դ洢�����ַ�����?��ַ
}word_t;


//�����������Ǹ��ݲ���len�Ĵ�С ����len��word_t��ռ�õĿռ�
word_t * createSpace(unsigned int len)
{
	//malloc / calloc void* calloc (size_t num, size_t size);
	word_t *ret = (word_t *)calloc(len, sizeof(word_t));
	return ret;
}

//�ͷŽṹ����ռ�õĿռ�
void freeSpace(word_t *ptr, unsigned int len)
{
	unsigned int i;
	for (i = 0; i<len; ++i)
	{
		if (ptr[i].key)
		{
			free(ptr[i].key); //��i���ṹ���Ա�е�keyָ���Ա ��ָ��Ŀռ�(�׵�ַ)
			ptr[i].key = NULL;
		}
		if (ptr[i].content)
		{
			free(ptr[i].content); //��i���ṹ���Ա�е�contentָ���Ա ��ָ��Ŀռ�(�׵�ַ)
			ptr[i].content = NULL;
		}
	}
	free(ptr);
}

//���ļ��ж�ȡ���� ���Ҵ洢���ڴ���
int readData(FILE *fp, word_t *data)
{
	if (fp == NULL)
		return 1;
	char buf[4096] = { 0 };
	int i = 0;
	while (fgets(buf, sizeof(buf), fp))
	{
		if (buf[0] == '#')
		{
			data[i].key = calloc(strlen(buf), sizeof(char));
			if (data[i].key == NULL)
			{
				fprintf(stderr, "û�п����ڴ���\n");
				return 1;
				//
			}
			formart(buf + 1);
			strcpy(data[i].key, buf + 1); //strtok
			//strlen����ǰ���#���ַ�������  �����ڸ��ƾͿ��Բ�����\0��λ��
		}
		else if (buf[0] == 'T')
		{
			data[i].content = calloc(strlen(buf), sizeof(char));
			if (data[i].content == NULL)
			{
				fprintf(stderr, "û�п����ڴ���\n");
				return 1;
			}
			//trans:fjldsjflds
			strcpy(data[i].content, buf + 6);
			i++;
		}
		memset(buf, 0, sizeof(buf));
	}
	return 0;
}

int search(const word_t *data, int len, char* find)
{
	if (data == NULL || len <1 || find == NULL)
		return 1;

	formart(find);
	int i;
	for (i = 0; i< len; ++i)
	{
		//��Ϊ�����Ѿ��������ַ���ǰ��Ŀհ��ַ�ȫ��ȥ�� ���ԾͿ�����ȫ�ľ�ȷƥ����
		if (strcmp(data[i].key, find) == 0)
		{
			printf("word %s found\n", find);
			printf("trans:%s\n", data[i].content);
			break;
		}
	}
	if (i == len)
	{
		printf("not found\n");
	}
	return 0;
}
int main(void)
{
	FILE *fp = fopen("d:\\dict.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "file not found\n");
		return 1;
	}
	word_t *word = createSpace(WORD_COUNT);
	if (word == NULL)
	{
		fprintf(stderr, "createSpace(WORD_COUNT) failed\n");
		return 1;
	}
	readData(fp, word);

	char input[64] = { 0 };
	while (1)
	{
		scanf("%s", input);
		if (strcmp(input, "exit-command") == 0)
			break;
		search(word, WORD_COUNT, input);
	}

	freeSpace(word, WORD_COUNT);
	fclose(fp);
	return 0;
}*/

