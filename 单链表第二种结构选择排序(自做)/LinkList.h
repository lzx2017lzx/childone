#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//��������ڵ���������
struct LinkNode
{
	struct LinkNode *next;
};

//������������
struct LinkList
{
	
	struct LinkNode header;
	int size;
};


//��ʼ��
/*
	�����ʼ��
	@return ��������ָ��
*/
struct LinkList *Init_LinkList();
//����
/*
	��������ָ��λ�ò�������
	@param list ����ָ��
	@param pos ����λ��
	@param data ��������
*/
void Insert_LinkList(struct LinkList *list, int pos, void *data);
//����
/*
	��������
	@param list ����ָ��
	@param myforeach �����ص�����
*/
void Foreach_LinkList(struct LinkList *list,void(*myforeach)(void *));
//ɾ��
/*
	ɾ��ָ��λ�õĽڵ�
	@param list ����ָ��
	@param pos ɾ��λ��
*/
void Remove_LinkList(struct LinkList *list, int pos);

/*
	��������
	@param list ����ָ��
*/
void Destroy_LinkList(struct LinkList *list);

//����������
typedef int(*COMPAREFUNCTION)(void *First, void *Next);
//ѡ������
int SelectRanking(struct LinkList *list, COMPAREFUNCTION func);


