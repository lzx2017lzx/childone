#pragma once

#include<stdlib.h>


//链表是由一系列节点组成
//定义链表节点的数据类型
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;


//为了C++中调用此函数
//c++不需要写此宏，C语言中需要写
#ifdef __cplusplus
extern "C"{
#endif

	//初始化  后缀主要为了防止命名冲突
	LinkList Init_LinkList();
	//插入
	void Insert_LinkList(LinkList list, int pos,void *data);
	//删除
	void Remove_LinkList(LinkList list, int pos);
	//遍历
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//销毁
	void Destroy_LinkList(LinkList list);
	//打印结点个数
	int Size_LinkList(LinkList list);
	//单链表选择排序(链表结点储存数据域)
	typedef int(*PCOMPARE)(void *Data1, void *Data2);//按照升序排列，所以返回值大于0，要处理
	int SelectSort(LinkList list, PCOMPARE Pfun);

	//单链表插入排序(链表结点存储数据域)
	int InsertSort(LinkList list, PCOMPARE Pfun);

#ifdef __cplusplus
}
#endif