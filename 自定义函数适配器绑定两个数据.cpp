//请自定义一个绑定适配器,绑定两个值
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
template<class Arg1, class Arg2, class Arg3, class RetType>
struct MyThirdFunction
{
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Arg3 third_argument_type;
	typedef RetType result_type;
};

template<class Functor>
class MyBinderFunction
{
	/*typedef typename Functor::first_argument_type first_arg_type;
	typedef typename Functor::second_argument_type second_arg_type;
	typedef typename Functor::third_argument_type third_arg_type;
	typedef typename Functor::result_type ret_type;*///Functor类继承了MyThirdFunction，所以可以这样定义。
	typedef  Functor::first_argument_type first_arg_type;
	typedef  Functor::second_argument_type second_arg_type;
	typedef  Functor::third_argument_type third_arg_type;
	typedef Arg1 first_argument_type;
	typedef  Functor::result_type ret_type;//测试不加typename，发现不能运行，体现typename第二种功能，声明Functor类型必须是从MyThirdFunction继承过来，含有MyThirdFunction中的first_argument_type、等类型。

public:
	MyBinderFunction(Functor functor, second_arg_type param2, third_arg_type param3) :mFunctor(functor), mParam2(param2), mParam3(param3)
	{

	}
	ret_type operator()(first_arg_type val)
	{
		return mFunctor(val, mParam2, mParam3);
	}

public:
	Functor mFunctor;
	second_arg_type mParam2;
	third_arg_type mParam3;
};

template<class FunctorType, class BindParaml, class BindParam2>//定义函数模板，返回一个对象
MyBinderFunction<FunctorType>BindThirdFunction(FunctorType functor,
	BindParaml param1, BindParam2 param2)
{
	return MyBinderFunction<FunctorType>(functor, param1, param2);
}

struct MyPrint :public MyThirdFunction<int, int, int, void>
{
	void operator()(int val, int p1, int p2)
	{
		cout << "val=" << val << "p1=" << p1 << "p2=" << p2 << endl;
	}
};

void test()
{
	vector<int>v = { 1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), BindThirdFunction(MyPrint(), 100, 200));//返回MyBinderFunction<FunctorType>类的对象，其中FunctorType对应MyPrint
																		 // BindThirdFunction(MyPrint(), 100, 200)是一个函数

}
int main(void)
{
	test();
	system("pause");
	return 0;
}