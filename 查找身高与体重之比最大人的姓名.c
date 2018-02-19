#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct information
{
	char name[20];
	int height;
	int weight;
};
int inputinf()
{
	char name1[20] = { 0 };
	char temp[1024] = { 0 };
	FILE *p = fopen("d:\\information.txt", "a");
	if (p == NULL)
		return 0;
	struct information inf = { 0 };

	while (1)
	{
		printf("please input the name:");
		scanf("%s", name1);
		if (!strcmp(name1, "exit"))
			break;
		strcpy(inf.name, name1);
		printf("please input the height:");
		scanf("%d", &inf.height);//scanf第二个参数必须是地址，如果不是也会解读为地址,且第一和第二个参数的格式要一致
		printf("%d", inf.height);
		printf("please input the weight:");
		scanf("%d", &inf.weight);
		printf("%d", inf.weight);
		//fwrite(&inf, 1, sizeof(struct information), p);
		fprintf(p, "name=%s,high=%d,weight=%d\n", inf.name, inf.height, inf.weight);
		//sprintf(temp, "name=%s,hign=%f,weight=%f\n", inf.name, inf.height, inf.weight);
		//printf("%s\n", temp);
		//fputs(temp, p);
	}
	fclose(p);
	return 0;
}
int printinf()
{
	char ch[1024] = { 0 };
	FILE *p = fopen("d:\\information.txt", "r");
	if (p == NULL)
		return 0;
	while (1)
	{
		fgets(ch, 1024, p);
		if (feof(p))
			break;
		printf("%s", ch);
	}
	fclose(p);
	return 0;
}
int insort(char *name)//如果传递的是地址，可以不用再一级指针改变值，地址与地址互传，可以改变内存空间
{
	struct information str = { 0 };
	float ratio;
	int max = 0;
	//char  name[30] = {0};
	char buf[1024] = { 0 };
	char *ptr;
	FILE *p = fopen("d:\\information.txt", "r");
	if (p == NULL)
		return 0;
	while (1)
	{
		//fscanf(&str, 1, sizeof(struct information), p);
		fgets(buf, 1024, p);
		printf("%s\n", buf);
		if (feof(p))
			break;
		strtok(buf, "=,");
		ptr = strtok(NULL, "=,");
		printf("%s\n", ptr);
		strcpy(str.name, ptr);
		printf("%s\n", str.name);
		strtok(NULL, "=,");
		ptr = strtok(NULL, "=,");
		printf("%s\n", ptr);
		int i = atoi(ptr);
		str.height = i;
		printf("%d\n", str.height);
		strtok(NULL, "=,");
		ptr = strtok(NULL, "=,");
		i = atoi(ptr);
		str.weight = i;
		printf("%d\n", str.weight);
		ratio = (float)(str.height) / (str.weight);
		printf("%f\n", ratio);
		if (ratio > max)
		{
			max = ratio;
			strcpy(name, str.name);
			printf("%s\n", name);
		}
	}
	fclose(p);
	return 0;
}
int main03()
{
	char name[30] = { 0 };
	//inputinf();
	printf("------------");
	//printinf();
	insort(name);
	//printinf();
	printf("the name of man with the maximum ratio:%s", name);
	system("pause");
	return 0;
}