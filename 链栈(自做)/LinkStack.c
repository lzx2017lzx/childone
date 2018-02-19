#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
/*
 * struct LinkStackNode
{
    void *Data;
    struct LinkStackNode *PLSNode;
};

//����ṹ���������й���
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};
 *
 * */
//��ʼ����ջ,ͷ��㲻������
void *InitLStack()
{
    struct LinkStack *PLStack=(struct LinkStack *)malloc(sizeof(struct LinkStack));
    PLStack->Header.Data=NULL;
    PLStack->Header.PLSNode=NULL;
    PLStack->Size=0;
    return PLStack;
}

//��ջͷ��������
void InsertLStack(struct LinkStack *LStack,void *Data)
{
    if(NULL==LStack)
    {
        return;
    }

    if(NULL==Data)
    {
        return;
    }
    //����ָ��ջ����ָ�룬����malloc�����㣬ע��ͷ��㲻����malloc���룬����ͷ������ջ��ͷ��
    struct LinkStackNode *LStackNode=(struct LinkStackNode *)malloc(sizeof(struct LinkStackNode));
    memset(LStackNode,0,sizeof(struct LinkStackNode));

    //��������Ľ���з�װ����
    LStackNode->Data=(struct LinkStackNode *)Data;
    //�ֽ�����Ľ���ָ����ָ��header�����ָ����ָ��Ľ�㣬��ֹ�������ٽ�ͷ����ָ����ָ��������Ľ��
    LStackNode->PLSNode=LStack->Header.PLSNode;

    LStack->Header.PLSNode=LStackNode;
    //�������ݣ�Ҫ��size��1
    LStack->Size++;
    return;

}

//����ջͷԪ��,��ָ�����ʵķ�ʽ��������
void VisitLStack(struct LinkStack *LStack,void(*VISITLLNode)(void *Data))
{
    if(NULL==LStack)
    {
        return;
    }

    if(NULL==VISITLLNode)
    {
        return;
    }
    if(0==LStack->Size)
    {
        return;
    }

    VISITLLNode(LStack->Header.PLSNode->Data);
    return;

}

//����ջͷԪ��
void PopLStack(struct LinkStack *LStack)
{
    if(NULL==LStack)
    {
        return;
    }

    if(0==LStack->Size)
    {
        return;
    }

    //����ָ�����ָ�룬����ָ����Ч���ݵ�ջ��Ԫ�صĽ��
    struct LinkStackNode *LStackNode=LStack->Header.PLSNode;

    //ͷ����е�ָ����ָ��ͷ������һ�����
    LStack->Header.PLSNode=LStackNode->PLSNode;

    //�ͷŽ��
    free(LStackNode);
    //ջsize��1��
    LStack->Size--;
    return;
}

//������ջ�ߴ�
int SizeLStack(struct LinkStack *LStack)
{
    if(NULL==LStack)
    {
        return -1;
    }

    return LStack->Size;
}

//������ջ
void DestroyLStack(struct LinkStack *LStack)
{
    if(NULL==LStack)
    {
        return;
    }

    //����ָ�����ָ�룬����ָ��Ҫ�ͷŵĽ��
    struct LinkStackNode *LStackNode=LStack->Header.PLSNode;
    while(LStackNode!=NULL)
    {//ͷ����е�ָ����ָ��ͷ������һ�����
    LStack->Header.PLSNode=LStackNode->PLSNode;

    //�ͷŽ��
    free(LStackNode);
    //LStackNodeָ��ͷ���ָ��Ľ�㣬׼���ͷ���һ��
    LStackNode=LStack->Header.PLSNode;
    }

}


