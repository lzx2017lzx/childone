#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct words
{
	char *name;
	char **trans;
	unsigned int count;
};
//int main(int argc,char **args)
//去除字符前后字符后的空格
char * removeempty(char *str)
{
	char *p1 = str;
	char *p2 = str;
	//printf("%s\n", p1);
	while (*p2)
	{
		p2++;
	}
	//printf("%d\n", *p2);
	//printf("%d\n", *(p2 - 3));
	//printf("p2--:%c\n", *(p2-1));
	while (*p1 == ' ')
	{
		p1++;
	}
	p2--;
	p2--;
	//printf("p2=%d\n", *p2);
	while (*p2 == ' ')
	{
		//	printf("p2=%c\n", *p2);
		*p2 = '\0';
		p2--;
	}
	//printf("%s\n", p1);
	return p1;
}
//释义分项,每次strtok时将字符串地址传到结构体内的相关数据
int sortofmeaning(struct words *str,char *buf)
{
	unsigned int k = 0;
	int l = 0;
	char *p1[10] = { 0 };
	p1[0] = buf;
	unsigned int length = strlen(buf) + 1;
	l = 1;
	for (k = 0; k < length; k++)
		if (buf[k] == '@')
		{
			l++;
			//p1[l++] = buf + k + 1;//用指针指定各释义，并计数
			buf[k] = '\0';
		}
	str->count = l;
	//	printf("ptr[i].count=%d\n", l);
	str->trans = (char **)malloc(sizeof(char *)*(str->count+1));
	str->trans[0] = (char *)malloc(sizeof(char)*(length-6));//修改
	memcpy(str->trans[0], &buf[6], length-6);
	for (k = 0, l = 1; k < length; k++)
	{
		if ((str->trans[0][k] == '\0'))
		{
			str->trans[l++] = str->trans[0] + k + 1;
			
		}
	}
	//if ((l > 3) && (l<7))
	//{
	//	printf("%d\n", l);
	//	printf("count=%d\n", str->count);
	//}
	return 0;
}
int sortmeaning(struct words *pst, char *str)
{

	return 0;


}
int main()
{
	//if (argc < 2)
	//		return 0;
	//打开文件
	FILE *p = fopen("d:\\dictionary.txt", "r");
	//查清文件行数
	int n = 0;
	char *buf = malloc(1024);
	//将文件每行信息输入内存
	int num = n / 2;//需要申请的结构体数目
	struct words *ptr = NULL;
	int i = 0;//realloc分配内存计数，并作为结构体下标
	int j = 0;//文件读取的行计数，用来控制扫描合适的行到结构体的name，meanings中。
	unsigned int k = 0;
	//int l = 0;
	int l = 0;
	while ((fgets(buf, 1024, p)) != NULL)
	{
		buf = removeempty(buf);
		ptr = (struct words *)realloc(ptr, (i + 1)*sizeof(struct words));
		if (ptr == NULL)
			return 0;
		if (j % 2 == 0)
		{
			//buf = removeempty(buf);
			ptr[i].name = (char *)malloc(strlen(buf) + 1);
			memset(ptr[i].name, 0, strlen(buf) + 1);
			strcpy(ptr[i].name, &buf[1]);
			//			printf("%s\n", ptr[i].name);
			j++;
		}
		else
		{
			sortofmeaning(ptr + i, buf);
			i++;
			j++;
		//	for (k = 0; k < ptr[i].count; k++)
		//	{
		//		printf("ptr[i]=%s\n", ptr[i].trans[k]);
		//	}
			/*
			char **ptemp = (char **)malloc(40);
			memset(ptemp, 0, 40);
			ptr[i].count = 0;
			int length = strlen(buf);
			int n12 = 0;
			*ptemp = (char *)calloc(length+1, sizeof(char));
			char *mm = *ptemp;
			strcpy(*ptemp, &buf[6]);
			strtok(*ptemp, "@");
			ptr[i].count++;
			char *p = NULL;
			while ((p = strtok(NULL, "@")) != NULL)
			{
				--p;
				*p = '\0';
				//ptr[i].count++;
				ptemp[ptr[i].count++] = p + 1;
			}
			n12 = (ptr[i].count)*sizeof(char *);
			printf("%d\n", n12);
			printf("count=%d\n", ptr[i].count);
			ptr[i].trans =(char **)malloc(n12);
			*(ptr[i].trans) = (char *)calloc(length, sizeof(char));
			memcpy(*(ptr[i].trans),*ptemp,length);
			printf("ptr[i].trans=%s\n", *(ptr[i].trans));
			for (k = 0,l=0; k <length; k++)
			{
				if (ptr[i].trans[0][k] == '\0')
				{
					printf("ptr[i].trans[l]=%s\n", ptr[i].trans[l]);
					l++;
					ptr[i].trans[l] = ptr[i].trans[0] + (k + 1);//确定结构体中指针的位置					
				}
			}
			for (k = 0; k < ptr[i].count; k++)
			{
				printf("%s\n", ptr[i].trans[k]);
			}
			free(mm);
			free(ptemp);		
			i++;
			j++;*/
			/*
			ptr[i].trans = (char **)malloc(40);
			memset(ptr[i].trans, 0, 40);
			ptr[i].count = 0;
			*(ptr[i].trans) = (char *)calloc(strlen(buf)+1,sizeof(char));
			strcpy(ptr[i].trans[0], &buf[6]);
			ptr[i].trans[1] = strtok(ptr[i].trans[0], "@");
			ptr[i].count++;
			char *p = NULL;
			while ((p = strtok(NULL, "@")) != NULL)
			{
				--p;
				*p = '\0';
				ptr[i].count++;
				ptr[i].trans[ptr[i].count] = p + 1;
			}
			//	printf("%s\n", ptr[i].meanings);
			i++;
			j++;*/
		}
	}
	//printf("%d\n", i);
	//输入要查找的单词
	char inputname[200] = { 0 };
	
	while (1)
	{
		printf("please input your words:");
		scanf("%s", inputname);
		strcat(inputname, "\n");
		//printf("%s\n", inputname);
		//进行查找，并输出查找结果
		if (!strcmp(inputname, "exit!\n"))
			break;
		for (l = 0; l < i; l++)
		{
			
			if ((!strcmp(ptr[l].name, inputname)))
			{
				//printf("%s\n", ptr[l].meanings);
				for (k = 0; k <ptr[l].count; k++)
				{
					//printf("%d\n", ptr[l].count);
					printf("%d、%s\n",k+1,ptr[l].trans[k]);
					//break;
				}
				break;
			}
			
		}
		if (l >= i)
			printf("no found\n");
	}
	//释放内存
	for (l = 0; l < i; l++)
	{
		free(ptr[l].trans[0]);
		//free(ptr[l].trans[1]);
		free(ptr[l].trans);
		free(ptr[l].name);
	}
	free(buf);
	free(ptr);
	fclose(p);
	system("pause");
	return 0;
}
int main01()
{

	char **ptr = (char **)malloc(sizeof(char *) * 1);
	ptr[0] = (char *)malloc(10);
	
	ptr[1] = &(ptr[0][3]);
	free(ptr[0]);
	//free(ptr);
	system("pause");

	return 0;
}