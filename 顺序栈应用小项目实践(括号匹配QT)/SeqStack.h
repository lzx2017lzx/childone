#pragma once

#define MAXSIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct SStack
{
	void* data[MAXSIZE]; //�������ݵ�����
	int size;
};

typedef void* SeqStack;

#ifdef __cplusplus
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


#ifdef __cplusplus
}
#endif
