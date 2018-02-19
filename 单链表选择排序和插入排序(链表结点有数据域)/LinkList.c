#include"LinkList.h"

//链表的数据类型
struct LList
{
	struct LinkNode header; //头结点
	int size; //链表大小
	//struct LinkNode *rear; //指向尾部节点
};

//初始化  后缀主要为了防止命名冲突
LinkList Init_LinkList()
{
	struct LList *list = malloc(sizeof(struct LList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;

	return list;
}
//插入
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	//辅助指针变量
	struct LinkNode *pCurrent = &(mylist->header);
	//找位置
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//1. 创建新节点
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//2. 新结点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;

}
//删除
void Remove_LinkList(LinkList list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size - 1)
	{
		return;
	}

	if (mylist->size == 0)
	{
		return;
	}

	//找到删除位置的前一个位置的节点
	struct LinkNode *pCurrent = &(mylist->header);

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//先缓存下待删除节点
	struct LinkNode *pDel = pCurrent->next;
	//重新建立待删除节点的前驱和后继节点关系
	pCurrent->next = pDel->next;
	//释放删除节点的内存
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//遍历
void Foreach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	//辅助指针
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//销毁
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}


	struct LList *mylist = (struct LList *)list;
	//辅助指针
	struct LinkNode *pCurrent = mylist->header.next;

	struct LinkNode *pNext = NULL;
	while (pCurrent != NULL)
	{
		//先缓存当前节点的下一个节点
		pNext = pCurrent->next;
		//放心的释放当前节点的内存
		free(pCurrent);

		pCurrent = pNext;
	}


	free(mylist);
	mylist = NULL;
}

//打印链表结点个数
int Size_LinkList(LinkList list)
{

	if (NULL == list)
	{
		return 0;
	}

	struct LList *mylist = (struct LList *)list;

	return mylist->size;
}

//单链表选择排序(链表结点储存数据域),设置回调函数，用来比较结点

int SelectSort(LinkList list,PCOMPARE Pfun)
{
	if (NULL == list)
	{
		return -1;
	}

	if (NULL == Pfun)
	{
		return -2;
	}
	struct LList*Plist = (struct LList*)list;//对void *型变量进行强制类型转换

	struct LinkNode*PLinkNode = NULL;//存放要交换的结点的地址

	struct LinkNode *PCur =Plist->header.next;//设置指向第一个有效结点的指针

	struct LinkNode *Ptemp = NULL;//用来遍历寻找要和PCur指向的结点交换的结点

	
	
	for (; PCur != NULL; PCur = PCur->next)
	{
		PLinkNode = PCur;//假设PLinkNode存放的就是要交换的结点，在这里表示data域最小的结点，按升序排列
		for (Ptemp = PCur->next; Ptemp != NULL; Ptemp = Ptemp->next)
		{
			if (Pfun(PLinkNode->data, Ptemp->data))//如果Ptemp的数据域小就将该结点的地址赋值给PLinkNode
			{
				PLinkNode = Ptemp;
			}
		}

		//交换两个结点的数据域，借用头结点的数据域作为交换的辅助空间
		Plist->header.data = PLinkNode->data;
		PLinkNode->data = PCur->data;
		PCur->data = Plist->header.data;
		
		//清空头结点的数据域
		Plist->header.data = NULL;
	}

	return 0;
}


//单链表插入排序(链表结点存储数据域)
int InsertSort(LinkList list, PCOMPARE Pfun)
{
	//首先设置指针指向要处理的结点，指针是不断指向链表的下一个结点的，不会返回，处理完后要保证该结点之前的所有结点的数据域都是有序的
	//要处理的结点的插入位置的要求是它比前一个结点的数据域大，但是比后一个的结点的数据域小
	if (NULL == list)
	{
		return -1;
	}

	if (NULL == Pfun)
	{
		return -2;
	}

	struct LList *PLList = (struct LList *)list;
	//设置指针用来指向PCur指向的结点的前一个结点；当对PCur指向的结点进行插入处理时，防止断链
	struct LinkNode *PCurPre = PLList->header.next;//指向第一个元素,这样可以有效地避免只有一个有效元素，不能顺利进行
	struct LinkNode *PCur = PCurPre->next;//设置指向要处理的结点的指针,初始化指向第一个有效结点

	//设置指针用来遍历PCur指向的结点的之前的结点；
	struct LinkNode *Ptemp = &(PLList->header);//
	//int flag = 0;//设置flag变量，因为第一次处理和之后的处理方式不一样，flag为0，表示第一次，否则为

	while(PCur != NULL)
	{
		Ptemp = PLList->header.next;//从头开始查找

		for (; (Ptemp != PCur)&&(Ptemp!=NULL); Ptemp = Ptemp->next)
		{
			if ((Pfun(Ptemp->data, PCur->data) <= 0) && (Pfun(PCur->data, Ptemp->next->data) < 0))
			{
				break;
			}

			if ((Pfun(Ptemp->data, PCur->data)) >=0)//如果第一个结点就大于等于目前的结点，也终止循环
			{
				break;
			}
		}

		if (Ptemp == PCur)//如果Ptemp==PCur，不需要交换
		{
			PCurPre = PCur;
			PCur = PCurPre->next;
			continue;
		}
		//如果第一个数大于PCur指向的结点的数，此时要处理
		if (Ptemp == PLList->header.next)//判断第一个有效结点的数据是不是大于要处理的结点
		{
			PCurPre->next = PCur->next;//防止断链
			PCur->next = Ptemp;
			PLList->header.next = PCur;
			PCur = PCurPre->next;
			continue;
		}
		
		//循环结束，意味Ptemp指向的结点的后一个结点，是PCur指向的结点的插入位置
		//进行插入
		PCurPre->next = PCur->next;//防止断链
		PCur->next = Ptemp->next;
		Ptemp->next = PCur;

		//将PCur指针指向PCurPre指向的结点的下一个结点
		PCur = PCurPre->next;
	}
	return 0;
}