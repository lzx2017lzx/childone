#pragma once
//#include<stdio.h>
typedef void LinkNode ;

LinkNode* SListCreat();//创建链表

void SListPrint(LinkNode * p);//打印

void SListNodeInsert(LinkNode* p, int x, int y);//插入

void SListNodeDel(LinkNode* p, int x);//删除结点

void SListNodeDestroy(LinkNode *p);//销毁链表