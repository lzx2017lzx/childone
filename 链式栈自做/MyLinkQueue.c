#include "MyLinkQueue.h"
#include<string.h>
/*
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
*/
//��ʼ����ʽ����
LinkQueueList InitLinkQueue()
{
	//����һ������
	struct LinkQueue *PLQueue = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
	memset(PLQueue, 0, sizeof(struct LinkQueue));

	//�������ڵ�βָ��ָ��ͷ���
	PLQueue->Rear = &(PLQueue->Header);

	return PLQueue;

}
//���
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
	//Ϊ���������������
	struct LinkNode *PLNode = (LNode *)malloc(sizeof(LNode));
	memset(PLNode, 0, sizeof(LNode));
	PLNode->Data = Data;
	PLNode->Next = NULL;

	//�������
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;
	PLQueue->Rear->Next = PLNode;//ͨ��ָ��ķ�ʽ�γɶ���
	//�������û�н�Size��1��������н������
	PLQueue->Size++;
	//��βָ�����β�����
	PLQueue->Rear = PLNode;

	return 0;
}
//����
int PopLinkQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}

	
	

	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//��void *�ͱ���ǿ��ת������ʽ����ָ��
	//�������PLQueue���޽�㣬�˳�
	if (0 == PLQueue->Size)
	{
		return -2;
	}
	//������Ϊһʱ�ͽ���������һʱ�����ݵ�����ʽ��һ��,��ΪҪ��֤βָ��ָ��β���

	//SizeΪ1

	if (PLQueue->Size == 1)
	{
		//�ͷŵ�һ�����
		free(PLQueue->Header.Next);
		PLQueue->Rear = &(PLQueue->Header);
		PLQueue->Size--;
		return 0;
	}

	//Size��Ϊ1
	//�Ӷ��е�ͷ��������
	LNode *PCur = PLQueue->Header.Next;
	PLQueue->Header.Next = PCur->Next;

	free(PCur);
	PLQueue->Size--;//��PLQueue->Size ��Ϊ 1�����������ʱ��û�п��ǵ�free����PLQueue->Size����
	return 0;
}
//���ʶ�ͷԪ��
void * VisitHeaderQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return NULL;
	}

	
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//��void *�ͱ���ǿ��ת������ʽ����ָ��
	if (0 == PLQueue->Size)
	{
		return NULL;
	}
	return PLQueue->Header.Next->Data;//�˴�����ͷ���㲻�洢���ݣ�ֻ��Ϊ�˷����������

}
//���ʶ�βԪ��
void *VisitRearQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return NULL;
	}


	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//��void *�ͱ���ǿ��ת������ʽ����ָ��
	if (0 == PLQueue->Size)
	{
		return NULL;
	}
	return PLQueue->Rear->Data;

}
//��ö���Ԫ�ظ���
int GetSizeQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}

	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//��void *�ͱ���ǿ��ת������ʽ����ָ��
	
	return PLQueue->Size;

}
//���ٶ�
int DestroyQueue(LinkQueueList LQueue)
{
	if (NULL == LQueue)
	{
		return -1;
	}
	struct LinkQueue *PLQueue = (struct LinkQueue *)LQueue;//��void *�ͱ���ǿ��ת������ʽ����ָ��
	free(PLQueue->Header.Next);
	PLQueue->Header.Next = NULL;

	free(PLQueue);
	return 0;
}