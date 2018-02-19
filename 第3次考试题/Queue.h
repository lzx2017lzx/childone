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
	//���
	void Push(const int& val);
	//����
	void Pop();
	//���ض���Ԫ��
	int& Front();
	//���ض�βԪ��
	int& Back();
	//�ж϶����Ƿ�Ϊ��
	bool Empty();
	//���ض��д�С
	int Size();
};
