#pragma once
//用结构体定义队列
#define MAXSIZE 1000
struct SeqQue
{
	void *Data[MAXSIZE];
	int Size;
};
typedef void *LinkQueue;
#ifdef __cplusplus
extern "C" {
#endif

	//初始化
	LinkQueue Init_LinkQueue();
	//入队
	int Push_LinkQueue(LinkQueue queue, void *data);
	//出队
	int Pop_LinkQueue(LinkQueue queue);
	//获得队头元素
	void *Front_LinkQueue(LinkQueue queue);
	//获得队尾元素
	void *Back_LinkQueue(LinkQueue queue);
	//大小
	int Size_LinkQueue(LinkQueue queue);
	//销毁
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif