#include"LinkList.h"

//�������������
struct LList
{
	struct LinkNode header; //ͷ���
	int size; //�����С
	//struct LinkNode *rear; //ָ��β���ڵ�
};

//��ʼ��  ��׺��ҪΪ�˷�ֹ������ͻ
LinkList Init_LinkList()
{
	struct LList *list = malloc(sizeof(struct LList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;

	return list;
}
//����
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

	//����ָ�����
	struct LinkNode *pCurrent = &(mylist->header);
	//��λ��
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//1. �����½ڵ�
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//2. �½��������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;

}
//ɾ��
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

	//�ҵ�ɾ��λ�õ�ǰһ��λ�õĽڵ�
	struct LinkNode *pCurrent = &(mylist->header);

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�Ȼ����´�ɾ���ڵ�
	struct LinkNode *pDel = pCurrent->next;
	//���½�����ɾ���ڵ��ǰ���ͺ�̽ڵ��ϵ
	pCurrent->next = pDel->next;
	//�ͷ�ɾ���ڵ���ڴ�
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//����
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

	//����ָ��
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//����
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}


	struct LList *mylist = (struct LList *)list;
	//����ָ��
	struct LinkNode *pCurrent = mylist->header.next;

	struct LinkNode *pNext = NULL;
	while (pCurrent != NULL)
	{
		//�Ȼ��浱ǰ�ڵ����һ���ڵ�
		pNext = pCurrent->next;
		//���ĵ��ͷŵ�ǰ�ڵ���ڴ�
		free(pCurrent);

		pCurrent = pNext;
	}


	free(mylist);
	mylist = NULL;
}

//��ӡ���������
int Size_LinkList(LinkList list)
{

	if (NULL == list)
	{
		return 0;
	}

	struct LList *mylist = (struct LList *)list;

	return mylist->size;
}

//������ѡ������(�����㴢��������),���ûص������������ȽϽ��

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
	struct LList*Plist = (struct LList*)list;//��void *�ͱ�������ǿ������ת��

	struct LinkNode*PLinkNode = NULL;//���Ҫ�����Ľ��ĵ�ַ

	struct LinkNode *PCur =Plist->header.next;//����ָ���һ����Ч����ָ��

	struct LinkNode *Ptemp = NULL;//��������Ѱ��Ҫ��PCurָ��Ľ�㽻���Ľ��

	
	
	for (; PCur != NULL; PCur = PCur->next)
	{
		PLinkNode = PCur;//����PLinkNode��ŵľ���Ҫ�����Ľ�㣬�������ʾdata����С�Ľ�㣬����������
		for (Ptemp = PCur->next; Ptemp != NULL; Ptemp = Ptemp->next)
		{
			if (Pfun(PLinkNode->data, Ptemp->data))//���Ptemp��������С�ͽ��ý��ĵ�ַ��ֵ��PLinkNode
			{
				PLinkNode = Ptemp;
			}
		}

		//�����������������򣬽���ͷ������������Ϊ�����ĸ����ռ�
		Plist->header.data = PLinkNode->data;
		PLinkNode->data = PCur->data;
		PCur->data = Plist->header.data;
		
		//���ͷ����������
		Plist->header.data = NULL;
	}

	return 0;
}


//�������������(������洢������)
int InsertSort(LinkList list, PCOMPARE Pfun)
{
	//��������ָ��ָ��Ҫ����Ľ�㣬ָ���ǲ���ָ���������һ�����ģ����᷵�أ��������Ҫ��֤�ý��֮ǰ�����н����������������
	//Ҫ����Ľ��Ĳ���λ�õ�Ҫ��������ǰһ������������󣬵��ǱȺ�һ���Ľ���������С
	if (NULL == list)
	{
		return -1;
	}

	if (NULL == Pfun)
	{
		return -2;
	}

	struct LList *PLList = (struct LList *)list;
	//����ָ������ָ��PCurָ��Ľ���ǰһ����㣻����PCurָ��Ľ����в��봦��ʱ����ֹ����
	struct LinkNode *PCurPre = PLList->header.next;//ָ���һ��Ԫ��,����������Ч�ر���ֻ��һ����ЧԪ�أ�����˳������
	struct LinkNode *PCur = PCurPre->next;//����ָ��Ҫ����Ľ���ָ��,��ʼ��ָ���һ����Ч���

	//����ָ����������PCurָ��Ľ���֮ǰ�Ľ�㣻
	struct LinkNode *Ptemp = &(PLList->header);//
	//int flag = 0;//����flag��������Ϊ��һ�δ����֮��Ĵ���ʽ��һ����flagΪ0����ʾ��һ�Σ�����Ϊ

	while(PCur != NULL)
	{
		Ptemp = PLList->header.next;//��ͷ��ʼ����

		for (; (Ptemp != PCur)&&(Ptemp!=NULL); Ptemp = Ptemp->next)
		{
			if ((Pfun(Ptemp->data, PCur->data) <= 0) && (Pfun(PCur->data, Ptemp->next->data) < 0))
			{
				break;
			}

			if ((Pfun(Ptemp->data, PCur->data)) >=0)//�����һ�����ʹ��ڵ���Ŀǰ�Ľ�㣬Ҳ��ֹѭ��
			{
				break;
			}
		}

		if (Ptemp == PCur)//���Ptemp==PCur������Ҫ����
		{
			PCurPre = PCur;
			PCur = PCurPre->next;
			continue;
		}
		//�����һ��������PCurָ��Ľ���������ʱҪ����
		if (Ptemp == PLList->header.next)//�жϵ�һ����Ч���������ǲ��Ǵ���Ҫ����Ľ��
		{
			PCurPre->next = PCur->next;//��ֹ����
			PCur->next = Ptemp;
			PLList->header.next = PCur;
			PCur = PCurPre->next;
			continue;
		}
		
		//ѭ����������ζPtempָ��Ľ��ĺ�һ����㣬��PCurָ��Ľ��Ĳ���λ��
		//���в���
		PCurPre->next = PCur->next;//��ֹ����
		PCur->next = Ptemp->next;
		Ptemp->next = PCur;

		//��PCurָ��ָ��PCurPreָ��Ľ�����һ�����
		PCur = PCurPre->next;
	}
	return 0;
}