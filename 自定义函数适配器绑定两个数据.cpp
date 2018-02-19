//���Զ���һ����������,������ֵ
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
	typedef typename Functor::result_type ret_type;*///Functor��̳���MyThirdFunction�����Կ����������塣
	typedef  Functor::first_argument_type first_arg_type;
	typedef  Functor::second_argument_type second_arg_type;
	typedef  Functor::third_argument_type third_arg_type;
	typedef Arg1 first_argument_type;
	typedef  Functor::result_type ret_type;//���Բ���typename�����ֲ������У�����typename�ڶ��ֹ��ܣ�����Functor���ͱ����Ǵ�MyThirdFunction�̳й���������MyThirdFunction�е�first_argument_type�������͡�

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

template<class FunctorType, class BindParaml, class BindParam2>//���庯��ģ�壬����һ������
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
	for_each(v.begin(), v.end(), BindThirdFunction(MyPrint(), 100, 200));//����MyBinderFunction<FunctorType>��Ķ�������FunctorType��ӦMyPrint
																		 // BindThirdFunction(MyPrint(), 100, 200)��һ������

}
int main(void)
{
	test();
	system("pause");
	return 0;
}