#include"LinkList.h"

//��ʼ��
struct LinkList *Init_LinkList()
{
	struct LinkList *list = malloc(sizeof(struct LinkList));
	list->header.next = NULL;
	list->size = 0;

	return list;

}



//����
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


	//����ָ�����
	struct LinkNode *pCurrent = &(list->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//��������

	struct LinkNode *newnode = (struct LinkNode *)data;

	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	list->size++;

}

//����
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


	//����ָ�����
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


	//�����´�ɾ���ڵ�
	struct LinkNode *pDel = pCurrent->next;

	//���½�����ɾ���ڵ�ǰ���ͺ�̽ڵ��ϵ
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

//�������и��ݺ����ķ��ؽ�����򣬷��ؽ������0����ʾ��һ��Ԫ�ش�С��0��ʾ���߸�����Ϊ�������������ָ�룬���Ժ������Ͳ�Ҳ����Ϊָ��
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

	//����ָ���������ָ�룬������������
	struct LinkNode *PiPre = &(list->header);//���ڵ�һ��forѭ��
	struct LinkNode *Pi = PiPre->next;//���ڵ�һ��forѭ��,ʼ��ָ��PiPre����һ�����
	struct LinkNode *PjPre = &(list->header);//���ڵڶ���forѭ��
	struct LinkNode *Pj = PjPre->next;//���ڵڶ���forѭ����ʼ��ָ��PiPre����һ�����


	//����ָ�������������
	struct LinkNode *PTemp1 = NULL;//ͬʱΪ�˷�ֹ����
	struct LinkNode *PTemp2 = NULL;//������ֹ����
	for (; Pi != NULL; PiPre=Pi,Pi=PiPre->next)
	{
		for (Pj = Pi; Pj != NULL; PjPre=Pj,Pj=PjPre->next)
		{
			if (func(Pi, Pj) > 0)//˵����Ҫ����
			{
				//��Ҫ�ж�Pi��Pj�Ƿ����ڣ����ڽ��Ͳ����ڽ�㽻����ʽ��һ��
				if (Pi->next != Pj)
				{//���Ƚ�Pj���뵽Pi��ǰ��
					PjPre->next = Pj->next;//��ֹ����
					Pj->next = Pi;//Pjָ��Ľ��ָ��Pi���
					PiPre->next = Pj;//�ɹ���Pjָ��Ľ����뵽Piָ��Ľ���ǰ��

					//�ٽ�Piָ��Ľ����뵽PjPreָ��Ľ��ĺ���
					Pj->next = Pi->next;//��ֹ����
					Pi->next = PjPre->next;//Piָ��Ľ��ָ��PjPreָ��Ľ�����һ�����
					PjPre->next = Pi;//PjPreָ��Ľ��ָ��Piָ��Ľ��

					//��󽻻�Pi��Pj��ֵ
					PTemp1 = Pi;
					Pi = Pj;
					Pj = PTemp1;
				}
				else
				{
					PjPre->next = Pj->next;//��ֹ����
					Pj->next = Pi;//Pjָ��Ľ��ָ��Pi���
					PiPre->next = Pj;

					//��󽻻�Pi��Pj��ֵ
					PTemp1 = Pi;
					Pi = Pj;
					Pj = PTemp1;

					//PjPre��ָ��Pjָ��Ľ���ǰ����
					PjPre = Pi;

				}
			}

		}
	}
	return 0;
}