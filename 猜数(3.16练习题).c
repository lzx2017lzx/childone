/*#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int num[4] = { 0,0,0,0 };
int input[4] = { 0,0,0,0 };

//������������4�� ����ͬ �������
void generateNumber()
{
	srand((unsigned int)time(NULL));
	//0-9
	int i,j;
	for (i = 0; i < 4; ++i) ///3  3 
	{
		num[i] = rand() % 10;
		for (j = 0; j < i; ++j)
			if (num[i] == num[j])
				i--;
	}
}

int myisdigit(int ch)
{
	if (ch <= '9' && ch >= '0')
		return 1;
	else
		return 0;
}

//��ȡ�û������4������ͬ�������   �ж��Ƿ�Ϸ�  ����Ϸ�����0  ���򷵻ط�0

int getInput() //a123 0123123\n
{
	char ch;
	int flag = 0;   //Ϊ0 ��ʾ����  ��0��ʾ����
	int count = 0;
	int j = 0;
	while ((ch = getchar()) != '\n') 
	{

		
		if (flag || count >= 4  || myisdigit(ch)==0)//����������ַ�  ���ط�0
		{
			flag = 1;
			continue;
		}
		//�жϵ�ǰ�ַ���ǰ����Ƿ��ظ�
		for (j = 0; j < count; ++j)
			if (ch == input[j] + '0')
			{
				flag = 1;
				break;
			}
		if (flag)
			continue;
		input[count] = ch - '0';
		count++;
	}
	return (flag || count<4) ? 1:0;
}

//�ȶ��û�����ͼ����������  ������� ��������䵽main��a��b��
void check(int *pa, int *pb)
{
	*pa = *pb = 0; //(*pa)++;
	int i, j;
	for(i=0;i<4;++i)
		for (j = 0; j < 4; ++j)
		{
			if (num[i] == input[j] && i == j)
			{
				(*pa)++;
			}
			else if (num[i] == input[j]) // i != j
			{
				(*pb)++;
			}
		}
}

//����a��b�ĸ���  ��ӡAB
void printAB(int a, int b)
{
	int i;
	for (i = 0; i < a; ++i)
		putchar('A');
	for (i = 0; i < b; ++i)
		putchar('B');

	if (a == 0 && b == 0)
		printf("��̫����");
	putchar('\n');
}



int main()
{
	int a = 0;    //�洢A
	int b = 0;    //   B�ĸ���
	generateNumber();

	while (1)
	{
		printf("please input 4numbers(0-9):");
		if( 0 != getInput())
		{
			printf("input error!");
			continue;
		}
		check(&a,&b);
		printAB(a, b);
		if (a == 4)
		{
			printf("GOOD!\n");
			break;
		}
	}

	return 0;
}*/