// ��д����������ʹ��vectorʱ���ڴ�(capacity�����׸Ķ�)
#include<iostream>
using namespace std;
#include<vector>
int main(void)
{
	vector<int> interg;
	interg.resize(20);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;

	//���������ӡ�����20��20
	//������size���ٿ����
	cout << "ʹ��resize�ü�����" << endl;
	interg.resize(5);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;

	//ͨ���������󽻻�����С�ڴ�
	cout << "ʹ������������С�ڴ�" << endl;
	vector<int>(interg).swap(interg);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;
	system("pause");
	return 0;
}