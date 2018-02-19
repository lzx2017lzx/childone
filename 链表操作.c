#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id; //数据域
	struct Node *next; //指针域
}Node;

//功能：循环创建节点，按-1退出
//返回值：结构体类型的指针变量，头结点的指针
Node *SListCreat()
{
	Node *head = NULL;
	Node *pNew = NULL; //新节点
	Node *pCur = NULL; //尾结点
	int data;

	//先创建头结点，只是作为标志，不保存有效数据
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	//保存最后一个节点
	pCur = head;

	//循环创建链表，数据节点

	while (1)
	{
		//先输入数字
		printf("请输入数字：");
		scanf("%d", &data);
		if (data < 0)
		{
			break;
		}

		//新建节点
		pNew = (Node *)malloc(sizeof(Node));
		pNew->id = data;

		//链表建立关系
		//尾节点next指向新节点
		pCur->next = pNew;
		//pNew作为尾结点
		pNew->next = NULL;
		//保存尾结点
		pCur = pNew;
	}

	return head;
}

//遍历打印每个节点的数据域
void SListPrint(Node * head)
{
	if (head == NULL)
	{
		return;
	}

	//遍历内容，从首节点开始，头结点的下一个节点开始
	Node * tmp = head->next;
	printf("head -> ");
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->id);

		//指向下一个节点
		tmp = tmp->next;
	}
	printf("NULL\n");
}

//在节点id等于x, 在这个节点的前面插入一个新节点，新节点的id为y
//如果没有节点id等于x, 在尾结点插入, 新节点的id为y
void SListNodeInsert(Node * head, int x, int y)
{
	if (head == NULL)
	{
		return;
	}

	Node * pPre = NULL;
	Node * pCur = NULL;
	Node * pNew = NULL;

	//相差一个节点，pCur靠后
	pPre = head;
	pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x) //条件满足，退出循环
		{
			break;
		}

		//节点各自往后移动
		pPre = pPre->next;
		pCur = pCur->next;
	}

	//插入新节点

	//新建节点
	pNew = (Node *)malloc(sizeof(Node));
	pNew->id = y;

	//pPre的next指向新节点
	pPre->next = pNew;
	//新节点的Next指向pCur
	pNew->next = pCur;
}

//删除第一个节点id值为x的结点
void SListNodeDel(Node *head, int x)
{
	if (head == NULL)
	{
		return;
	}

	Node * pPre = NULL;
	Node * pCur = NULL;
	int flag = 0; //默认没有找到

				  //相差一个节点，pCur靠后
	pPre = head;
	pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x) //条件满足，退出循环
		{
			//删除前，把pre的next指向cur的next
			pPre->next = pCur->next;

			free(pCur);
			pCur = NULL;
			flag = 1;

			break;
		}

		//节点各自往后移动
		pPre = pPre->next;
		pCur = pCur->next;
	}

	if (0 == flag)
	{
		printf("没有第一个节点id值为%d的结点\n", x);
	}

}

//释放所有节点
void SListNodeDestroy(Node *head)
{
	if (head == NULL)
	{
		return;
	}

	Node *del = head;
	Node *tmp = head;
	while (tmp != NULL)
	{
		//释放前，保存下一个节点
		tmp = tmp->next;
		free(del);
		del = NULL;

		//del保存需要释放的结点
		del = tmp;
	}
}
//删除值为x的所有结点
//没有判断是否数据域等于x的值存在与否
int SListNodeDelPro(Node *pHead, int x)
{
	if (pHead == NULL)
		return -1;
	Node *pPre = NULL;
	Node *pCur = NULL;

	pPre = pHead;
	pCur = pHead->next;
	//从头结点开始遍历链表，当发现结点数据域值为x时，删除结点
	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			pPre->next = pCur->next;
			free(pCur);
			pCur = pPre->next;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return 0;
}

