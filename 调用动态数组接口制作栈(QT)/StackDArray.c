#include"StackDArray.h"
#include<stdlib.h>

//初始化
SeqStack Init_SeqStack()
{
    return InitDynamicArray();
}

//入栈
void Push_SeqStack(SeqStack stack,void *data)
{
    struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    InsertDynamicArray(PDArray,0,data);
    return;
}

//出栈
void Pop_SeqStack(SeqStack stack)
{
     struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    DeleteDynamicArray(PDArray,0);
    return;
}

//获得栈顶元素
void* Top_SeqStack(SeqStack stack)
{
     struct DynamicArray *PDArray=(struct DynamicArray *)stack;
     return VisitCertainNode(PDArray,0);
}

//获得栈中元素个数
int Size_SeqStack(SeqStack stack)
{
    struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    return GetSize(PDArray);
}

//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
    if(NULL==stack)
    {
        return;
    }
    free(stack);
    return;
}
