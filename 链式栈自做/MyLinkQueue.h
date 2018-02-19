#pragma once
#include<stdlib.h>
//������ʽ���еĽ�㣬���ýṹ��
typedef struct LinkNode
{
	void *Data;
	struct LinkNode * Next;
}LNode;

//���ýṹ�嶨����ʽ����
struct LinkQueue
{
	LNode Header;
	int Size;
	LNode *Rear;
};

//�� void *���з�װ����ǿ���ݱ�����
typedef void * LinkQueueList;

#ifdef __cplusplus
extern "C" {
#endif
	//��ʼ����ʽ����
	LinkQueueList InitLinkQueue();
	//���
	int PushLinkQueue(LinkQueueList LQueue, void *Data);
	//����
	int PopLinkQueue(LinkQueueList LQueue);
	//���ʶ�ͷԪ��
	void * VisitHeaderQueue(LinkQueueList LQueue);
	//���ʶ�βԪ��
	void *VisitRearQueue(LinkQueueList LQueue);
	//��ö���Ԫ�ظ���
	int GetSizeQueue(LinkQueueList LQueue);
	//���ٶ�
	int DestroyQueue(LinkQueueList LQueue);




#ifdef __cplusplus
}
#endif