//链表节点排序，交换的是数据域
int SListNodeSortData(Node *pHead)
{
	if (pHead->next == NULL)
		return -1;

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node *p1 = NULL;
	Node temp = {0};

	pPre = pHead->next;
	while (pPre!=NULL)
	{
		pCur = pPre->next;
		while(pCur!=NULL)
		{ 
			if (pPre->id > pCur->id)
			{
				temp.id = pPre->id;
				pPre->id = pCur->id;
				pCur->id = temp.id;
			}
			pCur = pCur->next;
		}
		pPre = pPre->next;
	}
	return 0;
}

//链表排序，交换整个结点
int SListNodeSortNode(Node *pHead)
{
	if (pHead->next = NULL)
		return -1;
	Node *pPre = NULL;
	Node *pCur = NULL;
	Node temp = { 0 };

	pPre = pHead;
	pCur = pPre->next;
	
	//选择排序每轮都会将确定位置的结点与最终结果相同，pPre指向该位置的前一个结点，pCur指向该位置处的结点
	while (pPre->next != NULL)
	{
		pCur = pPre->next;
		while(pCur!=NULL)
		{
			if (pPre->next->id > pCur->next->id)
			{
				pPre->next = pCur->next;
				pCur->next = pCur->next->next;
				pPre->next->next = pCur;
			}
			pCur = pCur->next;
		}
		pPre = pPre->next;//指向位置限定处的结点	
	}
	return 0;
}
//注意，排序，next指针还需要交换
/*if (pPre->id > pCur->id) //升序
{
	//交换节点整体
	tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//再重新交换一下next指针域
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
}
*/
//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(Node *pHead, int x)
{
	if (pHead == NULL)
		return -1;
	Node *pPre = NULL;
	Node *pCur = NULL;

	pPre = pHead;
	pCur = pPre->next;

	Node *temp = (Node *)malloc(sizeof(Node));
	memset(temp, 0, sizeof(Node));
	temp->id = x;
	//先比较大小找到x应插入的位置，再申请结点插入
	while (pCur != NULL)
	{
		if (pCur->id >=x)
			break;
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//插入结点
	pPre->next = temp;
	temp->next = pCur;
	return 0;
}

//翻转链表的节点（不是排序，是翻转），交换的是指针域
int SListNodeReverse(Node *pHead)
{
	
	if (pHead == NULL)
		return -1;

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node *temp = NULL;

	pPre = pHead->next;
	pCur = pPre->next;
	temp = pCur->next;//防止断链
	pPre->next = NULL;
	//采用头插法
	while (temp != NULL)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
		temp = pCur->next;
		pHead->next = pPre;
	}
	pCur->next = pPre;
	pHead->next = pCur;
	return 0;
}
int main01(void)
{
	Node * head = NULL;
	head = SListCreat(); //创建链表

						 //遍历打印每个数据域
	SListPrint(head);

	printf("\n在5前面插入4后的结果：\n");
	SListNodeInsert(head, 5, 4); //在5前面插入4，如果没有5，在末尾插入
	SListPrint(head);

	printf("\n删除第一个节点id值为5的结点：\n");
	SListNodeDel(head, 5);
	SListPrint(head);

	SListNodeDestroy(head); //释放所有节点
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
int main()
{
Node *pHead = NULL;

pHead = SListCreat(); //创建头结点
printf("\n创建头结点后\n");
SListPrint(pHead); //遍历所有节点

SListNodeDelPro(pHead, 4);//删除所有值为4的结点
printf("\n删除所有值为4的结点\n");
SListPrint(pHead); //遍历所有节点

SListNodeSortData(pHead);//链表节点排序
printf("\n链表节点排序\n");
SListPrint(pHead); //遍历所有节点

SListNodeInsertPro(pHead, 5);//升序插入5
printf("\n升序插入5后\n");
SListPrint(pHead); //遍历所有节点

//翻转链表的节点（不是排序，是翻转）
SListNodeReverse(pHead);
printf("\n翻转链表的节点\n");
SListPrint(pHead); //遍历所有节点

SListNodeDestroy(pHead);//释放所有节点
pHead = NULL;
system("pause");
return 0;
}