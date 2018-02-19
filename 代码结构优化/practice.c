#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link.h"
#if 0
/*
��Ա������������Ҫ��ṹ������ͷ�ļ��д�ź���ԭ�͡���Ӧ��.c�ļ����庯����
*/
typedef struct Node
{
	int id;
	struct Node *next;
}Node;
typedef void  LinkNode;
LinkNode* SListCreat()
{
	Node *head = NULL;
	Node *pNew = NULL;
	Node *pCur = NULL;
	int data;

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	pCur = head;
	while (1)
	{
		printf("���������֣�");
		scanf("%d", &data);
		if (data < 0)
		{
			break;
		}
		pNew = (Node*)malloc(sizeof(Node));
		pNew->id = data;
		pCur->next = pNew;
		pNew->next = NULL;
		pCur = pNew;
	}
	return head;
}
void SListPrint(LinkNode * p)
{
	Node*head = (Node*)p;
	if (head == NULL)
	{
		return;
	}
	Node *tmp = head->next;
	printf("head->");
	while (tmp != NULL)
	{
		printf("%d-> ", tmp->id);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
void SListNodeInsert(LinkNode* p, int x, int y)
{
	Node *head = (Node*)p;
	if (head == NULL)
	{
		return;
	}

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node *pNew = NULL;

	pPre = head;
	pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	pNew = (Node*)malloc(sizeof(Node));
	pNew->id = y;
	pPre->next = pNew;
	pNew->next = pCur;

}
void SListNodeDel(LinkNode* p, int x)
{
	Node *head = (Node*)p;
	if (head == NULL)
	{
		return;
	}
	Node *pPre = NULL;
	Node *pCur = NULL;
	int flag = 0;

	pPre = head;
	pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			pPre->next = pCur->next;

			free(pCur);
			pCur = NULL;
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;

	}
	if (0 == flag)
	{
		printf("û��һ���ڵ�idֵΪ%d�Ľڵ�\n", x);
	}
}
void SListNodeDestroy(LinkNode *p)
{
	Node *head = (Node*)p;
	if (head == NULL)
	{
		return;
	}
	Node *del = head;
	Node *tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(del);
		del = NULL;
		del = tmp;
	}
}
int main()
{
	LinkNode *head = NULL;
	head = SListCreat();
	SListPrint(head);
	printf("\n��5ǰ�����4��Ľ����\n");
	SListNodeInsert(head, 5, 4);
	SListPrint(head);

	printf("\nɾ����һ���ڵ�idֵΪ5�Ľڵ㣺\n");
	SListNodeDel(head, 5);
	SListPrint(head);

	SListNodeDestroy(head);
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 1
int main()
{
	LinkNode *head = NULL;
	head = SListCreat();
	SListPrint(head);
	printf("\n��5ǰ�����4��Ľ����\n");
	SListNodeInsert(head, 5, 4);
	SListPrint(head);

	printf("\nɾ����һ���ڵ�idֵΪ5�Ľڵ㣺\n");
	SListNodeDel(head, 5);
	SListPrint(head);

	SListNodeDestroy(head);
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
#endif






