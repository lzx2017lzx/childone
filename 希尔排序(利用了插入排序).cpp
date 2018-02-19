//希尔排序（利用了插入排序)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ShellSort(int arr[], int len)
{
	//首先设置增量
	int Increasement = len;

	//只排序增量之间的数据，而且是实行插入排序，下一轮通过减小increasement继续排序
	//采用dowhile的方式
	do
	{
		Increasement = Increasement / 3 + 1;
		for (int i = Increasement; i < len; i = i + Increasement)//确定要处理的元素下标(i首先指向第二个要处理的数
		{
			//设置变量记录第i个下标的数
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

//打印数组
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