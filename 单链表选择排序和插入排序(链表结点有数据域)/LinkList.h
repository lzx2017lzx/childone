#pragma once

#include<stdlib.h>


//��������һϵ�нڵ����
//��������ڵ����������
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;


//Ϊ��C++�е��ô˺���
//c++����Ҫд�˺꣬C��������Ҫд
#ifdef __cplusplus
extern "C"{
#endif

	//��ʼ��  ��׺��ҪΪ�˷�ֹ������ͻ
	LinkList Init_LinkList();
	//����
	void Insert_LinkList(LinkList list, int pos,void *data);
	//ɾ��
	void Remove_LinkList(LinkList list, int pos);
	//����
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//����
	void Destroy_LinkList(LinkList list);
	//��ӡ������
	int Size_LinkList(LinkList list);
	//������ѡ������(�����㴢��������)
	typedef int(*PCOMPARE)(void *Data1, void *Data2);//�����������У����Է���ֵ����0��Ҫ����
	int SelectSort(LinkList list, PCOMPARE Pfun);

	//�������������(������洢������)
	int InsertSort(LinkList list, PCOMPARE Pfun);

#ifdef __cplusplus
}
#endif