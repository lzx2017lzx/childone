#include<iostream>
using namespace std;
template<class _CallBack>
void print(_CallBack _func)
{

	cout << typeid(_func).name() << endl;//
	int a = 3;
	_func(a);//相当于Show()(a);Show()产生匿名对象
	return;
}

//创建打印函数对象,必须有对（）运算符的重载
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
	cout << "不通过回调函数!" << endl;
	s1(5);
	cout << "使用回调函数!" << endl;
	Show()(80);//Show()产生一个匿名对象，因此可以通过这个表达式调用重载的()函数
	print(Show());
}

int main()
{
	test01();
	system("pause");
	return 0;

}