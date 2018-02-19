#include"LinkList.h"

//初始化
struct LinkList *Init_LinkList()
{
	struct LinkList *list = malloc(sizeof(struct LinkList));
	list->header.next = NULL;
	list->size = 0;

	return list;

}



//插入
void Insert_LinkList(struct LinkList *list, int pos, void *data)
{

	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}


	//辅助指针变量
	struct LinkNode *pCurrent = &(list->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//插入数据

	struct LinkNode *newnode = (struct LinkNode *)data;

	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	list->size++;

}

//遍历
void Foreach_LinkList(struct LinkList *list, void(*myforeach)(void *))
{

	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}


	//辅助指针变量
	struct LinkNode *pCurernt = list->header.next;
	while (pCurernt != NULL)
	{
		myforeach(pCurernt);
		pCurernt = pCurernt->next;
	}

}


void Remove_LinkList(struct LinkList *list, int pos)
{
	
	if (NULL == list)
	{
		return;
	}

	if (pos < 0 || pos > list->size - 1)
	{
		return;
	}

	struct LinkNode *pCurrent = &(list->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}


	//缓存下待删除节点
	struct LinkNode *pDel = pCurrent->next;

	//重新建立待删除节点前驱和后继节点关系
	pCurrent->next = pDel->next;
	
	list->size--;

}


void Destroy_LinkList(struct LinkList *list)
{

	if (NULL == list)
	{
		return;
	}

	free(list);
	list = NULL;
}

//排序其中根据函数的返回结果排序，返回结果大于0，表示第一个元素大，小于0表示后者更大，因为链表结点的数据是指针，所以函数的型参也设置为指针
int SelectRanking(struct LinkList *list, COMPAREFUNCTION func)
{
	if (NULL == list)
	{
		return -1;
	}

	if (0 == list->size)
	{
		return -2;
	}

	if (NULL == func)
	{
		return -3;
	}

	//设置指向链表结点的指针，用来遍历链表
	struct LinkNode *PiPre = &(list->header);//用于第一层for循环
	struct LinkNode *Pi = PiPre->next;//用于第一层for循环,始终指向PiPre的下一个结点
	struct LinkNode *PjPre = &(list->header);//用于第二层for循环
	struct LinkNode *Pj = PjPre->next;//用于第二层for循环，始终指向PiPre的下一个结点


	//设置指针用来交换结点
	struct LinkNode *PTemp1 = NULL;//同时为了防止断链
	struct LinkNode *PTemp2 = NULL;//用来防止断链
	for (; Pi != NULL; PiPre=Pi,Pi=PiPre->next)
	{
		for (Pj = Pi; Pj != NULL; PjPre=Pj,Pj=PjPre->next)
		{
			if (func(Pi, Pj) > 0)//说明需要交换
			{
				//需要判断Pi和Pj是否相邻，相邻结点和不相邻结点交换方式不一样
				if (Pi->next != Pj)
				{//首先将Pj插入到Pi的前面
					PjPre->next = Pj->next;//防止断链
					Pj->next = Pi;//Pj指向的结点指向Pi结点
					PiPre->next = Pj;//成功将Pj指向的结点插入到Pi指向的结点的前面

					//再将Pi指向的结点插入到PjPre指向的结点的后面
					Pj->next = Pi->next;//防止断链
					Pi->next = PjPre->next;//Pi指向的结点指向PjPre指向的结点的下一个结点
					PjPre->next = Pi;//PjPre指向的结点指向Pi指向的结点

					//最后交换Pi和Pj的值
					PTemp1 = Pi;
					Pi = Pj;
					Pj = PTemp1;
				}
				else
				{
					PjPre->next = Pj->next;//防止断链
					Pj->next = Pi;//Pj指向的结点指向Pi结点
					PiPre->next = Pj;

					//最后交换Pi和Pj的值
					PTemp1 = Pi;
					Pi = Pj;
					Pj = PTemp1;

					//PjPre需指向Pj指向的结点的前面结点
					PjPre = Pi;

				}
			}

		}
	}
	return 0;
}