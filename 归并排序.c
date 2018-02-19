#include <stdio.h>
#define MAX 1000
#include<time.h>
//�鲢���򣬽�һ�����ݷֳ����������֣��ٷֱ�Ƚϲ��á��Ƚϳɹ�һ������ԭ�����±�����һ�Σ�temp�±�Ҳ����һ�Σ����Ҫ�鿴��û��ʣ�ࣻ���
//ע��ÿ��ʹ��mergesort����ʱ���������������ݶ�������ģ�ͨ���ݹ�ķ�ʽ��ʹ�õ�һ�αȽ�ʱ�����������ݶ���1�����������ܱȽϣ�����һ�������ֻ��2
//�����ݵ�����
void MergSort(int arr[],int start,int mid,int end,int temp[])//ʵ���ϲ���ÿ��temp���鶼�ᱻ��������������ʱ��ֻ��һ��������תվ����������
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

    while(istart<=iend)//ʣ������ݱ�Ȼ������ģ�����ֱ�ӿ�����temp
    {
        temp[tempi++]=arr[istart++];
    }

    while(jstart<=jend)
    {
        temp[tempi++]=arr[jstart++];
    }

    //��temp�е����ݿ�����arr�У�ע��λ��Ҫ��Ӧ
    for(int i=start;i<=end;i++)
    {
        arr[i]=temp[i];
    }
}



void MergeDivde(int arr[],int start,int end,int temp[])//�����������ݣ�����ҪĿ����ʹ�õ�һ�ν��й鲢�Ƚ�ʱ�ܹ����������������ڵ�����������ġ�
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
    //ʹ���������������
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

