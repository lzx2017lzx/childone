#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//����һ
int input[4] = { 0 };
int randnum[4] = { 0 };
//�����ĸ��������,�Ҳ��ظ�
int generate()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++)
	{
		randnum[i] = rand() % 10;
		for (int j = 0; j < i; j++)
			if (randnum[i] == randnum[j])
			{			
				i--;
				break;
			}
	}
	printf("%d%d%d%d\n", randnum[0], randnum[1], randnum[2], randnum[3]);
	return 0;//��ʾ����������ɹ�
}
//���벢�ж��Ƿ��Ǻϸ����λ��
int inputnum()
{
	char ch[4] = {0};
	int flag;
	//char temp;
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
		if (((ch[i] = getchar()) < '0') || (ch[i] > '9'))
		{
			while (getchar() != '\n');
			return 1;//���벻������
		}
	//temp = ch[0];
	for (i = 0; i < 4; i++)
	{
		for (j = 1 + i; j < 4; j++)
			if (ch[i] == ch[j])
			{
				while (getchar() != '\n');
				return 1;//��������ͬ
			}
	}
	for (i = 0; i < 4; i++)
		input[i] = ch[i] - '0';
	//getchar();
	while (getchar() != '\n')
	{

		flag=1;//����������4
	}
	if (flag == 1)
		return 1;
	return 0;//�ϸ��������ֲ�ͬ
}
//��������������Ƚ�
int compareIR(int *input, int *randnum, int *a,int *b)
{
	int i = 0;
	int j = 0;
	*a = 0;
	*b = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (input[i] == randnum[i])
			{
				(*a)++;//�±���ͬ���Ҷ�Ӧ������ͬ����*a��¼A�ĸ���;
				break;
			}
			else if (input[i] == randnum[j])
			{
				(*b)++;//������Ȼ�±겻��ͬ��������ͬ����*b��¼B�ĸ���;
				break;
			}
	if (*a == 4)
		return 0;
	else
		return 1;
}
//��ӡ���
int printrt(int *a, int *b)
{
	int i, j;
	if (*a == 4)
	{
		printf("SO GOOD!");
		return 0;
	}
	if ((*b == 0)&&(*a==0))
		printf("SO BAD!");
		for (j = 0; j < 4; j++)
			if (j < *a)
				printf("A");
		for (i = 0; i < 4; i++)
			if (i < *b)
				printf("B");
		printf("\n");
		printf("please input 4 numbers:");
		return 1;
}
int main()
{
	int a = 0;
	int b = 0;
	generate();
	printf("please input 4 numbers:");
	while (1)
	{
	while((inputnum()!=0))
		printf("input error!please input 4 numbers:");
	if (compareIR(input, randnum, &a, &b) == 0)
		break;
	else
		printrt(&a, &b);
	};
	printrt(&a, &b);
	system("pause");
	return 0;
	}



//������
/*
int num[4] = { 0, 0, 0, 0 };
int input[4] = { 0, 0, 0, 0 };

//������������4�� ����ͬ �������
void generateNumber()
{
	srand((unsigned int)time(NULL));
	//0-9
	int i, j;
	for (i = 0; i < 4; ++i) ///3  3 
	{
		num[i] = rand() % 10;
		for (j = 0; j < i; ++j)
			if (num[i] == num[j])
				i--;
	}
}
//���������Ƿ�������
int ismydigit(char ch)
{
	if ((ch<'0') && (ch>'9'))
		return 1;
	else
		return 0;
}
//�����������
int getinput()
{
	char ch;
	int flag=0;
	int count=0;
	int j=0;
	while ((ch = getchar()) != '\n')
	{
		if (flag || count >= 4 || ismydigit(ch) != 0)
		{
			flag = 1;
			continue;//�˴����ismydigit(ch)==0�����������˳�ѭ�����𣿣���������ismydigit(ch)==1;
		}
		for (j = 0; j < count; j++)
		{
			if (ch == input[j] + '0')
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		input[count] = ch - '0';//����
		count++;
	}
	return (flag || count < 4) ? 1 : 0;
}
void check(int *pa, int *pb)
{
	*pa = 0;
	*pb = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			if ((num[i] == input[j]) && (i == j))
			{
				(*pa)++;
			}
			else if (num[i] == input[j])
			{
				(*pb)++;
			}
		}
}
void printAB(int a, int b)
{
	int i;
	for (i = 0; i < a; i++)
		putchar('A');
	for (i = 0; i < b; i++)
		putchar("B");
	if (a == 0 && b == 0)
		printf("SO BAD");
	putchar('\n');
}

int main()
{
	int a = 0;
	int b = 0;
	generateNumber();
	while (1)
	{
		printf("please input 4 numbers(0-9):");
		if (getinput() != 0)
		{
			printf("input error��");
			continue;
		}
		check(&a, &b);
		printAB(a, b);
		if (a == 4)
		{
			printf("SO GOOD!");
			break;
		}
	}
	return 0;
	}
*/