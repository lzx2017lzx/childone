#include"Queue.h"
//入队(栈s1是保存数据的栈，栈s2是用来辅助存入数据，每次插入数据时，需要借助s2将数据放到栈s1的最底部
//弹出数据不需要借助s2栈
void Queue::Push(const int& val)
{
	while (s1.size() != 0)
	{
		int temp = s1.top();
		s2.push(temp);
		s1.pop();
	}

	s1.push(val);
	
	while (s2.size() != 0)
	{
		int temp = s2.top();
		s1.push(temp);
		s2.pop();
	}

}
	//出队
void Queue::Pop()
{
	s1.pop();
}
	//返回队首元素
int& Queue::Front()
{
	return s1.top();
}
	//返回队尾元素(需要借助栈s2，将所有s1中元素放到s2，再访问s2的头元素，再弹入s1)
int& Queue::Back()
{
	while (s1.size() != 0)
	{
		int temp = s1.top();
		s2.push(temp);
		s1.pop();
	}
	int &temp = s2.top();
	
	while (s2.size() != 0)
	{
		int temp = s2.top();
		s1.push(temp);
		s2.pop();
	}
	return temp;

}
	//判断队列是否为空
bool Queue::Empty()
{
	if (s1.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	//返回队列大小
int Queue::Size()
{
	return s1.size();
}



