#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main02()
{
	int num[3] = { 0 };
	int sum = 0;
	int temp = 0;
	FILE *p = fopen("d:\\file.txt", "r+");
	if (p == NULL)
		return 0;
	//char ch = '\0';
	int res = 0;
	char ch[30] = { 0 };
	char *ch1;//strtok��ı�ch1ָ��ָ������freeʱ���ܳɹ���ʵ����ch1�趨���һ��ָ�뼴�ɣ�����Ҫ�����ڴ棬������ָ�븳ֵ��
	while (1)//fgets������гɹ������ص�ַch������ʾ�ļ���һ�еĿ�ʼ�������ǽ�β��
	{
		fgets(ch, 30, p);
		printf("%s", ch);
		if (feof(p))
			break;
		// sscanf(ch, "%d:%d:%d\n", &num[0], &num[1], &num[2]);
		ch1 = strtok(ch, ":");//���ص��ǵ�ַ
		num[0] = atoi(ch1);
		ch1 = strtok(NULL, ":");
		num[1] = atoi(ch1);
		ch1 = strtok(NULL, ":");
		num[2] = atoi(ch1);
		printf("%d %d %d", num[0], num[1], num[2]);//�˴���num[2]д��num[3]
		sum += num[0] * 3600 + num[1] * 60 + num[2];
		// printf("%s\n", ch);
		printf("sum=%d\n", sum);
	}
	num[0] = sum / 3600;
	temp = sum % 3600;
	num[1] = temp / 60;
	num[2] = temp % 60;
	//free(ch1);
	fclose(p);
	p = fopen("d:\\file.txt", "a");
	fseek(p, 0, SEEK_END);
	fprintf(p, "%02d:%2d:%2d\n", num[0], num[1], num[2]);
	fclose(p);
	system("pause");
	return 0;
}