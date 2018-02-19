#include"SeqStack.h"

//初始化
SeqStack Init_SeqStack()
{
	//一般情况下，只要开辟内存空间都要初始化
	struct SStack *stack = malloc(sizeof(struct SStack));
    int i = 0;
    for (i=0; i < MAXSIZE;++i)
	{
		stack->data[i] = NULL;
	}

	//memset(stack->data, 0, MAXSIZE * sizeof(void *));

	stack->size = 0;

	return stack;
}
//入栈
void Push_SeqStack(SeqStack stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == MAXSIZE)
	{
		return;
	}

	s->data[s->size] = data;
	s->size++;

}
//出栈
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == 0)
	{
		return;
	}

	s->size--;

}
//获得栈顶元素
void* Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == 0)
	{
		return NULL;
	}

	return s->data[s->size - 1];

}
//获得栈中元素个数
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	struct SStack *s = (struct SStack *)stack;

	return s->size;
}
//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
