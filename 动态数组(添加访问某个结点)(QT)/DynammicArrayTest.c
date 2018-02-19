#include <stdio.h>
#include"DynammicArray.h"

//定义结构体类型，存储用户数据信息
struct Person
{
    char name[20];
    int age;
};
/*
 * struct DynamicArray
{
    void **DArray;//用来申请堆空间，堆的单位元素是void *
    int Capacity;//动态数组的容量
    int Size;//动态数组的大小
};
 * */
//自定义VISITFUNCTION函数
void PrintDynamicArray(void *Data)
{
    if(NULL==Data)
    {
        return;
    }
    struct Person *PPerson=(struct Person *)Data;
    printf("name:%s,age:%d\n",PPerson->name,PPerson->age);
    return;
}

//定义测试函数
void test()
{
    //定义用户数据信息
    struct Person p1={"abc",20};
    struct Person p2={"ddd",21};
    struct Person p3={"mbc",20};
    struct Person p4={"ndd",21};
    struct Person p5={"pbc",20};
    struct Person p6={"ldd",21};

    //初始化动态数组
    //初始化动态数组
    struct DynamicArray *PDArray=(struct DynamicArray *)InitDynamicArray();

    //向动态数组指定位置插入元素
    InsertDynamicArray(PDArray,0,&p1);
    InsertDynamicArray(PDArray,0,&p2);
    InsertDynamicArray(PDArray,0,&p3);
    InsertDynamicArray(PDArray,0,&p4);
    InsertDynamicArray(PDArray,0,&p5);
    InsertDynamicArray(PDArray,0,&p6);
    //对动态数组遍历
    VisitEachNode(PDArray,PrintDynamicArray);
    printf("----------------------------\n");
    //删除动态数组指定位置的元素
    DeleteDynamicArray(PDArray,0);
    //对动态数组遍历
    VisitEachNode(PDArray,PrintDynamicArray);
    //销毁动态数组
    DestroyDynamicArray(PDArray);
}

int main(void)
{
    test();
    printf("Hello World!\n");
    return 0;
}

