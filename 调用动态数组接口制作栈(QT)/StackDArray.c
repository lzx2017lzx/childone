#include"StackDArray.h"
#include<stdlib.h>

//��ʼ��
SeqStack Init_SeqStack()
{
    return InitDynamicArray();
}

//��ջ
void Push_SeqStack(SeqStack stack,void *data)
{
    struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    InsertDynamicArray(PDArray,0,data);
    return;
}

//��ջ
void Pop_SeqStack(SeqStack stack)
{
     struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    DeleteDynamicArray(PDArray,0);
    return;
}

//���ջ��Ԫ��
void* Top_SeqStack(SeqStack stack)
{
     struct DynamicArray *PDArray=(struct DynamicArray *)stack;
     return VisitCertainNode(PDArray,0);
}

//���ջ��Ԫ�ظ���
int Size_SeqStack(SeqStack stack)
{
    struct DynamicArray *PDArray=(struct DynamicArray *)stack;
    return GetSize(PDArray);
}

//����ջ
void Destroy_SeqStack(SeqStack stack)
{
    if(NULL==stack)
    {
        return;
    }
    free(stack);
    return;
}
