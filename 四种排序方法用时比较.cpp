#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#if 1
#define MAX 100000
//相同数据请计算快速排序的完成时间、冒泡排序、选择排序、插入排序的完成时间，

//快速排序
void QuickSort(int arr[], int start, int end)//本算法是按升序排序
{
	int i = start;//start数据不能改动，为递归保留数据完整
	int j = end;//理由同上
	int target = arr[i];//选择基数

	if (i < j)//设置循环终止条件
	{
		while(i<j)
		{
			while (i < j&&arr[j] > target)//保证target右边所有元素都比其大
			{
				j--;
			}//循环结束，要么i==j，要么arr[j]<target;如果i==j，要保证退出循环(可以通过break；也可以通过i<j的判断；如果后面每一句都有i<j的条件判断，就可以不同break了
	//如果arr[j]<target;必须将arr[j]移动到target左边，可以通过将arr[j]覆盖target所在存储空间(此处为下标1)的信息，并将i++；因为下标i处数据已经比target小，之后的几轮循环没有必要进行比较
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}//此时arr[j]最可能是target的合适位置。(注意因为是覆盖，arr[j]值在数组中有两份。

			while (i < j&&arr[i] < target)//此处的目的是从左向右，保证所有的数都比target小。
			{
				i++;
			}//循环结束，arr[i]>target(需在接下来执行覆盖),如果i==j，要保证后续程序都不执行即添加条件判断i<j;

			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}//j位置后所有数据都比target大
			
		}
		//if条件判断结束，将target放入合适位置

		arr[i] = target;//i和j的值相同

						//递归快速排序i下标左边的数据
		QuickSort(arr, start, i - 1);//i下标已经是正确数据，不需要比较

									 //递归快速排序i下标右边的数据
		QuickSort(arr, i + 1, end);
	}

	
}

