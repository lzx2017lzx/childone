#include<iostream>
using namespace std;
template<class _CallBack>
void print(_CallBack _func)
{

	cout << typeid(_func).name() << endl;//
	int a = 3;
	_func(a);//�൱��Show()(a);Show()������������
	return;
}

//������ӡ��������,�����жԣ��������������
struct Show
{
	void operator()(int a)
	{
		cout << a << endl;
	}
};

void test01()
{
	Show s1;
	cout << "��ͨ���ص�����!" << endl;
	s1(5);
	cout << "ʹ�ûص�����!" << endl;
	Show()(80);//Show()����һ������������˿���ͨ��������ʽ�������ص�()����
	print(Show());
}

int main()
{
	test01();
	system("pause");
	return 0;

}