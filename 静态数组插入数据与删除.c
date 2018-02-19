#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
2. ��һ�����飬����Ԫ��û�з��������һ����������ָ��λ�ò���ָ��Ԫ�أ�ָ��λ��ɾ��Ԫ��
int a[15] = {1, 3, 5, 7, 9, 11, 13};
//a��������Ԫ�ص�ַ
//pos��ָ����λ��
//data����Ҫ�����Ԫ��
//size������ĳ��ȣ�����Ԫ�صĸ�������������Ĵ�С������Ԫ�أ���Ҫ����Ӧ�޸�
void insert_array(int *a, int pos, int data, int *size);

void remove_array(int *a, int pos, int *size);

void print_array(int *a, int size); //��ӡ����

int main()
{

int a[15] = {1, 3, 5, 7, 9, 11, 13};
int size = 7; //���鳤�ȣ��Ѿ���Ԫ�صĸ���

print_array(a, size); //��ӡ
insert_array(a, 0, -1, &size); //��0��λ�ò���-1
print_array(a, size); //��ӡ

insert_array(a, 2, 8, &size); //��2��λ�ò���8
print_array(a, size); //��ӡ

insert_array(a, size, 250, &size); //��ĩβ��λ�ò���250
print_array(a, size); //��ӡ

print_array(a, size); //��ӡ
remove_array(a, 0, &size); //ɾ����0��Ԫ��
print_array(a, size); //��ӡ

return 0;
}

*/
void insert_array(int *a, int pos, int data, int *size)
{
	if ((a == NULL) || (pos < 0) || (pos > *size))
	{
		return;
	}
	int i = 0;
	int j = 0;
	int temp;
	for(i=0;i<=*size;i++)
	{
		if (i == pos)
		{
			temp = a[i];
			a[i] = data;
			data = temp;
			temp = a[i + 1];
			for (j = i; j < *size; j++)
			{
				a[j + 1] = data;
				data = temp;
				temp = a[j + 2];
			}
			*size = *size + 1;
			break;
		}
	}
}

void remove_array(int *a, int pos, int *size)
{
	if ((a == NULL) || (pos < 0) || (pos >= *size) || (*size == 0))
	{
		return ;
	}
	int i = 0;
	int j = 0;
	for  ( i=0; i < *size; i++)
	{
		if (i == pos)
		{
			for(j=i;j<*size;j++)
			a[j] = a[j + 1];
			break;
		}
	}
	*size = *size - 1;
	return;
}

void print_array(int *a, int size) //��ӡ����
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //���鳤�ȣ��Ѿ���Ԫ�صĸ���

	print_array(a, size); //��ӡ
	insert_array(a, 0, -1, &size); //��0��λ�ò���-1
	print_array(a, size); //��ӡ

	insert_array(a, 2, 8, &size); //��2��λ�ò���8
	print_array(a, size); //��ӡ

	insert_array(a, size, 250, &size); //��ĩβ��λ�ò���250
	print_array(a, size); //��ӡ

	print_array(a, size); //��ӡ
	remove_array(a, 0, &size); //ɾ����0��Ԫ��
	print_array(a, size); //��ӡ

	system("pause");
	return 0;
}

