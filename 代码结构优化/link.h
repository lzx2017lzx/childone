#pragma once
//#include<stdio.h>
typedef void LinkNode ;

LinkNode* SListCreat();//��������

void SListPrint(LinkNode * p);//��ӡ

void SListNodeInsert(LinkNode* p, int x, int y);//����

void SListNodeDel(LinkNode* p, int x);//ɾ�����

void SListNodeDestroy(LinkNode *p);//��������