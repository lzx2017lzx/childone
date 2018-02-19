#pragma once

#include<iostream>
using namespace std;
#include<stack>

class Queue
{
private:       
	stack<int> s1;
	stack<int> s2;
public:
	//入队
	void Push(const int& val);
	//出队
	void Pop();
	//返回队首元素
	int& Front();
	//返回队尾元素
	int& Back();
	//判断队列是否为空
	bool Empty();
	//返回队列大小
	int Size();
};
