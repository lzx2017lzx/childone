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

//定义结构体对链表进行管理
struct LinkStack
{
    struct LinkStackNode Header;
    int Size;
};
 *
 * */
//初始化链栈,头结点不存数据
void *InitLStack()
{
    struct LinkStack *PLStack=(struct LinkStack *)malloc(sizeof(struct LinkStack));
    PLStack->Header.Data=NULL;
    PLStack->Header.PLSNode=NULL;
    PLStack->Size=0;
    return PLStack;
}

//向栈头插入数据
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
    //定义指向栈结点的指针，并用malloc申请结点，注意头结点不是用malloc申请，而且头结点就是栈的头部
    struct LinkStackNode *LStackNode=(struct LinkStackNode *)malloc(sizeof(struct LinkStackNode));
    memset(LStackNode,0,sizeof(struct LinkStackNode));

    //向新申请的结点中封装数据
    LStackNode->Data=(struct LinkStackNode *)Data;
    //现将申请的结点的指针域指向header结点内指针域指向的结点，防止断链，再将头结点的指针域指向新申请的结点
    LStackNode->PLSNode=LStack->Header.PLSNode;

    LStack->Header.PLSNode=LStackNode;
    //插入数据，要将size加1
    LStack->Size++;
    return;

}

//访问栈头元素,需指定访问的方式，即函数
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

//弹出栈头元素
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

    //定义指向结点的指针，用来指向有效数据的栈首元素的结点
    struct LinkStackNode *LStackNode=LStack->Header.PLSNode;

    //头结点中的指针域指向头结点的下一个结点
    LStack->Header.PLSNode=LStackNode->PLSNode;

    //释放结点
    free(LStackNode);
    //栈size减1；
    LStack->Size--;
    return;
}

//访问链栈尺寸
int SizeLStack(struct LinkStack *LStack)
{
    if(NULL==LStack)
    {
        return -1;
    }

    return LStack->Size;
}

//销毁链栈
void DestroyLStack(struct LinkStack *LStack)
{
    if(NULL==LStack)
    {
        return;
    }

    //定义指向结点的指针，用来指向要释放的结点
    struct LinkStackNode *LStackNode=LStack->Header.PLSNode;
    while(LStackNode!=NULL)
    {//头结点中的指针域指向头结点的下一个结点
    LStack->Header.PLSNode=LStackNode->PLSNode;

    //释放结点
    free(LStackNode);
    //LStackNode指向头结点指向的结点，准备释放下一个
    LStackNode=LStack->Header.PLSNode;
    }

}


