#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id; //������
	struct Node *next; //ָ����
}Node;

//���ܣ�ѭ�������ڵ㣬��-1�˳�
//����ֵ���ṹ�����͵�ָ�������ͷ����ָ��
Node *SListCreat()
{
	Node *head = NULL;
	Node *pNew = NULL; //�½ڵ�
	Node *pCur = NULL; //β���
	int data;

	//�ȴ���ͷ��㣬ֻ����Ϊ��־����������Ч����
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	//�������һ���ڵ�
	pCur = head;

	//ѭ�������������ݽڵ�

	while (1)
	{
		//����������
		printf("���������֣�");
		scanf("%d", &data);
		if (data < 0)
		{
			break;
		}

		//�½��ڵ�
		pNew = (Node *)malloc(sizeof(Node));
		pNew->id = data;

		//��������ϵ
		//β�ڵ�nextָ���½ڵ�
		pCur->next = pNew;
		//pNew��Ϊβ���
		pNew->next = NULL;
		//����β���
		pCur = pNew;
	}

	return head;
}

//������ӡÿ���ڵ��������
void SListPrint(Node * head)
{
	if (head == NULL)
	{
		return;
	}

	//�������ݣ����׽ڵ㿪ʼ��ͷ������һ���ڵ㿪ʼ
	Node * tmp = head->next;
	printf("head -> ");
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->id);

		//ָ����һ���ڵ�
		tmp = tmp->next;
	}
	printf("NULL\n");
}

//�ڽڵ�id����x, ������ڵ��ǰ�����һ���½ڵ㣬�½ڵ��idΪy
//���û�нڵ�id����x, ��β������, �½ڵ��idΪy
void SListNodeInsert(Node * head, int x, int y)
{
	if (head == NULL)
	{
		return;
	}

	Node * pPre = NULL;
	Node * pCur = NULL;
	Node * pNew = NULL;

	//���һ���ڵ㣬pCur����
	pPre = head;
	pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x) //�������㣬�˳�ѭ��
		{
			break;
		}

		//�ڵ���������ƶ�
		pPre = pPre->next;
		pCur = pCur->next;
	}

	//�����½ڵ�

	//�½��ڵ�
	pNew = (Node *)malloc(sizeof(Node));
	pNew->id = y;

	//pPre��nextָ���½ڵ�
	pPre->next = pNew;
	//�½ڵ��Nextָ��pCur
	pNew->next = pCur;
}

//ɾ����һ���ڵ�idֵΪx�Ľ��
void SListNodeDel(Node *head, int x)
{
	if (head == NULL)
	{
		return;
	}

	Node * pPre = NULL;
	Node * pCur = NULL;
	int flag = 0; //Ĭ��û���ҵ�

				  //���һ���ڵ㣬pCur����
	pPre = head;
	pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x) //�������㣬�˳�ѭ��
		{
			//ɾ��ǰ����pre��nextָ��cur��next
			pPre->next = pCur->next;

			free(pCur);
			pCur = NULL;
			flag = 1;

			break;
		}

		//�ڵ���������ƶ�
		pPre = pPre->next;
		pCur = pCur->next;
	}

	if (0 == flag)
	{
		printf("û�е�һ���ڵ�idֵΪ%d�Ľ��\n", x);
	}

}

//�ͷ����нڵ�
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
		//�ͷ�ǰ��������һ���ڵ�
		tmp = tmp->next;
		free(del);
		del = NULL;

		//del������Ҫ�ͷŵĽ��
		del = tmp;
	}
}
//ɾ��ֵΪx�����н��
//û���ж��Ƿ����������x��ֵ�������
int SListNodeDelPro(Node *pHead, int x)
{
	if (pHead == NULL)
		return -1;
	Node *pPre = NULL;
	Node *pCur = NULL;

	pPre = pHead;
	pCur = pHead->next;
	//��ͷ��㿪ʼ�������������ֽ��������ֵΪxʱ��ɾ�����
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

//����ڵ����򣬽�������������
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

//�������򣬽����������
int SListNodeSortNode(Node *pHead)
{
	if (pHead->next = NULL)
		return -1;
	Node *pPre = NULL;
	Node *pCur = NULL;
	Node temp = { 0 };

	pPre = pHead;
	pCur = pPre->next;
	
	//ѡ������ÿ�ֶ��Ὣȷ��λ�õĽ�������ս����ͬ��pPreָ���λ�õ�ǰһ����㣬pCurָ���λ�ô��Ľ��
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
		pPre = pPre->next;//ָ��λ���޶����Ľ��	
	}
	return 0;
}
//ע�⣬����nextָ�뻹��Ҫ����
/*if (pPre->id > pCur->id) //����
{
	//�����ڵ�����
	tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//�����½���һ��nextָ����
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
}
*/
//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
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
	//�ȱȽϴ�С�ҵ�xӦ�����λ�ã������������
	while (pCur != NULL)
	{
		if (pCur->id >=x)
			break;
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//������
	pPre->next = temp;
	temp->next = pCur;
	return 0;
}

//��ת����Ľڵ㣨���������Ƿ�ת������������ָ����
int SListNodeReverse(Node *pHead)
{
	
	if (pHead == NULL)
		return -1;

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node *temp = NULL;

	pPre = pHead->next;
	pCur = pPre->next;
	temp = pCur->next;//��ֹ����
	pPre->next = NULL;
	//����ͷ�巨
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
	head = SListCreat(); //��������

						 //������ӡÿ��������
	SListPrint(head);

	printf("\n��5ǰ�����4��Ľ����\n");
	SListNodeInsert(head, 5, 4); //��5ǰ�����4�����û��5����ĩβ����
	SListPrint(head);

	printf("\nɾ����һ���ڵ�idֵΪ5�Ľ�㣺\n");
	SListNodeDel(head, 5);
	SListPrint(head);

	SListNodeDestroy(head); //�ͷ����нڵ�
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
int main()
{
Node *pHead = NULL;

pHead = SListCreat(); //����ͷ���
printf("\n����ͷ����\n");
SListPrint(pHead); //�������нڵ�

SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
printf("\nɾ������ֵΪ4�Ľ��\n");
SListPrint(pHead); //�������нڵ�

SListNodeSortData(pHead);//����ڵ�����
printf("\n����ڵ�����\n");
SListPrint(pHead); //�������нڵ�

SListNodeInsertPro(pHead, 5);//�������5
printf("\n�������5��\n");
SListPrint(pHead); //�������нڵ�

//��ת����Ľڵ㣨���������Ƿ�ת��
SListNodeReverse(pHead);
printf("\n��ת����Ľڵ�\n");
SListPrint(pHead); //�������нڵ�

SListNodeDestroy(pHead);//�ͷ����нڵ�
pHead = NULL;
system("pause");
return 0;
}