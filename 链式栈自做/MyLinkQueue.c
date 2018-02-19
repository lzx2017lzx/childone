#include "MyLinkQueue.h"
#include<string.h>
/*
//定义链式队列的结点，借用结构体
typedef struct LinkNode
{
void *Data;
struct LinkNode * Next;
}LNode;

//借用结构体定义链式队列
struct LinkQueue
{
LNode Header;
int Size;
LNode *Rear;
};
*/
//初始化链式队列
LinkQueueList InitLinkQueue()
{
	//申请一个链表
	struct LinkQueue *PLQueue = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
	memset(PLQueue, 0, sizeof(struct LinkQueue));

	//将链表内的尾指针指向头结点
	PLQueue->Rear = &(PLQueue->Header);

	return PLQueue;

}
//入队
int PushLinkQueue(LinkQueueList LQueue, void *Data)
{
	if (NULL == LQueue)
	{
		return -1;
	}
	if (NULL == Data)
	{
		return -2;
	}
	//为插入的数据申请结点
	struct LinkNode *PLNode = (LNode *)malloc(sizeof(LNode));
	memset(PLNode, 0, sizeof(LNode));
	PLNode->Data = Data;
	PLNode->Next = NULL;

	//插入操作
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;
	PLQueue->Rear->Next = PLNode;//通过指针的方式形成队列
	//插入操作没有将Size加1，造成运行结果错误
	PLQueue->Size++;
	//将尾指针放在尾结点上
	PLQueue->Rear = PLNode;

	return 0;
}
//出队
int PopLinkQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}

	
	

	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//将void *型变量强制转换成链式队列指针
	//如果链队PLQueue内无结点，退出
	if (0 == PLQueue->Size)
	{
		return -2;
	}
	//结点个数为一时和结点个数超过一时的数据弹出方式不一样,因为要保证尾指针指向尾结点

	//Size为1

	if (PLQueue->Size == 1)
	{
		//释放第一个结点
		free(PLQueue->Header.Next);
		PLQueue->Rear = &(PLQueue->Header);
		PLQueue->Size--;
		return 0;
	}

	//Size不为1
	//从队列的头弹出数据
	LNode *PCur = PLQueue->Header.Next;
	PLQueue->Header.Next = PCur->Next;

	free(PCur);
	PLQueue->Size--;//当PLQueue->Size 不为 1这种情况发生时，没有考虑到free过后将PLQueue->Size减减
	return 0;
}
//访问队头元素
void * VisitHeaderQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return NULL;
	}

	
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//将void *型变量强制转换成链式队列指针
	if (0 == PLQueue->Size)
	{
		return NULL;
	}
	return PLQueue->Header.Next->Data;//此处忘记头定点不存储数据，只是为了方便操作设立

}
//访问队尾元素
void *VisitRearQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return NULL;
	}


	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//将void *型变量强制转换成链式队列指针
	if (0 == PLQueue->Size)
	{
		return NULL;
	}
	return PLQueue->Rear->Data;

}
//获得队内元素个数
int GetSizeQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}

	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//将void *型变量强制转换成链式队列指针
	
	return PLQueue->Size;

}
//销毁队
int DestroyQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//将void *型变量强制转换成链式队列指针
	free(PLQueue->Header.Next);
	PLQueue->Header.Next = NULL;

	free(PLQueue);
	return 0;
}