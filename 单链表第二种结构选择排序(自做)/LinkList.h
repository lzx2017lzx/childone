#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//定义链表节点数据类型
struct LinkNode
{
	struct LinkNode *next;
};

//链表数据类型
struct LinkList
{
	
	struct LinkNode header;
	int size;
};


//初始化
/*
	链表初始化
	@return 返回链表指针
*/
struct LinkList *Init_LinkList();
//插入
/*
	向链表在指定位置插入数据
	@param list 链表指针
	@param pos 插入位置
	@param data 插入数据
*/
void Insert_LinkList(struct LinkList *list, int pos, void *data);
//遍历
/*
	遍历链表
	@param list 链表指针
	@param myforeach 遍历回调函数
*/
void Foreach_LinkList(struct LinkList *list,void(*myforeach)(void *));
//删除
/*
	删除指定位置的节点
	@param list 链表指针
	@param pos 删除位置
*/
void Remove_LinkList(struct LinkList *list, int pos);

/*
	销毁链表
	@param list 链表指针
*/
void Destroy_LinkList(struct LinkList *list);

//定义排序函数
typedef int(*COMPAREFUNCTION)(void *First, void *Next);
//选择排序
int SelectRanking(struct LinkList *list, COMPAREFUNCTION func);


