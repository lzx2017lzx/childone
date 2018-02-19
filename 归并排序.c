#include <stdio.h>
#define MAX 1000
#include<time.h>
//归并排序，将一个数据分成左右两部分，再分别比较采用“比较成功一个，将原数据下标增加一次，temp下标也增加一次，最后还要查看有没有剩余；其次
//注意每次使用mergesort函数时，左右两部分数据都是有序的，通过递归的方式，使得第一次比较时左右两边数据都是1个，这样就能比较，生成一个有序的只有2
//个数据的数组
void MergSort(int arr[],int start,int mid,int end,int temp[])//实际上不是每次temp数组都会被数据填满，更多时候只是一个数据中转站，用来排序。
{
    int istart=start;
    int iend=mid;
    int jstart=mid+1;
    int jend=end;
    int tempi=start;

    while(istart<=iend&&jstart<=jend)
    {
        if(arr[istart]<arr[jstart])
        {
            temp[tempi++]=arr[istart];
            istart++;
        }
        else
        {
            temp[tempi++]=arr[jstart];
            jstart++;
        }
    }

    while(istart<=iend)//剩余的数据必然是有序的，可以直接拷贝到temp
    {
        temp[tempi++]=arr[istart++];
    }

    while(jstart<=jend)
    {
        temp[tempi++]=arr[jstart++];
    }

    //将temp中的数据拷贝到arr中，注意位置要对应
    for(int i=start;i<=end;i++)
    {
        arr[i]=temp[i];
    }
}



void MergeDivde(int arr[],int start,int end,int temp[])//用来划分数据，最主要目的是使得第一次进行归并比较时能够让左右两份数据内的数据是有序的。
{
    if(start==end)
    {
        return;
    }

    int mid=(start+end)/2;
    MergeDivde(arr,start,mid,temp);
    MergeDivde(arr,mid+1,end,temp);

    MergSort(arr,start,mid,end,temp);
}

void PrintArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n-----------------------------------\n");
}

int main(void)
{
    srand((unsigned int)(time(NULL)));
    int a[MAX]={0};
    //使用随机数生成数据
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand()%10;
    }
    int temp[MAX]={0};
    PrintArray(a,MAX);
    MergeDivde(a,0,MAX-1,temp);
    PrintArray(a,MAX);
    printf("Hello World!\n");
    return 0;
}

