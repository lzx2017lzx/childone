#pragma once
#include<stdlib.h>
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

//对 void *进行封装，增强数据保密性
typedef void * LinkQueueList;

#ifdef __cplusplus
extern "C" {
#endif
	//初始化链式队列
	LinkQueueList InitLinkQueue();
	//入队
	int PushLinkQueue(LinkQueueList LQueue, void *Data);
	//出队
	int PopLinkQueue(LinkQueueList LQueue);
	//访问队头元素
	void * VisitHeaderQueue(LinkQueueList LQueue);
	//访问队尾元素
	void *VisitRearQueue(LinkQueueList LQueue);
	//获得队内元素个数
	int GetSizeQueue(LinkQueueList LQueue);
	//销毁队
	int DestroyQueue(LinkQueueList LQueue);




#ifdef __cplusplus
}
#endif