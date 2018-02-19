#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//���
	void Push(const int& val)
	{
		s1.push(val);
	}
	//����
	void Pop()
	{
		if (Empty())
			return;
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
	//���ض���Ԫ��
	int& Front()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	//���ض�βԪ��
	int& Back()
	{
		if (s1.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		return s1.top();
	}
	//�ж϶����Ƿ�Ϊ��
	bool Empty()
	{
		return s1.empty() && s2.empty();
	}
	//���ض��д�С
	int Size()
	{
		return s1.size() + s2.size();
	}
};

int main()
{
	Queue q;
	for (int i = 0; i < 10; ++i)
	{
		q.Push(i);
	}
	cout << q.Size() << endl;//10
	cout << q.Front() << endl;//0
	cout << q.Back() << endl;//9
	q.Pop();
	cout << q.Front() << endl;//1
	cout << q.Size() << endl;//9
	cout << "---------------" << endl;
	while (!q.Empty())
	{
		cout << q.Front() << endl;//1-9
		q.Pop();
	}
	cout << q.Size() << endl;//0
	return 0;
}