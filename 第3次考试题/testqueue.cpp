#include<iostream>
using namespace std;
#include"Queue.h"

void test()
{
	Queue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	
	cout << "q.size:" << q.Size() << endl;

	cout << "queue's head element:" << q.Front() << endl;
	
	cout << "queue's back element:" << q.Back() << endl;

	cout << "whether queue is empty(0 represent false;1 represent true):" << q.Empty() << endl;

	//����Ԫ��
	q.Pop();
	q.Pop();

	//����ͷԪ��
	cout << "head element after poping two elements is:" << q.Front() << endl;
	cout << "q.size:" << q.Size() << endl;
	
	//��������Ԫ��
	while (q.Size() != 0)
	{
		q.Pop();
	}

	cout << "Size after popping all elements:" << q.Size() << endl;
}
int main(void)
{
	test();
	system("pause");
	return 0;
}
