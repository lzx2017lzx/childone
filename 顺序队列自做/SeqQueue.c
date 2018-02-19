#include"SeqQueue.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/*struct SeqQue
{
	void *Data[MAXSIZE];
	int Size;
};*/
//初始化
LinkQueue Init_LinkQueue()
{
	struct SeqQue *PSeqQue = (struct SeqQue *)malloc(sizeof(struct SeqQue));
	memset(PSeqQue, 0, sizeof(struct SeqQue));

	PSeqQue->Size = 0;
	return PSeqQue;
}
//入队
int Push_LinkQueue(LinkQueue queue, void *data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	struct SeqQue *PSeqQue = (struct SeqQue *)queue;
	if (PSeqQue->Size == MAXSIZE)
	{
		printf("OverFlow.\n");
		return -3;
	}
	
	//设计从下标零处开始插入，先将数组所有元素后移一位
	int i = 0;
	for (i = PSeqQue->Size-2; i >=0; i--)
	{
		PSeqQue->Data[i + 1] = PSeqQue->Data[i];
	}
	PSeqQue->Data[0] = data;
	PSeqQue->Size++;
	return 0;
}
//出队
int Pop_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	
	struct SeqQue *PSeqQue = (struct SeqQue *)queue;
	if (0 == PSeqQue->Size)
	{
		return -2;
	}
	PSeqQue->Data[PSeqQue->Size - 1] = NULL;

	PSeqQue->Size--;
	return 0;

}
//获得队头元素
void *Front_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	struct SeqQue *PSeqQue = (struct SeqQue *)queue;
	if (0 == PSeqQue->Size)
	{
		return NULL;
	}

	return PSeqQue->Data[0];

}
//获得队尾元素
void *Back_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	struct SeqQue *PSeqQue = (struct SeqQue *)queue;
	if (0 == PSeqQue->Size)
	{
		return NULL;
	}

	return PSeqQue->Data[PSeqQue->Size - 1];
}
//大小
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	struct SeqQue *PSeqQue = (struct SeqQue *)queue;

	return PSeqQue->Size;
}
//销毁
int Destroy_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	//为了防止queue指向的是一个无效的堆空间,需要判断Size大小
	struct SeqQue *PSeqQue = (struct SeqQue *)queue;
	if (NULL == PSeqQue)
	{
		return -2;
	}
	if (0 == PSeqQue->Size)
	{
		return -3;
	}
	free(PSeqQue);
	return 0;

}