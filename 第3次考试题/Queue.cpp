#include"Queue.h"
//���(ջs1�Ǳ������ݵ�ջ��ջs2�����������������ݣ�ÿ�β�������ʱ����Ҫ����s2�����ݷŵ�ջs1����ײ�
//�������ݲ���Ҫ����s2ջ
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
	//����
void Queue::Pop()
{
	s1.pop();
}
	//���ض���Ԫ��
int& Queue::Front()
{
	return s1.top();
}
	//���ض�βԪ��(��Ҫ����ջs2��������s1��Ԫ�طŵ�s2���ٷ���s2��ͷԪ�أ��ٵ���s1)
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
	//�ж϶����Ƿ�Ϊ��
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
	//���ض��д�С
int Queue::Size()
{
	return s1.size();
}



