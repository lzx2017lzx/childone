//ϣ�����������˲�������)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ShellSort(int arr[], int len)
{
	//������������
	int Increasement = len;

	//ֻ��������֮������ݣ�������ʵ�в���������һ��ͨ����Сincreasement��������
	//����dowhile�ķ�ʽ
	do
	{
		Increasement = Increasement / 3 + 1;
		for (int i = Increasement; i < len; i = i + Increasement)//ȷ��Ҫ�����Ԫ���±�(i����ָ��ڶ���Ҫ�������
		{
			//���ñ�����¼��i���±����
			int temp = arr[i];
			int j = 0;
			for (j = i; j >0 && arr[j - Increasement]>temp; j = j - Increasement)
			{
				arr[j] = arr[j - Increasement];
			}

			arr[j] = temp;
		}

	} while (Increasement > 1);





}

//��ӡ����
void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void)
{
	int arr[] = { 2,1,3,6,4,5,9,8,7 };

	int len = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, len);
	ShellSort(arr, len);
	PrintArray(arr, len);



	printf("\n");
	system("pause");
	return 0;
}