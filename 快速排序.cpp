#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 10
#if 1
void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void QuickSort(int arr[], int start, int end)//½µÐòÅÅÁÐ
{
	int i = start;
	int j = end;
	int target = arr[start];
	if (i < j)
	{
		while (i < j)
		{
			while (i < j&&arr[j] < target)
			{
				j--;
			}

			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			while (i<j&&arr[i]>target)
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}

		arr[i] = target;

		QuickSort(arr, start, i - 1);

		QuickSort(arr, i + 1, end);
	}
}
int main(void)
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	printArray(arr, MAX);

	QuickSort(arr, 0, MAX - 1);

	printArray(arr, MAX);
	//system("pause");
	printf("\n");
	system("pause");
	return 0;
}
#endif

