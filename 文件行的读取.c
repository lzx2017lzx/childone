#if 1
/*
02 ��֪char **p = NULL; int lines ��д���ļ����������ļ��ж�ȡ���ݣ�Ϊÿһ�����ݰ���С����ռ䡣
void readFile(char ***p,int *line);

��ʾ��
����ɨ���ļ�����������������ָ��p����ָ������ռ䡣
�ٸ���ÿ�����ݣ���̬����ռ䣬���ÿ�����ݡ�
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

	//�����ļ�ָ�룬ֻ����ʽ��
	FILE *fp = fopen(fileName, "r");
	if (NULL == fp)
	{
		printf("�ļ���ʧ��!\n");
		return;
	}

	//�Ȼ���ļ�����
	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))//������ļ���β���˳�ѭ��
		{
			break;
		}

		totalLines++;//�����ۼ�
	}
	printf("totalLines=%d\n", totalLines);
	//�����ļ�ָ�뵽�ļ���ʼλ��
	fseek(fp, 0, SEEK_SET);

	//�����������ڴ�
	//char *tmp[totalLines]
	char **tmp = (char **)malloc(sizeof(char *)*totalLines);

	int j = 0;
	for (j = 0; j < totalLines; j++)
	{
		memset(buf, 0, 1024);

		fgets(buf, sizeof(buf), fp);//��ȡ����

		tmp[j] = (char *)malloc(strlen(buf) + 1);
		memset(tmp[j], 0, strlen(buf) + 1);

		strcpy(tmp[j], buf);
	}

	//ָ���Ӹ�ֵ
	*p = tmp;
	*line = totalLines;

	//�ر��ļ�
	fclose(fp);
}
int main(void)
{
	char **p = NULL;
	int lines = 0;

	readFile(&p, &lines);

	int i = 0;
	//��ʾ�ļ�����
	for (i = 0; i < lines; i++)
	{
		printf("%s", p[i]);
		//�ͷŵ�ǰ���ڴ�
		free(p[i]);
		p[i] = NULL;
	}
	
	//�ͷ�
	free(p);
	printf("\n");
	system("pause");
	return 0;
}

#endif
