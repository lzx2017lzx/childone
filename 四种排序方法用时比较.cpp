#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#if 1
#define MAX 100000
//��ͬ��������������������ʱ�䡢ð������ѡ�����򡢲�����������ʱ�䣬

//��������
void QuickSort(int arr[], int start, int end)//���㷨�ǰ���������
{
	int i = start;//start���ݲ��ܸĶ���Ϊ�ݹ鱣����������
	int j = end;//����ͬ��
	int target = arr[i];//ѡ�����

	if (i < j)//����ѭ����ֹ����
	{
		while(i<j)
		{
			while (i < j&&arr[j] > target)//��֤target�ұ�����Ԫ�ض������
			{
				j--;
			}//ѭ��������Ҫôi==j��Ҫôarr[j]<target;���i==j��Ҫ��֤�˳�ѭ��(����ͨ��break��Ҳ����ͨ��i<j���жϣ��������ÿһ�䶼��i<j�������жϣ��Ϳ��Բ�ͬbreak��
	//���arr[j]<target;���뽫arr[j]�ƶ���target��ߣ�����ͨ����arr[j]����target���ڴ洢�ռ�(�˴�Ϊ�±�1)����Ϣ������i++����Ϊ�±�i�������Ѿ���targetС��֮��ļ���ѭ��û�б�Ҫ���бȽ�
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}//��ʱarr[j]�������target�ĺ���λ�á�(ע����Ϊ�Ǹ��ǣ�arr[j]ֵ�������������ݡ�

			while (i < j&&arr[i] < target)//�˴���Ŀ���Ǵ������ң���֤���е�������targetС��
			{
				i++;
			}//ѭ��������arr[i]>target(���ڽ�����ִ�и���),���i==j��Ҫ��֤�������򶼲�ִ�м���������ж�i<j;

			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}//jλ�ú��������ݶ���target��
			
		}
		//if�����жϽ�������target�������λ��

		arr[i] = target;//i��j��ֵ��ͬ

						//�ݹ��������i�±���ߵ�����
		QuickSort(arr, start, i - 1);//i�±��Ѿ�����ȷ���ݣ�����Ҫ�Ƚ�

									 //�ݹ��������i�±��ұߵ�����
		QuickSort(arr, i + 1, end);
	}

	
}

//ð������(ÿ����ѭ�����ǽ��������ŵ����ұ�(���򣩻������(����)),��ѭ������������ѭ�������ݵĸ���
void BubbleSort(int arr[], int len)//����
{
	int i = 0;
	int j = 0;

	//����temp����������������
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

//ѡ������(ѡ�����������ص���ÿ�ζ���ָ��λ�÷�����ʵ����ݣ�ͨ����ָ��λ�õ��������������ݽ����ķ�ʽ��һ������ɹ��ܹ���һ�����ݷ��뵽ָ��λ��
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

//��������
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

////��·�鲢����
//int MergeCompare(int arr[], int start, int mid, int end, int temp[])
//{
//	//��һ�ε��±귶Χ
//	int istart = start;
//	int iend = mid;
//
//	//�ڶ��ε��±귶Χ
//	int jstart = mid + 1;
//	int jend = end;
//	int length = start;//temp��start�±꿪ʼ
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
//	}//�鲢�����������ݣ������������temp������
//
//	while (istart <= iend)//ʣ������ݱ�Ȼ������ģ�����ֱ�ӿ�����temp
//	{
//		temp[length++] = arr[istart++];
//	}
//
//	while (jstart <= jend)//ʣ������ݱ�Ȼ������ģ�����ֱ�ӿ�����temp
//	{
//		temp[length++] = arr[jstart++];
//	}
//
//	//��temp�е����������ٿ�����arr��
//
//	for (int i = start; i <= end; i++)
//	{
//		arr[i] = temp[i];
//	}
//
//	return 0;
//}
////�ݹ鱣֤��һ��ʹ��mergecompareʱ�����ֵ���������������ġ�
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



//���ô�ӡ����
void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void testBubble(int arr[],char ***buf,int *Member)//�������ֱ����test������ʱ��������ַ�������ʽ��������Ȼ��������Ƕ��бȽϺ�
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
	//ð������
	BubbleSort(arr1, MAX);
	
	time(&AfterSortTime);
	//PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member+1)*sizeof(char *));//����һ������ָ��ָ����һ��ָ��

	(*buf)[*Member] =(char *)calloc(100, sizeof(char));//Ϊһ��ָ���������ַ��ռ�

	sprintf((*buf)[*Member], "BubbleSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));
	
	(*Member)++;
	return;
}

void testSelect(int arr[], char ***buf, int *Member)//�������ֱ����test������ʱ��������ַ�������ʽ��������Ȼ��������Ƕ��бȽϺ�
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
	//ð������
	SelectSort(arr1, MAX);

	time(&AfterSortTime);
//	PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//����һ������ָ��ָ����һ��ָ��

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//Ϊһ��ָ���������ַ��ռ�

	sprintf((*buf)[*Member], "SelectSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));

	(*Member)++;
	return;
}

void testinsert(int arr[], char ***buf, int *Member)//�������ֱ����test������ʱ��������ַ�������ʽ��������Ȼ��������Ƕ��бȽϺ�
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
	//ð������
	InsertSort(arr1, MAX);

	time(&AfterSortTime);
//	PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//����һ������ָ��ָ����һ��ָ��

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//Ϊһ��ָ���������ַ��ռ�

	sprintf((*buf)[*Member], "InsertSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));

	(*Member)++;
	return;
}

void testQuick(int arr[], char ***buf, int *Member)//�������ֱ����test������ʱ��������ַ�������ʽ��������Ȼ��������Ƕ��бȽϺ�
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
	//ð������
	QuickSort(arr1,0,MAX-1);

	time(&AfterSortTime);
	//PrintArray(arr1, MAX);

	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//����һ������ָ��ָ����һ��ָ��

	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//Ϊһ��ָ���������ַ��ռ�

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
//	//ð������
//	MergeSort(arr1, 0, MAX - 1,temp);
//
//	time(&AfterSortTime);
//	//PrintArray(arr1, MAX);
//
//	*buf = (char **)realloc(*buf, (*Member + 1) * sizeof(char *));//����һ������ָ��ָ����һ��ָ��
//
//	(*buf)[*Member] = (char *)calloc(100, sizeof(char));//Ϊһ��ָ���������ַ��ռ�
//
//	sprintf((*buf)[*Member], "MergeSort costs:%lf", (double)difftime(AfterSortTime, BeforeSortTime));
//
//	(*Member)++;
//	return;
//
//
//}

//��ӡʱ��
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
	////����ǰ��ӡ
	//PrintArray(arr, MAX);

	//QuickSort(arr, 0, MAX - 1);
	//BubbleSort(arr, MAX);
	//SelectSort(arr, MAX );
	//InsertSort(arr, MAX);
	//������ӡ
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



