#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//手动模拟插入排序的流程
int main(void)
{
	//插入排序
	int a[] = { 2,3,9,4,8,5,1,7,6 };
	int Len = sizeof(a) / sizeof(a[0]);

	int i, j;//i是要处理的数据的下标，每处理一次，i自增，j是为了处理下标为i的数据所设置的变量，注意j是--的，设置j是为了逆向比较，和移动元素
	int temp;//用来存储要处理的变量，防止向后移位时，造成覆盖
	for (i = 1; i < Len; i++)
	{
		if (a[i-1] > a[i])
		{
			temp = a[i];
			for (j = i - 1; j >= 0 && temp < a[j]; j--)//j指向i的前一个元素，直到找到的元素比要处理的元素小.注意退出循环时j下标指向的元素是比要处理的元素值小，是要插入位置的前一个位置
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}

	}

	//循环打印
	for (i = 0; i < Len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
