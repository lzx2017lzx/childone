#pragma once

#define MAXSIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct SStack
{
	void* data[MAXSIZE]; //保存数据的数组
	int size;
};

typedef void* SeqStack;

#ifdef __cplusplus
extern "C"{
#endif

	//初始化
	SeqStack Init_SeqStack();
	//入栈
	void Push_SeqStack(SeqStack stack,void *data);
	//出栈
	void Pop_SeqStack(SeqStack stack);
	//获得栈顶元素
	void* Top_SeqStack(SeqStack stack);
	//获得栈中元素个数
	int Size_SeqStack(SeqStack stack);
	//销毁栈
	void Destroy_SeqStack(SeqStack stack);


#ifdef __cplusplus
}
#endif
