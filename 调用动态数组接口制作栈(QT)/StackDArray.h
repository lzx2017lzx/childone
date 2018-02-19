#pragma once
#include"D:\qt_code\DynamicArray\DynammicArray.h"
#define MAXSIZE 1024
//�ýṹ������ջ
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
    void* data[MAXSIZE]; //�������ݵ�����
    int size;
};
typedef struct StackDArray *SeqStack;
#if __cplusplus
extern "C"{
#endif
    //��ʼ��
    SeqStack Init_SeqStack();
    //��ջ
    void Push_SeqStack(SeqStack stack,void *data);
    //��ջ
    void Pop_SeqStack(SeqStack stack);
    //���ջ��Ԫ��
    void* Top_SeqStack(SeqStack stack);
    //���ջ��Ԫ�ظ���
    int Size_SeqStack(SeqStack stack);
    //����ջ
    void Destroy_SeqStack(SeqStack stack);

#if __cplusplus
}
#endif



//
