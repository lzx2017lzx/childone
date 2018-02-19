#pragma once

//定义一个结构体类型，作为动态数组
struct DynamicArray
{
    void **DArray;//用来申请堆空间，堆的单位元素是void *
    int Capacity;//动态数组的容量
    int Size;//动态数组的大小
};
//定义函数指针类型
typedef void (*VISITFUNCTION)(void *Data);
//为了保持该代码能被C++编译器编译
#ifdef __cplusplus
extern "C"{
#endif
        //初始化动态数组
        void *InitDynamicArray();
        //向动态数组指定位置插入元素
        void InsertDynamicArray(struct DynamicArray *PDArray,int Pos,void *Data);
        //删除动态数组指定位置的元素
        void DeleteDynamicArray(struct DynamicArray *PDArray,int Pos);
        //对动态数组遍历
        void VisitEachNode(struct DynamicArray *PDArray,VISITFUNCTION VisitFunction);
        //访问指定位置的元素
        void* VisitCertainNode(struct DynamicArray *PDArray,int Pos);
        //获得元素个数
        int GetSize(struct DynamicArray *PDArray);
        //销毁动态数组
        void DestroyDynamicArray(struct DynamicArray *PDArray);


#ifdef __cplusplus
}
#endif

