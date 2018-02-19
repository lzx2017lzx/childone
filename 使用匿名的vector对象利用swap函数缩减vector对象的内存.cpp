// 编写程序用缩减使用vector时的内存(capacity不容易改动)
#include<iostream>
using namespace std;
#include<vector>
int main(void)
{
	vector<int> interg;
	interg.resize(20);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;

	//上述程序打印结果是20、20
	//现缩减size；再看结果
	cout << "使用resize裁剪数据" << endl;
	interg.resize(5);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;

	//通过匿名对象交换来缩小内存
	cout << "使用匿名对象缩小内存" << endl;
	vector<int>(interg).swap(interg);
	cout << "size:" << interg.size() << endl;

	cout << "capacity:" << interg.capacity() << endl;
	system("pause");
	return 0;
}