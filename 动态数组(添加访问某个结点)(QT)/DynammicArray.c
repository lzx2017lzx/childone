#include"DynammicArray.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * struct DynamicArray
{
    void **DArray;//用来申请堆空间，堆的单位元素是void *
    int Capacity;//动态数组的容量
    int Size;//动态数组的大小
};
 *
 * */
//初始化动态数组
void *InitDynamicArray()
{
    //申请指针变量指向一个动态数组
    struct DynamicArray *PDArray=(struct DynamicArray *)malloc(sizeof(struct DynamicArray));
    memset(PDArray,0,sizeof(struct DynamicArray));


    //申请连续的指针变量堆空间存储指向数据
    PDArray->DArray=(void *)malloc(6*sizeof(void *));
    memset(PDArray->DArray,0,sizeof(void *)*6);

    PDArray->Capacity=6;
    PDArray->Size=0;
    return PDArray;
}

//向动态数组插入元素
void InsertDynamicArray(struct DynamicArray *PDArray,int Pos,void *Data)
{
    if(NULL==PDArray)
    {
        return;
    }
    if(NULL==Data)
    {
        return;
    }
    if(Pos>PDArray->Size-1&&(PDArray->Size!=0))//目的是不让Pos小于零
    {
        Pos=PDArray->Size-1;
    }
    if(Pos<0)
    {
        Pos=0;
    }


    //插入数据前要先检查动态数组中的Size和Capacity是否相等，如果相等，意味动态数组空间不足以存储新的数据
    //需要重新申请空间

    if(PDArray->Capacity==PDArray->Size)
    {
        //申请2倍于Capacity的堆空间，数据域是void *
        void **NewDArray=(void **)malloc(2*sizeof(void *)*(PDArray->Capacity));
        memset(NewDArray,0,2*(PDArray->Capacity)*sizeof(void *));

        //将源DArray中的数据拷贝到新的空间中
        memcpy(NewDArray,PDArray->DArray,(PDArray->Capacity)*sizeof(void *));

        //释放掉DArray指向的堆空间
        free(PDArray->DArray);

        //DArray指向NewDArray
        PDArray->DArray=NewDArray;
    }

    //插入新的数据,由于动态数组可以通过下标直接访问，与链表不同所以不需要遍历找到位置，但是首先必须要将pos位置处元素到最后一个元素之间的所有元素后移一位，并且从最后一个元素开始移
    int i=0;
    for(i=PDArray->Size-1;i>Pos-1;i--)
    {
            PDArray->DArray[i+1]=PDArray->DArray[i];
    }
    //插入新的数据
    PDArray->DArray[i+1]=Data;
    //将动态数组长度加1
    PDArray->Size++;

}

//删除动态数组指定位置的元素
void DeleteDynamicArray(struct DynamicArray *PDArray,int Pos)
{
    if(NULL==PDArray)
    {
        return;
    }
    if(Pos<0||Pos>PDArray->Size-1)
    {
        return;
    }

    //直接通过覆盖的方式删除元素，依次前移,检查发现当i=PDArray->Size-1时，i+1已经越界，所以i的上界要调整
    int i=0;
    for(i=Pos;i<PDArray->Size-1;i++)
    {
        PDArray->DArray[i]=PDArray->DArray[i+1];
    }
    //让尾元素的数据域变成空
    PDArray->DArray[i]=NULL;
    //改变Size
    PDArray->Size--;
}

//对动态数组遍历,需指定遍历的函数，因此再函数原型中应该定义函数指针
void VisitEachNode(struct DynamicArray *PDArray,VISITFUNCTION VisitFunction)
{
    if(NULL==PDArray)
    {
        return;
    }

    if(NULL==VisitFunction)
    {
        return;
    }
    //注意任何数据结构，Size等于0，就没必要遍历了，动态数组就是数据类型
    if(0==PDArray->Size)
    {
        return;
    }
    //VISITFUNCTION类型的函数形参实void *Data，所以必须循环使用该类型函数，才能实现遍历
    int i=0;
    for(i=0;i<PDArray->Size;i++)
    {
        VisitFunction(PDArray->DArray[i]);
    }

    return;
}
 //访问指定位置的元素
 void * VisitCertainNode(struct DynamicArray *PDArray,int Pos)
 {
     if(NULL==PDArray)
     {
         return NULL;
     }

     //注意任何数据结构，Size等于0，就没必要遍历了，动态数组就是数据类型
     if(0==PDArray->Size)
     {
         return NULL;
     }
     if(Pos<0||Pos>PDArray->Size-1)
     {
         return NULL;
     }
     //VISITFUNCTION类型的函数形参实void *Data，所以必须循环使用该类型函数，才能实现遍历



     return PDArray->DArray[Pos];
 }

/*
 * struct DynamicArray
{
    void **DArray;//用来申请堆空间，堆的单位元素是void *
    int Capacity;//动态数组的容量
    int Size;//动态数组的大小
};
 *
 * */
 //获得元素个数
 int GetSize(struct DynamicArray *PDArray)
 {
     if(NULL==PDArray)
     {
         return -1;
     }
     return PDArray->Size;
 }

//销毁动态数组
void DestroyDynamicArray(struct DynamicArray *PDArray)
{
    if(NULL==PDArray)
    {
        return;
    }
    free(PDArray->DArray);
    PDArray->DArray=NULL;
    free(PDArray);//注意如果PDArray不是指针类型，就不方便释放动态数组的堆空间，动态数组本身也是在堆空间存储
    PDArray=NULL;
    return;
}
