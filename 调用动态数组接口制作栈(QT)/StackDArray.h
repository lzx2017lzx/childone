#pragma once
#include"D:\qt_code\DynamicArray\DynammicArray.h"
#define MAXSIZE 1024
//用结构体描述栈
/*struct StackDArrayNode
{
    void *Data;
    struct StackDArray*PSDArray;
};
*/
/*
struct StackDArray
{
    struct StackDArrayNode *PHeader;
    int Size;
};*/
struct StackDArray
{
    void* data[MAXSIZE]; //保存数据的数组
    int size;
};
typedef struct StackDArray *SeqStack;
#if __cplusplus
extern "C"{
#endif
    //初始化
    SeqStack Init_SeqStack();
    //入栈
    void Push_SeqStack(SeqStack stack,void *data);
    //出栈
    void Pop_SeqStack(SeqStack stack);
    //获得栈顶元素
    void* Top_SeqStack(SeqStack stack);
    //获得栈中元素个数
    int Size_SeqStack(SeqStack stack);
    //销毁栈
    void Destroy_SeqStack(SeqStack stack);

#if __cplusplus
}
#endif



//