//冒泡排序(每次内循环总是将最大的数放到最右边(升序）或最左边(降序)),外循环用来控制内循环内数据的个数
void BubbleSort(int arr[], int len)//升序
{
	int i = 0;
	int j = 0;

	//设置temp变量用来交换数据
	int temp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//选择排序(选择排序最大的特点是每次都将指定位置放入合适的数据，通过将指定位置的数据与其它数据交换的方式。一次排序成功能够将一个数据放入到指定位置
void SelectSort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int temp;
	for (i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

//插入排序
void InsertSort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	//int temp = 0;

	for (i = 1; i < len; i++)
	{
		int temp = arr[i];
		j = i;
		//if(arr[j-1]>arr[j])
		//{
			for ( ; j >0 && arr[j-1] > temp; j--)
			{
				arr[j] = arr[j-1];
			}
		//}
		arr[j] = temp;
	}
	return;
}

////二路归并排序
//int MergeCompare(int arr[], int start, int mid, int end, int temp[])
//{
//	//第一段的下标范围
//	int istart = start;
//	int iend = mid;
//
//	//第二段的下标范围
//	int jstart = mid + 1;
//	int jend = end;
//	int length = start;//temp从start下标开始
//	while (istart <= iend&&jstart <= jend)
//	{
//		if (arr[istart] < arr[jstart])
//		{
//			temp[length++] = arr[istart++];
//		}
//		else
//		{
//			temp[length++] = arr[jstart++];
//		}
//	}//归并排序两段数据，并将结果放入temp数组中
//
//	while (istart <= iend)//剩余的数据必然是有序的，可以直接拷贝到temp
//	{
//		temp[length++] = arr[istart++];
//	}
//
//	while (jstart <= jend)//剩余的数据必然是有序的，可以直接拷贝到temp
//	{
//		temp[length++] = arr[jstart++];
//	}
//
//	//将temp中的有序数据再拷贝到arr中
//
//	for (int i = start; i <= end; i++)
//	{
//		arr[i] = temp[i];
//	}
//
//	return 0;
//}
////递归保证第一次使用mergecompare时，所分的两段数据是有序的。
//int MergeSort(int arr[], int start, int end, int temp[])
//{
//	if (start == end)
//	{
//		return 0;
//	}
//
//	int mid = (start + end) / 2;
//
//	MergeSort(arr, start, mid, temp);
//
//	MergeSort(arr, mid + 1, end, temp);
//
//	MergeCompare(arr, start, mid, end, temp);
//
//	return 0;
//}



//设置打印函数
void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void testBubble(int arr[],char ***buf,int *Member)//主函数分别调用test，并将时间差结果以字符串的形式传出，显然这里如果是队列比较好
{
	int arr1[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr1[i] = arr[i];
	}

	time_t BeforeSortTime;
	time_t AfterSortTime;
	//PrintArray(arr1, MAX);
	time(&BeforeSortTime);
	//冒泡排序
	BubbleSort(arr1, MAX);
	
	time(&AfterSortTime);
	//PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member+1)*sizeof(char *));//申请一个二级指针指向多个一级指针

	(*buf)[*Member] =(char *)calloc(100, sizeof(char));//为一级指针申请多个字符空间

	sprintf((*buf)[*Member], "BubbleSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));
	
	(*Member)++;
	return;
}

void testSelect(int arr[], char ***buf, int *Member)//主函数分别调用test，并将时间差结果以字符串的形式传出，显然这里如果是队列比较好
{
	int arr1[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr1[i] = arr[i];
	}

	time_t BeforeSortTime;
	time_t AfterSortTime;
	//PrintArray(arr1, MAX);
	time(&BeforeSortTime);
	//冒泡排序
	SelectSort(arr1, MAX);

	time(&AfterSortTime);
//	PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//申请一个二级指针指向多个一级指针

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//为一级指针申请多个字符空间

	sprintf((*buf)[*Member], "SelectSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));

	(*Member)++;
	return;
}

void testinsert(int arr[], char ***buf, int *Member)//主函数分别调用test，并将时间差结果以字符串的形式传出，显然这里如果是队列比较好
{
	int arr1[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr1[i] = arr[i];
	}

	time_t BeforeSortTime;
	time_t AfterSortTime;
	//PrintArray(arr1, MAX);
	time(&BeforeSortTime);
	//冒泡排序
	InsertSort(arr1, MAX);

	time(&AfterSortTime);
//	PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//申请一个二级指针指向多个一级指针

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//为一级指针申请多个字符空间

	sprintf((*buf)[*Member], "InsertSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));

	(*Member)++;
	return;
}

void testQuick(int arr[], char ***buf, int *Member)//主函数分别调用test，并将时间差结果以字符串的形式传出，显然这里如果是队列比较好
{
	int arr1[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr1[i] = arr[i];
	}

	time_t BeforeSortTime;
	time_t AfterSortTime;
	//PrintArray(arr1, MAX);
	time(&BeforeSortTime);
	//冒泡排序
	QuickSort(arr1,0,MAX-1);

	time(&AfterSortTime);
	//PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//申请一个二级指针指向多个一级指针

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//为一级指针申请多个字符空间

	sprintf((*buf)[*Member], "QuickSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));

	(*Member)++;
	return;
}

//void testMergeSort(int arr[], char ***buf, int *Member)
//{
//
//	int arr1[MAX];
//	int temp[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr1[i] = arr[i];
//	}
//
//	time_t BeforeSortTime;
//	time_t AfterSortTime;
//	//PrintArray(arr1, MAX);
//	time(&BeforeSortTime);
//	//冒泡排序
//	MergeSort(arr1, 0, MAX - 1,temp);
//
//	time(&AfterSortTime);
//	//PrintArray(arr1, MAX);
//
//	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//申请一个二级指针指向多个一级指针
//
//	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//为一级指针申请多个字符空间
//
//	sprintf((*buf)[*Member], "MergeSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));
//
//	(*Member)++;
//	return;
//
//
//}

//打印时间
void PrintTime(char **buf, int Member)
{
	for (int i = 0; i < Member; i++)
	{
		printf("%s\n", buf[i]);
	}
}
int main(void)
{
	int arr[MAX]= { 0 };
	srand(unsigned(time(NULL)));

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand()%10;
	}

	char **buf = NULL;
	int Member = 0;
	testBubble(arr,&buf,&Member);

	testSelect(arr, &buf, &Member);

	testinsert(arr, &buf, &Member);

	testQuick(arr, &buf, &Member);

	//testMergeSort(arr, &buf, &Member);
	printf("%d\n", Member);

	PrintTime(buf, Member);
	//double t1=(double)time(NULL);
	//printf("t=%lf", t1);
	//time_t TimeBeforeSort;
	//time_t TimeAfterSort;
	////排序前打印
	//PrintArray(arr, MAX);

	//QuickSort(arr, 0, MAX - 1);
	//BubbleSort(arr, MAX);
	//SelectSort(arr, MAX );
	//InsertSort(arr, MAX);
	//排序后打印
	//PrintArray(arr, MAX);
	printf("\n");
	system("pause");
	return 0;
}
#endif


#if 0
int main()
{
	time_t t1;
	time(&t1);
	printf("%lf", (double)t1);
	Sleep(2000);
	time(&t1);
	printf("%lf", (double)t1);
	system("pause");
	return 0;
}
#endif



